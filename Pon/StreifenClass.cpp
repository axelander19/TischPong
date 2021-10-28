#include "StreifenClass.h"


void StreifenClass::init(byte pin, byte team) {
	this->Pin = pin;
	this->Team = team;

    //---------streifen initialisieren
 //   streifen.Init(Pin, AnzahlLEDproStreifen);


    //----------Teamfarbe setzen
   // byte id = 0;

    for (byte id = 0; id < AnzahlLEDproStreifen; id++) {
        //aktivieren led
        streifen.setPixelTeam(id);
        streifen.showPixel();
        //Serial.println("Streifeneinpiel");
        delay(100);
    }     
}

void StreifenClass::treffer() {
    for (byte i = aktID; aktID < AnzahlLEDproStreifen / divider; aktID++){
        streifen.setPixelTeam(aktID);
        streifen.setPixelGruen(aktID+1);
        streifen.showPixel();
        delay(10);
    }
    divider = 1;
    if (aktID == AnzahlLEDproStreifen - 1)
    {
        aktID = 0;
        divider = 2;
    }
}

  void StreifenClass::setModus(int hel, bool sparmodus){
    
  }
