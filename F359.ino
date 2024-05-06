int state;

void setup() {
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  state = 0;
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
}

void loop() {
  int leitura = analogRead(A0);
  Serial.print(leitura);
  if (leitura >= 1020) {
    Serial.println(" Obstaculo");
    state = 1;
  }
  else {
    Serial.println(" Livre");
    state = 0;
  }
  
  if (state == 1) { // Ligado
    digitalWrite(2, state);
    digitalWrite(4, !state);
    delay(50);
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    delay(1000);
  }

}
