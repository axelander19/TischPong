#ifndef _ButtonClass_h
#define _ButtonClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif





class ButtonClass
{
private:
  bool status;
  byte Pin;
  
public:
  void init(byte pin);
  bool lesen();
};
#endif
