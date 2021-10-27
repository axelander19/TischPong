#include "ButtonClass.h"
#include "MatrixClass.h"
#include "StreifenClass.h"
//#include "leds.h"
#include "BecherClass.h"
  
//  #include "Farben.h"
byte helligkeit=10;
bool Energiesparmodus=false;
//-------------------------Pins-------------------------------------------

#define PinSensoren0 0
#define PinSourceselect 22
#define PinRinge0 10
#define PinStreifen0 12
#define PinStreifen1 1
#define PinMatrix0 6
#define PinMatrix1 9
#define PinSchalter 1


//RingLeds.setPixelColor(0, RingLeds.Color(0, 255, 0));

//RingLeds.begin();
//LEDPixel.setBrightness(10);
//RingLeds.show();

//inits
//void initBecher();
void initButton();
void initMatrix();
void initStreifen();

//Einlesen
//void SensorEinlesen();
void ButtonEinlesen();

//bool zustandBecher[AnzahlSensor];
void aktAnzeige(byte Anzahlbecher, MatrixClass Matrix);
//void aktSpielstand();
//void aktRinge();

//Ausgeben

byte BecherCount0=0;                    //linke Seite
byte Becher0davor = 0;
byte BecherCount1;                    //rechte Seite
byte Becher1davor = 0;

//GlassClass Becher[AnzahlSensor];
//BecherClass Becher0(0, PinRinge0, PinSensoren0);
BecherClass Becher0;

ButtonClass EnergieButton;
MatrixClass AnzeigeMatrix0;
MatrixClass AnzeigeMatrix1;
StreifenClass Streifen1;
StreifenClass Streifen0;

int temp = 0;
//-------------------------Setup-------------------------------------------

void setup()
{
   Serial.begin(9600);
  // Serial.println(F("Start"));
    //Sensoren+Ringe Initialisieren
    //initBecher();
   Becher0.init(0, PinRinge0, PinSensoren0);
//    Stripes initialisieren
//initStreifen();

    //Buttons Initialisieren
   //initButton();
        
    //Anzeige Initialisieren
  //  initMatrix(); 
   //RingLeds.begin();

}


//-------------------------Loop-------------------------------------------

void loop()
{
    //button einlesen
    /*
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
   // aktSpielstand();  
      
  */    
  
   // RingLeds.setPixelColor(0, RingLeds.Color(0, 255, 0));



   // aktAnzeige(Becher1, AnzeigeMatrix1);
    //aktAnzeige(Becher0, AnzeigeMatrix0);

   /* if (Becher0 < Becher0davor) {               //wenn Becher weniger als davor
                  
        Streifen0.treffer();                    //led einmal halbe runde
        //aktRinge();                             //bei hälfte becher ring aktualisieren
        Streifen0.treffer();                    //runde zu ende
    }
    if (Becher1 < Becher1davor) {
        Streifen1.treffer();                    //led einmal halbe runde
        //aktRinge();                             //bei hälfte becher ring aktualisieren
        Streifen1.treffer();                    //runde zu ende
    }*/
  Serial.print("main");
    Becher0.ReadSensor();
Becher0.setStatus(true, 1);
    Becher0.setStatus(true, 0);

    Becher0.AktRinge();
    if (temp == 1) {
        temp = 0;
    }
    //aktRinge();
    /*
    if(BecherCount0 ==11){
      BecherCount0=0;
      BecherCount1=0;
    }
BecherCount0++;
BecherCount1++;
if (Becher[0].getStatus() == true) {
    Becher[0].setStatus(false);
}
else { Becher[0].setStatus(true); }
Becher[1].setStatus(false);
    
    Becher0davor = BecherCount0;
    Becher1davor = BecherCount1;*/
    delay(1000);
}


//-------------------------Einlesen---------------------------------------
/*
void SensorEinlesen(){

    for (byte i = 0; i < AnzahlSensor; i++) {
        zustandBecher[i] = Becher[i].SensorLesen();
    }
}
*/
void ButtonEinlesen(){
    Energiesparmodus = EnergieButton.lesen();
}


//-------------------------Aktualisieren-----------------------------------

/*void aktRinge(){
    for (byte i = 0; i < AnzahlSensor;i++) {
      //Serial.println("aktRing");
        Becher[i].aktFarbe(helligkeit);
        delay(0);
    }

}*/
/*
void aktSpielstand(){
    int n = 0;
    BecherCount0 = 0;
    BecherCount1 = 0;

    for (byte i = 0; i < AnzahlMP; i++) {
        for (byte m = 0; m < AnzahlProMP; m++) {
            if (Becher[n].getStatus() == true) {
                if (i == 0) {
                    BecherCount0++;
                }
                if (i == 1) {
                    BecherCount1++;
                }                
            }
            
            n++;
        }
        
    }
}*/

void aktAnzeige(byte Anzahlbecher, MatrixClass Matrix){
 
    Matrix.aktMatrix(Anzahlbecher,helligkeit);
   
}


//-------------------------Inits------------------------------------------
/*
void initBecher() {
    //int komp = 0;
    byte BecherID = 0;
    for (byte Imp = 0; Imp < AnzahlMP; Imp++) {              //alle multiplexer durchgehen
     
        byte LEDID = 0;

        for (byte Ie = 0; Ie < AnzahlProMP; Ie++) {              //alle eing�nge eines MP durchgehen
            Serial.println(PinRinge);
            

            Becher[BecherID].init(Imp, Ie, BecherID, LEDID, PinSourceselect, PinSensoren, PinRinge);
            LEDID = LEDID + 12;                             //Start id halben kreis weiterschieben
            BecherID++;

            if ((BecherID == 7)|| (BecherID == 12)||(BecherID == 15)) {           //Bei neuer reihe extra weiterschieben
                LEDID = LEDID + 12;
            }
        }
    }
    
    Becher[BecherID].init(3,0,AnzahlSensor-2,0, PinSourceselect, PinSensoren, PinRinge);

    BecherID++;
    Becher[BecherID].init(4,0,AnzahlSensor-1,24, PinSourceselect, PinSensoren, PinRinge);
}
*/
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
