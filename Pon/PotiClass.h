#pragma once
#ifndef _PotiClass_h
#define _PotiClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define resolution 1024

class PotiClass
{
private:
	int value;
	int Pin;
	float faktor;

public:
	void init(int pin);
	float lesen();

};

#endif
