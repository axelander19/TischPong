#include "MatrixClass.h"

void MatrixClass::init(byte pin, byte team) {
	this->Team = team;
    this->Pin = pin;
	
    matrix.init(Pin, Reihen * Spalten);
    matrix.showPixel(Helligkeit);
}

void MatrixClass::aktMatrix(byte Zahl, byte hel){
    Helligkeit = hel;
  
    switch (Zahl)
    {
    case 0:
   // Serial.println(F("aktMatrix case0"));
    //int* zeiger = matri0
    
        schreibeMatrix(matrix0);
      //  break;
  /*  case 1:
        schreibeMatrix(matrix1);
    case 2:
        schreibeMatrix(matrix2);
    case 3:
        schreibeMatrix(matrix3);
    case 4:
        schreibeMatrix(matrix4);
    case 5:
        schreibeMatrix(matrix5);
    case 6:
        schreibeMatrix(matrix6);
    case 7:
        schreibeMatrix(matrix7);
    case 8:
        schreibeMatrix(matrix8);
    case 9:
        schreibeMatrix(matrix9);
    case 10:
        schreibeMatrix(matrix10);
    default:
        break;*/
    }
}

void MatrixClass::schreibeMatrix(int aktMatrix[][8]) {
    byte id = IDStart;
   // Serial.println("SChreibemtrix case0");

    for (byte reihe = 0; reihe < Reihen; reihe++) {
              Serial.println("neue Reihe");

        for (byte spalte = 0; spalte < Spalten; spalte++) {
                  Serial.println(F("neue Spalte"));

            if (aktMatrix[reihe][spalte] == 1) {
                //aktivieren led
                                        Serial.println(matrixID[reihe][spalte]);

                //matrix.setPixelRot(matrixID[reihe][spalte]);
               // matrix.showPixel(Helligkeit);
            }
            else {
                matrix.setPixelTeam(matrixID[reihe][spalte], Team);
                                matrix.showPixel(Helligkeit);
            
            }
                        Serial.println(spalte);

            id++;
            delay(100);
        }
                Serial.println(F("SChreibematrix case0  reihe zuende"));
                        Serial.println(reihe);
delay(100);

    }
        Serial.println("SChreibematrix case0 zuende");

}
