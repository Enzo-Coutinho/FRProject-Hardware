#ifndef FocusLight_h
#define FocusLight_h
#include "Freenove_WS2812_Lib_for_ESP32.h"
#include "Arduino.h"

struct PercentTotal {
    int emotionTotal[3];
};

enum Emotions {
    ANGRY = 0,
    HAPPY = 1,
    FEAR = 2,
    SAD = 3,
    DISGUST = 4,
    NEUTRAL = 5,
};

enum Colors {
    R = 0,
    G = 1,
    B = 2,
};

class FocusLight {
    private:
        PercentTotal percentTotal;
        static Freenove_ESP32_WS2812 FitaLED;
        static const int QUANTIDADE_PESSOAS = 10;
        int emotions[7] = {};
        int emotionPercent[7] = {};
        int emotionPercentTotal[3];
        static const int CHANNEL = 0;
        static const int PINO = 14;
        static const int LED_COUNT = 30;
    public:
        void calcule();
        PercentTotal getPercentTotal();
        void setColor();
        void rainbow();
        FocusLight();
};

#endif