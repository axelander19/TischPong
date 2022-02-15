#include "StreifenClass.h"


void StreifenClass::init(byte pin, byte team) {
	this->Pin = pin;
	this->Team = team;

    //---------streifen initialisieren
    streifen.Init(Pin, AnzahlLEDproStreifen, Team);


    //----------Teamfarbe setzen

   streifen.setPixelsTeam(aktID, AnzahlLEDproStreifen);

}

void StreifenClass::treffer() {
    
    for (byte i = aktID; aktID < AnzahlLEDproStreifen / divider; aktID++){

        if (allowedPixel[aktID] == 1) {
            streifen.setPixelsTeam(aktID, 1);
        }
        else{
            streifen.setPixelsOut(aktID, 1);
        }

        streifen.setPixelsGruen(aktID+ 1, AnzahlLEDWelle);
    }

    divider = 1;
    Serial.println(aktID);
    if (aktID == AnzahlLEDproStreifen)
    {
        aktID = 0;
        divider = 2;
    }
}
    

    void StreifenClass::setModus(int hel, bool sparmodus) {

        streifen.setModus(hel, sparmodus);

        //allowedPixel setzten
        if (sparmodus == true) {
            for (int i = 0; i < AnzahlLEDproStreifen; i++) {
                if ((i % 4) == 0) {
                    allowedPixel[i] = 1;
                }
                else {
                    allowedPixel[i] = 0;
                }
            }
        }

        if (sparmodus == false) {
            for (int i = 0; i < AnzahlLEDproStreifen; i++) {                
                allowedPixel[i] = 1;              
                
            }
        }

        treffer();
        treffer();
    }

     void StreifenClass::setBrightness(int hel){
        streifen.setBrightness(hel);
    }
