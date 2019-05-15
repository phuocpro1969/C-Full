#pragma once
#include "cPhanSo.h"
class cDSPhanSo
{
private:
	int sops;
	cPhanSo* arr_ps;
public:
	cDSPhanSo();
	cDSPhanSo(int);
	cPhanSo congallps();
	cPhanSo maxps();
	cPhanSo minps();
	void sort_tang();
	void sort_giam();
	void nhap();
	void xuat();
	~cDSPhanSo();
};

