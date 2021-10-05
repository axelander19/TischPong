#include "ButtonClass.h"

void ButtonClass::init(byte pin){
  this->Pin = pin;
  pinMode(Pin, INPUT);
}

bool ButtonClass::lesen(){
  status = analogRead(Pin);
  return status;
}
