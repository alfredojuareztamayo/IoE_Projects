#include "life.h"
#include <Arduino.h>

int damage = 0;
void setLife() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT); 
    digitalWrite(ledPins[i], HIGH); 
  }
}
void getDamage() {
  // Apagar todos los LEDs
  for (int i = 0; i <= damage; i++) {
    digitalWrite(ledPins[i], LOW);
  }
 damage++;
}
