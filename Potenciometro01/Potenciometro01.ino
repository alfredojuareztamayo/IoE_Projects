const int led1 = 3;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(A0);
  Serial.println(potValue);
  delay(100);

  (potValue >= 0 && potValue <= 256) ? digitalWrite(led1, HIGH) : 
  ((potValue > 256 && potValue <= 512) ? digitalWrite(led1, LOW) : 
  (digitalWrite(led1, HIGH), delay(100), digitalWrite(led1, LOW), delay(100)));
}
