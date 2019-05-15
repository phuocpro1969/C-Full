#include"cDiem.h"
#include<iostream>
using namespace std;

int main()
{
	cDiem a;
	float xx, yy;
	a.nhap();
	a.xuat();
	cout << "tinh tien : "<< endl;
	cout << " tinh tien Ox : ";
	cin >> xx;
	cout << " tinh tien Oy : ";
	cin >> yy;
	a.tinhtien(xx, yy).xuat();
}