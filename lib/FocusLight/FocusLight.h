#ifndef FocusLight_h
#define FocusLight_h
#include "Freenove_WS2812_Lib_for_ESP32.h"
#include "Arduino.h"
#include "ArduinoJson.h"

struct PercentTotal {
    int emotionTotal[3];
};

enum Colors {
    R = 0,
    G = 1,
    B = 2,
};

class FocusLight {
    private:
        const char* emotes[5] = { "happy", "neutral", "sad", "tired", "angry"};
        double count[5];
        PercentTotal percentTotal;
        static const int QUANTIDADE_PESSOAS = 1;
        int emotionPercentTotal[3];
        static const int CHANNEL = 0;
        static const int PINO = 27;
        static const int LED_COUNT = 61;
    public:
        static Freenove_ESP32_WS2812 ws2812b;
        JsonDocument doc;
        FocusLight(void);
        void readSerial();
        void init();
        void sendSerial(String data);
        void setColor(int color[]);
        void setOneColor(int color[], int leds=1);
        void rainbow();
        int* calcule();
};

#endif