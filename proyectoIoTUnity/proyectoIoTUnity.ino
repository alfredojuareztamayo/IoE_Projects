#include <WiFi.h>
#include <PubSubClient.h>
#include "music.h"
//#include "BluetoothSerial.h"

// Configuración WiFi
const char* ssid = "SAE_INSTITUTE";
const char* password = "AlumnosSAE..";
// Configuración MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "esp32/foco";

WiFiClient espClient;
PubSubClient client(espClient);

//BluetoothSerial SerialBT;

//const char* deviceName = "steren LAM-BOC";  // Nombre del dispositivo Bluetooth

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

  //SerialBT.begin("ESP32 Sleekhell"); // Nombre del dispositivo ESP32
  Serial.println("El ESP32 está listo para conectar");

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

  // Procesar el mensaje y enviar el comando al dispositivo Bluetooth
  sendCommand(message.c_str());
}
/*
bool connectToBluetoothDeviceByName(const char* name) {
  SerialBT.disconnect();
  delay(1000);

  Serial.print("Intentando conectar al dispositivo Bluetooth con nombre: ");
  Serial.println(name);

  if (SerialBT.connect(name)) {
    Serial.println("Conectado al dispositivo Bluetooth");
    return true;
  } else {
    Serial.println("No se pudo conectar al dispositivo Bluetooth. Verifica que el dispositivo esté encendido y en modo descubrible.");
    return false;
  }
}
*/

void sendCommand(const char* cmd) {
  if (SerialBT.connected()) {
    SerialBT.println(cmd);
    Serial.println("Comando enviado: " + String(cmd));
  } else {
    Serial.println("El dispositivo Bluetooth no está conectado");
  }
}