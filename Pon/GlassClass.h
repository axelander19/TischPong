// GlassClass.h

#ifndef _GLASSCLASS_h
#define _GLASSCLASS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"


#else

	#include "WProgram.h"

#endif
#include "LedClass.h"


//------------------------------
#define AnzahlSensor 34
#define AnzahlMP 2
#define AnzahlProMP 16
#define AnzahlSelectMP 4
#define AnzahlLEDproRing 24

#define SensorSchwellwert 500

class GlassClass
{
private:
	byte PinfirstSelect;
	byte PinSensor;
	byte PinLED;
	byte PinSelect0;
	byte PinSelect1;
	byte PinSelect2;
	byte PinSelect3;

	LedClass RingeLED;
	byte Helligkeit;

	byte SensorWert;
	bool status = true; //true=becher da; false=beacher weg

	byte SensorID;
	byte AbschnittID;
	byte MPEingangID;

	//int LEDs[24];
	byte StartLedID;

public:
	void init(byte AbschnittID, byte Ie, byte i, byte LEDID, byte pinSelect, byte pinSensor, byte pinLED);
	bool SensorLesen();
	void sourceSelect();
	bool getStatus();
	void aktFarbe(byte hel);
};




#endif

