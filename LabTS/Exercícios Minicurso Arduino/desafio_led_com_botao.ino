void setup() {
  
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
}

void loop() {
  
 int botao = digitalRead(9);
 
  if (botao == LOW) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  delay(10);
}
