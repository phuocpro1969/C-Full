#include "cTime.h"
#include <iostream>
using namespace std;

int main()
{
	cTime t;
	//nhap
	t.nhap();
	//xuat
	t.xuat();
	int c,tg,cn;
	do
	{ 
		cout << "------------------------------------------" << endl;
		cout << "MENU" << endl;
		cout << "1.Update time" << endl;
		cout << "2.Tang/Giam time" << endl;
		cout << "3.Exit" << endl;
		cout << "Ban chon so : ";
		cin >> c;
		switch (c)
		{
		case 1:
			do
			{
				cout << "------------------------------------------" << endl;
				cout << "MENU" << endl;
				cout << "1.Update time" << endl;
				cout << "2.Exit" << endl;
				cout << "Ban chon so : ";
				cin >> cn;
				switch (cn)
				{
				case 1:
					cout << "Update time : " << endl;
					t.update();
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
					cout << "tong thoi gian tang (s) : ";
					cin >> tg;
					t.tangks(tg).xuat();
					break;
				case 2:
					cout << "Giam thoi gian : " << endl;
					cout << "tong thoi gian giam (s) : ";
					cin >> tg;
					t.giamks(tg).xuat();
					break;
				case 3:
					break;
				default:
					cout << " Ban chon tu 1 --> 3" << endl;
				}
			} while (cn != 3);
			break;
		case 3:
			break;
		default :
			cout << " Ban chon tu 1 --> 3" << endl;
		}
	} while (c != 3);
	return 0;
}