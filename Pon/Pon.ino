#include "ButtonClass.h"
#include "MatrixClass.h"
#include "StreifenClass.h"
#include "BecherClass.h"




//-------------------------Pins-------------------------------------------

#define PinSensoren0 A0
#define PinSensoren1 A1

#define PinSourceselect0 8
#define PinSourceselect1 30
#define PinRinge0 3
#define PinRinge1 10

#define PinStreifen0 12
#define PinStreifen1 1
#define PinMatrix0 6
#define PinMatrix1 9
#define PinSchalter 51

#define NormaleHelligkeit 50
#define SparmodusHelligkeit 10

byte helligkeit;
bool Energiesparmodus = false;

#define AnzahlPositionen 16


//inits
void initButton();
void initMatrix();
void initStreifen();

//Einlesen
void ButtonEinlesen();

//bool zustandBecher[AnzahlSensor];
void aktSpielstand();
void aktRinge();
void aktModus();



byte BecherCount0 = 0;                    //linke Seite
byte Becher0davor = 0;
byte BecherCount1 = 0;                    //rechte Seite
byte Becher1davor = 0;


BecherClass Becher0;
BecherClass Becher1;
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
   Becher0.init(0, PinRinge0, PinSensoren0, PinSourceselect0, 2);
   //Becher1.init(1, PinRinge1, PinSensoren1, PinSourceselect1, 3);

//    Stripes initialisieren
//initStreifen();
       //Buttons Initialisieren
   initButton();
        
    //Anzeige Initialisieren
    initMatrix(); 
 }

//-------------------------Loop-------------------------------------------

void loop()
{
    Serial.println("main");

    //----------------------------------//
    ButtonEinlesen();                 //
                                        //--Stromsparmodus                    Hellikeit und status energiesparen wird an klassen gegeben        AUF ÄNDERUNG BASIEREND ALLE LEEDS UPDATEN
    aktModus();                         //                                 
    //----------------------------------//
    

        // Sensoren einlesen
    Becher0.ReadSensor();
    Becher1.ReadSensor();

        // Spielstand aktualisieren
    aktSpielstand();                            //Bechercounts werden berrechnet
      
    Serial.println(BecherCount0);
    //Serial.println(BecherCount1);
    delay(10);
  
    if (Becher0davor != BecherCount0) {
        AnzeigeMatrix0.aktMatrix(BecherCount0);
    }
    if (Becher0davor != BecherCount1) {
     //   AnzeigeMatrix1.aktMatrix(BecherCount1);
    }
    delay(10);


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

    //Becher0.setStatus(true, temp);
    //Becher0.setStatus(false, temp-1);
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
    delay(10);
}


//-------------------------Einlesen---------------------------------------


void ButtonEinlesen(){
    Energiesparmodus = EnergieButton.lesen();
}


//-------------------------Aktualisieren-----------------------------------

void aktRinge(){
    Becher0.AktRinge();
   // Becher1.AktRinge();

}

void aktSpielstand(){
    Becher0davor = BecherCount0;
    Becher1davor = BecherCount1;

    BecherCount0 = 0;
    BecherCount1 = 0;
    Serial.println(BecherCount0);
    Serial.println(BecherCount1);

    for (byte i = 0; i < /*AnzahlPositionen*/2; i++) {  
        if ((Becher0.getStatus(i)) == true) {
            BecherCount0++;
            Serial.println(BecherCount0);

        }
        if (Becher1.getStatus(i) == true) {
            BecherCount1++;
            Serial.println(BecherCount1);

        }
    }
    if (BecherCount0 > 10) {
        BecherCount0 = 0;
    }
    if (BecherCount1 > 10) {
        BecherCount1 = 0;
    }
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

void initButton(){
  EnergieButton.init(PinSchalter);
}

void initMatrix() {
    AnzeigeMatrix0.init(PinMatrix0, 0, 0);
    AnzeigeMatrix1.init(PinMatrix1, 1, 1);
}

void initStreifen() {
   // Streifen0.init(PinStreifen0, 0, 4);
   // Streifen1.init(PinStreifen1, 1, 5);
}
