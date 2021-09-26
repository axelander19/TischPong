#include "BecherClass.h"
#include "SensorClass.h"
#include "ButtonClass.h"

#define AnzahlButton 2


//inits
void initSensor();
void initLED();
void initButton();

//Einlesen
void SensorEinlesen();
void ButtonEinlesen();

bool zustandBecher[AnzahlSensor];
int LedRingID[AnzahlRinge][AnzahlLEDproRing];
void aktAnzeige();

//Ausgeben

void ringeAktualisieren();


BecherClass Becher[AnzahlRinge];
SensorClass Sensoren[AnzahlSensor];
ButtonClass StartButton;
ButtonClass ResetButton;


int PinStartButton = 2;
int PinResetButton = 3;

void setup()
{
    Serial.begin(115200);
    
    int SensorPins[] = {0,1,2,3};       //ersten zwei sind Multiplexer
    int SourceselectPins[] = {0,1,2,3,4,5,6,7};
    int MPPins[] = {0,1};          //Multiplexer auf analoge eing�nge ab 0 stecken
                              
    //Sensoren Initialisieren
    initSensor();

    
    //Kreise initialisieren

    //Stripes initialisieren

    //Buttons Initialisieren
    initButton();

    initLED();
}



// Add the main program code into the continuous loop() function
void loop()
{

    //Sensoren einlesen
    SensorEinlesen();
    //button einlesen
    //ringeAktualisieren();
                Becher[0].rot();
    aktAnzeige();

        //ringe nächte led höher

 


           
  delay(1000);
}



void SensorEinlesen(){

    for (int i = 0; i < AnzahlSensor; i++) {
        zustandBecher[i] = Sensoren[i].SensorLesen();
    }
}

void ButtonEinlesen(){
  
}

void ringeAktualisieren(){
    for (int i = 0; i < AnzahlRinge; i++) {
        if (zustandBecher == true) {
//            Becher[i]->rot;
        }
}}



void aktAnzeige(){
int a;
}

void initLED(){
    for(int m=0; m<(AnzahlLEDproRing*AnzahlRinge); m++)
    for (int i = 0; i < AnzahlRinge; i++) {
        for (int n = 0; n++; n < AnzahlLEDproRing) {
            LedRingID[i][n]=m;
        }
    }
}

void initSensor() {
    int i = 0;
    for (int Imp = 0; Imp < AnzahlMP; Imp++) {              //alle multiplexer durchgehen
        pinMode(Imp, INPUT);
        for (int Ie; Ie < AnzahlProMP; Ie++) {              //alle eing�nge eines MP durchgehen
            Sensoren[i].init(Imp, Ie, i);
            i++;
        }
    }
    Sensoren[i].init(0,0,AnzahlSensor-1);
    i++;
    Sensoren[i].init(0,0,AnzahlSensor-2);
}

void initButton(){
  StartButton.init(PinStartButton);
  ResetButton.init(PinResetButton);
}
