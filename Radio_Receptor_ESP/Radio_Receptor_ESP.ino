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


int tensao = 0.0;
float corrente = 4.0;
int tempo_incremento;


void setup() {

  Serial.begin(9600);

  //Ebyte
  SerialEbyte.begin(9600, SERIAL_8N1, EBYTE_RX, EBYTE_TX);
  pinMode(EBYTE_M0, OUTPUT);
  pinMode(EBYTE_M1, OUTPUT);

  //RS485
  SerialRS485.begin(9600, SERIAL_8N1, RS485_RX, RS485_TX);
  pinMode(RS485_RE_DE, OUTPUT);

  Serial1.println("iniciando....");
}

void loop() {

  digitalWrite(EBYTE_M0, LOW);
  digitalWrite(EBYTE_M1, LOW);
  receber();

  digitalWrite(RS485_RE_DE, HIGH);  // LOW PARA RECEBER E HIGH PARA ENVIAR

  //if (millis() - tempo_incremento > 2500) {

  // tempo_incremento = millis();

  // tensao = !tensao;
  //   corrente = corrente + 4.0;
  // }
  //if (corrente > 20.0) {

  //  corrente = 4.0;
  ///}


  ///Serial.println(String(1) + ";" + String(0) + ";" + String(1) + ";" + String(0) + ";" + "4.0" + ";" + "8.4" + ";" + "16.5" + ";" + "0.0" + ";" + "0.0" + ";@");

  //SerialRS485.println(String(1) + ";" + String(0) + ";" + String(1) + ";" + String(0) + ";" + "4.0" + ";" + "8.4" + ";" + "16.5" + ";" + "0.0" + ";" + "0.0" + ";@");
  // Serial.println(String(tensao) + ";" + String(tensao) + ";" + String(tensao) + ";" + String(tensao) + ";" + String(corrente) + ";" + String(corrente) + ";" + String(corrente) + ";@");
  // SerialRS485.println(String(tensao) + ";" + String(tensao) + ";" + String(tensao) + ";" + String(tensao) + ";" + String(corrente) + ";" + String(corrente) + ";" + String(corrente) + ";@");

  Serial.println(valor1 + ";" + valor2 + ";" + valor3 + ";" + valor4 + ";" + valor5 + ";" + valor6 + ";" + valor7 + ";" + valor8 +  ";@");
  SerialRS485.println(valor1 + ";" + valor2 + ";" + valor3 + ";" + valor4 + ";" + valor5 + ";" + valor6 + ";" + valor7 + ";" + valor8 +  ";@");
}
