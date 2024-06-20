const int led1 = 3;
int potValue = 0;

unsigned long time = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(led1,OUTPUT);
}

long newTime(int pot){
long time = (0.27077)*(pot) + 100;
return time;
}

void intervaluePot(long time)
{
digitalWrite(led1, HIGH);
delay(time);
digitalWrite(led1, LOW);
delay(time);
}
void loop() {
  // put your main code here, to run repeatedly:
potValue = analogRead(A0);
intervaluePot(newTime(potValue));
}
