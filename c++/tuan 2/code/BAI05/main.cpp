#include "cDate.h"
#include <iostream>
using namespace std;

int main()
{
	cDate d;
	//nhap
	d.nhap();
	//xuat
	d.xuat();
	cDate dn(1, 4, 2019);
	dn.xuat();
	int c, tg, cn, thu;
	do
	{
		cout << "------------------------------------------" << endl;
		cout << "MENU" << endl;
		cout << "1.Update date" << endl;
		cout << "2.Tang/Giam date" << endl;
		cout << "3. Lay thu trong tuan" << endl;
		cout << "4.Exit" << endl;
		cout << "Ban chon so : ";
		cin >> c;
		switch (c)
		{
		case 1:
			do
			{
				cout << "------------------------------------------" << endl;
				cout << "MENU" << endl;
				cout << "1.Update date" << endl;
				cout << "2.Exit" << endl;
				cout << "Ban chon so : ";
				cin >> cn;
				switch (cn)
				{
				case 1:
					d.update();
					break;
				case 2:
					break;
				default:
					cout << " Ban chon tu 1 --> 2" << endl;
				}
			} while (cn != 2);
			break;
		case 2:
			do
			{
				cout << "------------------------------------------" << endl;
				cout << "MENU" << endl;
				cout << "1.Tang time" << endl;
				cout << "2.Giam time" << endl;
				cout << "3.Exit" << endl;
				cout << "Ban chon so : ";
				cin >> cn;
				switch (cn)
				{
				case 1:
					cout << "Tang thoi gian : " << endl;
					cout << "tong thoi gian tang (ngay) : ";
					cin >> tg;
					d.tangkn(tg).xuat();
					break;
				case 2:
					cout << "Giam thoi gian : " << endl;
					cout << "tong thoi gian giam (ngay) : ";
					cin >> tg;
					d.giamkn(tg).xuat();
					break;
				case 3:
					break;
				default:
					cout << " Ban chon tu 1 --> 3" << endl;
				}
			} while (cn != 3);
			break;
		case 3:
			thu = d.thungay(dn);
			break;
		case 4:
			break;
		default:
			cout << " Ban chon tu 1 --> 4" << endl;
		}
	} while (c != 4);

	return 0;
}