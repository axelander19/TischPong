#pragma once

#include "LedClass.h"

#define AnzahlPositionen 16
#define AnzahlLEDproRing 24

class BecherClass
{
private:
	byte Team;

	int PinLed;
	int PinSensor;
	byte PinSelect0;
	byte PinSelect1;
	byte PinSelect2;
	byte PinSelect3;

	int SensorSchwellwert;

	int StartLedID[AnzahlPositionen + 1];
	int SensorID[AnzahlPositionen + 1];
	bool Status[AnzahlPositionen] = { false };
	bool PreStatus[AnzahlPositionen] = {true};

	LedClass LED;
	byte LedClassId;

	void SourceSelect(int sensorid);

public:
	void init(bool team, int pinLed, int pinSensor, int pinSelect, byte ledid);
	void AktRinge();
	void ReadSensor();
	void setStatus(int status, int id);
	bool getStatus(int id);
	void setModus(int hel, bool sparmodus);
};
