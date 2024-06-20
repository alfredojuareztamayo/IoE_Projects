#include "music.h"
#include <Arduino.h>

int melody[] = {
  REST, NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_C5, 
  NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4,
  NOTE_D4, 
  NOTE_D4,
  
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_B4,
  NOTE_G4,
  NOTE_AS4,
   
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_DS5, NOTE_D5,
  NOTE_CS5, NOTE_A4,
  NOTE_AS4, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_D4,
  NOTE_D5, 
  REST, NOTE_AS4,  
  
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_AS4,
  NOTE_G4
};

int durations[] = {
  2, 4,
  4, 8, 4,
  2, 4,
  2, 
  2,
  4, 8, 4,
  2, 4,
  1, 
  4,
  
  4, 8, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1,
  4,
   
  2, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1, 
  4, 4,  
  
  2, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1
};
int melody2[] = {
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4,
  
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4,  REST, NOTE_A4,
  
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
  NOTE_G4,
  NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
  NOTE_G4,
  
  NOTE_C5,
  NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4,
  
  REST, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 
  NOTE_D4,
  REST, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 
  NOTE_D4,
  
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
  NOTE_G4,
  NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
  NOTE_G4,
  
  NOTE_C5,
  NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4,
  
  REST, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 
  NOTE_D4,
  REST, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 
  NOTE_D4,
  
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4, 
  
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
  NOTE_G4,
  NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
  NOTE_G4,
  
  NOTE_C5,
  NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4,
  
  REST, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 
  NOTE_D4,
  REST, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 
  NOTE_D4,
  
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4
};
int durations2[] = {
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 8, 4, 8, 4,
  1,
  
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 8, 4, 8, 4,
  2, 8, 16,
  
  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 16, 8, 16, 8, 16,
  
  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 16, 8, 16, 8, 16,
  
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 4, 4, 4,
  1,
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 4, 4, 4,
  1,
  
  1,
  4, 8, 8, 2,
  4, 8, 4, 8, 4,
  1,
  
  4, 8, 8, 8, 8, 8, 8, 
  1,
  4, 8, 8, 8, 8, 8, 8, 
  1,
  
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 4, 4, 4,
  1,
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 4, 4, 4,
  1,
  
  1,
  4, 8, 8, 2,
  4, 8, 4, 8, 4,
  1,
  
  4, 8, 8, 8, 8, 8, 8, 
  1,
  4, 8, 8, 8, 8, 8, 8, 
  1,
  
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 8, 4, 8, 4,
  1, 
  
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 4, 4, 4,
  1,
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 4, 4, 4,
  1,
  
  1,
  4, 8, 8, 2,
  4, 8, 4, 8, 4,
  1,
  
  4, 8, 8, 8, 8, 8, 8, 
  1,
  4, 8, 8, 8, 8, 8, 8, 
  1,
  
  4, 4, 8, 4, 8,
  4, 4, 8, 4, 8,
  4, 8, 4, 8, 4,
  1
};

//Simpson
int melody3[] = {
  NOTE_C4, NOTE_E4, NOTE_FS4, REST, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A3,
  NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, REST,
  NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, NOTE_AS3,
  NOTE_B3, REST
};

int durations3[] = {
  2, 4, 4, 32, 8,
  2, 4, 4, 8,
  8, 8, 8, 4, 2,
  8, 8, 8, 4, 2,
  2, 2
};

//NeverGonnaGiveYouUp
int melody4[] = {
  NOTE_A4, REST, NOTE_B4, REST, NOTE_C5, REST, NOTE_A4, REST,
  NOTE_D5, REST, NOTE_E5, REST, NOTE_D5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E5, NOTE_E5, REST,
  NOTE_D5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_D5, REST,
  NOTE_C5, REST, NOTE_B4, NOTE_A4, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5, REST,
  NOTE_B4, NOTE_A4, NOTE_G4, REST, NOTE_G4, REST, NOTE_D5, REST, NOTE_C5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E5, NOTE_E5, REST,
  NOTE_D5, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G5, NOTE_B4, REST,
  NOTE_C5, REST, NOTE_B4, NOTE_A4, REST,

  NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5, REST,
  NOTE_B4, NOTE_A4, NOTE_G4, REST, NOTE_G4, REST, NOTE_D5, REST, NOTE_C5, REST,

  NOTE_C5, REST, NOTE_D5, REST, NOTE_G4, REST, NOTE_D5, REST, NOTE_E5, REST,
  NOTE_G5, NOTE_F5, NOTE_E5, REST,

  NOTE_C5, REST, NOTE_D5, REST, NOTE_G4, REST
};

