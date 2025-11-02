#include <Arduino.h>

// Cria a Serial3 explicitamente associando à USART3 real
HardwareSerial Serial3(USART3);  // Usa a instância da USART3 de verdade

#include "stm32f1xx_hal.h"
#include "head.h"
#include "saidas.h"

//HardwareSerial Serial3(PB10, PB11);  // USART3: TX, RX

#define RE_DE PA8
#define LED PC13

#define DO1 PA3
#define DO2 PA2
#define DO3 PA1
#define DO4 PA0



long tempo;
int estado = 0;
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

  //mySerial.begin(9600);
  Serial.begin(9600, SERIAL_8N1);
  Serial3.begin(9600, SERIAL_8N1);

  pinMode(LED, OUTPUT);

  pinMode(DO1, OUTPUT);
  pinMode(DO2, OUTPUT);
  pinMode(DO3, OUTPUT);
  pinMode(DO4, OUTPUT);

  pinMode(RE_DE, OUTPUT);

  // mySerial.begin(9600);  // pode mudar a taxa conforme seu RS485
  init_pwm_500hz();
}

void loop() {

  digitalWrite(RE_DE, LOW);

  //HAL_Delay(1);

  receber();

  if (HAL_GetTick() - tempo > 0) {
    tempo = HAL_GetTick();

    estado = !estado;
    // mostrar_dados();

    D_OUT1 = valorA;
    D_OUT2 = valorB;
    D_OUT3 = valorC;
    D_OUT4 = valorD;

    Corrente1 = valorE + 0.04;
    Corrente2 = valorF + 0.04;
    Corrente3 = valorG + 0.04;


    //Corrente1 = round(valorE * 10) / 10.0;
    //Corrente2 = round(valorF * 10) / 10.0;
    //Corrente3 = round(valorG * 10) / 10.0;
  }



  //if (Corrente1 > 20.0) {
    //Corrente1 = 20.0;
  //}

  //if (Corrente2 > 20.0) {

    //Corrente2 = 20.0;
  //}

  //if (Corrente3 > 20.0) {
    //Corrente3 = 20.0;
  //}

  if (Corrente1 < 0.0) {
    Corrente1 = 0.0;
  }

  if (Corrente2 < 0.0) {

    Corrente2 = 0.0;
  }

  if (Corrente3 < 0.0) {
    Corrente3 = 0.0;
  }

  mostrar_dados();

  digitalWrite(DO1, D_OUT1);
  digitalWrite(DO2, D_OUT2);
  digitalWrite(DO3, D_OUT3);
  digitalWrite(DO4, D_OUT4);



  // int pwm = 1900;

  //TIM3->CCR1 = pwm;  // AO1
  // TIM3->CCR2 = pwm;  // AO2
  // TIM3->CCR3 = pwm;  // AO3

  //float corrente = 19.0 + 0.08;

  TIM3->CCR1 = currentToPWM_CH1(Corrente1);  // AO1
  TIM3->CCR2 = currentToPWM_CH2(Corrente2);  // AO2
  TIM3->CCR3 = currentToPWM_CH3(Corrente3);  // AO3
}
