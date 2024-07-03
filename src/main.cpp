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
  for(int i = 0; i<3; i++) {
    Serial.print(color[i]);
  }
  Serial.println("");
  controller.setColor(color);
  delay(100);
}
