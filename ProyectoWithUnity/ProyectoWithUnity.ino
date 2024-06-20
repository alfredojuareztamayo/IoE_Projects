#include <WiFi.h>
#include <PubSubClient.h>
#include "servomoto.h"
#include "music.h"
#include "life.h"
#include "paginaWeb.h"


// Configuración WiFi
//const char* ssid = "SAE_INSTITUTE";
//const char* password = "AlumnosSAE..";


const char* ssid = "INFINITUM69A5_2.4";
const char* password = "B9a3smjJNm";
// Configuración MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "esp32sleek";

WiFiClient espClient;
PubSubClient client(espClient);

// Pin del LED
const int ledPin = 2;

//server del wifi

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Conectando a ");
  Serial.println(ssid);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  
  Serial.println("El ESP32 está listo para conectar");

  pinMode(ledPin, OUTPUT);
  pinMode(ZumbadorPin, OUTPUT);
  setLife();
  initServo();
  moveServo(0);    // Mueve a 0 grados
  delay(1000);
  Serial.println("mapa encontrado 0%");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
}
void reconnect() {
  while (!client.connected()) {
    Serial.print("Intentando conectar al servidor MQTT...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("fallo, rc=");
      Serial.print(client.state());
      Serial.println(" intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");
  
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  
  Serial.println(message);

  // Verificar si el mensaje recibido es para encender el LED
  if (strcmp(topic, mqtt_topic) == 0) {
    if (message.equals("Fon")) {
      digitalWrite(ledPin, HIGH);  // Encender el LED
      Serial.println("LED encendido");
    } 
    if(message.equals("Foff")){
      digitalWrite(ledPin, LOW);   // Apagar el LED
      Serial.println("LED apagado");
    }
    if(message.equals("M1")){
      playMarchaImperial();
      Serial.println("Music On");
    }
    if(message.equals("M1n")){
      stopMusic();
      Serial.println("Music Off");
    }
    if(message.equals("M2")){
      playHarryPotter();
      Serial.println("Music on");
    }
    if(message.equals("M3")){
      playLionSleepTonight();
      Serial.println("Music on");
    }
    if(message.equals("M4")){
      playSimpsons();
      Serial.println("Music on");
    }
    if(message.equals("damage")){
      getDamage();
      Serial.println("Recibi Daño");
    }
    
    if(message.equals("lvl1")){
      moveServo(90);    // Mueve a 0 grados
      delay(1000);
      Serial.println("mapa encontrado 0%");
    }
    if(message.equals("lvl2")){
      moveServo(180);    // Mueve a 0 grados
      delay(1000);
      Serial.println("mapa encontrado 100%");
    }
    if(message.equals("gameover")){
      playNeverGive();    
      delay(1000);
      Serial.println("perdiste");
    }
    if(message.equals("win")){
      playEnemy();   
      delay(1000);
      Serial.println("Ganaste");
    }
  }
  
}