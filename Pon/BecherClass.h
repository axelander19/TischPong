#define AnzahlSensor 34
#define AnzahlMP 2
#define AnzahlProMP 16
#define AnzahlSelectMP 4
#define AnzahlLEDproRing 24

#define firstSelectPin 0
#define firstMPPin 0
#define firstRingPin 8

#define SensorSchwellwert 500

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif


class BecherClass
{
private:
	int SensorWert;
	bool status; //true=becher da; false=beacher weg
	
	int SensorID;
	int AbschnittID;
	int MPEingangID;

	int LEDs[24];
	int StartLedID;


public:
	void init(int AbschnittID, int Ie, int i, int LEDID);
	bool SensorLesen();
	int getID();
	void setPin(int pin);
	void sourceSelect();
	bool getStatus();
	void BecherWeg();
	int getLEDPin();
	int getSensorPin();
};
