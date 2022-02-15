#include "BecherClass.h"

void BecherClass::init(bool team, int pinLed, int pinSensor, int pinSelect, byte ledid) {
	
	this->LedClassId = ledid;
	this->Team = team;
	this->PinSensor = pinSensor;
	this->PinLed = pinLed;
	this->PinSelect0 = pinSelect;
	this->PinSelect1 = pinSelect+2;
	this->PinSelect2 = pinSelect+4;
	this->PinSelect3 = pinSelect+6;

	pinMode(PinSensor, INPUT);
	pinMode(PinSelect0, OUTPUT);
	pinMode(PinSelect1, OUTPUT);
	pinMode(PinSelect2, OUTPUT);
	pinMode(PinSelect3, OUTPUT);

	int medianSensor;
	int SumSensor = 0;

	int aktStartid = 0;
	for (int i = 0; i < AnzahlPositionen; i++) {

		SourceSelect(i);
		//int SensorSig = analogRead(PinSensor);
		//SumSensor += SensorSig;


		Status[i] = false;
		SensorID[i] = i;
		StartLedID[i] = aktStartid;

		aktStartid = aktStartid + 24;


		//if ((aktStartid == 7*AnzahlLEDproRing) || (aktStartid == 12* AnzahlLEDproRing) || (aktStartid == 15* AnzahlLEDproRing)) {		      //Bei neuer reihe extra weiterschieben
			//aktStartid = aktStartid + 12;
		//}
	}

	//SensorSchwellwert = SumSensor / (AnzahlPositionen);
	
	LED.Init(PinLed, AnzahlLEDproRing * 11, Team);
}


void BecherClass::ReadSensor() {
	for (byte i = 0; i < AnzahlPositionen; i++) {

		PreStatus[i] = Status[i];
		SourceSelect(i);
		delay(1);
		Serial.println(analogRead(PinSensor));
		if (analogRead(PinSensor) < /*SensorSchwellwert*/80) {
			Status[i] = true;
		}
		else {
			Status[i] = false;
		}
	}
}

void BecherClass::AktRinge() {
	
	for (byte i = 0; i < AnzahlPositionen; i++) {

		if ((Status[i] != PreStatus[i]) || (statuschange == true)) {		
			bool failure = false;

			if (Status[i] == true) {
				LED.setPixelsGruen(StartLedID[i], AnzahlLEDproRing);
				//setPixel(StartLedID[i], LedClassId, 0, 255, 0, AnzahlLEDproRing);
			}
			if (Status[i] == false) {

				if (i > 0) {

					if ((Status[i - 1] == true) && (StartLedID[i] == StartLedID[i - 1] + 12)) {
						//schreibe erst ab der h�lfte auf rot
						LED.setPixelsRot(StartLedID[i] + 12, AnzahlLEDproRing - 12);
						//setPixel(StartLedID[i], LedClassId, 255, 0, 0, AnzahlLEDproRing);

						failure = true;
					}
				}
				if (failure == false) {
					LED.setPixelsRot(StartLedID[i], AnzahlLEDproRing);						//bei keinem fehler wird normal beschirieben
					//setPixel(StartLedID[i], LedClassId, 255, 0, 0, AnzahlLEDproRing);

				}
			}

		}
	}
	statuschange = false;
}

void BecherClass::SourceSelect(byte sensorid) {
	byte E3 = (sensorid % 2);
	byte E2 = ((sensorid / 2) % 2);
	byte E1 = ((sensorid / 4) % 2);
	byte E0 = ((sensorid / 8) % 2);
	digitalWrite(PinSelect0, E0);			
	digitalWrite(PinSelect1, E1);
	digitalWrite(PinSelect2, E2);
	digitalWrite(PinSelect3, E3);
}

void BecherClass::setStatus(bool status, int id) {
	Status[id] = status;
}

bool BecherClass::getStatus(int id) {
	return Status[id];
}

void BecherClass::setModus(int hel, bool sparmodus) {
	statuschange = true;
	LED.setModus(hel, sparmodus);
	AktRinge();
}

 void BecherClass::setBrightness(int hel){
        LED.setBrightness(hel);
    }
