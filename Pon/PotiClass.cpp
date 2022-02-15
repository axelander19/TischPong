#include "PotiClass.h"

void PotiClass::init(int pin) {
	this->Pin = pin;
	pinMode(Pin, INPUT);
}

float PotiClass::lesen(){

	faktor = analogRead(Pin)/resolution;

	return faktor;
}
