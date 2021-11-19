#include "ButtonClass.h"

void ButtonClass::init(int pin){
  this->Pin = pin;
  pinMode(Pin, INPUT);
}

bool ButtonClass::lesen(){
  status = digitalRead(Pin);
  return status;
}
