#ifndef _leds_h
#define _leds_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#include "LedClass.h"

#else
#include "WProgram.h"
#endif


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


Adafruit_NeoPixel RingLeds(200, 10, NEO_GRB + NEO_KHZ800);









//#include "Farben.h"

/*
    byte Pin;
    byte Team;



    Adafruit_NeoPixel Ringe;
    Ringe = Adafruit_NeoPixel(200, Pin, NEO_GRB + NEO_KHZ800);
    Ringe.setPixelColor(0, LEDPixel.Color(0, 255, 0));


    void Init(byte pin, byte Anzahl);
    void setPixelTeam(byte id, byte i);
    void setPixelRot(byte id);
    void setPixelGruen(byte id);

    void showPixel(byte Helligkeit);







    void Init(byte pin, byte Anzahl) {
        this->Pin = pin;
        pinMode(Pin, OUTPUT);
        Serial.println(pin);

        LEDPixel = Adafruit_NeoPixel(Anzahl, Pin, NEO_GRB + NEO_KHZ800);
        LEDPixel.setPixelColor(0, LEDPixel.Color(0, 255, 0));

        LEDPixel.begin();
        //LEDPixel.setBrightness(10);
        LEDPixel.show();

    }

    void setPixelRot(byte id) {
        LEDPixel.setPixelColor(id, LEDPixel.Color(255, 0, 0));
        //  LEDPixel.begin();

    }

    void setPixelGruen(byte id) {
        Serial.println("in ledclass guen pin: und id");
        Serial.println(Pin);
        Serial.println(id);

        LEDPixel.setPixelColor(id, LEDPixel.Color(0, 255, 0));
        LEDPixel.begin();

        LEDPixel.show();

    }

    void setPixelTeam(byte id, byte i) {
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

    void showPixel(byte Helligkeit) {
        //Serial.println("in show guen pin: und id");
        //Serial.println(Pin);
        //LEDPixel.setBrightness(Helligkeit);
        LEDPixel.show();
    }


    */

#endif
