const int led1 = 3;
const int button = 6;
bool status_button;

void setup() {
  /*
  Inicializar variables
  Inicializar protocolos 
  Codigos que solamente nos interesa que se ejecute 1 vez
  */
  // put your setup code here, to run once:

  Serial.begin(9600);  //La trasmisión de informacion es a 2 hilos  GND

  pinMode(led1, OUTPUT);


  pinMode(button, INPUT);

  digitalWrite(led1, LOW);
}

void loop() {
  status_button = digitalRead(button);

  // Verificar si el botón ha sido presionado
  if (status_button == HIGH) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}
