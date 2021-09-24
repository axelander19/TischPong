#include "BecherClass.h"
#include "SensorClass.h"
#include "ButtonClass.h"

#define AnzahlButton 2

int SensorPins[AnzahlSensor-(AnzahlMP*AnzahlProMP)+AnzahlMP] = { 0,1,2,3};

//inits
void initSensor();
void initLED();
void initButton();

void SensorEinlesen();
void Buttoneinlesen();

bool zustandBecher[AnzahlSensor];
int LedID[AnzahlRinge][AnzahlLEDproRing];
void aktAnzeige();


void ringeAktualisieren();
int MPArray[AnzahlMP][AnzahlProMP];


BecherClass Becher[AnzahlRinge];
SensorClass Sensoren[AnzahlSensor];
ButtonClass StartButton;
ButtonClass ResetButton;

    
/*   for(int i=0; i++; i<AnzahlSensor){
    SensorClass * Sensoren[AnzahlSensor];
    Sensoren[i] = new SensorClass();
}*/
int PinStartButton = 2;
int PinResetButton = 3;

void setup()
{
Serial.begin(115200);

int SourceselectPins[AnzahlMP * AnzahlSelectMP] = {0,1,2,3,4,5,6,7};
int MPPins[AnzahlMP] = { 0,1 };          //Multiplexer auf analoge eing�nge ab 0 stecken

                                            
                                            /*
for(int i=0; i++; i<AnzahlSensor){
    Becher[i] = new BecherClass();
}*/

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

        //

 


           
  delay(1000);
}



void SensorEinlesen(){

    for (int i = 0; i++; i < AnzahlSensor) {   
        zustandBecher[i] = Sensoren[i].SensorLesen();
    }
}

void ButtonEinlesen(){
  
}

void ringeAktualisieren(){
    for (int i = 0; i++; i < AnzahlRinge) {
        if (zustandBecher == true) {
//            Becher[i]->rot;
        }
}}



void aktAnzeige(){
int a;
}

void initLED(){
    for(int m=0; m++; m<(AnzahlLEDproRing*AnzahlRinge))
    for (int i = 0; i < AnzahlRinge; i++) {
        for (int n = 0; n++; n < AnzahlLEDproRing) {
            LedID[i][n]=m;
        }
    }
}

void initSensor() {
    int i = 0;
    for (int Imp = 0; Imp++; Imp < AnzahlMP) {              //alle multiplexer durchgehen
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
