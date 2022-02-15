#include "ButtonClass.h"
#include "MatrixClass.h"
#include "StreifenClass.h"
#include "BecherClass.h"
#include "UnterBodenClass.h"
#include "PotiClass.h"


//-------------------------Pins-------------------------------------------

#define PinSensoren0 A0
#define PinSensoren1 A1

#define PinSourceselect0 47
#define PinSourceselect1 39
#define PinRinge0 3
#define PinRinge1 4

#define PinStreifen0 10
#define PinStreifen1 11

#define PinStreifenUnten0 
#define PinStreifenUnten1 
#define PinStreifenUnten 34

#define PinMatrix0 8
#define PinMatrix1 9

#define PinSparmodus 42
#define PinPoti A5

//--------------------------------------------------------------------------

#define NormaleHelligkeit 50
#define SparmodusHelligkeit 5

byte grundHelligkeit;
byte helligkeit;
bool Energiesparmodus = false;
bool Energiesparmodusbevore = true;
float faktor = 0;
float faktorBevore = 0;

#define AnzahlPositionen 11


//inits
void initButtons();
void initMatrix();
void initStreifen();

//Einlesen
void ButtonsEinlesen();

//bool zustandBecher[AnzahlSensor];
void aktSpielstand();
void aktRinge();
void aktModus();

//void StreifenTreffer();

byte BecherCount0 = 0;                    //linke Seite
byte Becher0davor = 0;
byte BecherCount1 = 0;                    //rechte Seite
byte Becher1davor = 0;

ButtonClass EnergieButton;
PotiClass Poti;

BecherClass Becher0;
BecherClass Becher1;

MatrixClass AnzeigeMatrix0;
MatrixClass AnzeigeMatrix1;

StreifenClass Streifen0;
StreifenClass Streifen1;

UnterBodenClass StreifenUnten;
//UnterBodenClass Streifen0Unten;
//UnterBodenClass Streifen1Unten;

//Adafruit_NeoPixel testledmatrix;
//Adafruit_NeoPixel testledring;


int temp = 0;
//-------------------------Setup-------------------------------------------

void setup()
{
    //Wire.begin();        // join i2c bus (address optional for master)

    Serial.begin(9600);

    //Buttons Initialisieren
    initButtons();

    //Sensoren+Ringe Initialisieren
    initBecher();
    
    //Stripes initialisieren
    initStreifen();
        
    //Anzeige Initialisieren
    initMatrix(); 

 }

//-------------------------Loop-------------------------------------------
void loop()
{
    Serial.println("main");

    //----------------------------------//
    ButtonsEinlesen();                   //
                                        //--Stromsparmodus                    Hellikeit und status energiesparen wird an klassen gegeben        AUF ÄNDERUNG BASIEREND ALLE LEEDS UPDATEN
    aktModus();                         //                                 
    //----------------------------------//
    

        // Sensoren einlesen
    Becher0.ReadSensor();
    Becher1.ReadSensor();

        // Spielstand aktualisieren
    aktSpielstand();                            //Bechercounts werden berrechnet
      
    delay(10);
  
    if (Becher0davor != BecherCount0) {
        AnzeigeMatrix0.aktMatrix(BecherCount0);
    }
    if (Becher0davor != BecherCount1) {
     //   AnzeigeMatrix1.aktMatrix(BecherCount1);
    }
    delay(10);


    if (BecherCount0 < Becher0davor) {               //wenn Becher weniger als davor
                 
        Streifen0.treffer();
        //led einmal halbe runde
        aktRinge();                             //bei hälfte becher ring aktualisieren
        
        StreifenUnten.treffer(0);                   //evtl immer in der gewinnerteamfarbe           -        kurz azfflackern wenn getroffen   evtl wenn ring aktualisiert wird
        Streifen0.treffer();                    //runde zu ende
    }
    if (BecherCount1 < Becher1davor) {
        //Streifen1.treffer();                    //led einmal halbe runde
        //aktRinge();                             //bei hälfte becher ring aktualisieren
        //Streifen1.treffer();                    //runde zu ende
        //StreifenUnten.treffer(1);
    }

    //Becher0.setStatus(true, temp);
    //Becher0.setStatus(false, temp-1);
    aktRinge();


   
    delay(10);
}


//-------------------------Einlesen---------------------------------------


void ButtonsEinlesen(){
    Energiesparmodusbevore = Energiesparmodus;
    Energiesparmodus = EnergieButton.lesen();
    faktorBevore = faktor;
    faktor = Poti.lesen();
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
    

    for (byte i = 0; i < /*AnzahlPositionen-1*/2; i++) {  
        if ((Becher0.getStatus(i)) == true) {
            BecherCount0++;

        }
        if (Becher1.getStatus(i) == true) {
            BecherCount1++;

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

    if (faktor != faktorBevore) {
        helligkeit = grundHelligkeit * faktor;
        
        AnzeigeMatrix0.setBrightness(helligkeit);
        AnzeigeMatrix1.setBrightness(helligkeit);
        Becher0.setBrightness(helligkeit);
        Becher1.setBrightness(helligkeit);
        Streifen0.setBrightness(helligkeit);
        Streifen1.setBrightness(helligkeit);
    }


    if (Energiesparmodus != Energiesparmodusbevore) {
        if (Energiesparmodus == true) {
            grundHelligkeit = SparmodusHelligkeit;
        }
        if (Energiesparmodus == false) {
            grundHelligkeit = NormaleHelligkeit;
        }
        helligkeit = grundHelligkeit * faktor;
        AnzeigeMatrix0.setModus(helligkeit, Energiesparmodus);
        //AnzeigeMatrix1.setModus(helligkeit, Energiesparmodus);
        Becher0.setModus(helligkeit, Energiesparmodus);
        //Becher1.setModus(helligkeit, Energiesparmodus);
        Streifen0.setModus(helligkeit, Energiesparmodus);
        //Streifen1.setModus(helligkeit, Energiesparmodus);
  
    }
}

//-------------------------Inits------------------------------------------

void initButtons(){
  EnergieButton.init(PinSparmodus);
  Poti.init(PinPoti);
}

void initMatrix() {
    AnzeigeMatrix0.init(PinMatrix0, 0);
    //AnzeigeMatrix1.init(PinMatrix1, 1);
}

void initStreifen() {
    Streifen0.init(PinStreifen0, 0);
    //Streifen0Unten.init(PinStreifenUnten0, 0);
    //Streifen1.init(PinStreifen1, 1);
    StreifenUnten.init(PinStreifenUnten, 0);
}

void initBecher() {
    Becher0.init(0, PinRinge0, PinSensoren0, PinSourceselect0, 2);
    //Becher1.init(1, PinRinge1, PinSensoren1, PinSourceselect1, 3);
}
