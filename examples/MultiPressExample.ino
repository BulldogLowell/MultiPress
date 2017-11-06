#include "/src/MultiPress.h"

#ifdef PARTICLE
  #define LEDPIN D7
  #define BUTTON_A D2
  #define BUTTON_B D3
#elif ARDUINO >= 100
  #define LEDPIN 13
  #define BUTTON_A 2
  #define BUTTON_B 3
#endif

void A_ButtonActions(void);  // Callback function definitions are required...
void B_ButtonActions(const int value);

SimplePress pushButtonSwitches[]= {
  //{BUTTON_A, 100, A_ButtonActions},  // pin, interval, callback-on-pressed
  {BUTTON_A, 100, [](){digitalWrite(LEDPIN, !digitalRead(LEDPIN));}},  // same as above but done with Lambda
  {BUTTON_B, 300, B_ButtonActions},
};

void setup()
{
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  Serial.println(SimplePress::getCount());
  SimplePress::beginAll();
  SimplePress::setDebounceAll(50);
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
