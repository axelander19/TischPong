#include "MatrixClass.h"

void MatrixClass::init(int pin, int ID) {
	IDStart = ID;
	int n = 0;

	for (int i = 0; i < Spalten; i++) {
		for (int m = 0; m < Reihen; m++) {
			matrix[m][i] = n;
			n++;
		}
	}
}

void MatrixClass::strich() {

}