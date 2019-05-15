#include "cDaGiac.h"

cDaGiac::cDaGiac()
{
}

cDaGiac::cDaGiac(int sd)
{
	sodinh = sd;
	arr_dinh = new cDiem[sodinh];
}

void cDaGiac::nhap()
{
	cout << "Nhap so luong dinh cua da giac : ";
	cin >> sodinh;
	arr_dinh = new cDiem[sodinh + 1];

	for (int i = 0; i < sodinh; i++)
		arr_dinh[i].nhap();
}

void cDaGiac::xuat()
{
	cout << "Da giac duoc tao boi cac dinh : ";
	for (int i = 0; i < sodinh - 1; i++)
	{
		arr_dinh[i].xuat();
		cout << ",";
	}
		arr_dinh[sodinh - 1].xuat();
}

void cDaGiac::tt(float x, float y)
{
	for (int i = 0; i < sodinh; i++)
		arr_dinh[i].tt(x, y);
}

void cDaGiac::quay(float rad)
{
	for (int i = 0; i < sodinh; i++)
		arr_dinh[i].quay(rad);
}

cDaGiac::~cDaGiac()
{
}
