// --- Quantidade total de pontos de calibração ---
const int nPoints = 30;

// --- Canal 1 ---
const int PWM_CH1[nPoints] = {
  0, 250, 342, 347, 365, 370, 375, 475, 500, 550,
  602, 755, 1000, 1170, 1180, 1250, 1300, 1350, 1500, 1580,
  1597, 1600, 1610, 1700, 1750, 1900, 1970, 1980, 2000, 2000
};
const float I_CH1[nPoints] = {
  0, 3.11, 4.00, 4.09, 4.23, 4.29, 4.37, 5.37, 5.63, 6.07,
  6.59, 8.04, 10.39, 11.96, 12.06, 12.73, 13.19, 13.66, 15.06, 15.87,
  16.03, 16.06, 16.16, 17.07, 17.57, 19.08, 19.79, 19.89, 20.08, 20.08
};

// --- Canal 2 ---
const int PWM_CH2[nPoints] = {
  0, 250, 342, 347, 365, 370, 375, 475, 500, 550,
  602, 755, 1000, 1170, 1180, 1250, 1300, 1350, 1500, 1580,
  1597, 1600, 1610, 1700, 1750, 1900, 1970, 1980, 2000, 2000
};
const float I_CH2[nPoints] = {
  0, 2.85, 3.75, 3.84, 3.98, 4.04, 4.14, 5.16, 5.43, 5.90,
  6.44, 7.98, 10.44, 12.06, 12.17, 12.85, 13.32, 13.80, 15.24, 16.05,
  16.22, 16.24, 16.35, 17.26, 17.77, 19.29, 20.01, 20.11, 20.32, 20.32
};

// --- Canal 3 ---
const int PWM_CH3[nPoints] = {
  0, 250, 342, 347, 365, 370, 375, 475, 500, 550,
  602, 755, 1000, 1170, 1180, 1250, 1300, 1350, 1500, 1580,
  1597, 1600, 1610, 1700, 1750, 1900, 1970, 1980, 2000, 2000
};
const float I_CH3[nPoints] = {
  0, 2.84, 3.75, 3.84, 3.98, 4.04, 4.12, 5.15, 5.42, 5.88,
  6.42, 7.94, 10.37, 11.98, 12.09, 12.76, 13.23, 13.71, 15.14, 15.95,
  16.12, 16.14, 16.25, 17.16, 17.66, 19.18, 19.89, 19.99, 20.19, 20.19
};

// --- Função genérica de interpolação linear ---
int interpolatePWM(const float I[], const int PWM[], int size, float current_mA) {
  // Limita à faixa medida
  if (current_mA <= I[0]) return PWM[0];
  if (current_mA >= I[size - 1]) return PWM[size - 1];

  // Busca o intervalo correto
  for (int i = 0; i < size - 1; i++) {
    if (current_mA >= I[i] && current_mA <= I[i + 1]) {
      float t = (current_mA - I[i]) / (I[i + 1] - I[i]);
      return (int)(PWM[i] + t * (PWM[i + 1] - PWM[i]) + 0.5f);
    }
  }
  return PWM[size - 1];
}

// --- Conversão para cada canal ---
int currentToPWM_CH1(float current_mA) {
  if (current_mA < 4.0f) current_mA = 4.0f;
  if (current_mA > 20.0f) current_mA = 20.0f;
  return interpolatePWM(I_CH1, PWM_CH1, nPoints, current_mA);
}

int currentToPWM_CH2(float current_mA) {
  if (current_mA < 4.0f) current_mA = 4.0f;
  if (current_mA > 20.0f) current_mA = 20.0f;
  return interpolatePWM(I_CH2, PWM_CH2, nPoints, current_mA);
}

int currentToPWM_CH3(float current_mA) {
  if (current_mA < 4.0f) current_mA = 4.0f;
  if (current_mA > 20.0f) current_mA = 20.0f;
  return interpolatePWM(I_CH3, PWM_CH3, nPoints, current_mA);
}
