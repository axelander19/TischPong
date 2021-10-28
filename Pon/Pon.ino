#include "ButtonClass.h"
#include "MatrixClass.h"
#include "StreifenClass.h"
//#include "leds.h"
#include "BecherClass.h"
#include <Wire.h>


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

#define NormaleHelligkeit 100
#define SparmodusHelligkeit 10

#define AnzahlPositionen 15


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
void aktSpielstand();
void aktRinge();
void aktModus();

//Ausgeben

byte BecherCount0=0;                    //linke Seite
byte Becher0davor = 0;
byte BecherCount1;                    //rechte Seite
byte Becher1davor = 0;

//GlassClass Becher[AnzahlSensor];
BecherClass Becher0(0, PinRinge0, PinSensoren0);
//BecherClass Becher0;
//BecherClass Becher1;
BecherClass Becher1(0, PinRinge0, PinSensoren0);
ButtonClass EnergieButton;
MatrixClass AnzeigeMatrix0;
MatrixClass AnzeigeMatrix1;
StreifenClass Streifen1;
StreifenClass Streifen0;

int temp = 0;
//-------------------------Setup-------------------------------------------

void setup()
{
   //Wire.begin();        // join i2c bus (address optional for master)

   Serial.begin(9600);
  // Serial.println(F("Start"));
    //Sensoren+Ringe Initialisieren
    //initBecher();
  // Becher0.init(0, PinRinge0, PinSensoren0);
//    Stripes initialisieren
//initStreifen();

    //Buttons Initialisieren
   //initButton();
        
    //Anzeige Initialisieren
  //  initMatrix(); 

}


//-------------------------Loop-------------------------------------------

void loop()
{
    //----------------------------------//
    ButtonEinlesen();                   //
                                        //--Stromsparmodus                    Hellikeit und status energiesparen wird an klassen gegeben
    aktModus();                         //                                 
    //----------------------------------//
    

        // Sensoren einlesen
    SensorEinlesen();

        // Spielstand aktualisieren
    aktSpielstand();  
      
      
  



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

Becher0.setStatus(true, 1);
    Becher0.setStatus(true, 0);

    if (temp == 1) {
        temp = 0;
    }
    aktRinge();
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

void SensorEinlesen(){
    
    Becher0.ReadSensor();
    Becher1.ReadSensor();

}

void ButtonEinlesen(){
    Energiesparmodus = EnergieButton.lesen();
}


//-------------------------Aktualisieren-----------------------------------

void aktRinge(){
    Becher0.AktRinge();
    //Becher1.AktRinge();

}

void aktSpielstand(){
    BecherCount0 = 0;
    BecherCount1 = 0;
   
    for (byte i = 0; i < AnzahlPositionen; i++) {  
        if (Becher0.getStatus(i) == true) {
            BecherCount0++;
        }
        if (Becher1.getStatus(i) == true) {
            BecherCount1++;
        }
    }
}

void aktAnzeige(byte Anzahlbecher, MatrixClass Matrix){
 
    Matrix.aktMatrix(Anzahlbecher,helligkeit);
   
}

void aktModus() {                                           //Sparmodus

    if (Energiesparmodus == true) {
        helligkeit = SparmodusHelligkeit;
    }
    else {
        helligkeit = NormaleHelligkeit;
    }
    Becher0.setModus(helligkeit, Energiesparmodus);
    Becher1.setModus(helligkeit, Energiesparmodus);
    Streifen0.setModus(helligkeit, Energiesparmodus);
    Streifen1.setModus(helligkeit, Energiesparmodus);
    AnzeigeMatrix0.setModus(helligkeit, Energiesparmodus);
    AnzeigeMatrix1.setModus(helligkeit, Energiesparmodus);

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
