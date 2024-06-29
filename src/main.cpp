#include <Arduino.h>
#include "FocusLight.h"

FocusLight controller = FocusLight();

void setup() {
  Serial.begin(115200);
}

void loop() {
  int* data = controller.readSerial();
  int* output = controller.calcule(data);
  for(int k = 0; k<3; k++) {
    Serial.print(output[k]);
  }
  Serial.println("");
  delay(100);
}