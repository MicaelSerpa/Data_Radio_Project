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




float lerCorrenteCalibrada1(float entrada_adc, float r_shunt) {
  // Conversão ADC para tensão
  float tensao = 3.3 / 4095.0 * entrada_adc;

  // Conversão tensão para corrente (mA)
  float corrente_mA = (tensao / r_shunt) * 1000.0;

  // Calibração
  float corrente_calibrada = 0.9818 * corrente_mA - 0.0165;

  return corrente_calibrada;
}


float lerCorrenteCalibrada2(float entrada_adc, float r_shunt) {
  float tensao = 3.3 / 4095.0 * entrada_adc;
  float corrente_mA = (tensao / r_shunt) * 1000.0;

  // Calibração canal 2
  float corrente_calibrada = 0.9824 * corrente_mA - 0.1278;

  return corrente_calibrada;
}

float lerCorrenteCalibradaCanal3(float entrada_adc, float r_shunt) {
  float tensao = 3.3 / 4095.0 * entrada_adc;
  float corrente_mA = (tensao / r_shunt) * 1000.0;

  // Calibração canal 3
  float corrente_calibrada = 0.9814 * corrente_mA - 0.0079;

  return corrente_calibrada;
}
