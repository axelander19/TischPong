#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define AnzahlLED

class StreifenClass
{
private:
	int Pin;

public:
	void init(int pin);
};

