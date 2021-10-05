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
        schreibeMatrix(matrix0);
    case 1:
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
        break;
    }
}

void MatrixClass::schreibeMatrix(int	aktMatrix[Reihen][Spalten]) {
    byte id = IDStart;

    for (byte reihe = 0; reihe < Reihen; reihe++) {
        for (byte spalte = 0; spalte < Spalten; spalte++) {
            if (aktMatrix[reihe][spalte] == 1) {
                //aktivieren led
                matrix.setPixelRot(matrixID[reihe][spalte]);
                matrix.showPixel(Helligkeit);
            }
            else {
                matrix.setPixelTeam(matrixID[reihe][spalte], Team);            
            }

            id++;
            delay(10);
        }
    }
}
