//#ifndef _LedClass_h
//#define _LedClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif





#include "LedClass.h"

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

void LedClass::setPixelGruen(byte id) {
      Serial.println("in ledclass guen pin: und id");
    Serial.println(Pin);
    Serial.println(id);

    LEDPixel.setPixelColor(id, LEDPixel.Color(0, 255, 0));
    LEDPixel.begin();

    LEDPixel.show();

}

void LedClass::setPixelTeam(byte id, byte i) { 
  if (i == 0) {
            Serial.println("Streifeneinpiel in led");

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

