#include "head.h"

int D_OUT1, D_OUT2, D_OUT3, D_OUT4;
float Corrente1, Corrente2, Corrente3;


bool DI1;
bool DI2;
bool DI3;
bool DI4;

int AI1;
int AI2;
int AI3;

long tempo_loop;

int estado_led = 0;

void setup() {

  Serial1.begin(9600, SERIAL_8N1);
  Serial3.begin(9600, SERIAL_8N1);

  // SerialRS485.begin(9600);  // Serial por software (pode ajustar)

  Serial1.println("iniciando....");

  pinMode(LED, OUTPUT);
  pinMode(RE_DE, OUTPUT);

  pinMode(DO1, OUTPUT);
  pinMode(DO2, OUTPUT);
  pinMode(DO3, OUTPUT);
  pinMode(DO4, OUTPUT);

  pinMode(AO1, OUTPUT);  // PA0 - TIM2_CH1
  pinMode(AO2, OUTPUT);  // PA1 - TIM2_CH2
  pinMode(AO3, OUTPUT);  // PA2 - TIM2_CH3

  digitalWrite(RE_DE, LOW);
  digitalWrite(LED, HIGH);

  Serial.println("travando no loop");
}


void loop() {

  //Serial.println("travando no loop");
  digitalWrite(RE_DE, LOW);  // LOW PARA RECEBER E HIGH PARA ENVIAR

  if (millis() - tempo_loop > 2000) {

    tempo_loop = millis();
    estado_led = !estado_led;
    digitalWrite(LED, estado_led);
  }

  receber();


  //  mostrar_dados();


  D_OUT1 = valorA;
  D_OUT2 = valorB;
  D_OUT3 = valorC;
  D_OUT4 = valorD;

  digitalWrite(DO1, D_OUT1);
  digitalWrite(DO2, D_OUT2);
  digitalWrite(DO3, D_OUT3);
  digitalWrite(DO4, D_OUT4);

  //valorE
  //valorF
  //valorG

  float corrente_desejada = 4.0;


  Corrente1 = valorE;
  Corrente2 = valorF;
  Corrente3 = valorG;

  int AI1 = (int)(((Corrente1 - 4.0) * 204.0 / 16.0) + 46.0);
  int AI2 = (int)(((Corrente2 - 4.0) * 204.0 / 16.0) + 46.0);
  int AI3 = (int)(((Corrente3 - 4.0) * 204.0 / 16.0) + 46.0);

  AI1 = constrain(AI1, 46, 250);
  AI2 = constrain(AI2, 46, 247);
  AI3 = constrain(AI3, 46, 248);

  analogWrite(AO1, 40);
  analogWrite(AO2, 40);
  analogWrite(AO3, 40);
}
