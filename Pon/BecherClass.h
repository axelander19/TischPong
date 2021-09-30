#define AnzahlSensor 34
#define AnzahlMP 2
#define AnzahlProMP 16
#define AnzahlSelectMP 4
#define AnzahlLEDproRing 24


#define SensorSchwellwert 500

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif


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
	int getLEDPin();
	int getSensorPin();
	void aktualisiereFarbe();
};
