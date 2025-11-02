void init_pwm_500hz() {

  HAL_Init();

  // --- Clocks ---
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_TIM3_CLK_ENABLE();

  // --- GPIOs PWM ---
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // PA6, PA7 (TIM3_CH1 e TIM3_CH2)
  GPIO_InitStruct.Pin = AO1_PIN | AO2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // PB0 (TIM3_CH3)
  GPIO_InitStruct.Pin = AO3_PIN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // --- Timer 3 (PWM 500 Hz, 11 bits) ---
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 69;        // Ajustado para 500 Hz
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 2047;         // 11 bits
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_PWM_Init(&htim3);

  // --- Canais PWM ---
  TIM_OC_InitTypeDef sConfigOC = {0};
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.Pulse = 0;  // duty inicial = 0

  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3);

  // --- Inicia PWM ---
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
}


void init_pwm_1khz() {

  HAL_Init();

  // --- Clocks ---
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_TIM3_CLK_ENABLE();

  // --- Configura GPIOs PWM como saída alternativa push-pull ---
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // PA6, PA7 (TIM3_CH1 e TIM3_CH2)
  GPIO_InitStruct.Pin = AO1_PIN | AO2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // PB0 (TIM3_CH3)
  GPIO_InitStruct.Pin = AO3_PIN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // --- Configura o Timer 3 (PWM 1 kHz, 11 bits) ---
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 34;        // <<< ajustado para 1 kHz
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 2047;         // 11 bits
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_PWM_Init(&htim3);

  // --- Configura canais PWM ---
  TIM_OC_InitTypeDef sConfigOC = {0};
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.Pulse = 0;  // duty inicial = 0

  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3);

  // --- Inicia os três canais PWM ---
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
}

void init_pwm_17khz() {

  HAL_Init();

  // --- Clocks ---
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_TIM3_CLK_ENABLE();

  // --- Configura GPIOs PWM como saída alternativa push-pull ---
  GPIO_InitTypeDef GPIO_InitStruct = { 0 };

  // PA6, PA7 (TIM3_CH1 e TIM3_CH2)
  GPIO_InitStruct.Pin = AO1_PIN | AO2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // PB0 (TIM3_CH3)
  GPIO_InitStruct.Pin = AO3_PIN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // --- Configura o Timer 3 (PWM 17 kHz, 11 bits) ---
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1;  // PSC = 1 → divide clock por 2
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 2047;  // ARR = 2047 → 11 bits
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_PWM_Init(&htim3);

  // --- Configura canais PWM ---
  TIM_OC_InitTypeDef sConfigOC = { 0 };
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.Pulse = 0;  // duty inicial = 0

  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3);

  // --- Inicia os três canais PWM ---
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
}
