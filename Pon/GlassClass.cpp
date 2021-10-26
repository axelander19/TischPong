// 
// 
// 

#include "GlassClass.h"


void GlassClass::init(byte Imp, byte Ie, byte i, byte LEDID, byte pinSelect, byte pinSensor, byte pinLED) {
	StartLedID = LEDID;
	this->AbschnittID = Imp;
	this->MPEingangID = Ie;
	this->SensorID = i;
	//Serial.println(PinLED);

	PinfirstSelect = pinSelect + AbschnittID * 4;
	PinSelect0 = pinSelect + (AbschnittID * 4);
	PinSelect1 = pinSelect + 1 + (AbschnittID * 4);
	PinSelect2 = pinSelect + 2 + (AbschnittID * 4);
	PinSelect3 = pinSelect + 3 + (AbschnittID * 4);

	this->PinLED = pinLED + AbschnittID;
	this->PinSensor = pinSensor + AbschnittID;
	//Serial.println(PinLED);

	pinMode(PinSensor, INPUT);

	//RingeLED.Init(PinLED, AnzahlLEDproRing);
}

bool GlassClass::SensorLesen() {

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

void GlassClass::sourceSelect() {
	byte E3 = (MPEingangID % 2);
	byte E2 = ((MPEingangID / 2) % 2);
	byte E1 = ((MPEingangID / 4) % 2);
	byte E0 = ((MPEingangID / 8) % 2);
	digitalWrite(PinSelect0, E0);
	digitalWrite(PinSelect1, E1);
	digitalWrite(PinSelect2, E2);
	digitalWrite(PinSelect3, E3);
}

bool GlassClass::getStatus() {
	return status;
}


void GlassClass::aktFarbe(byte hel) {
	Helligkeit = hel;
	if (status == true) {			//farbe auf gruen
		//Serial.print(F("becher auf gruen mit led "));

		for (byte i = StartLedID; i < AnzahlLEDproRing; i++) {
			//Serial.println(PinLED);
			RingLeds.setPixelColor(i, RingLeds.Color(0, 255, 0));
			
			//RingeLED.setPixelGruen(i);													//was bei überlapen?    bit für 4eraufstellung
			//RingeLED.showPixel(Helligkeit);
			RingLeds.show();

		}
	}
	if (status == false) {
		for (byte i = StartLedID; i < AnzahlLEDproRing; i++) {
			RingLeds.setPixelColor(i, RingLeds.Color(255, 0, 0));

			//RingeLED.setPixelRot(i);													//was bei überlapen?    bit für 4eraufstellung
			//RingeLED.showPixel(Helligkeit);
		}
		

	}
	delay(100);
}



void GlassClass::setStatus(bool Status) {
	this->status = Status;

}