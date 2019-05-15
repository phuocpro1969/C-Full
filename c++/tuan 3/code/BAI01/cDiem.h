#pragma once
#include <iostream>
using namespace std;

class cDiem
{
private:
	float ox, oy;
public:
	cDiem();
	cDiem(float, float);
	void nhap();
	void xuat();
	float getox();
	float getoy();
	void setox(float);
	void setoy(float);
	cDiem vector(cDiem);
	void setxy(float, float);
	void tt(float, float);
	void quay(float);
	~cDiem();
};

