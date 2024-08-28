#include "Arduino.h"
#include "FocusLight.h"
#include "FLClient.h"

FLClient client;
FocusLight controller;

void setup() {
  Serial.begin(115200);
  client.initWiFi();
  //controller.init();
}

void loop() {
  //controller.readSerial();
  int* color = client.getEmotes();
  //controller.setColor(color);
  for(int i = 0; i <= 2; i++) {
    Serial.println(color[i]);
  }
  delay(500);
}
