#include "cDaThuc.h"
#include <algorithm>

cDaThuc::cDaThuc()
{
}

cDaThuc::cDaThuc(int b)
{
	setbac(b);
	heso = new int[b];
}

cDaThuc::cDaThuc(int b, int hs[])
{
	setbac(b);
	heso = new int[b];

	for (int i = b; i >= 0; i--)
		heso[i] = hs[i];
}

void cDaThuc::setbac(int b)
{
	bac = b;
	heso = new int[b];
}

int cDaThuc::getbac()
{
	return bac;
}

void cDaThuc::nhap()
{
	int b;
	cout << "Nhap Da thuc :" << endl;
	cout << "Nhap bac cao nhat cua da thuc n = ";
	cin >> b;
	setbac(b);
	heso = new int[b];
	for (int i = b; i >= 0; i--)
	{
		cout << " he so cua x ^ " << i << " : ";
		if (i == bac)
		{
			while (i == bac)
			{
				cin >> heso[i];
				if (heso[bac] == 0)
					cout << "Nhap lai he so : ";
				else
					i--;
			}
			i = bac;
		}
		else
			cin >> heso[i];
	}
}

void cDaThuc::xuat()
{
	cout << " Da thuc F(x) = ";
	for (int i = bac; i >= 0; i--)
	{
		if ((bac > i) && (heso[i] != 0))
			cout << " + ";

		if (heso[i] != 0)
			if (((i > 0) && (heso[i] != 1)) || (i == 0))
				cout << heso[i];

		if ((i > 0) && (heso[i] != 0))
		{
			if (heso[i] != 1 && heso[i] != 0) 
			cout << "*";
			if (i == 1)
				cout << "x ";
			else
				cout << "(x ^ " << i << ") ";
		}
	}
}

cDaThuc cDaThuc::cong(cDaThuc dt)
{
	cDaThuc kq;
	kq.setbac(max(getbac(), dt.getbac()));
	
	for (int i = 0; i <= kq.getbac()+1; i++)
		kq.heso[i] = 0;

	for (int i = getbac(); i >= 0; i--)
			kq.heso[i] += heso[i];

	for (int i = dt.getbac(); i >= 0; i--)
			kq.heso[i] += dt.heso[i];
	return kq;
}

cDaThuc cDaThuc::tru(cDaThuc dt)
{
	cDaThuc kq;
	kq.setbac(max(getbac(), dt.getbac()));

	for (int i = 0; i <= kq.getbac() + 1; i++)
		kq.heso[i] = 0;

	for (int i = getbac(); i >= 0; i--)
		kq.heso[i] += heso[i];

	for (int i = dt.getbac(); i >= 0; i--)
		kq.heso[i] -= dt.heso[i];
	return kq;
}

long long cDaThuc::tinhgt(int x)
{
	int i;
	long long tong = 0, gt = 1;

	for (i = 0; i <= bac; i++)
	{
		tong += heso[i] * gt;
		gt *= x;
	}
	return tong;

}

cDaThuc::~cDaThuc()
{
}
