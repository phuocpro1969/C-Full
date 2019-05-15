#include "cTamGiac.h"
using namespace std;
void main()
{
	float x, y, k, rad;
	cTamGiac tg;
	tg.nhap();
	tg.xuat();

	cout << "tinh tien theo v(x,y) : " << endl;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	tg.tt(x, y);
	tg.xuat();

	cout << "Nhap goc quay rad = : ";
	cin >> rad;
	tg.quay(rad);
	tg.xuat();

	cout << "Nhap he so thu phong : ";
	cin >> k;
	tg.thuphong(k);
	tg.xuat();
}