int durations4[] = {
  8, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 2, 2,

  8, 8, 8, 8, 2, 8, 8,
  2, 8,

  8, 8, 8, 8, 2, 8, 8,
  4, 8, 8, 8, 8,

  8, 8, 8, 8, 2, 8, 8,
  2, 8, 4, 8, 8, 8, 8, 8, 1, 4,

  8, 8, 8, 8, 2, 8, 8,
  2, 8,

  8, 8, 8, 8, 2, 8, 8,
  2, 8, 8, 8, 8,

  8, 8, 8, 8, 2, 8, 8,
  4, 8, 3, 8, 8, 8, 8, 8, 1, 4,

  2, 6, 2, 6, 4, 4, 2, 6, 2, 3,
  8, 8, 8, 8,

  2, 6, 2, 6, 2, 1
};
//Enemy imagineDragons
int melody5[] = {
  NOTE_B4, REST,
  NOTE_FS4, NOTE_FS4, NOTE_B4, NOTE_FS4, NOTE_E4, REST, NOTE_B3,

  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3, NOTE_AS3, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3, NOTE_B3,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3, NOTE_AS3, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3,

  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_FS4, NOTE_E4, NOTE_B4,
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_FS4, NOTE_AS4,

  REST, NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_B3,
  NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_B4,
  REST, NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_B3,
  NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_B4, REST, NOTE_B3, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_FS3, NOTE_E3, NOTE_FS3, NOTE_FS4, NOTE_B4, NOTE_FS4, NOTE_E4,
  
  REST
};

int durations5[] = {
  4, 2,
  4, 8, 4, 8, 4, 2, 8,

  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2, 8,
  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2, 8,
  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2, 8,
  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2,

  2, 2, 2, 4, 1, 1, 8,
  2, 2, 2, 4, 1, 1,

  2, 2, 8, 8, 8, 2,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2,
  2, 2, 8, 8, 8, 2,
  8, 8, 8, 8, 8, 8, 2, 2, 8, 8, 8,
  2, 2, 2, 8, 4, 4, 8, 4, 8, 2,

  1
};


void playMarchaImperial() {

    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);
    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);
    tone(ZumbadorPin, a, 1000);
    delay(1000 + 50);
    tone(ZumbadorPin, eH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, eH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, eH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, fH, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);
    tone(ZumbadorPin, gS, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);
    tone(ZumbadorPin, a, 1000);
    delay(1000 + 50);
    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 350);
    delay(350 + 50);
    tone(ZumbadorPin, a, 150);
    delay(150 + 50);
    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, gSH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, gH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, fSH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fSH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, aS, 250);
    delay(250 + 50);
    tone(ZumbadorPin, dSH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, dH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, cSH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, b, 125);
    delay(125 + 50);
    tone(ZumbadorPin, cH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, f, 125);
    delay(125 + 50);
    tone(ZumbadorPin, gS, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 375);
    delay(375 + 50);
    tone(ZumbadorPin, a, 125);
    delay(125 + 50);
    tone(ZumbadorPin, cH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 375);
    delay(375 + 50);
    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, eH, 1000);
    delay(1000 + 50);
    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 350);
    delay(350 + 50);
    tone(ZumbadorPin, a, 150);
    delay(150 + 50);
    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, gSH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, gH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, fSH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fSH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, aS, 250);
    delay(250 + 50);
    tone(ZumbadorPin, dSH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, dH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, cSH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, b, 125);
    delay(125 + 50);
    tone(ZumbadorPin, cH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, f, 250);
    delay(250 + 50);
    tone(ZumbadorPin, gS, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 375);
    delay(375 + 50);
    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 375);
    delay(375 + 50);
    tone(ZumbadorPin, c, 125);
    delay(125 + 50);
    tone(ZumbadorPin, a, 1000);
    delay(1000 + 50);
    delay(2000);  // dos segundos para volver a empezar.
    
    stopMusic();
}
void stopMusic() {
    noTone(ZumbadorPin); // Detiene cualquier tono que se esté reproduciendo en ZumbadorPin.
}

void playHarryPotter() {
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) 
  {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(ZumbadorPin, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(ZumbadorPin);
  }
}
void playLionSleepTonight()
{
  int size = sizeof(durations2) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations2[note];
    tone(ZumbadorPin, melody2[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(ZumbadorPin);
  }
}

void playSimpsons()
{
  int size = sizeof(durations3) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations3[note];
    tone(ZumbadorPin, melody3[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(ZumbadorPin);
  }
}

void playNeverGive()
{
  int size = sizeof(durations4) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations4[note];
    tone(ZumbadorPin, melody4[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(ZumbadorPin);
  }
}

void playEnemy(){
   int size = sizeof(durations5) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations5[note];
    tone(ZumbadorPin, melody5[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(ZumbadorPin);
  }
}