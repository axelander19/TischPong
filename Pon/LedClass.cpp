//#ifndef _LedClass_h
//#define _LedClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif





#include "LedClass.h"

/*
LedClass::LedClass(byte pin, byte Anzahl) {
    this->Pin = pin;
    pinMode(Pin, OUTPUT);
    Serial.println(pin);

    LEDPixel = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
    LEDPixel.setPixelColor(0, LEDPixel.Color(0, 255, 0));

    LEDPixel.begin();
    //LEDPixel.setBrightness(10);
    LEDPixel.show();
}
*/

void LedClass::Init(byte pin, byte Anzahl) {
	this->Pin = pin;
    pinMode(Pin, OUTPUT);
    Serial.println(pin);

    LEDPixel = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
    LEDPixel.setPixelColor(0, LEDPixel.Color(0, 255, 0));

    LEDPixel.begin();
    //LEDPixel.setBrightness(10);
     LEDPixel.show();

}

void LedClass::setPixelRot(byte id) {
    LEDPixel.setPixelColor(id, LEDPixel.Color(255, 0, 0));
  //  LEDPixel.begin();

}

void LedClass::setPixelsRot(byte startid, byte laenge) {
    for (int i = 0; i < laenge; i++) {
        setPixelRot(startid + i);
        delay(100);
    }
}

void LedClass::setPixelGruen(byte id) {
      
    LEDPixel.setPixelColor(id, LEDPixel.Color(0, 255, 0));
    //LEDPixel.begin();

    LEDPixel.show();

}

void LedClass::setPixelsGruen(byte startid, byte laenge) {
    Serial.println(Pin);
    for (int i = 0; i < laenge; i++) {
        setPixelGruen(startid + i);
        delay(100);
    }
}

void LedClass::setPixelTeam(byte id, byte i) { 
  if (i == 0) {

      LEDPixel.setPixelColor(id, LEDPixel.Color(10, 10, 10));
      //LEDPixel.begin();

      LEDPixel.show();

  }
  if (i == 1) {
      LEDPixel.setPixelColor(id, LEDPixel.Color(10, 0, 10));
     // LEDPixel.begin();
      LEDPixel.show();

  }

}

void LedClass::showPixel(byte Helligkeit) {
    //Serial.println("in show guen pin: und id");
    //Serial.println(Pin);
    //LEDPixel.setBrightness(Helligkeit);
    LEDPixel.show();
}

