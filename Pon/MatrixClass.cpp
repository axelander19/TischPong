#include "MatrixClass.h"

void MatrixClass::init(byte pin, byte team) {
	this->Team = team;
    this->Pin = pin;
	
    matrix.Init(Pin, (Reihen * Spalten));


    matrix.showPixel(Helligkeit);
}

void MatrixClass::aktMatrix(byte Zahl, byte hel){
    Helligkeit = hel;
  
    switch (Zahl)
    {
    case 0:    
        schreibeMatrix(matrix0);
        break;
    case 1:
        schreibeMatrix(matrix1);
        break;
    case 2:
        schreibeMatrix(matrix2);
        break;
    case 3:
        schreibeMatrix(matrix3);
        break;
    case 4:
        schreibeMatrix(matrix4);
        break;
    case 5:
        schreibeMatrix(matrix5);
        break;
    case 6:
        schreibeMatrix(matrix6);
        break;
    case 7:
        schreibeMatrix(matrix7);
        break;
    case 8:
        schreibeMatrix(matrix8);
        break;
    case 9:
        schreibeMatrix(matrix9);
        break;
    case 10:
        schreibeMatrix(matrix10);
        break;
    default:
        break;
    }
}

void MatrixClass::schreibeMatrix(int aktMatrix[][8]) {
    byte id = IDStart;
   // Serial.println("SChreibemtrix case0");

    for (byte reihe = 0; reihe < Reihen; reihe++) {
             // Serial.println("neue Reihe");

        for (byte spalte = 0; spalte < Spalten; spalte++) {

            if (aktMatrix[reihe][spalte] == 1) {
                //aktivieren led
                              //          Serial.println(matrixID[reihe][spalte]);

                matrix.setPixelRot(matrixID[reihe][spalte]);
               // matrix.showPixel(Helligkeit);
            }
            else {
                matrix.setPixelTeam(matrixID[reihe][spalte], Team);
                              //  matrix.showPixel(Helligkeit);
            
            }
                        //Serial.println(spalte);

            id++;
            delay(1);
        }
               // Serial.println(F("SChreibematrix case0  reihe zuende"));
                    //    Serial.println(reihe);
delay(10);

    }
       // Serial.println("SChreibematrix case0 zuende");

}
