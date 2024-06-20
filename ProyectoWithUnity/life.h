#ifndef LIFE_H
#define LIFE_H

const int ledPins[] = {13, 14, 15}; // Arreglo de pines de LEDs
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
extern int damage;

void setLife();
void getDamage();

#endif