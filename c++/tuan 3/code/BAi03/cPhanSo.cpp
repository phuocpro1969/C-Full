#include "cPhanSo.h"

cPhanSo::cPhanSo()
{
	ituso = 0;
	imauso = 1;
}

cPhanSo::cPhanSo(int tu, int mau)
{
	if (mau != 0)
	{
		ituso = tu;
		imauso = mau;
	}
}

void cPhanSo::settu(int tu)
{
	ituso = tu;
}

void cPhanSo::setmau(int mau)
{
	if (mau != 0)
		imauso = mau;
}

int cPhanSo::gettu()
{
	return ituso;
}

int cPhanSo::getmau()
{
	return imauso;
}

void cPhanSo::nhap()
{
	int tu, mau;
	cout << "Moi nhap tu va mau cua phan so :" << endl;
	cout << "Nhap tu so : ";
	cin >> tu;
	cout << "Nhap mau so : ";
	cin >> mau;
	settu(tu);
	setmau(mau);
}

void cPhanSo::xuat()
{
	cout << ituso << "/" << imauso;
}
int cPhanSo::ucln(int a, int b)
{
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
	int uc = ucln(abs(ituso), abs(imauso));
	cPhanSo kq;
	kq.settu(ituso / uc);
	kq.setmau(imauso / uc);
	return kq;
}

cPhanSo cPhanSo::congps(cPhanSo ps)
{
	cPhanSo kq;
	kq.settu(ituso * ps.imauso + ps.ituso * imauso);
	kq.setmau(imauso * ps.imauso);
	return kq;
}

cPhanSo cPhanSo::trups(cPhanSo ps)
{
	cPhanSo kq;
	kq.settu(ituso * ps.imauso - ps.ituso * imauso);
	kq.setmau(imauso * ps.imauso);
	return kq;
}

cPhanSo cPhanSo::nhanps(cPhanSo ps)
{
	cPhanSo kq;
	kq.settu(ituso * ps.ituso);
	kq.setmau(imauso * ps.imauso);
	return kq;
}

cPhanSo cPhanSo::chiaps(cPhanSo ps)
{
	cPhanSo kq;
	kq.settu(ituso * ps.imauso);
	kq.setmau(imauso * ps.ituso);
	return kq;
}

cPhanSo::~cPhanSo()
{
}

