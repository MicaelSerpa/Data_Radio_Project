#include "head.h"



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


  Serial.println("iniciando....");
}

void loop() {

  //Serial.println(millis());
  digitalWrite(EBYTE_M0, LOW);
  digitalWrite(EBYTE_M1, LOW);

  digitalWrite(RS485_RE_DE, LOW);  // LOW PARA RECEBER E HIGH PARA ENVIAR
  receber_RS485();


  if (millis() - tempo_loop > 1500) {
    tempo_loop = millis();
    Serial.println(valor1 + ";" + valor2 + ";" + valor3 + ";" + valor4 + ";" + valor5 + ";" + valor6 + ";" + valor7 + ";" + valor8 + ";@");
    SerialEbyte.println(valor1 + ";" + valor2 + ";" + valor3 + ";" + valor4 + ";" + valor5 + ";" + valor6 + ";" + valor7 + ";" + valor8 + ";@");
  }
}
