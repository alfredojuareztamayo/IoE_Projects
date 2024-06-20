#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLEClient.h>

const char* DEVICE_ADDRESS = "CD:42:CF:43:50:1E"; // Dirección MAC del dispositivo Bluetooth

BLEClient* pClient;

class MyClientCallback : public BLEClientCallbacks {
    void onConnect(BLEClient* pClient) {
        Serial.println("Conectado a audífonos Bluetooth");
    }

    void onDisconnect(BLEClient* pClient) {
        Serial.println("Desconectado de audífonos Bluetooth");
    }
};

void setup() {
    Serial.begin(115200);
    delay(1000);

    BLEDevice::init("ESP32"); // Inicializar BLE
    pClient = BLEDevice::createClient(); // Crear instancia del cliente BLE
    pClient->setClientCallbacks(new MyClientCallback());

    // Escaneo de dispositivos Bluetooth
    BLEScan* pBLEScan = BLEDevice::getScan();
    pBLEScan->setActiveScan(true);

    Serial.println("Escaneando dispositivos Bluetooth...");
    BLEScanResults* pScanResults = pBLEScan->start(5); // Escanear durante 5 segundos

    // Buscar el dispositivo por dirección MAC
    BLEAdvertisedDevice foundDevice;
    bool deviceFound = false;
    for (int i = 0; i < pScanResults->getCount(); i++) {
        foundDevice = pScanResults->getDevice(i);

        // Imprimir información detallada sobre el dispositivo encontrado
        Serial.print("Dispositivo encontrado ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print("Nombre: ");
        Serial.print(foundDevice.getName());
        Serial.print(", Dirección: ");
        Serial.println(foundDevice.getAddress().toString().c_str());

        // Verificar si el dispositivo tiene la dirección MAC buscada
        if (foundDevice.getAddress().toString() == DEVICE_ADDRESS) {
            deviceFound = true;
            break;
        }
    }

    if (deviceFound) {
        // Conectar al dispositivo encontrado
        pClient->connect(&foundDevice);
        Serial.println("Intentando conectar a audífonos Bluetooth...");
    } else {
        Serial.println("Dispositivo no encontrado");
    }
}

void loop() {
    // Aquí puedes agregar tu lógica para manejar la conexión Bluetooth
    delay(1000);
}