#include "BecherClass.h"

void BecherClass::rot(){
  status = true;
}
void BecherClass::gruen(){
  status = false;
}
bool BecherClass::getstatus(){
  return status;
  }
