int lerDigitais(int entrada) {
  int saida;

  if (entrada >= 2000) {

    saida = 1;

  }

  else {
    saida = 0;
  }

  return saida;
}

float lerCorrente(float entrada, float r_shunt) {

  float saida;

  saida = 3.3 / 4095.0 * entrada;  //adc para tensao

  saida = (saida / r_shunt) * 1000.0;  //x 1000 para converter em mA.

  return saida;
}

float lerCorrenteCalibrada(float entrada_adc, float r_shunt, float ganho, float offset) {
  float tensao = 3.3 / 4095.0 * entrada_adc;
  float corrente_mA = (tensao / r_shunt) * 1000.0;
  return ganho * corrente_mA + offset;
}
