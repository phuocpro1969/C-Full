#include "cDathuc.h"

cDathuc::cDathuc()
{
	n = -1;
	hs = NULL;
}

cDathuc::cDathuc(float a[], int m)
{
	n = m;
	hs = new float[n + 1];
	for (int i = 0; i <= n; i++)
		hs[i] = a[i];
}

cDathuc::cDathuc(const cDathuc& f)
{
	n = f.n;
	hs = new float[n + 1];
	for (int i = 0; i <= n; i++)
		hs[i] = f[i];
}

cDathuc::~cDathuc()
{
	if (hs)
		delete[]hs;
}

float cDathuc::evalue(float x)const
{
	float tam = hs[n];
	for (int i = n; i > 0; --i)
		tam = tam * x + hs[i - 1];
	return tam;
}

float cDathuc::operator[](int i) const
{
	if (i >= 0 && i <= n)
		return hs[i];
	return 0.0f;
}

float cDathuc::operator()(float i) const
{
	return  evalue(i);
}

cDathuc cDathuc::operator*(const cDathuc& f)
{
	int i, j, m;
	float tam, * hsm;

	m = n + f.n;

	hsm = new float[m + 1];
	for (i = 0; i <= m; ++i)
	{
		tam = 0.0f;
		for (j = 0; j <= i && j <= n; ++j)
			tam += hs[j] * f[i - j];
		hsm[i] = tam;
	}
	return cDathuc(hsm, m);
}

cDathuc cDathuc::operator*(float d)
{
	int i, m;
	float * hsm;

	m = n;

	hsm = new float[m];
	for (i = 0; i <= m; ++i)
		hsm[i] = (cDathuc(*this))[i] * d;
	return cDathuc(hsm, m);
}

bool cDathuc::operator==(const cDathuc& f)
{
	if (n == f.n)
	{
		for (int i = 0; i <= n; ++i)
			if (hs[i] - f[i] != 0.0f)
				return false;
		return true;
	}
	return false;
}

cDathuc cDathuc::operator+(const cDathuc& f)
{
	int i, m;
	float * hsm;

	m = max(n, f.n);

	hsm = new float[m + 1];
	for (i = 0; i <= m; ++i)
		hsm[i] = (*this)[i] + f[i];
	return cDathuc(hsm, m);
}

cDathuc cDathuc::operator-(const cDathuc& f)
{
	int i, m;
	float * hsm;

	cDathuc tam = (*this) * (-1.0f);
	cDathuc t = (tam + f);
	m = t.n + 1;
	while (t[m] == 0.0f && m >= 0)
		m--;
	hsm = new float[m + 1];
	for (i = 0; i <= m; ++i)
		hsm[i] = (*this)[i] + f[i];
	if (m == -1)
	{
		m = 1;
		hsm = new float[1];
		hsm[0] = 0.0f;
		hsm[1] = 0.0f;
	}
	return cDathuc(hsm, m);
}

cDathuc& cDathuc::operator=(const cDathuc& f)
{
	if (!(*this == f))
	{
		if (hs)
			delete[]hs;
		n = f.n;
		hs = new float[n + 1];
		for (int i = 0; i <= n; ++i)
			hs[i] = f[i];
	}
	return *this;
}

ostream& operator <<(ostream& out, cDathuc& f)
{
	int dem = 0;
	for (int i = f.n; i > 1; --i)
	{
		if (f[i] == 1.0f)
			out << "x^" << i;
		else
		{
			if (f[i] != 0.0f)
			{
				out << f[i] << "*x^" << i;
			}
			else
				dem++;
		}
		if (f[i - 1] > 0)
			out << " + ";
		else
			out << "";
	}
	if (f[1] == 1.0f)
		out << "x";
	else
	{
		if (f[1] != 0.0f)
			out << f[1] << "x";
		else
			dem++;
	}
	if (f[0] != 0.0f)
		out << " + " << f[0];
	else
		dem++;
	if ((dem-1) == f.n) out << "0";
	return out;
}

istream& operator>>(istream& in, cDathuc& f)
{
	cout << "Nhap bac da thuc : ";
	in >> f.n;
	if (f.hs)
		delete[]f.hs;

	f.hs = new float[f.n + 1];
	for (int i = f.n; i >= 0; --i)
	{
		cout << "Nhap he so bac " << i << " : ";
		in >> f.hs[i];
	}
	return in;
}

