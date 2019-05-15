#pragma once
#include <iostream>

using namespace std;

class cDaThuc
{
private:
	int bac;
	int* heso;
public:
	cDaThuc();
	cDaThuc(int);
	cDaThuc(int, int*);
	void setbac(int);
	int getbac();
	void nhap();
	void xuat();
	cDaThuc cong(cDaThuc);
	cDaThuc tru(cDaThuc);
	long long tinhgt(int);
	~cDaThuc();
};

