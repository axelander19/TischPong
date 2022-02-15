#include "MatrixClass.h"

void MatrixClass::init(byte pin, byte team) {
	this->Team = team;
    this->Pin = pin;
	
    matrix.Init(Pin, (Reihen * Spalten), Team);

    if (Team == 0) {
        aktMatrix(99);
    }
    if (Team == 1) {
        aktMatrix(100);
    }
}

void MatrixClass::aktMatrix(byte Zahl){
    becher = Zahl;

    switch (becher)
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
    case 99:
        schreibeMatrix(matrixha);
        break;
    case 100:
        schreibeMatrix(matrixllo);
        break;
    default:
        break;
    }
}

void MatrixClass::schreibeMatrix(int aktMatrix[Reihen][Spalten]) {
    
    //byte id = IDStart;

    for (byte reihe = 0; reihe < Reihen; reihe++) {

        for (byte spalte = 0; spalte < Spalten; spalte++) {

            if (aktMatrix[reihe][spalte] == 1) {
                //aktivieren led
                matrix.setPixelsRot(matrixID[reihe][spalte], 1);
            }
            if (aktMatrix[reihe][spalte] == 0){
                if (energiesparmodus == false) {
                    matrix.setPixelsTeam(matrixID[reihe][spalte], 1);
                }
                if (energiesparmodus == true) {
                    matrix.setPixelsOut(matrixID[reihe][spalte], 1);
                }
            }
        }
    }
}

  void MatrixClass::setModus(int hel, bool sparmodus){
      
      energiesparmodus = sparmodus;
      matrix.setModus(hel, sparmodus);
      aktMatrix(becher);
  }

 void MatrixClass::setBrightness(int hel){
        matrix.setBrightness(hel);
    }
    
