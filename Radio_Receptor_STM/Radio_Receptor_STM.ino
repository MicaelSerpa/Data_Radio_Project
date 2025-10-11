#include "head.h"
#include <Filters.h>  //Filtro para remover as variações do sinal analógico

FilterOnePole filtro_AO1(LOWPASS, 0.2);
FilterOnePole filtro_AO2(LOWPASS, 0.2);
FilterOnePole filtro_AO3(LOWPASS, 0.2);



int PWM_ = 69;  //4.05 mA
//int PWM_ = 115; //8,03 mA
//int PWM_ = 157; //12.03 mA
//int PWM_ = 198;  //16.04 mA
//int PWM_ = 247;  //20.02 mA

//1535 GERA 12,89

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

  digitalWrite(DO1, !valorA);
  digitalWrite(DO2, valorB);
  digitalWrite(DO3, valorC);
  digitalWrite(DO4, valorD);



  int AI1 = (int)(((valorE - 4.0) * (247.0 - 69.0) / (20.0 - 4.0) + 69.0) * 1);
  int AI2 = (int)(((valorF - 4.0) * (247.0 - 69.0) / (20.0 - 4.0) + 69.0) * 1);
  int AI3 = (int)(((valorG - 4.0) * (247.0 - 69.0) / (20.0 - 4.0) + 69.0) * 1);

  analogWrite(AO1, AI1);
  analogWrite(AO2, AI2);
  analogWrite(AO3, AI3);
}
