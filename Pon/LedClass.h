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
private:
	byte Pin;
	byte Team;

	 Adafruit_NeoPixel LEDPixel;

public:
	void Init(byte pin, byte Anzahl);
	void setPixelTeam(byte id, byte i);
	void setPixelRot(byte id);
	void setPixelGruen(byte id);

	void showPixel(byte Helligkeit);


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
