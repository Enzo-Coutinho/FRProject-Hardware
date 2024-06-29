#include "FocusLight.h"

Freenove_ESP32_WS2812 FocusLight::FitaLED = Freenove_ESP32_WS2812(LED_COUNT, PINO, CHANNEL);

FocusLight::FocusLight() {
    FitaLED.begin();
    FitaLED.setBrightness(40);
}

int * FocusLight::calcule(int emotionsQuant[]) {
  for(int i = 0; i < 7; i++) {
    emotionPercent[i] = (emotionsQuant[i] / QUANTIDADE_PESSOAS);
  }

  percentTotal.emotionTotal[R] = (emotionPercent[ANGRY] + emotionPercent[SAD]) * 255;
  percentTotal.emotionTotal[G] = (emotionPercent[HAPPY] + emotionPercent[NEUTRAL]) * 255;
  percentTotal.emotionTotal[B] = (emotionPercent[DISGUST] + emotionPercent[FEAR] + 
                                  emotionPercent[SURPRISE]) * 255;

  return percentTotal.emotionTotal;
}

PercentTotal FocusLight::getPercentTotal() {
    return percentTotal;
}

int * FocusLight::readSerial() {
  for(int i = 0; i < 7; i++) {
    emotions[i] = Serial.read();
  } 
  return emotions;
}

void FocusLight::sendSerial(String data) {
  Serial.println(data);
}

void FocusLight::setColor() {
  FocusLight::FitaLED.setAllLedsColor(percentTotal.emotionTotal[R], 
                                      percentTotal.emotionTotal[G], 
                                      percentTotal.emotionTotal[B]);
}