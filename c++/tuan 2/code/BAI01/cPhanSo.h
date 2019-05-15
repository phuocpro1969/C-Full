#pragma once
class cPhanSo
{
private:
	int ituso;
	int imauso;
public:
	cPhanSo();
	cPhanSo(int, int);
	int gettuso();
	int getmauso();
	void settuso(int);
	void setmauso(int);
	void nhapps();
	void xuatps();
	cPhanSo congps(cPhanSo);
	cPhanSo trups(cPhanSo);
	cPhanSo nhanps(cPhanSo);
	cPhanSo chiaps(cPhanSo);
	cPhanSo rutgonps();
	~cPhanSo();
};

