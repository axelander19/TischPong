#pragma once

#include "LedClass.h"

#define AnzahlPositionen 15
#define AnzahlLEDproRing 24

class BecherClass
{
private:
	int PinLed;
	int PinSensor;
	byte PinSelect0;
	byte PinSelect1;
	byte PinSelect2;
	byte PinSelect3;
	
	int SensorSchwellwert;

	int StartLedID[AnzahlPositionen+1];
	int SensorID[AnzahlPositionen+1];
	bool Status[AnzahlPositionen + 1];

	LedClass LED;


	void SourceSelect(int sensorid);

public:
	//BecherClass(bool team, int pinLed, int pinSensor);
	void init(bool team, int pinLed, int pinSensor);
	void AktRinge();
	void ReadSensor();
	void setStatus(int status, int id) {
		Status[id] = status;

	}
};

