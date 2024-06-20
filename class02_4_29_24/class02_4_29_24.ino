const int led1 = 3;
const int led2 = 4;
bool flag1 = 0;
bool flag2 = 0;


unsigned long tiempo = 0;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiempo = millis();
  //delay(1000);
  //Serial.println(tiempo);
  if (tiempo % 500 == 0) {
    flag1 = !flag1;
    digitalWrite(led1, flag1);
    Serial.println(tiempo);
  }

  if (tiempo % 300 == 0) {
    flag2 = !flag2;
    digitalWrite(led2, flag2);
    Serial.println(tiempo);
  }
}
