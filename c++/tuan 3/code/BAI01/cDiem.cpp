#include "cDiem.h"

cDiem::cDiem()
{
}

void cDiem::setox(float x)
{
	ox = x;
}

void cDiem::setoy(float y)
{
	oy = y;
}

float cDiem::getox()
{
	return ox;
}

float cDiem::getoy()
{
	return oy;
}

void cDiem::setxy(float x, float y)
{
	ox = x;
	oy = y;
}

void cDiem::nhap()
{
	cout << "Hoanh do x = ";
	cin >> ox;
	cout << "Tung do y =";
	cin >> oy;
}

void cDiem::xuat()
{
	cout << "(" << ox << "," << oy << ")";
}

void cDiem::tt(float x, float y)
{
	ox += x;
	oy += y;
}

void cDiem::quay(float rad)
{
	ox = ox * cos(rad) + oy * sin(rad);
	oy = oy * sin(rad) + ox * cos(rad);
}

cDiem cDiem::vector(cDiem d)
{
	cDiem kq;
	kq.setox(d.getox() - ox);
	kq.setoy(d.getoy() - oy);
	return kq;
}

cDiem::~cDiem()
{
}
