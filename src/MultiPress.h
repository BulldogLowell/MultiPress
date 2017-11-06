#ifndef MULTIPRESS_H
#define MULTIPRESS_H

#ifdef PARTICLE
  #include "Particle.h"
#elif ARDUINO >= 100
  #include "Arduino.h"
#endif

#define MAX_BUTTON_INSTANCES 5
#define DEFAULT_DEBOUNCE_MILLISECONDS 50

class SimplePress{
  public:
    SimplePress(int _pin, uint32_t _pressInterval, void(*_callBack)(int value));
    bool begin();
    int8_t pressed();
    static void update(void);
    static bool beginAll();
    static int getCount() {return instanceCount;}
  private:
    byte pressCount;
    byte lastState;
    byte pin;
    uint32_t lastMillis;
    uint8_t debouncePeriod;
    uint16_t pressInterval;
    void(*callBack)(int value);
    static uint8_t instanceCount;
    static SimplePress* instances[MAX_BUTTON_INSTANCES];
};

#endif
