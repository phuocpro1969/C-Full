#include "cDiem.h"
#include <iostream>
using namespace std;



cDiem::cDiem()
{
	ox = 0;
	oy = 0;
}

cDiem::cDiem(float xx, float yy)
{
	ox = xx;
	oy = yy;
}

void cDiem::setOx(float xx)
{
	ox = xx;
}

void cDiem::setOy(float yy)
{
	oy = yy;
}

float cDiem::getOx()
{
	return ox;
}

float cDiem::getOy()
{
	return oy;
}

void cDiem::nhap()
{
	cout << "Nhap toa do Ox : "; 
	cin >> ox;
	cout << "Nhap toa do Oy : ";
	cin >> oy;
}

void cDiem::xuat()
{
	cout << "toa do :(" << ox << "," << oy << ")" << endl;
}

cDiem cDiem::tinhtien(float tx, float ty)
{
	cDiem kq;
	kq.setOx(ox);
	kq.setOy(oy);
	kq.ox += tx;
	kq.oy += ty;
	setOx(kq.ox);
	setOy(kq.oy);
	return kq;
}

cDiem::~cDiem()
{
}
