#include "MPU9250.h"

MPU9250 mpu;
unsigned long prev_ms = 0;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);

    //Conexion con mpu
    if (!mpu.setup(0x68)) {
        while (1) {
            Serial.println("Fallo en la conexión del MPU.");
            delay(5000);
        }
    }
}

void loop() {
    if (mpu.update()) {

            // Leyendo datos de aceleración
            float accelX = mpu.getAccX();
            float accelY = mpu.getAccY();
            float accelZ = mpu.getAccZ();

            // Leyendo datos de giroscopio
            float gyroX = mpu.getGyroX();
            float gyroY = mpu.getGyroY();
            float gyroZ = mpu.getGyroZ();

            // Leyendo datos de magnetómetro
            float magX = mpu.getMagX();
            float magY = mpu.getMagY();
            float magZ = mpu.getMagZ();

            // Imprimiendo datos
            Serial.println("Aceleración: " + (String)accelX + " " + (String)accelY + " " + (String)accelZ);
            Serial.println("Giroscopio: " + (String)gyroX + " " + (String)gyroY + " " + (String)gyroZ);
            Serial.println("Magnetómetro: " + (String)magX + " " + (String)magY + " " + (String)magZ);

           delay(1000);
    }
}