#ifndef FLClient_h
#define FLClient_h
#include "WiFi.h"
#include "esp32-hal-log.h"
#include <HTTPClient.h>
#include "ArduinoJson.h"
#include "StreamUtils.h"

class FLClient {
    private:
        const char* ssid = "CLARO_849";
        const char* passoword = "";
        const char* url = "http://192.168.0.105:5000/emotions";
        TaskHandle_t reconnectHandler;
        static void events(WiFiEvent_t event);
        static void reconnect(void * arg);
        HTTPClient client;
        int colors[];
    public:
        void initWiFi();
        int * getEmotes();
};

#endif