#include <Ultrasonic.h>

#include "Adafruit_TCS34725.h"
/*
Códigos ultrassonico:
Ultrasonic ultrasonic(2, 13); // inicializa o sensor nesses pinos
float cm, in; // define variaveis em cm e polegadas
long microsec = ultrasonic.timing(); // le as informacoes do sensor, em cm e pol
cm = ultrasonic.convert(microsec, Ultrasonic::CM); // le as informacoes do sensor em cm
in = ultrasonic.convert(microsec, Ultrasonic::IN); // le as informacoes do sensor em pol
*/

#include <AFMotor.h>
/*
Códigos motor:
AF_DCMotor motor(3); = inicializa o motor
motor.setSpeed(200); = seta a velocidade
motor.run(RELEASE); = para o motor
motor.run(FORWARD); = liga o motor
motor.run(BACKWARD); = muda direção do motor
*/

#define pino_trigger 2
#define pino_echo 13
Ultrasonic ultrasonic(pino_trigger, pino_echo);
Adafruit_TCS34725 sensTCS = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_300MS, TCS34725_GAIN_1X);

AF_DCMotor motor1(4); //direita
AF_DCMotor motor2(1); //esquerda

void setup() {
  Serial.begin(9600);

  //Motores
  motor1.run(FORWARD);
  motor2.run(FORWARD);

  //Sensor de cor
  if (sensTCS.begin()) {
    Serial.println("Sensor conectado");
  } else { //Se o sensor não conectou , mostra a mensagem de erro
    Serial.println("Sensor com problema");
  }
}

void loop() {
  float cm; // define variaveis em cm e polegadas
  long microsec = ultrasonic.timing(); // le as informacoes do sensor, em cm e pol
  cm = ultrasonic.convert(microsec, Ultrasonic::CM); // le as informacoes do sensor em cm
  Serial.println(cm);

  uint16_t r, g, b, c, TempCor, LUX;

  //O sensor lê os valores do Vermelho (R), Verde(G), Azul(B)
  sensTCS.getRawData(&r, &g, &b, &c);
 
  //Calcula a temperatura da cor
  TempCor = sensTCS.calculateColorTemperature(r, g, b);

  //Calcula a luminosidade
  LUX = sensTCS.calculateLux(r, g, b);

  Serial.print("Vermelho(R): ");
  Serial.print(r); //escreve no monitor serial o valor do Vermelho

  Serial.print("   Verde(G): ");
  Serial.print(g);//escreve no monitor serial o valor do Verde

  Serial.print("   Azul(B): ");
  Serial.print(b);//escreve no monitor serial o valor do Azul

  Serial.print("   Temperatura: ");
  Serial.print(TempCor); //escreve no monitor serial o valor da Temperatura da Cor

  Serial.print("   Intensidade: ");
  Serial.println(LUX); //escreve no monitor serial o valor da intensidade luminosa

  if (c < 5000) {
    if(LUX <= 85) {
      if (cm >= 8) {
        motor1.setSpeed(200);
        motor2.setSpeed(200);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
      }
      else {
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        delay(1000);
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor1.setSpeed(100);
        motor1.run(FORWARD);
        motor1.run(RELEASE);
        delay(1000);
        motor2.setSpeed(100);
        motor2.run(FORWARD);
        delay(1000);
      }
    }
    else {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
  }
}
