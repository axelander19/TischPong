#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//------------------------------
#define AnzahlSensor 34
#define AnzahlMP 2
#define AnzahlProMP 16
#define AnzahlSelectMP 4
#define AnzahlLEDproRing 24

#define SensorSchwellwert 500




class BecherClass
{
private:
	int PinfirstSelect;
	int PinSensor;
	int PinLED;
	int PinSelect0;
	int PinSelect1;
	int PinSelect2;
	int PinSelect3;
	
	Adafruit_NeoPixel RingeLED;
	uint32_t Rot = RingeLED.Color(FarbeRot[0], FarbeRot[1], FarbeRot[2]); // Red
	uint32_t Team0 = RingeLED.Color(FarbeTeam0[0], FarbeTeam0[1], FarbeTeam0[2]);
	uint32_t Team1 = RingeLED.Color(FarbeTeam1[0], FarbeTeam1[1], FarbeTeam1[2]);
	uint32_t Gruen = RingeLED.Color(FarbeGruen[0], FarbeGruen[1], FarbeGruen[2]);

	int SensorWert;
	bool status; //true=becher da; false=beacher weg
	
	int SensorID;
	int AbschnittID;
	int MPEingangID;

	int LEDs[24];
	int StartLedID;


public:
	void init(int AbschnittID, int Ie, int i, int LEDID, int pinSelect, int pinSensor, int pinLED);
	bool SensorLesen();
	int getID();
	void setPin(int pin);
	void sourceSelect();
	bool getStatus();
	void BecherWeg();
	void aktFarbe();
};
