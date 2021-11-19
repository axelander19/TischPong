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

#define AnzahllehreLEDs 5


//#include "Farben.h"

class LedClass
{
private:
	byte Pin;
	byte Team;
	byte LedClassId;

	int Helligkeit;
	bool EnergieModus;

	Adafruit_NeoPixel Matrix0;				//LEDID 0
	Adafruit_NeoPixel Matrix1;				//LEDID 1
	Adafruit_NeoPixel Ring0;				//LEDID 2
	Adafruit_NeoPixel Ring1;				//LEDID 3
	Adafruit_NeoPixel Streifen0;			//LEDID 4
	Adafruit_NeoPixel Streifen1;			//LEDID 5

public:

	void Init(byte pin, int Anzahl, byte Team, byte ledclassid);
	//void setPixelTeam(byte id, byte ledclassid);

	//void setPixelRot(byte id, byte ledclassid);
	void setPixelsRot(byte startid, byte laenge, byte ledclassid);

	

	void setPixelsGruen(byte startid, byte laenge, byte ledclassid);
	//void setPixelGruen(byte id, byte ledclassid);

	void setPixel(byte id, byte ledclassid, int r, int g, int b);

	void setPixelsTeam(byte startid, byte laenge, byte ledclassid);
	void setModus(int hel, bool sparmodus);
};
#endif
