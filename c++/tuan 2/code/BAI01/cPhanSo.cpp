#include "cPhanSo.h"
#include <iostream>
#include <math.h>
using namespace std;



cPhanSo::cPhanSo()
{
	settuso(0);
	setmauso(1);
}

cPhanSo::cPhanSo(int t, int m)
{
	if (m != 0)
	{
		settuso(t);
		setmauso(m);
	}
}

int cPhanSo::gettuso()
{
	return cPhanSo::ituso;
}

int cPhanSo::getmauso()
{
	return cPhanSo::imauso;
}

void cPhanSo::settuso(int t)
{
	cPhanSo::ituso = t;
}

void cPhanSo::setmauso(int m)
{
	if (m != 0)
		cPhanSo::imauso = m;
}

void cPhanSo::nhapps()
{
	int t, m;
	cout << "Nhap gia tri phan so" << endl;
	cout << "Nhap tu so  : ";
	cin >> t;
	cout << "Nhap mau so : ";
	cin >> m;
	if (m != 0)
	{
		settuso(t);
		setmauso(m);
	}
}

void cPhanSo::xuatps()
{
	cout << "Phan so : " << ituso << "/" << imauso << endl;
}

cPhanSo cPhanSo::congps(cPhanSo ps2)
{
	cPhanSo kq;
	kq.ituso = ituso * ps2.imauso + imauso * ps2.ituso;
	kq.imauso = imauso * ps2.imauso;
	return kq;
}

cPhanSo cPhanSo::trups(cPhanSo ps2)
{
	cPhanSo kq;
	kq.ituso = ituso * ps2.imauso - imauso * ps2.ituso;
	kq.imauso = imauso * ps2.imauso;
	return kq;
}

cPhanSo cPhanSo::nhanps(cPhanSo ps2)
{
	cPhanSo kq;
	kq.ituso = ituso * ps2.ituso;
	kq.imauso = imauso * ps2.imauso;
	return kq;
}

cPhanSo cPhanSo::chiaps(cPhanSo ps2)
{
	cPhanSo kq;
	kq.ituso = ituso * ps2.imauso ;
	kq.imauso = imauso * ps2.ituso;
	return kq;
}

int ucln(int a, int b)
{
	a = abs(a);
	b = abs(b);

	if (a == 0 || b == 0)
		return a + b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

cPhanSo cPhanSo::rutgonps()
{
	int uc = ucln(ituso, imauso);
	cPhanSo kq;
	kq.ituso = ituso / uc;
	kq.imauso = imauso / uc;
	return kq;
}

cPhanSo::~cPhanSo()
{
}
