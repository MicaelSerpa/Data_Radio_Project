void testar_saidas() {

if (millis() - tempo_loop > 1500) {

  tempo_loop = millis();
  estado_led = !estado_led;

  // digitalWrite(LED, estado_led);

  digitalWrite(DO1, estado_led);
  digitalWrite(DO2, estado_led);
  digitalWrite(DO3, estado_led);
  digitalWrite(DO4, estado_led);

  AI1 = AI1 + 50;
  AI2 = AI2 + 50;
  AI3 = AI3 + 50;
}

if (AI1 >= 255) {

  AI1 = 50;
  AI2 = 50;
  AI3 = 50;
}

analogWrite(AO1, AI1);
analogWrite(AO2, AI2);
analogWrite(AO3, AI3);
}
