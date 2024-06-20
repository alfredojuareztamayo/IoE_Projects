#include "servomoto.h"

Servo myservo;  // Crea un objeto servo para controlar un servomotor

void initServo() {
  myservo.attach(servoPin);  // Adjunta el servo al pin definido
}

void moveServo(int angle) {
  myservo.write(angle);  // Mueve el servomotor al ángulo especificado
}