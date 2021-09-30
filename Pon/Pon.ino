#include "BecherClass.h"
#include "ButtonClass.h"
#include "MatrixClass.h"
#include "StreifenClass.h"

#define AnzahlButton 2

//-------------------------Pins-------------------------------------------

int PinStartButton = 7;
int PinResetButton = 8;
int PinMatrix0 = 6;
int PinMatrix1 = 5;
int PinSensor = 0;
int PinSourceselect = 22;
int PinRinge = 2;
int PinStreifen0 = 0;
int PinStreifen1 = 1;

//inits
void initBecher();
void initButton();
void initMatrix();
void initStreifen();

//Einlesen
void SensorEinlesen();
void ButtonEinlesen();

bool zustandBecher[AnzahlSensor];
void aktAnzeige(int Seite, MatrixClass Matrix);
void aktSpielstand();

//Ausgeben

void aktRinge();
int Becher0;                    //linke Seite
int Becher1;                    //rechte Seite

BecherClass Becher[AnzahlSensor];
ButtonClass StartButton;
ButtonClass ResetButton;
MatrixClass AnzeigeMatrix0;
MatrixClass AnzeigeMatrix1;
StreifenClass Streifen0;
StreifenClass Streifen1;

//-------------------------Setup-------------------------------------------

void setup()
{
    Serial.begin(115200);
   
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

    //Sensoren einlesen
    SensorEinlesen();
    //button einlesen
    // 
    // Spielstand aktualisieren
    aktSpielstand();        //done
    // 
    //ringeAktualisieren();
               


    aktAnzeige(Becher0, AnzeigeMatrix0);
    aktAnzeige(Becher1, AnzeigeMatrix1);


    //led einmal eine runde
    //bei hälfte becher ring aktualisieren


        //ringe nächte led höher

 

   
           
  delay(1000);
}


//-------------------------Einlesen---------------------------------------

void SensorEinlesen(){

    for (int i = 0; i < AnzahlSensor; i++) {
        zustandBecher[i] = Becher[i].SensorLesen();
    }
}

void ButtonEinlesen(){
  
}


//-------------------------Aktualisieren-----------------------------------

void aktRinge(){
 

}

void aktSpielstand(){
    int n = 0;
    Becher0 = 0;
    Becher1 = 0;

    for (int i = 0; i < AnzahlMP; i++) {
        for (int m; m < AnzahlProMP; m++) {
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

void aktAnzeige(int Seite, MatrixClass Matrix){
    switch (Seite)
    {
    case 0:
        Matrix.null();
    case 1:
        Matrix.eins();
    case 2:
        Matrix.zwei();
    case 3:
        Matrix.drei();
    case 4:
        Matrix.vier();
    case 5:
        Matrix.fuenf();
    case 6:
        Matrix.sechs();
    case 7:
        Matrix.sieben();
    case 8:
        Matrix.acht();
    case 9:
        Matrix.neun();
    case 10:
        Matrix.zehn();
    default:
        break;
    }
}


//-------------------------Inits------------------------------------------

void initBecher() {
    int komp = 0;
    int BecherID = 0;
    for (int Imp = 0; Imp < AnzahlMP; Imp++) {              //alle multiplexer durchgehen
     
        int LEDID = 0;

        for (int Ie; Ie < AnzahlProMP; Ie++) {              //alle eing�nge eines MP durchgehen

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
  StartButton.init(PinStartButton);
  ResetButton.init(PinResetButton);
}

void initMatrix() {
    pinMode(PinMatrix0, OUTPUT);
    pinMode(PinMatrix1, OUTPUT);

    AnzeigeMatrix0.init(PinMatrix1, 0);
    AnzeigeMatrix1.init(PinMatrix2, 0);

}

void initStreifen() {
    Streifen0.init(PinStreifen0);
    Streifen1.init(PinStreifen1);
}