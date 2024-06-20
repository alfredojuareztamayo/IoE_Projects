#ifndef MUSIC_H
#define MUSIC_H

const int ZumbadorPin = 11; // definimos el pin al que conectaremos el zumbador.

/*definimos cada una de las frecuencias de las notas musicales.
c, d, e... son las notas en notación inglesa.
Cuando van acompañadas de la letra S significa que esa nota es sostenido.
Cuando van acompañadas de la letra H significa que esa nota está en una
octava superior (High).
*/

const int c = 261; 
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 783;
const int gSH = 830;
const int aH = 880;

void playMarchaImperial();

#endif