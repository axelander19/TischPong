#pragma once

#include "LedClass.h"

#define Spalten 8
#define Reihen 8

class MatrixClass
{
private:
	byte IDStart = 0;
	byte Pin;
	byte Team;
  byte Helligkeit = 0;
  
	LedClass matrix;
	
	int matrixID[Reihen][Spalten] = {
	{7, 6, 5, 4, 3, 2, 1, 0},
	{8, 9, 10, 11, 12, 13, 14, 15},
	{23, 22, 21, 20, 19, 18, 17, 16},
	{24, 25, 26, 27, 28, 29, 30, 31},
	{39, 38, 37, 36, 35, 34, 33, 32},
	{40, 41, 42, 43, 44, 45, 46, 47},
	{55, 54, 53, 52, 51, 50, 49, 48},
	{56, 57, 58, 59, 60, 61, 62, 63} };
	int	matrix10[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 0},
		{0, 1, 1, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 0, 1},
		{0, 1, 1, 1, 0, 1, 1, 0} };
	int	matrix9[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 1, 0, 0} };
	int	matrix8[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 1, 0, 0} };
	int	matrix7[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0} };
	int	matrix6[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 1, 0, 0} };
	int	matrix5[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 1, 1, 1, 1, 0, 0} };
	int	matrix4[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0} };
	int	matrix3[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 1, 0, 0} };
	int	matrix2[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 0} };
	int	matrix1[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 0} };
	int	matrix0[Reihen][Spalten] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 1, 0, 0} };



public:
	void init(byte pin, byte Team);

	void aktMatrix(byte Zahl, byte hel);

	void schreibeMatrix(int	aktMatrix[Reihen][Spalten]);
};
