#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class cPhanSo
{
private:
	int ituso;
	int imauso;
public:
	cPhanSo();
	cPhanSo(int, int);
	int gettuso();
	int getmauso();
	void settuso(int);
	void setmauso(int);
	cPhanSo congps(cPhanSo);
	cPhanSo trups(cPhanSo);
	cPhanSo nhanps(cPhanSo);
	cPhanSo chiaps(cPhanSo);
	cPhanSo rutgonps();
	cPhanSo operator+(const cPhanSo& a);
	cPhanSo operator-(const cPhanSo& a);
	cPhanSo operator*(const cPhanSo& a);
	cPhanSo operator/(const cPhanSo& a);
	bool operator>(const cPhanSo& a);
	bool operator>=(const cPhanSo& a);
	bool operator<(const cPhanSo& a);
	bool operator<=(const cPhanSo& a);
	friend ostream& operator<<(ostream& out, cPhanSo a);
	friend istream& operator>>(istream& in, cPhanSo& a);
	~cPhanSo();
};

