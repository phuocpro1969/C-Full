#include "cSoPhuc.h"

cSoPhuc::cSoPhuc(float b, float c)
{
	t = b;
	a = c;
}

float cSoPhuc::dodai()
{
	return sqrt(t * t + a * a);
}

cSoPhuc::~cSoPhuc(void)
{
}

cSoPhuc cSoPhuc::operator+(const cSoPhuc& x)
{
	cSoPhuc c;
	c.t = x.t + this->t;
	c.a = x.a + this->t;
	return c;
}

cSoPhuc cSoPhuc::operator-(const cSoPhuc& x)
{
	cSoPhuc c;
	c.t = t - x.t;
	c.a = a - x.a;
	return c;
}

cSoPhuc cSoPhuc::operator*(const cSoPhuc& x)
{
	cSoPhuc c;
	c.t = t * x.t - a * x.a;
	c.a = t * x.a + a * x.t;
	return c;
}

cSoPhuc cSoPhuc::operator/(const cSoPhuc& x)
{
	cSoPhuc c;
	c.t = (t * x.t + a * x.a) / (x.t * x.t + x.a * x.a);
	c.a = (a * x.t - t * x.a) / (x.t * x.t + x.a * x.a);
	return c;
}

ostream& operator<<(ostream& out, const cSoPhuc& a)
{
	if (a.t == 0 && a.a != 0) out << a.a << "i";
	else if (a.a == 0 && a.t != 0) out << a.t;
	else if (a.t == 0 && a.a == 0) out << 0;
	else out << a.t << ((a.a > 0) ? " + " : " - ") << abs(a.a) << "i";
	return out;
}

istream& operator>>(istream& in, cSoPhuc& a)
{
	cout << "Phan thuc = "; in >> a.t;
	cout << "Phan ao   = "; in >> a.a;
	return in;
}

bool cSoPhuc::operator<(cSoPhuc& x)
{
	if (dodai() < x.dodai())
		return true;
	return false;
}

bool cSoPhuc::operator<=(cSoPhuc& x)
{
	if (dodai() <= x.dodai())
		return true;
	return false;
}

bool cSoPhuc::operator>(cSoPhuc& x)
{
	if (dodai() > x.dodai())
		return true;
	return false;
}

bool cSoPhuc::operator>=(cSoPhuc& x)
{
	if (dodai() >= x.dodai())
		return true;
	return false;
}

bool cSoPhuc::operator==(cSoPhuc& x)
{
	if (dodai() == x.dodai())
		return true;
	return false;
}

bool cSoPhuc::operator!=(cSoPhuc& x)
{
	if (dodai() != x.dodai())
		return true;
	return false;
}
