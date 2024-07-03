#include "FocusLight.h"

Adafruit_NeoPixel FocusLight::ws2812b(LED_COUNT, PINO, NEO_GRB + NEO_KHZ800);

FocusLight::FocusLight() {

}

void FocusLight::init() {
  ws2812b.begin();
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
  for(int i = 0; i < LED_COUNT; i++) {
    ws2812b.setPixelColor(i, ws2812b.Color(color[R], color[G], color[B]));
    ws2812b.show();
  }
}

void FocusLight::setOneColor(int color[], int leds) {
    ws2812b.setPixelColor(leds, ws2812b.Color(color[R], color[G], color[B]));
    ws2812b.show();
    delay(1000);
    ws2812b.clear();
}