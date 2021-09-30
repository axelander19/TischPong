#include "StreifenClass.h"

void StreifenClass::init(int pin) {
	this->Pin = pin;
	pinMode(pin, OUTPUT);
}