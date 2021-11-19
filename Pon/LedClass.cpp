//#ifndef _LedClass_h
//#define _LedClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "LedClass.h"

void LedClass::Init(byte pin, int Anzahl, byte team, byte ledclassid) {
	
    this->Pin = pin;
    this->Team = team;
    pinMode(Pin, OUTPUT);

    switch (ledclassid)
    {
    case 0:
        Matrix0 = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
        Matrix0.setPixelColor(0, Matrix0.Color(0, 255, 0));
        Matrix0.begin();
        Matrix0.show();
        break;
    case 1:
        Matrix1 = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
        Matrix1.setPixelColor(0, Matrix1.Color(0, 255, 0));
        Matrix1.begin();
        Matrix1.show();
        break;
    case 2:
        Ring0 = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
        Ring0.setPixelColor(0, Ring0.Color(0, 255, 0));
        Ring0.begin();
        Ring0.show();
    break;
    case 3:
        Ring1 = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
        Ring1.setPixelColor(0, Ring1.Color(0, 255, 0));
        Ring1.begin();
        Ring1.show();
    break;
    case 4:
        Streifen0 = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
        Streifen0.setPixelColor(0, Streifen0.Color(0, 255, 0));
        Streifen0.begin();
        Streifen0.show();
    break;
    case 5:
        Streifen1 = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
        Streifen1.setPixelColor(0, Streifen1.Color(0, 255, 0));
        Streifen1.begin();
        Streifen1.show();
    break;
    default:
        break;
    }
    /*LEDPixel = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
    LEDPixel.setPixelColor(0, LEDPixel.Color(0, 255, 0));
    LEDPixel.begin();
    LEDPixel.show();*/

}



void LedClass::setPixel(byte id, byte ledclassid, int r, int g, int b) {
    switch (ledclassid)
    {
    case 0:
        Matrix0.setPin(6);
        Matrix0.setPixelColor(id, Matrix0.Color(r, g, b));
        Matrix0.setBrightness(Helligkeit);
        Matrix0.show();
        break;
    case 1:
        Matrix1.setPixelColor(id, Matrix1.Color(r, g, b));
        Matrix1.setBrightness(Helligkeit);
        Matrix1.show();
        break;
    case 2:
        Serial.print(LedClassId);
        Ring0.setPin(3);

        Ring0.setPixelColor(id, Ring0.Color(r, g, b));
        Ring0.setBrightness(Helligkeit);
        Ring0.show();
        break;
    case 3:
        Ring1.setPixelColor(id, Ring1.Color(r, g, b));
        Ring1.setBrightness(Helligkeit);
        Ring1.show();
        break;
    case 4:
        Streifen0.setPixelColor(id, Streifen0.Color(r, g, b));
        Streifen0.setBrightness(Helligkeit);
        Streifen0.show();
        break;
    case 5:
        Streifen0.setPin(Pin);
        Streifen1.setPixelColor(id, Streifen1.Color(r, g, b));
        Streifen1.setBrightness(Helligkeit);
        Streifen1.show();
        break;
    default:
        break;
    }
}



/*
void LedClass::setPixelRot(byte id, byte ledclassid) {
    LEDPixel.setPixelColor(id, LEDPixel.Color(255, 0, 0));
    LEDPixel.setBrightness(Helligkeit);
    LEDPixel.show();
}*/

void LedClass::setPixelsRot(byte startid, byte laenge, byte ledclassid) {

    for (int i = 0; i < laenge; i++) {
        setPixel(startid + i, ledclassid, 255, 0, 0);

        if (EnergieModus == true) {
            i = i + AnzahllehreLEDs;
        }
    }
}





/*
void LedClass::setPixelGruen(byte id, byte ledclassid) {
      
    LEDPixel.setPixelColor(id, LEDPixel.Color(0, 255, 0));
    LEDPixel.setBrightness(Helligkeit);
    LEDPixel.show();
}*/

void LedClass::setPixelsGruen(byte startid, byte laenge, byte ledclassid) {

    for (int i = 0; i < laenge; i++) {
        setPixel(startid + i, ledclassid, 0, 255, 0);

        if (EnergieModus == true) {
            i = i + AnzahllehreLEDs;
        }
    }
}








void LedClass::setPixelsTeam(byte startid, byte laenge, byte ledclassid) {

    for (byte i = 0; i < laenge; i++) {
        if (Team == 0) {
            setPixel(startid + i, ledclassid, 10, 10, 10);
        }

        if(Team == 1){
            setPixel(startid + i, ledclassid, 10, 0, 10);

        }
        
        if (EnergieModus == true) {
            i = i + AnzahllehreLEDs;
        }
    }
}
/*
void LedClass::setPixelTeam(byte id, byte ledclassid) {

    if (Team == 0) {
        LEDPixel.setPixelColor(id, LEDPixel.Color(10, 10, 10));
        LEDPixel.setBrightness(Helligkeit);
        LEDPixel.show();
    }

    if (Team == 1) {
        LEDPixel.setPixelColor(id, LEDPixel.Color(10, 0, 10));
        LEDPixel.setBrightness(Helligkeit);
        LEDPixel.show();
    }
}*/

void LedClass::setModus(int hel, bool sparmodus) {
    Helligkeit = hel;
    EnergieModus = sparmodus;
   // LEDPixel.setBrightness(Helligkeit);
   // LEDPixel.show();

}
