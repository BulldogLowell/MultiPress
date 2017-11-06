#include "/src/MultiPress.h"

#ifdef PARTICLE
  #define LEDPIN D7
#elif ARDUINO >= 100
  #define LEDPIN 13
#endif

void A_ButtonActions(void);  // Callback function definitions are required...
void B_ButtonActions(const int value);

SimplePress pushButtonSwitches[]= {
  //{2, 100, A_ButtonActions},  // pin, interval, callback-on-pressed
  {2, 100, [](){digitalWrite(LEDPIN, !digitalRead(LEDPIN));}},  // same as above but done with Lambda
  {3, 300, B_ButtonActions},
};

void setup()
{
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  Serial.println(SimplePress::getCount());
  SimplePress::beginAll();
  SimplePress::setDebounceAll(25);
}

void loop()
{
  SimplePress::update();
}

void A_ButtonActions(void)  // simple example of registering "Pressed"
{
  digitalWrite(LEDPIN, !digitalRead(LEDPIN));
}

void B_ButtonActions(const int value)  // example of registering Multi-Presses
{
  Serial.print(F("Button B:\t"));
  switch(value)
  {
    case -1:
      Serial.println(F("Long Press"));
      break;
    case 1:
      Serial.println(F("One Press"));
      break;
    case 2:
      Serial.println(F("Two Presses"));
      break;
    case 3:
      Serial.println(F("Three Presses"));
      break;
    default:
      Serial.println(F("Whole Lotta Presses"));
      break;
  }
}
