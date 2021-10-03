#include "MatrixClass.h"

void MatrixClass::init(int pin, int ID) {
	IDStart = ID;
 this->Pin = pin;
	Serial.println("init");
	  matrix = Adafruit_NeoPixel(Spalten*Reihen, Pin, NEO_GRB + NEO_KHZ800);

	 matrix.begin();
  //strip.setBrightness(50);
  matrix.show(); // Initialize all pixels to 'off'
	//matrix.setPixelColor(5, c);

          matrix.show();


}

  void MatrixClass::zehn() {
  	int id = IDStart;
  
  	for (int reihe = 0; reihe < Reihen; reihe++) {
  		for (int spalte = 0; spalte < Spalten; spalte++) {
  			if (matrix10[reihe][spalte] == 1) {
  				  //aktivieren led
            //matrix.setPixelColor(10, 255,255,225);
            matrix.setPixelColor(matrixID[reihe][spalte], 255,0,0);
           
            Serial.print("matrixzehn");
            Serial.println(matrixID[reihe][spalte]);
               matrix.show();
  			    }	
            else{
              matrix.setPixelColor(matrixID[reihe][spalte], 0,10,0);
		        }
  			id++;
       
        delay(10);
  	    }
      }       
  }

void MatrixClass::neun() {
	int id = IDStart;
  
    for (int reihe = 0; reihe < Reihen; reihe++) {
      for (int spalte = 0; spalte < Spalten; spalte++) {
        if (matrix9[reihe][spalte] == 1) {
            //aktivieren led
            //matrix.setPixelColor(10, 255,255,225);
            matrix.setPixelColor(matrixID[reihe][spalte], 255,0,0);
           
            Serial.print("matrixzehn");
            Serial.println(matrixID[reihe][spalte]);
               matrix.show();
            } 
            else{
              matrix.setPixelColor(matrixID[reihe][spalte], 0,10,0);
            }
        id++;
       
        delay(10);
        }
      }    
}

void MatrixClass::acht(){
  
}
void MatrixClass::sieben(){
  
}
void MatrixClass::sechs(){}

void MatrixClass::fuenf(){
  
}
void MatrixClass::vier(){
  
}
void MatrixClass::drei(){
  
}
void MatrixClass::zwei(){
  
}
void MatrixClass::eins(){
  
}
void MatrixClass::nulll(){
  
}
