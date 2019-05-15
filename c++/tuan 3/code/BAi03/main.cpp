#include "cDSPhanSo.h"

int main()
{
	cDSPhanSo dsps;
	dsps.nhap();
	cout << "Cac phan so da nhap : ";
	dsps.xuat();
	cout << endl;
	cout << "Tong tat ca phan so : ";
	dsps.congallps().xuat();
	cout << endl;
	cout << "Max tat ca phan so : ";
	dsps.maxps().xuat();
	cout << endl;
	cout << "Min tat ca phan so : ";
	dsps.minps().xuat();
	cout << endl;
	cout << " sap xep giam dan : ";
	dsps.sort_tang();
	dsps.xuat();
	cout << endl;
	cout << " sap xep giam dan : ";
	dsps.sort_giam();
	dsps.xuat();
	cout << endl;
}