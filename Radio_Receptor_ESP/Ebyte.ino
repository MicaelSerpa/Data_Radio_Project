long Tempo_Ultima_Comunicacao = 0;
int Flag_Serial = 0;

void receber() {

  if (millis() - Tempo_Ultima_Comunicacao > 3000) {

    Flag_Serial = 0;
    Serial.println("Sem sinal");

    valorA = 0;
    valorB = 0;
    valorC = 0;
    valorD = 0;
    valorE = 0.0;
    valorF = 0.0;
    valorG = 0.0;
    valorH = 0.0;
    valorI = 0.0;
    valorJ = 0.0;


    valor1 = "0";
    valor2 = "0";
    valor3 = "0";
    valor4 = "0";
    valor5 = "0.0";
    valor6 = "0.0";
    valor7 = "0.0";
    valor8 = "0.0";
    valor9 = "0.0";
    valor10 = "0.0";
  }


  while (SerialEbyte.available()) {

    Tempo_Ultima_Comunicacao = millis();
    Flag_Serial = 1;

    char c = SerialEbyte.read();
    switch (c) {
      case '@':         //caso receba @ na serial, entende que é o fim dos dados e então trata eles
        mensagem = "";  // resseta a variável para receber os novos dados
        if (size == 0) {
          return;
        }
        buffer[size] = 0;
        size = 0;
        for (int i = 0; i < BUFFER_SIZE; i++) {  //este for é para armazenar os bytes que estavam no buffer, na string com todas as informações recebidas
          mensagem += buffer[i];
        }
        controleRecebido = 6;  // reset da variável de controle da comunicação. Valor da variável define o tempo para até avisar de perda de comunicação
        break;                 // para calcular o valor basta dividir o tempo que deseja, pelos milissegundos definido no primeiro IF do loop
      default:
        if (size < BUFFER_SIZE - 1) {  //enquanto não encontra o marcador(@) de fim de dados, continua armazenando os bytes no buffer
          buffer[size] = c;
          ++size;
        }
    }
  }

  mensagem = mensagem + ';';

  // Serial1.println(mensagem);


  for (i = 0; i < mensagem.length(); i++) {

    if (mensagem[i] == ';') {
      separador = i;

      if (cont_dado == 1) {

        valor1 = mensagem.substring(separador_ant + 1, separador);
        valorA = valor1.toInt();
      }

      if (cont_dado == 2) {

        valor2 = mensagem.substring(separador_ant + 1, separador);
        valorB = valor2.toInt();
      }

      if (cont_dado == 3) {

        valor3 = mensagem.substring(separador_ant + 1, separador);
        valorC = valor3.toInt();
      }

      if (cont_dado == 4) {

        valor4 = mensagem.substring(separador_ant + 1, separador);
        valorD = valor4.toInt();
      }

      if (cont_dado == 5) {

        valor5 = mensagem.substring(separador_ant + 1, separador);
        valorE = valor5.toFloat();
      }

      if (cont_dado == 6) {

        valor6 = mensagem.substring(separador_ant + 1, separador);
        valorF = valor6.toFloat();
      }

      if (cont_dado == 7) {

        valor7 = mensagem.substring(separador_ant + 1, separador);
        valorG = valor7.toFloat();
      }
      if (cont_dado == 8) {

        valor8 = mensagem.substring(separador_ant + 1, separador);
        valorH = valor8.toFloat();
      }
      if (cont_dado == 9) {

        valor9 = mensagem.substring(separador_ant + 1, separador);
        valorI = valor9.toFloat();
      }

      if (cont_dado == 10) {

        valor10 = mensagem.substring(separador_ant + 1, separador);
        valorJ = valor10.toFloat();
      }



      separador_ant = separador;
      cont_dado++;
    }
  }

  cont_dado = 1;
  separador_ant = -1;
}
