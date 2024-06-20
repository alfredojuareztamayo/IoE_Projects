#include <WiFi.h>

//----------Servidor Web en puerto 80

WiFiServer server(80);

//**********Credenciales de WiFi

const char* ssid = "SAE_INSTITUTE";
const char* password = "AlumnosSAE..";

//**********Variables globales

int contconexion = 0;
int med = 5;
String header; //Variable para guardar el HTTP request

//Otras variables
String estadoSalida = "off";

const int salida = 2;

//*-------Codigo HTML-----

String pagina = "<!DOCTYPE html>"
"<html>"
  "<head>"
  "<meta charset = 'utf-8'/>"
  "<title>ARTEK ESP32</title>"
  "</head>"
  "<body>"
  "<center>"
  "<h1>Servidor Artek Web Esp32</h1>"
  "<p><a href='/on'><button style='height:50px;width:100px'>ON</button></a></p>"
  "<p><a href='/off'><button style='height:50px;width:100px'>OFF</button></a></p>"
    "</p></center></body></html>";

    //----------SETUP

void setup()
{
Serial.begin(115200);
Serial.println("Bienvenidos");

pinMode(salida,OUTPUT);
digitalWrite(salida,LOW);

//CONEXIPN WIFI
WiFi.begin(ssid,password);
//Cuenta hasta 50 si no se puede conectar lo cancela
  while(WiFi.status() != WL_CONNECTED and contconexion < 50)
  {
    ++contconexion;
    delay(500);
    Serial.print(".");
  }

if(contconexion < 50)
{
  //para usar ip fija
  //IPAddres ip(192,162,1,180);
  //IPAddres gateway(192,168,1,1);
  //IPAddres subnet(255,255,255,0);
  //Wifi.config(ip,gateway,subnet);

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println(WiFi.localIP());
  server.begin(); //inciamos el server

}
else{
  Serial.println("");
  Serial.println("Error de conexion");
}
}


//------------LOOP


void loop()
{

  WiFiClient client = server.available(); //Escucha los clientes entrantes

  if(client)
  {
    Serial.println("New Client");
    String currentLine = "";
    while(client.connected()){
      if(client.available())
      {
        char c = client.read();
        Serial.write(c);
        header += c;
        if(c == '\n')
        {
          //Si la nueva linea queda en blanco
          //HTTP request del cliente
          if(currentLine.length()==0){
            client.println("HTTP/1.1 200 OK");
            client.println("content-typetext/html");
            client.println("Connection: close");
            client.println();
            //enciende y apaga el GPIO
            if(header.indexOf("GET /on")>=0){
              Serial.println("GPIO on");
              estadoSalida = "on";
              digitalWrite(salida, HIGH);
            }
            else if(header.indexOf("GET /off")>=0){
              Serial.println("GPIO off");
              estadoSalida = "off";
              digitalWrite(salida, LOW);
            }
            //Muestra la pagina Web
            client.println(pagina);
            //client.print(med);
            //client.print("metros </p> </center></body></html>");

            //la respuesta HTTP termina con una linea en blanco
            client.println();
            break;
          }else{
            currentLine = "";
          }
        } else if(c != '\r'){
          currentLine += c;
        }
      }
    }
    //Limpiamos la variable header
    header = "";
    //Cerramos" la conexion
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}