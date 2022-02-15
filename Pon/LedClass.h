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

#define AnzahllehreLEDs 3


//#include "Farben.h"

class LedClass
{
private:
	byte Pin;
	byte Team;

	uint32_t Colourgruen = LEDs->Color(0, 255, 0);
	uint32_t Colourrot = LEDs->Color(255, 0, 0);
	uint32_t ColourTeam1 = LEDs->Color(255, 120, 0);
	uint32_t ColourTeam0 = LEDs->Color(0, 180, 255);
	uint32_t ColourTeam = LEDs->Color(0, 0, 0);
	uint32_t Colourout = LEDs->Color(0, 0, 0);


	int Helligkeit=50;
	bool EnergieModus = false;

	Adafruit_NeoPixel *LEDs;

public:

	void RunningLights(int anzahlled);

	void Init(byte pin, int Anzahl, byte Team);
	
	void setPixel(byte id, uint32_t Colour);
	
	void setPixels(byte startid, byte laenge, uint32_t Colour);

	void setPixelsRot(byte startid, byte laenge);
	void setPixelsGruen(byte startid, byte laenge);
	void setPixelsTeam(byte startid, byte laenge);
	void setPixelsOut(byte startid, byte laenge);

	void setModus(int hel, bool sparmodus);
	void setBrightness(int hel);

  void changeTeam(bit newTeam);
};
#endif
