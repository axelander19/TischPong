#include "SensorCLass.h"


void SensorClass::init(int Imp, int Ie, int i) {
	setMPID(Imp);
	setE(Ie);
	setID(i);
}

bool SensorClass::SensorLesen() {
	
	sourceSelect();
	
//	SensorWert = analogRead(MPID);
	if (SensorWert < 500) {
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
/*	digitalWrite((MPID * 4), E0);
	digitalWrite((MPID * 4)+1, E1);
	digitalWrite((MPID * 4)+2, E2);
  digitalWrite((MPID * 4)+3, E3);*/


}

void SensorClass::setE(int e) {
	this->E = e;
}
