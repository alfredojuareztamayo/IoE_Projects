
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;
const int led5 = 7;
const int led6 = 8;
const int led7 = 9;
const int led8 = 10;
int potValue = 0;

unsigned long time = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
pinMode(led8,OUTPUT);

}

void turnOffOnLeds(int led1_state,int led2_state,int led3_state,int led4_state,int led5_state,int led6_state,int led7_state,int led8_state){
digitalWrite(led1,led1_state);
digitalWrite(led2,led2_state);
digitalWrite(led3,led3_state);
digitalWrite(led4,led4_state);
digitalWrite(led5,led5_state);
digitalWrite(led6,led6_state);
digitalWrite(led7,led7_state);
digitalWrite(led8,led8_state);
}
void intervaluePotLeds(int potent)
{
(potent <= 0)?turnOffOnLeds(LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW):
((potent > 0 && potent <= 128)?turnOffOnLeds(HIGH,LOW,LOW,LOW,LOW,LOW,LOW,LOW):
((potent > 128 && potent <= 128*2)?turnOffOnLeds(HIGH,HIGH,LOW,LOW,LOW,LOW,LOW,LOW):
((potent > 128*2 && potent <= 128*3)?turnOffOnLeds(HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW,LOW):
((potent > 128*3 && potent <= 128*4)?turnOffOnLeds(HIGH,HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW):
((potent > 128*4 && potent <= 128*5)?turnOffOnLeds(HIGH,HIGH,HIGH,HIGH,HIGH,LOW,LOW,LOW):
((potent > 128*5 && potent <= 128*6)?turnOffOnLeds(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW,LOW):
((potent > 128*6 && potent <= 128*7)?turnOffOnLeds(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW):
turnOffOnLeds(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH))))))));
}
void loop() {
  // put your main code here, to run repeatedly:
potValue = analogRead(A0);
//Serial.println(potValue);
intervaluePotLeds(potValue);
}
