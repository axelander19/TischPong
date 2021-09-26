#include "SensorCLass.h"

void SensorClass::init(int Imp, int Ie, int i) {
	setMPID(Imp);
	setE(Ie);
	setID(i);
}

bool SensorClass::SensorLesen() {
	
	sourceSelect();
	
	SensorWert = analogRead(MPID+firstMPPin);
	if (SensorWert < SensorSchwellwert) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
}

int SensorClass::getID() {
	return ID;
	}

void SensorClass::setID(int id) {
	this->ID = id;
}

void SensorClass::setPin(int pin) {
	this->MPID = pin;
}

void SensorClass::setMPID(int mpid) {
	this->MPID = mpid;
}

void SensorClass::sourceSelect() {	
	int E3 = (E % 2);
	int E2 = ((E/2) % 2);
	int E1 = ((E/4) % 2);
	int E0 = ((E/8) % 2);
	digitalWrite((MPID * 4)+firstSelectPin, E0);
	digitalWrite((MPID * 4)+1+ firstSelectPin, E1);
	digitalWrite((MPID * 4)+2+ firstSelectPin, E2);
	digitalWrite((MPID * 4)+3+ firstSelectPin, E3);
}

void SensorClass::setE(int e) {
	this->E = e;
}
