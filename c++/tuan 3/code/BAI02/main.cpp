#include "cDaGiac.h"

int main()
{
	float x, y, k, rad;
	cDaGiac dg;
	dg.nhap();
	dg.xuat();
	cout << endl;

	cout << "tinh tien theo v(x,y) : " << endl;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	dg.tt(x, y);
	dg.xuat();
	cout << endl;

	cout << "Nhap goc quay rad = : ";
	cin >> rad;
	dg.quay(rad);
	dg.xuat();
}