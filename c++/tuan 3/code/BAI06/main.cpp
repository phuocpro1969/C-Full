#include "cListCandidate.h"

int main()
{
	cListCandidate ds;
	cout << "Nhap danh sach thi sinh" << endl;
	ds.nhap();
	cout << endl;

	cout << "Danh sach thi sinh" << endl;
	ds.xuat();
	cout << endl;

	cout << "Danh sach thi sinh tong diem > 15" << endl;
	ds.tongdiemlon15();
	cout << endl;

	cout << "Thong tin thi sinh tong 3 mon cao nhat " << endl;
	ds.cttsmax();
	cout << endl;

	cout << " Danh sach thi sinh duoc sap xep qua tong 3 mon" << endl;
	ds.sort();
}