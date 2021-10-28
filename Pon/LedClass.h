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

	int Helligkeit;
	bool EnergieModus;

	Adafruit_NeoPixel LEDPixel;

public:

	//LedClass(byte pin, byte Anzahl);
	void Init(byte pin, byte Anzahl, byte Team);
	void setPixelTeam(byte id);
	void setPixelRot(byte id);
	void setPixelGruen(byte id);
	void setPixelsRot(byte startid, byte laenge);
	void setPixelsGruen(byte startid, byte laenge);
	void setPixelsTeam(byte startid, byte laenge);


	void setModus(int hel, bool sparmodus);


	void showPixel();


	/*LedClass(byte pin, byte Anzahl):
		LEDPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800){}*/
	
	
	/*/
	
	{
	this->Pin = pin;
	pinMode(Pin, OUTPUT);
	Serial.println(pin);

	LEDPixel = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
	LEDPixel.setPixelColor(0, LEDPixel.Color(0, 255, 0));

	LEDPixel.begin();
	//LEDPixel.setBrightness(10);
	 LEDPixel.show();

}*/



};
#endif
