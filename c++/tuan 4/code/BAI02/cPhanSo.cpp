#include "cPhanSo.h"

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
	return ituso;
}

int cPhanSo::getmauso()
{
	return imauso;
}

void cPhanSo::settuso(int t)
{
	ituso = t;
}

void cPhanSo::setmauso(int m)
{
	if (m != 0)
		imauso = m;
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
	kq.ituso = ituso * ps2.imauso;
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

cPhanSo cPhanSo::operator+(const cPhanSo& a)
{
	return this->congps(a);
}

cPhanSo cPhanSo::operator-(const cPhanSo& a)
{
	return this->trups(a);
}

cPhanSo cPhanSo::operator*(const cPhanSo& a)
{
	return this->nhanps(a);
}

cPhanSo cPhanSo::operator/(const cPhanSo& a)
{
	return this->chiaps(a);
}

bool cPhanSo::operator>(const cPhanSo& a)
{
	long tu1 = long(ituso * a.imauso);
	long tu2 = long(a.ituso * imauso);
	long mau = long(imauso * a.imauso);

	if (mau > 0)
		return tu1 > tu2;
	return tu1 < tu2;
}

bool cPhanSo::operator>=(const cPhanSo& a)
{
	long tu1 = long(ituso * a.imauso);
	long tu2 = long(a.ituso * imauso);
	long mau = long(imauso * a.imauso);

	if (mau > 0)
		return tu1 >= tu2;
	return tu1 <= tu2;
}

bool cPhanSo::operator<(const cPhanSo& a)
{
	long tu1 = long(ituso * a.imauso);
	long tu2 = long(a.ituso * imauso);
	long mau = long(imauso * a.imauso);

	if (mau > 0)
		return tu1 < tu2;
	return tu1 > tu2;
}

bool cPhanSo::operator<=(const cPhanSo& a)
{
	long tu1 = long(ituso * a.imauso);
	long tu2 = long(a.ituso * imauso);
	long mau = long(imauso * a.imauso);

	if (mau > 0)
		return tu1 <= tu2;
	return tu1 >= tu2;
}

ostream& operator<<(ostream& out, cPhanSo a)
{
	if (a.getmauso() == 1) out << a.gettuso();
	else if (a.getmauso() == 0) out << "Khong ton tai phan so";
	else if (a.gettuso() == 0 && a.getmauso() != 0) out << 0;
	else out <<a.gettuso() <<"/"<< a.getmauso();
	return out;
}

istream & operator>>(istream & in, cPhanSo & a)
{
	int t, m;
	cout << "Tu so  = "; in >> t;
	cout << "Mau so = "; in >> m;
	if (m != 0)
	{
		a.settuso(t);
		a.setmauso(m);
	}
	return in;
}

cPhanSo::~cPhanSo()
{
}
