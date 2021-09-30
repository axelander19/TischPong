#include "MatrixClass.h"

void MatrixClass::init(int pin, int ID) {
	IDStart = ID;
	/*int n = 0;

	for (int i = 0; i < Spalten; i++) {
		for (int m = 0; m < Reihen; m++) {
			//matrix[m][i] = n;
			n++;
		}
	}*/
}

void MatrixClass::zehn() {
	int id = 0;

	for (int reihe = 0; reihe < Reihen; reihe++) {
		for (int spalte = 0; spalte < Spalten; spalte++) {
			if (matrix10[reihe][spalte] == 1) {
				//aktivieren led
			}					
			id++;
		}
	}


}

void MatrixClass::neun() {
	
}
/*
void MatrixClass::acht();
void MatrixClass::sieben();
void MatrixClass::sechs();
void MatrixClass::fuenf();
void MatrixClass::vier();
void MatrixClass::drei();
void MatrixClass::zwei();
void MatrixClass::eins();
void MatrixClass::null();*/