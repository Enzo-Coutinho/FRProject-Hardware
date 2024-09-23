#ifndef FLClient_h
#define FLClient_h
#include "WiFi.h"
#include "esp32-hal-log.h"
#include <HTTPClient.h>
#include "ArduinoJson.h"
#include "StreamUtils.h"

class FLClient {
    private:
        const char* ssid = "FocusLight";
        const char* password = "123456789";
        const char* url = "http://192.168.4.2:5000/emotions";
        TaskHandle_t reconnectHandler;
        static void events(WiFiEvent_t event);
        static void reconnect(void * arg);
        void setChannel();
        HTTPClient client;
        static bool clientStatus;
        int colors[];
    public:
        void initWiFi();
        int * getEmotes();
};

#endif