#pragma once

#define Spalten 32
#define Reihen 8

class MatrixClass
{
private:
	int matrix[Spalten][Reihen];
	

public:
	void init(int pin,int ID);
	int IDStart;
	void strich();
	void zehn();
	void neun();
	void acht();
	void sieben();
	void sechs();
	void fuenf();
	void vier();
};

