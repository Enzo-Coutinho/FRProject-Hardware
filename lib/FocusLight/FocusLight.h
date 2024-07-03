#ifndef FocusLight_h
#define FocusLight_h
#include <Adafruit_NeoPixel.h>
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
        int CHANNEL = 0;
        static const int PINO = 14;
        static const int LED_COUNT = 30;
    public:
        static Adafruit_NeoPixel ws2812b;
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