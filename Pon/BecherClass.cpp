#include "BecherClass.h"

void BecherClass::init(byte Imp, byte Ie, byte i, byte LEDID, byte pinSelect, byte pinSensor, byte pinLED) {
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

	RingeLED.init(PinLED, AnzahlLEDproRing);
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

void BecherClass::sourceSelect() {
	byte E3 = (MPEingangID % 2);
	byte E2 = ((MPEingangID/2) % 2);
	byte E1 = ((MPEingangID/4) % 2);
	byte E0 = ((MPEingangID/8) % 2);
	digitalWrite(PinSelect0, E0);
	digitalWrite(PinSelect1, E1);
	digitalWrite(PinSelect2, E2);
	digitalWrite(PinSelect3, E3);
}

bool BecherClass::getStatus() {
	return status;
}


void BecherClass::aktFarbe(byte hel) {
  Helligkeit = hel;
	if (status == true) {			//farbe auf gruen
  Serial.print("becher auf gruen mit led ");

		for (byte i = StartLedID; i < AnzahlLEDproRing; i++) {
			    Serial.println(i);

			RingeLED.setPixelGruen(i);													//was bei überlapen?    bit für 4eraufstellung
			RingeLED.showPixel(Helligkeit);
		}
	}
	if (status == false) {
		for (byte i = StartLedID; i < AnzahlLEDproRing; i++) {
			RingeLED.setPixelRot(i);													//was bei überlapen?    bit für 4eraufstellung
			showPixel(Helligkeit);
		}
	}
}
