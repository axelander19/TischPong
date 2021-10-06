#ifndef _LedClass_h
#define _LedClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#include "LedClass.h"

#else
#include "WProgram.h"
#endif


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif




//#include "Farben.h"

class LedClass
{
public:
	void Init(byte pin, byte Anzahl);
	void setPixelTeam(byte id, byte i);
	void setPixelRot(byte id);
	void setPixelGruen(byte id);

	void showPixel(byte Helligkeit);


private:
	byte Pin;
	byte Team;

	Adafruit_NeoPixel LEDPixel;

/*
  int FarbeTeam0[3] = { 255,264,248 };
  int FarbeTeam1[3] = { 255,264,248 };
  int FarbeRot[3] = { 255,0,0 };
  int FarbeGruen[3] = { 0,255,0 };*/
};
#endif
