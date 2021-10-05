#include "BecherClass.h"
#include "ButtonClass.h"
#include "MatrixClass.h"
#include "StreifenClass.h"

  
  
//  #include "Farben.h"
byte helligkeit=0;
bool Energiesparmodus;
//-------------------------Pins-------------------------------------------

#define PinSensor 0
#define PinSourceselect 22
#define PinRinge 2
#define PinStreifen0 0
#define PinStreifen1 1
#define PinMatrix0 6
#define PinMatrix1 5
#define PinSchalter 10

//inits
void initBecher();
void initButton();
void initMatrix();
void initStreifen();

//Einlesen
void SensorEinlesen();
void ButtonEinlesen();

//bool zustandBecher[AnzahlSensor];
void aktAnzeige(byte Anzahlbecher, MatrixClass Matrix);
void aktSpielstand();
void aktRinge();

//Ausgeben

byte Becher0;                    //linke Seite
byte Becher0davor = 0;
byte Becher1;                    //rechte Seite
byte Becher1davor = 0;

BecherClass Becher[AnzahlSensor];
ButtonClass EnergieButton;
MatrixClass AnzeigeMatrix0;
MatrixClass AnzeigeMatrix1;
StreifenClass Streifen0;
StreifenClass Streifen1;

//-------------------------Setup-------------------------------------------

void setup()
{
 //   Serial.begin(115200);
   
    //Sensoren+Ringe Initialisieren
    initBecher();

    //Stripes initialisieren


    //Buttons Initialisieren
    initButton();
        
    //Anzeige Initialisieren
    initMatrix();     
}


//-------------------------Loop-------------------------------------------

void loop()
{
    //button einlesen
    ButtonEinlesen();
    if (Energiesparmodus == true) {
        helligkeit = 10;
    }
    else {
        helligkeit = 50;
    }

    //Sensoren einlesen
    SensorEinlesen();
 
    // Spielstand aktualisieren
    aktSpielstand();        
    
  


    aktAnzeige(Becher0, AnzeigeMatrix0);
    aktAnzeige(Becher1, AnzeigeMatrix1);

    if (Becher0 < Becher0davor) {               //wenn Becher weniger als davor
                  
        Streifen0.treffer();                    //led einmal halbe runde
        aktRinge();                             //bei hälfte becher ring aktualisieren
        Streifen0.treffer();                    //runde zu ende
    }
    if (Becher1 < Becher1davor) {
        Streifen1.treffer();                    //led einmal halbe runde
        aktRinge();                             //bei hälfte becher ring aktualisieren
        Streifen1.treffer();                    //runde zu ende
    }


    aktRinge();


    Becher0davor = Becher0;
    Becher1davor = Becher1;
    delay(1000);
}


//-------------------------Einlesen---------------------------------------

void SensorEinlesen(){

    for (byte i = 0; i < AnzahlSensor; i++) {
       /* zustandBecher[i] =*/ Becher[i].SensorLesen();
    }
}

void ButtonEinlesen(){
    Energiesparmodus = EnergieButton.lesen();
}


//-------------------------Aktualisieren-----------------------------------

void aktRinge(){
    for (byte i = 0; i < AnzahlSensor;i++) {
        Becher[i].aktFarbe(helligkeit);
    }

}

void aktSpielstand(){
    int n = 0;
    Becher0 = 0;
    Becher1 = 0;

    for (byte i = 0; i < AnzahlMP; i++) {
        for (byte m = 0; m < AnzahlProMP; m++) {
            if (Becher[n].getStatus() == true) {
                if (i == 0) {
                    Becher0++;
                }
                if (i == 1) {
                    Becher1++;
                }                
            }
            
            n++;
        }
        
    }
}

void aktAnzeige(byte Anzahlbecher, MatrixClass Matrix){
 
    Matrix.aktMatrix(Anzahlbecher,helligkeit);
   
}


//-------------------------Inits------------------------------------------

void initBecher() {
    //int komp = 0;
    byte BecherID = 0;
    for (byte Imp = 0; Imp < AnzahlMP; Imp++) {              //alle multiplexer durchgehen
     
        byte LEDID = 0;

        for (byte Ie; Ie < AnzahlProMP; Ie++) {              //alle eing�nge eines MP durchgehen

            Becher[BecherID].init(Imp, Ie, BecherID, LEDID, PinSourceselect, PinSensor, PinRinge);
            LEDID = LEDID + 12;                             //Start id halben kreis weiterschieben
            BecherID++;

            if ((BecherID == 7)|| (BecherID == 12)||(BecherID == 15)) {           //Bei neuer reihe extra weiterschieben
                LEDID = LEDID + 12;
            }
        }
    }
    
    Becher[BecherID].init(3,0,AnzahlSensor-2,0, PinSourceselect, PinSensor, PinRinge);

    BecherID++;
    Becher[BecherID].init(4,0,AnzahlSensor-1,24, PinSourceselect, PinSensor, PinRinge);

}

void initButton(){
  EnergieButton.init(PinSchalter);
}

void initMatrix() {
    AnzeigeMatrix0.init(PinMatrix0, 0);
    AnzeigeMatrix1.init(PinMatrix1, 1);
}

void initStreifen() {
    Streifen0.init(PinStreifen0,0);
    Streifen1.init(PinStreifen1,1);
}
