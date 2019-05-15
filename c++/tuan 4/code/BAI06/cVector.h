#pragma once
#include <iostream>
using namespace std;
class cVector
{
private:
	int* vector;
	int n;
public:
	cVector();
	cVector(int);
	cVector(const cVector& a);
	~cVector();
	friend ostream& operator<<(ostream& out, const cVector& a);
	friend istream& operator>>(istream& in, cVector& a);
	cVector operator+(const cVector& a);
	cVector operator-(const cVector& a);
	cVector operator*(int& a);
	long scalar(cVector& a);
	friend class cMatrix;
};

