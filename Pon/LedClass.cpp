//#ifndef _LedClass_h
//#define _LedClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "LedClass.h"

void LedClass::Init(byte pin, int Anzahl, byte team) {
	
    this->Pin = pin;
    this->Team = team;
    pinMode(Pin, OUTPUT);
        
    if (Team == 0) {
        ColourTeam = ColourTeam0;
    }
    if (Team == 1) {
        ColourTeam = ColourTeam1;
    }
    LEDs = new Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);        
    LEDs->setPixelColor(0, LEDs->Color(0, 255, 0));       
    LEDs->begin();    
    LEDs->show();       
}

void LedClass::setPixels(byte startid, byte laenge, uint32_t Colour) {

    for (int i = 0; i < laenge; i++) {
        setPixel(startid + i, Colour);

        if (laenge > AnzahllehreLEDs) {
            if (EnergieModus == true) {
                for (int j = i + 1; j < (i + AnzahllehreLEDs + 1); j++) {
                    setPixel(startid + j, Colourout);

                }
                i = i + AnzahllehreLEDs;
            }
        }
    }

}


void LedClass::setPixel(byte id, uint32_t Colour) {
   
    LEDs->setPixelColor(id, Colour);
    LEDs->setBrightness(Helligkeit);
    LEDs->show();           
}


void LedClass::setPixelsRot(byte startid, byte laenge) {
    
    setPixels(startid, laenge, Colourrot);
}


void LedClass::setPixelsGruen(byte startid, byte laenge) {
    
    setPixels(startid, laenge, Colourgruen);
}


void LedClass::setPixelsTeam(byte startid, byte laenge){
    
    setPixels(startid, laenge, ColourTeam);
}

void LedClass::setPixelsOut(byte startid, byte laenge) {

    setPixels(startid, laenge, Colourout);
}

void LedClass::setModus(int hel, bool sparmodus){
    Helligkeit = hel;
    EnergieModus = sparmodus;   
    LEDs->setBrightness(hel);
    LEDs->show();
}

void LedClass::setBrightness(int hel){
    LEDs->setBrightness(hel);
    LEDs->show();
}

void LedClass::RunningLights(int anzahlled) {
    for(int i = 0; i < 100; i++){
        int Position = 0;

        for (int j = 0; j < anzahlled * 2; j++)
        {
            Position++; // = 0; //Position + Rate;
            for (int i = 0; i < anzahlled; i++) {
                // sine wave, 3 offset waves make a rainbow!
                //float level = sin(i+Position) * 127 + 128;
                //setPixel(i,level,0,0);
                //float level = sin(i+Position) * 127 + 128;
                LEDs->setPixelColor(i, ((sin(i + Position) * 127 + 128) / 255) * 100,
                    ((sin(i + Position) * 127 + 128) / 255) * 100,
                    ((sin(i + Position) * 127 + 128) / 255) * 100);
            }

            LEDs->show();
            delay(100);
    
        }
    }
}

void LedClass::changeTeam(bit newTeam){
    Team = newTeam;
}
}
