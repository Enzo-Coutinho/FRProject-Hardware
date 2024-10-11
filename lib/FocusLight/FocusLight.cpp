#include "FocusLight.h"

Freenove_ESP32_WS2812 FocusLight::ws2812b(LED_COUNT, PINO, CHANNEL, TYPE_GRB);

FocusLight::FocusLight() {

}

void FocusLight::init() {
  ws2812b.begin();
  ws2812b.setBrightness(255);
}

int * FocusLight::calcule() {
  percentTotal.emotionTotal[R] = doc["r"];
  percentTotal.emotionTotal[G] = doc["g"];
  percentTotal.emotionTotal[B] = doc["b"];

  return percentTotal.emotionTotal;
}

void FocusLight::readSerial() {
  deserializeJson(doc, Serial);
}

void FocusLight::sendSerial(String data) {
  Serial.println(data);
}

void FocusLight::setColor(int color[]) {
  ws2812b.setAllLedsColor(color[0], color[1], color[2]);
}

void FocusLight::setOneColor(int color[], int leds) {

}