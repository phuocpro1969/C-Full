#pragma once
#include <iostream>

using namespace std;

class cPhanSo
{
private:
	int ituso;
	int imauso;
public:
	int ucln(int, int);
	cPhanSo();
	cPhanSo(int, int);
	~cPhanSo();
	void settu(int);
	void setmau(int);
	int gettu();
	int getmau();
	cPhanSo congps(cPhanSo);
	cPhanSo trups(cPhanSo);
	cPhanSo nhanps(cPhanSo);
	cPhanSo chiaps(cPhanSo);
	cPhanSo rutgonps();
	void nhap();
	void xuat();
};

