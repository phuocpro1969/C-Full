#include "cDaThuc.h"

int main()
{
	cDaThuc dt1;
	cDaThuc dt2;

	dt1.nhap();
	dt2.nhap();
	cout << endl;
	cout << endl;
	dt1.xuat();
	cout << endl;
	dt2.xuat();
	
	cout << endl;
	cout << endl;
	cout << " Cong 2 da thuc : " << endl;
	dt1.cong(dt2).xuat();
	cout << endl;

	cout << " Tru 2 da thuc : " << endl;
	dt1.tru(dt2).xuat();
	cout << endl;
	cout << endl;
	cout << endl;
	int x; long long gt = 0;
	cout << " F(x) Gia tri x = ";
	cin >> x;

	cout << "Tinh gia tri da thuc F1(" << x << ") = ";
	gt = dt1.tinhgt(x);
	cout << gt;
	cout << endl;

	cout << "Tinh gia tri da thuc F2(" << x << ") = ";
	gt = dt2.tinhgt(x);
	cout << gt;
	cout << endl;
}