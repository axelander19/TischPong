#include "BecherClass.h"

void BecherClass::init(bool team, int pinLed, int pinSensor) {

  this->Team = team;
	this->PinSensor = pinSensor;
	this->PinLed = pinLed;

	pinMode(PinSensor, INPUT);
	pinMode(PinSelect0, OUTPUT);
	pinMode(PinSelect1, OUTPUT);
	pinMode(PinSelect2, OUTPUT);
	pinMode(PinSelect3, OUTPUT);

	int medianSensor;
	int SumSensor = 0;

	int aktStartid = 0;
	for (int i = 0; i < AnzahlPositionen + 1; i++) {

		SourceSelect(i);
		int SensorSig = analogRead(PinSensor);
		SumSensor += SensorSig;

		aktStartid = aktStartid + 12;

		Status[i] = false;
		SensorID[i] = i;
		StartLedID[i] = aktStartid;

		if ((aktStartid == 7) || (aktStartid == 12) || (aktStartid == 15)) {		      //Bei neuer reihe extra weiterschieben
			aktStartid = aktStartid + 12;
		}
	}

	SensorSchwellwert = SumSensor / (AnzahlPositionen + 1);

	LED.Init(pinLed, AnzahlLEDproRing * 11, Team);

}

BecherClass::BecherClass(bool team, int pinLed, int pinSensor) {
	
	this->PinSensor = pinSensor;
	this->PinLed = pinLed;
	
	pinMode(PinSensor, INPUT);
	pinMode(PinSelect0, OUTPUT);
	pinMode(PinSelect1, OUTPUT);
	pinMode(PinSelect2, OUTPUT);
	pinMode(PinSelect3, OUTPUT);

	int SumSensor = 0;

	int aktStartid = 0;
	for (byte i = 0;i < AnzahlPositionen+1; i++) {
		
		SourceSelect(i);
		int SensorSig = analogRead(PinSensor);
		SumSensor += SensorSig;

		aktStartid = aktStartid + 12;

		Status[i] = false;
		SensorID[i] = i;
		StartLedID[i] = aktStartid;

		if ((aktStartid == 7) || (aktStartid == 12) || (aktStartid == 15)) {           //Bei neuer reihe extra weiterschieben
			aktStartid = aktStartid + 12;
		}
	}

	SensorSchwellwert = SumSensor / (AnzahlPositionen + 1);

	LED.Init(pinLed, AnzahlLEDproRing*11, Team);

}

void BecherClass::ReadSensor() {
	for (byte i = 0; i < AnzahlPositionen; i++) {

		SourceSelect(i);	
		int SensorSig = analogRead(PinSensor);
		if (SensorSig < SensorSchwellwert) {
			Status[i] = true;
		}
		else {
			Status[i] = false;
		}
	}
}

void BecherClass::AktRinge() {
	
	for (byte i=0; i < AnzahlPositionen; i++) {
		bool failure = false;

		if (Status[i] == true) {
			LED.setPixelsGruen(StartLedID[i], AnzahlLEDproRing);
		}
		else {
			if ((Status[i - 1] == true)&&(StartLedID[i] == StartLedID[i-1]+12)){
																							//schreibe erst ab der h�lfte auf rot
				LED.setPixelsRot(StartLedID[i]+12, AnzahlLEDproRing -12);
				failure = true;
			}
			if(failure=false){
				LED.setPixelsRot(StartLedID[i], AnzahlLEDproRing);						//bei keinem fehler wird normal beschirieben
			}
		}

	}
}

void BecherClass::SourceSelect(int sensorid) {
	byte E3 = (sensorid % 2);
	byte E2 = ((sensorid / 2) % 2);
	byte E1 = ((sensorid / 4) % 2);
	byte E0 = ((sensorid / 8) % 2);
	digitalWrite(PinSelect0, E0);
	digitalWrite(PinSelect1, E1);
	digitalWrite(PinSelect2, E2);
	digitalWrite(PinSelect3, E3);
}

void BecherClass::setStatus(int status, int id) {
	Status[id] = status;

}

bool BecherClass::getStatus(int id) {
	return Status[id];
}


void BecherClass::setModus(int hel, bool sparmodus) {

	
	this->Helligkeit = hel;
	this->EnergieStatus = sparmodus;

}
