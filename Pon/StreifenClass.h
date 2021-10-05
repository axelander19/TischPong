#pragma once

#include "LedClass.h"

#define AnzahlLEDproStreifen 200


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
};
