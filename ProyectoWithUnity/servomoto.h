#ifndef SERVOMOTO_H
#define SERVOMOTO_H

#include <Arduino.h>
#include <ESP32Servo.h>
const int servoPin = 4;

// Declaración de la función para inicializar el servomotor
void initServo();

// Declaración de la función para controlar el servomotor
void moveServo(int angle);

#endif