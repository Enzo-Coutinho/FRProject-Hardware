#include "Arduino.h"
#include "FocusLight.h"
#include "FLClient.h"

FLClient client;
FocusLight controller;

void setup() {
  Serial.begin(115200);
  client.initWiFi();
  controller.init();
}

void loop() {
  int* color = client.getEmotes();
  for(int i = 0; i<3; i++) {
    Serial.print(color[i]);
    Serial.print(" ");
  }
  Serial.println("");
  controller.setColor(color);
  delay(500);
}
