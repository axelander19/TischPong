#pragma once
#ifndef _UnterBodenClass_h
#define _UnterBodenClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"

#endif
#include "LedClass.h"



#define AnzahlLEDproStreifen 300
#define AnzahlLEDWelle 5

class UnterBodenClass
{
private:
	byte Team;
	byte Pin;
	byte aktID = 0;

	byte divider = 2;

	LedClass streifen;

	bool Energiesparmodus = false;

	int allowedPixel[AnzahlLEDproStreifen] = { 1 };


public:
	void init(byte pin, byte team);
	void setModus(int hel, bool sparmodus);
	void setBrightness(int hel);

	void treffer(bit Team);

};
#endif
