#include "cArray.h"

int main()
{
	cArray a;
	int x;

	a.random();
	a.xuat();

	cout << endl;
	cout << "Nhap gia tri x can tim trong mang : x = ";
	cin >> x;

	int kq = a.demx(x);

	cout << "Tong so luong x co trong mang la : " << kq;
	cout << endl;

	bool kt = a.kt_tang();

	cout << "Mang co tang dan : " << kt;
	cout << endl;

	long min = a.tim_min_le();
	if (min == 0)
		cout << "khong ton tai so nguyen le nho nhat" << endl;
	else
		cout << "So nguyen le nho nhat la : " << min << endl;
	
	a.prime();
	long max = a.tim_max_snt();
	if (max == 0)
		cout << "khong ton tai so nguyen to lon nhat" << endl;
	else
		cout << "So nguyen to lon nhat la : " << max << endl;
	
	a.sort();
}