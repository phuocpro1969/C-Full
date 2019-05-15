#pragma once
#include "cVector.h"
class cMatrix
{
private:
	int row, column;
	double** matran;
public:
	cMatrix();
	cMatrix(int r, int c);
	cMatrix(const cMatrix& a);
	~cMatrix();
	friend ostream& operator<<(ostream& out, const cMatrix& a);
	friend istream& operator>>(istream& in, cMatrix& a);
	cMatrix operator+(const cMatrix& a);
	cMatrix operator-(const cMatrix& a);
	cMatrix operator*(int& k);
	cMatrix operator*(cVector& a);
	cMatrix operator*(const cMatrix& a);
};

