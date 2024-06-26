#include "FocusLight.h"

Freenove_ESP32_WS2812 FocusLight::FitaLED = Freenove_ESP32_WS2812(LED_COUNT, PINO, CHANNEL);

FocusLight::FocusLight() {
    FitaLED.begin();
    FitaLED.setBrightness(40);
}

void FocusLight::calcule() {
  int count = 0;
  while(Serial.available()) {
    emotions[count] = Serial.read();
    count += 1;
  }

  for(int i = 0; i <= 6; i++) {
    emotionPercent[i] = emotions[i] / QUANTIDADE_PESSOAS;
  }

  percentTotal.emotionTotal[R] = (emotionPercent[ANGRY] + emotionPercent[SAD]);
  percentTotal.emotionTotal[G] = (emotionPercent[HAPPY] + emotionPercent[NEUTRAL]);
  percentTotal.emotionTotal[B] = (emotionPercent[DISGUST] + emotionPercent[FEAR] + emotionPercent[6]);
}

PercentTotal FocusLight::getPercentTotal() {
    return percentTotal;
}