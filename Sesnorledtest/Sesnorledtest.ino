#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#define numPixel 24

int sensor = 0;
int led= 1;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixel, led, NEO_GRB + NEO_KHZ800);


void setup() {
pinMode(sensor,INPUT);
pinMode(led, OUTPUT);
    pixels.begin();

}

void loop() {

int SensorWer = analogRead(sensor);

if(SensorWer < 500){
  for(int i=0;i<numPixel;i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000); // Delay for a period of time (in milliseconds).
  }
}
if(SensorWer > 500){
  for(int i=0;i<numPixel;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(1000); // Delay for a period of time (in milliseconds).
  }
}
}
