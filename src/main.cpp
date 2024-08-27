#include "Arduino.h"
#include "FocusLight.h"

FocusLight controller;
void setup() {
  Serial.begin(115200);
  controller.init();
}
void loop() {
  controller.readSerial();
  int* color = controller.calcule();
  controller.setColor(color);
}
