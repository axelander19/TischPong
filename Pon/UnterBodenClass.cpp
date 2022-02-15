#include "UnterBodenClass.h"

void UnterBodenClass::init(byte pin, byte team) {

	this->Pin = pin;
	this->Team = team;

	//---------streifen initialisieren
	streifen.Init(Pin, AnzahlLEDproStreifen, Team);


	//----------Teamfarbe setzen

	streifen.setPixelsTeam(aktID, AnzahlLEDproStreifen);
}

void UnterBodenClass::treffer(bit Team) {
    if (this->Energiesparmodus == true) {
        //streifen.RunningLights(AnzahlLEDproStreifen);
        
        streifen.changeTeam(Team);

        streifen.setPixelsTeam(0,AnzahlLEDproStreifen);

    }
    
}


void UnterBodenClass::setModus(int hel, bool sparmodus) {

    this->Energiesparmodus = sparmodus;

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

    //treffer();
    //treffer();
}

 void UnterBodenClass::setBrightness(int hel){
        streifen.setBrightness(hel);
    }
