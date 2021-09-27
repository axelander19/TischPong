#include "BecherClass.h"

void BecherClass::init(int Imp, int Ie, int i, int LEDID) {
	StartLedID = LEDID;
	this->AbschnittID = Imp;
	this->MPEingangID = Ie;
	this->SensorID = i;
}

bool BecherClass::SensorLesen() {
	
	sourceSelect();
	
	SensorWert = analogRead(AbschnittID+firstMPPin);
	if (SensorWert < SensorSchwellwert) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

int BecherClass::getID() {
	return SensorID;
	}


void BecherClass::setPin(int pin) {
	this->AbschnittID = pin;
}



void BecherClass::sourceSelect() {
	int E3 = (MPEingangID % 2);
	int E2 = ((MPEingangID/2) % 2);
	int E1 = ((MPEingangID/4) % 2);
	int E0 = ((MPEingangID/8) % 2);
	digitalWrite((AbschnittID * 4)+firstSelectPin, E0);
	digitalWrite((AbschnittID * 4)+1+ firstSelectPin, E1);
	digitalWrite((AbschnittID * 4)+2+ firstSelectPin, E2);
	digitalWrite((AbschnittID * 4)+3+ firstSelectPin, E3);
}



bool BecherClass::getStatus() {
	return status;
}

void BecherClass::BecherWeg() {
	getLEDPin();
	StartLedID;
}

int BecherClass::getLEDPin() {
	return (firstRingPin + AbschnittID);
}
int BecherClass::getSensorPin() {
	return (firstMPPin + AbschnittID);
}