#include <virtuabotixRTC.h>

#define clk 5
#define dat 4
#define rst 2
const int pinoRele = 10;
const int pinoSensor = A0;
const int tempoRega = 180; //3 minutos em segundos
const int tempoEspera = 1800; //30 minutos em segundos
const int tempoDesliga = 600; //10 minutos em segundos

virtuabotix myRTC(clk, dat, rst);

void setup() {
  pinMode(pinoRele, OUTPUT);
  pinMode(pinoSensor, INPUT);
  Serial.begin(9600);
  //myRTC.setDS1302Time(0, 58, 11, 2, 13, 5, 2024);
}

void loop() {
  myRTC.updateTime();
  int solo = analogRead(pinoSensor);
  //Serial.println(solo);

  if ((myRTC.hours >= 7 && myRTC.hours <= 10) || (myRTC.hours >= 20 && myRTC.hours <= 23)) {
    if (solo >= 650) {
      digitalWrite(pinoRele, HIGH);
      delay(1000*tempoRega);
      digitalWrite(pinoRele, LOW);
      delay(1000*tempoEspera);
    }
    else {
      digitalWrite(pinoRele, LOW);
      delay(1000*tempoDesliga);
    }
  }
  else {
    digitalWrite(pinoRele, LOW);
  }
}
