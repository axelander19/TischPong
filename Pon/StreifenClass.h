#pragma once
#ifndef _StreifenClass_h
#define _StreifenClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"

#endif
#include "LedClass.h"



#define AnzahlLEDproStreifen 60


class StreifenClass
{
private:
	byte Team;
	byte Pin;
	byte aktID = 0;
	
	byte divider = 2;

	LedClass streifen;
	byte Helligkeit = 0;
 
public:
	void init(byte pin, byte team);
	//int *TeamColour();
	void treffer();
	void setModus(int hel, bool sparmodus);

};
#endif
