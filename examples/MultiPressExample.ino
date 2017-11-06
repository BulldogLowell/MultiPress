#include "MultiPress.h"

void A_ButtonActions(const int value);  // Callback function definitions are required...
void B_ButtonActions(const int value);

SimplePress pushButtonSwitches[]= {
  {2, 100, A_ButtonActions},  // pin, interval, callback-on-pressed
  {3, 300, B_ButtonActions},  
};

void setup() 
{
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  Serial.println(SimplePress::getCount());
  SimplePress::beginAll();
}

void loop() 
{
  SimplePress::update();
}

void A_ButtonActions(const int value)  // simple example of registering "Pressed"
{
  digitalWrite(13, !digitalRead(13));
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

