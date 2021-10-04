#include "BecherClass.h"

void BecherClass::init(int Imp, int Ie, int i, int LEDID, int pinSelect, int pinSensor, int pinLED) {
	StartLedID = LEDID;
	this->AbschnittID = Imp;
	this->MPEingangID = Ie;
	this->SensorID = i;
	
	
	PinfirstSelect = pinSelect+AbschnittID*4;
	PinSelect0 = pinSelect + (AbschnittID * 4);
	PinSelect1 = pinSelect +1+ (AbschnittID * 4);
	PinSelect2 = pinSelect +2+ (AbschnittID * 4);
	PinSelect3 = pinSelect +3+ (AbschnittID * 4);

	this->PinLED = pinLED + AbschnittID;
	this->PinSensor = pinSensor + AbschnittID;

	pinMode(PinSensor, INPUT);
	pinMode(PinLED, OUTPUT);

	RingeLED = Adafruit_NeoPixel(AnzahlLEDproRing*AnzahlSensor, PinLED, NEO_GRB + NEO_KHZ800);
	RingeLED.begin();
	RingeLED.setBrightness(helligkeit);
	RingeLED.show();
}

bool BecherClass::SensorLesen() {
	
	sourceSelect();
	
	SensorWert = analogRead(PinSensor);
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
	digitalWrite(PinSelect0, E0);
	digitalWrite(PinSelect1, E1);
	digitalWrite(PinSelect2, E2);
	digitalWrite(PinSelect3, E3);
}



bool BecherClass::getStatus() {
	return status;
}

void BecherClass::BecherWeg() {
	
	StartLedID;
}

void BecherClass::aktFarbe() {
	if (status == true) {			//farbe auf grün

	}
}
