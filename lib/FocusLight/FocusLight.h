#ifndef FocusLight_h
#define FocusLight_h
#include "Freenove_WS2812_Lib_for_ESP32.h"
#include "Arduino.h"

struct PercentTotal {
    int emotionTotal[3];
};

enum Emotions {
    ANGRY = 0,
    HAPPY = 3,
    FEAR = 2,
    SAD = 5,
    DISGUST = 1,
    NEUTRAL = 4,
    SURPRISE = 6
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
        static const int QUANTIDADE_PESSOAS = 1;
        int emotions[7] = {};
        double emotionPercent[7] = {};
        int emotionPercentTotal[3];
        static const int CHANNEL = 0;
        static const int PINO = 14;
        static const int LED_COUNT = 30;
    public:
        FocusLight();
        int* readSerial();
        void sendSerial(String data);
        PercentTotal getPercentTotal();
        void setColor();
        void rainbow();
        int * calcule(int emotionsQuant[]);
};

#endif