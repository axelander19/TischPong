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
  int Pin;
  
public:
  void init(int pin);
  bool lesen();
};
#endif
