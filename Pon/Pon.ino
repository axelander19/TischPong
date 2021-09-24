
#define AnzahlSensor 34
#define AnzahlRinge 22 
#define AnzahlLEDproRing 24
#define AnzahlMP 2
#define AnzahlProMP 16
#define AnzahlSelectMP 4
#define firstSelectPin 5
#define selectStartPin 0

#include "BecherClass.h"
#include "SensorCLass.h"

int SensorPins[AnzahlSensor-(AnzahlMP*AnzahlProMP)+AnzahlMP] = { 0,1,2,3};

//inits
void initSensor();
void initLED();

bool zustandBecher[AnzahlSensor];
int LedID[AnzahlRinge][AnzahlLEDproRing];
void aktAnzeige();
void einlesen();
void ringeAktualisieren();
int MPArray[AnzahlMP][AnzahlProMP];


BecherClass Becher[AnzahlRinge];
SensorClass Sensoren[AnzahlSensor];

    

    
/*   for(int i=0; i++; i<AnzahlSensor){
    SensorClass * Sensoren[AnzahlSensor];
    Sensoren[i] = new SensorClass();
}*/
  
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

    initLED();
}



// Add the main program code into the continuous loop() function
void loop()
{

    //Sensoren einlesen
    einlesen();
   
    //ringeAktualisieren();
                Becher[0].rot();
    aktAnzeige();

//Sensoren[0].SensorenLesen;
        //

        /*
        int sensor_1;
        int sensor_2;
        int sensor_3;
        int tischgewicht_1 = 0;
        int tischgewicht_2 = 0;
        int tischgewicht_3 = 0;
        int buttonPin = 12;
        boolean buttonPress;

        void setup() {
            pinMode(buttonPin, INPUT_PULLUP);
            Serial.begin(9600);
        }

        void loop() {
            buttonPress = digitalRead(buttonPin);
            if (buttonPress == 0) {
                tischgewicht();
            }
            sensor_1 = analogRead(A0) - tischgewicht_1;
            sensor_2 = analogRead(A1) - tischgewicht_2;
            sensor_3 = analogRead(A2) - tischgewicht_3;
            Serial.print("(");
            Serial.print(sensor_1);
            Serial.print("|");
            Serial.print(sensor_2);
            Serial.print("|");
            Serial.print(sensor_3);
            Serial.println(")");
        }
*/
}



void einlesen(){

    for (int i = 0; i++; i < AnzahlSensor) {
        zustandBecher[i] = Sensoren[i].SensorLesen();
    }
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
