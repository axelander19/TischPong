#include "RingClass.h"
#include "BecherClass.h"
#include "ButtonClass.h"
#include "MatrixClass.h"

#define AnzahlButton 2


int PinStartButton = 2;
int PinResetButton = 3;
int PinMatrix = 4;


//inits
void initBecher();
void initRing();
void initButton();
void initMatrix();

//Einlesen
void SensorEinlesen();
void ButtonEinlesen();

bool zustandBecher[AnzahlSensor];
int LedRingID[AnzahlRinge][AnzahlLEDproRing];
void aktAnzeige();
void aktSpielstand();

//Ausgeben

void aktRinge();
int BecherA;                    //linke Seite
int BecherB;                    //rechte Seite

RingClass Ringe[AnzahlRinge];
BecherClass Becher[AnzahlSensor];
ButtonClass StartButton;
ButtonClass ResetButton;
MatrixClass AnzeigeMatrixA;
MatrixClass AnzeigeMatrixB;
MatrixClass AnzeigeMatrixMitte;

void setup()
{
    Serial.begin(115200);
    
    int SensorPins[] = {0,1,2,3};       //ersten zwei sind Multiplexer
    int SourceselectPins[] = {0,1,2,3,4,5,6,7};


    //Sensoren Initialisieren
    initBecher();

    
    //Kreise initialisieren

    //Stripes initialisieren

    //Buttons Initialisieren
    initButton();

    initRing();

    initMatrix();
}



// Add the main program code into the continuous loop() function
void loop()
{

    //Sensoren einlesen
    SensorEinlesen();
    //button einlesen
    // 
    // Spielstand aktualisieren
    aktSpielstand();        //done
    // 
    //ringeAktualisieren();
               


    aktAnzeige();

        //ringe nächte led höher

 

   
           
  delay(1000);
}



void SensorEinlesen(){

    for (int i = 0; i < AnzahlSensor; i++) {
        zustandBecher[i] = Becher[i].SensorLesen();
    }
}

void ButtonEinlesen(){
  
}

void aktRinge(){
    for (int i = 0; i < AnzahlRinge; i++) {
        if (zustandBecher[i] = true) {
//            Becher[i]->rot;
        }
}}

void aktSpielstand(){
    int n = 0;
    BecherA = 0;
    BecherB = 0;

    for (int i = 0; i < AnzahlMP; i++) {
        for (int m; m < AnzahlProMP; m++) {
            if (Becher[n].getStatus() == true) {
                if (i == 0) {
                    BecherA++;
                }
                if (i == 1) {
                    BecherB++;
                }                
            }
            
            n++;
        }
        
    }
}

void aktAnzeige(){

}

void initRing() {
/*    for (int m = 0; m<(AnzahlLEDproRing * AnzahlRinge); m++)
    for (int i = 0; i < AnzahlRinge; i++) {
        for (int n = 0; n++; n < AnzahlLEDproRing) {
            LedRingID[i][n]=m;
        }
    }*/
    for (int i = 0; i < AnzahlRinge; i++) {
        Ringe[i].init();
    }
}

void initBecher() {
    int komp = 0;
    int BecherID = 0;
    for (int Imp = 0; Imp < AnzahlMP; Imp++) {              //alle multiplexer durchgehen
        pinMode(firstMPPin+Imp, INPUT);
        pinMode(firstRingPin+Imp, OUTPUT);
        int LEDID = 0;

        for (int Ie; Ie < AnzahlProMP; Ie++) {              //alle eing�nge eines MP durchgehen

            Becher[BecherID].init(Imp, Ie, BecherID, LEDID);
            LEDID = LEDID + 12;                             //Start id halben kreis weiterschieben
            BecherID++;

            if ((BecherID == 7)|| (BecherID == 12)||(BecherID == 15)) {           //Bei neuer reihe extra weiterschieben
                LEDID = LEDID + 12;
            }
        }
    }
    
    Becher[BecherID].init(0,0,AnzahlSensor-2,0);
    pinMode(firstMPPin + 2, INPUT);
    pinMode(firstRingPin + 2, OUTPUT);
    BecherID++;
    Becher[BecherID].init(0,0,AnzahlSensor-1,24);
   
}

void initButton(){
  StartButton.init(PinStartButton);
  ResetButton.init(PinResetButton);
}

void initMatrix() {
    pinMode(PinMatrix, OUTPUT);

    AnzeigeMatrixA.init(PinMatrix, 0);
    AnzeigeMatrixB.init(PinMatrix, 144);
    AnzeigeMatrixMitte.init(PinMatrix, 80);

    AnzeigeMatrixMitte.strich();
}
