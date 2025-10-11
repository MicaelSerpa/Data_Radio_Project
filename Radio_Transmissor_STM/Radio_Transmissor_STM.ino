#include "head.h"

long tempo_troca;
int estado_led = 0;
float incremento_corrente = 4.0;


String Pacote = "";

void setup() {

  Serial1.begin(9600, SERIAL_8N1);

  Serial3.begin(9600, SERIAL_8N1);

  Serial1.println("iniciando....");

  pinMode(DO1, INPUT);
  pinMode(DO2, INPUT);
  pinMode(DO3, INPUT);
  pinMode(DO4, INPUT);

  pinMode(AO1, INPUT);
  pinMode(AO2, INPUT);
  pinMode(AO3, INPUT);

  pinMode(RE_DE, OUTPUT);

  pinMode(LED, OUTPUT);
}

void loop() {


  digitalWrite(RE_DE, HIGH);  // High para enviar

  // di1 = analogRead(DO1);
  //di2 = analogRead(DO2);
  // di3 = analogRead(DO3);
  // di4 = analogRead(DO4);

  // DI1 = lerDigitais(di1);
  // DI2 = lerDigitais(di2);
  // DI3 = lerDigitais(di3);
  // DI4 = lerDigitais(di4);

  if (millis() - tempo_troca > 1500) {

    tempo_troca = millis();

    estado_led = !estado_led;

    incremento_corrente = incremento_corrente + 4.0;
  }

  if (incremento_corrente >= 20.0) {

    incremento_corrente = 4.0;
  }

  DI1 = !estado_led;
  DI2 = estado_led;
  DI3 = !estado_led;
  DI4 = estado_led;

  // AI1 = incremento_corrente;
  // AI2 = incremento_corrente;
  // AI3 = incremento_corrente;




  ai1 = analogRead(AO1);
  ai2 = analogRead(AO2);
  ai3 = analogRead(AO3);

  AI1 = lerCorrente(ai1, 156.67);
  AI2 = lerCorrente(ai2, 156.67);
  AI3 = lerCorrente(ai3, 156.67);


  digitalWrite(LED, estado_led);

  Pacote = String(DI1) + ";" + String(DI2) + ";" + String(DI3) + ";" + String(DI4) + ";" + String(AI1, 3) + ";" + String(AI2, 3) + ";" + String(AI3, 3) + ";" + "0.0" + ";@";

  Serial3.println(Pacote);
  Serial1.println(Pacote);
}
