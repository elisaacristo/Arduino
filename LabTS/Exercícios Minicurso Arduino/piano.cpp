#define notaC 262
#define notaD 294
#define notaE 330
#define notaF 349
#define notaG 392
#define notaA 440
#define notaB 493

int buzzer = 11;

int botaoC = 10;
int botaoD = 9;
int botaoE = 8;
int botaoF = 7;
int botaoG = 6;
int botaoA = 5;
int botaoB = 4;

void setup()
{
  pinMode(botaoC, INPUT);
  digitalWrite(botaoC, HIGH);
  pinMode(botaoD, INPUT);
  digitalWrite(botaoD, HIGH);
  pinMode(botaoE, INPUT);
  digitalWrite(botaoE, HIGH);
  pinMode(botaoF, INPUT);
  digitalWrite(botaoF, HIGH);
  pinMode(botaoG, INPUT);
  digitalWrite(botaoG, HIGH);
  pinMode(botaoA, INPUT);
  digitalWrite(botaoA, HIGH);
  pinMode(botaoB, INPUT);
  digitalWrite(botaoB, HIGH);
}

void loop()
{
  while(digitalRead(botaoC) == LOW) {
    tone(buzzer,notaC, 20000);
  }
  
  while(digitalRead(botaoD) == LOW) {
    tone(buzzer,notaD);
  }

  while(digitalRead(botaoE) == LOW) {
    tone(buzzer,notaE);
  }

  while(digitalRead(botaoF) == LOW) {
    tone(buzzer,notaF);
  }

  while(digitalRead(botaoG) == LOW) {
    tone(buzzer,notaG);
  }

  while(digitalRead(botaoA) == LOW) {
    tone(buzzer,notaA);
  }

  while(digitalRead(botaoB) == LOW) {
    tone(buzzer,notaB);
  }
  
  noTone(buzzer);                       
}
