const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int button = 6;
int time = 500;

int iterador = 0;

bool status_button;
bool last_button_state = LOW;
bool button_just_pressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void Sequence(int led1_state, int led2_state, int led3_state) {
  digitalWrite(led1, led1_state);
  digitalWrite(led2, led2_state);
  digitalWrite(led3, led3_state);
  delay(time);
}

void startSequence(int ite) {
  switch (ite) {
    case 1:
      Sequence(HIGH, LOW, LOW);
      Sequence(LOW, HIGH, LOW);
      Sequence(LOW, LOW, HIGH);
      break;
    case 2:
      Sequence(HIGH, LOW, LOW);
      Sequence(HIGH, HIGH, LOW);
      Sequence(HIGH, HIGH, HIGH);
      break;
    case 3:
      Sequence(LOW, LOW, LOW);
      Sequence(LOW, HIGH, LOW);
      Sequence(HIGH, LOW, HIGH);
      break;
    default:
      break;
  }
}

void loop() {
  status_button = digitalRead(button);

  if (status_button == HIGH && last_button_state == LOW) {
    button_just_pressed = true;
  }

  last_button_state = status_button;

  if (button_just_pressed) {
    iterador++;
    if (iterador > 3) {
      iterador = 1;
    }
    button_just_pressed = false;
  }

  startSequence(iterador);
}
