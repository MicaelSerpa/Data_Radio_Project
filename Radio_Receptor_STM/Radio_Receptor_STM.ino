#include "head.h"
#include <Filters.h>  //Filtro para remover as variações do sinal analógico

FilterOnePole filtro_AO1(LOWPASS, 0.2);
FilterOnePole filtro_AO2(LOWPASS, 0.2);
FilterOnePole filtro_AO3(LOWPASS, 0.2);





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


  // mostrar_dados();

  digitalWrite(DO1, valorA);
  digitalWrite(DO2, valorB);
  digitalWrite(DO3, valorC);
  digitalWrite(DO4, valorD);

  //valorE
  //valorF
  //valorG

  float corrente_desejada = 20.0;

  int AI1 = (int)(((valorE - 4.0) * 204.0 / 16.0) + 46.0);
  int AI2 = (int)(((valorF - 4.0) * 204.0 / 16.0) + 46.0);
  int AI3 = (int)(((valorG - 4.0) * 204.0 / 16.0) + 46.0);

  AI1 = constrain(AI1, 46, 250);
  AI2 = constrain(AI2, 46, 247);
  AI3 = constrain(AI3, 46, 248);

  analogWrite(AO1, AI1);
  analogWrite(AO2, AI2);
  analogWrite(AO3, AI3);
}
