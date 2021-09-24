#include "BecherClass.h"

void BecherClass::init(){
  
}

void BecherClass::rot(){
  status = true;
}
void BecherClass::gruen(){
  status = false;
  digitalWrite(1,1);
}
bool BecherClass::getstatus(){
  return status;
  }
