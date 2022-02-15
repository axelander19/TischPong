#pragma once
#ifndef _StreifenClass_h
#define _StreifenClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"

#endif
#include "LedClass.h"



#define AnzahlLEDproStreifen 100
#define AnzahlLEDWelle 5

class StreifenClass
{
private:
	byte Team;
	byte Pin;
	byte aktID = 0;
	
	byte divider = 2;

	LedClass streifen;
 
	int allowedPixel[AnzahlLEDproStreifen] = { 1 };

public:
	void init(byte pin, byte team);
	void setModus(int hel, bool sparmodus);
	void setBrightness(int hel);

	void treffer();

};
#endif
