#pragma once
#include <iostream>
#include "cDiem.h"
using namespace std;

class cDaGiac
{
private:
	int sodinh;
	cDiem* arr_dinh;
public:
	cDaGiac();
	cDaGiac(int);
	void tt(float x, float y);
	void quay(float rad);
	void nhap();
	void xuat();

	~cDaGiac();
};
