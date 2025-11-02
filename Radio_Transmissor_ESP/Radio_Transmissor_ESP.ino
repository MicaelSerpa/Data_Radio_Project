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

unsigned long tempo_envio = 0;
unsigned long tempo_ack = 0;
bool aguardandoOK = false;

void loop() {
  digitalWrite(EBYTE_M0, LOW);
  digitalWrite(EBYTE_M1, LOW);
  digitalWrite(RS485_RE_DE, LOW);  // LOW = receber, HIGH = enviar
  receber_RS485();

  
  if ((millis() - tempo_envio > 100) && !aguardandoOK) {
    tempo_envio = millis();

    String pacote = valor1 + ";" + valor2 + ";" + valor3 + ";" + valor4 + ";" + valor5 + ";" + valor6 + ";" + valor7 + ";" + valor8 + ";@";

    Serial.println(pacote);
    SerialEbyte.println(pacote);

    aguardandoOK = true;   
    tempo_ack = millis(); 
  }

  
  if (aguardandoOK && SerialEbyte.available()) {
    String resposta = SerialEbyte.readStringUntil('\n');
    resposta.trim();

    if (resposta == "OK") {
      Serial.println("Confirmação recebida!");
      aguardandoOK = false;
    }
  }

  if (aguardandoOK && (millis() - tempo_ack > 900)) {
    Serial.println("Sem resposta, reenviando...");
    aguardandoOK = false; 
  }
}
