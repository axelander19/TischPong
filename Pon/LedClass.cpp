#include "LedClass.h"

void LedClass::init(byte pin, byte Anzahl) {
	this->Pin = pin;
    pinMode(Pin, OUTPUT);

    LEDPixel = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);

    LEDPixel.begin();
//    LEDPixel.setBrightness(helligkeit);
}

void LedClass::setPixelRot(byte id) {
    LEDPixel.setPixelColor(id, LEDPixel.Color(255, 0, 255));
}

void LedClass::setPixelGruen(byte id) {
    LEDPixel.setPixelColor(id, LEDPixel.Color(0, 255, 255));
}

void LedClass::setPixelTeam(byte id, byte i) { 
  if (i == 0) {
      LEDPixel.setPixelColor(id, LEDPixel.Color(255, 0, 255));
  }
  if (i == 1) {
      LEDPixel.setPixelColor(id, LEDPixel.Color(255, 0, 255));
  }
}

void LedClass::showPixel(byte Helligkeit) {
    LEDPixel.setBrightness(Helligkeit);
    LEDPixel.show();
}

  /*int* LedClass::getRot(){
//    return {255,0,0};
  }*/
