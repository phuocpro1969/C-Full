#include "cDSPhanSo.h"
#include <algorithm>


cDSPhanSo::cDSPhanSo()
{
}

cDSPhanSo::cDSPhanSo(int slps)
{
	sops = slps;
	arr_ps = new cPhanSo[sops];
}

void cDSPhanSo::nhap()
{
	cout << "Nhap so luong phan so : ";
	cin >> sops;
	arr_ps = new cPhanSo[sops + 1];

	for (int i = 0; i < sops; i++)
	{
		arr_ps[i].nhap();
	}
}

void cDSPhanSo::xuat()
{
	for (int i = 0; i < (sops-1); i++)
	{
		arr_ps[i].xuat();
		cout << ", ";
	}
	arr_ps[sops-1].xuat();
}

cPhanSo cDSPhanSo::congallps()
{
	cPhanSo kq, a;
	kq.settu(arr_ps[0].gettu());
	kq.setmau(arr_ps[0].getmau());
	for (int i = 1; i < sops; i++)
	{
		a = kq.congps(arr_ps[i]).rutgonps();
		kq.settu(a.gettu());
		kq.setmau(a.getmau());
	}
	return kq;
}

cPhanSo cDSPhanSo::maxps()
{
	cPhanSo kq, a;
	kq.settu(arr_ps[0].gettu());
	kq.setmau(arr_ps[0].getmau());
	for (int i = 1; i < sops; i++)
	{
		a = kq.trups(arr_ps[i]);
			if (a.gettu() < 0)
			{
				kq.settu(arr_ps[i].gettu());
				kq.setmau(arr_ps[i].getmau());
			}
	}
	return kq;
}

cPhanSo cDSPhanSo::minps()
{
	cPhanSo kq, a;
	kq.settu(arr_ps[0].gettu());
	kq.setmau(arr_ps[0].getmau());
	for (int i = 1; i < sops; i++)
	{
		a = kq.trups(arr_ps[i]);
		if (a.gettu() > 0)
		{
			kq.settu(arr_ps[i].gettu());
			kq.setmau(arr_ps[i].getmau());
		}
	}
	return kq;
}

void cDSPhanSo::sort_tang()
{
	cPhanSo a;
	for (int i = 0; i < sops - 1; i++)
		for (int j = i + 1; j < sops; j++)
		{
			a = arr_ps[i].trups(arr_ps[j]);
			if (a.gettu() > 0)
				swap(arr_ps[i], arr_ps[j]);
		}
}

void cDSPhanSo::sort_giam()
{
	cPhanSo a;
	for (int i = 0; i < sops - 1; i++)
		for (int j = i + 1; j < sops; j++)
		{
			a = arr_ps[i].trups(arr_ps[j]);
			if (a.gettu() < 0)
				swap(arr_ps[i], arr_ps[j]);
		}
}

cDSPhanSo::~cDSPhanSo()
{
}
