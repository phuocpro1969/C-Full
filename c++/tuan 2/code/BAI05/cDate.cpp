#include "cDate.h"
#include <iostream>
using namespace std;

cDate::cDate()
{
}

cDate::cDate(int d, int m, int y)
{
	if (d <= max_day(m,y) && kt_month(m))
	{
		setd(d,m,y);
		setm(m);
		sety(y);
	}
	else
		cout << "Nhap sai thong tin" << endl;
}

bool cDate::kt_month(int m)
{
	return (1 <= m && m <= 12);
}

bool cDate::kt_namnhuan(int y)
{
	return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int cDate::max_day(int m, int y)
{
	switch (m)
	{
	case 2:
		if (kt_namnhuan(y))
			return 29;
		else
			return 28;
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	default :
		return 30;
	}
}

void cDate::setd(int d, int m, int y)
{
	if (d <= max_day(m, y))
		ngay = d;
}

void cDate::setm(int m)
{
	if (kt_month(m))
		thang = m;
}

void cDate::sety(int y)
{
	nam = y;
}

int cDate::getd()
{
	return ngay;
}

int cDate::getm()
{
	return thang;
}

int cDate::gety()
{
	return nam;
}

int cDate::doingay()
{
	bool kt = kt_namnhuan(nam);
	switch (thang)
	{
	case 1:
		return ngay;
	case 2:
		return 31 + ngay;
	case 3:
		if (kt)
			return 31 + 29 + ngay;
		else
			return 31 + 28 + ngay;
	case 4:
		if (kt)
			return 31 + 29 + 31 + ngay;
		else
			return 31 + 28 + 31 + ngay;
	case 5:
		if (kt)
			return 31 + 29 + 31 + 30 + ngay;
		else
			return 31 + 28 + 31 + 30 + ngay;
	case 6:
		if (kt)
			return 31 + 29 + 31 + 30 + 31 + ngay;
		else
			return 31 + 28 + 31 + 30 + 31 + ngay;
	case 7:
		if (kt)
			return 31 + 29 + 31 + 30 + 31 + 30 + ngay;
		else
			return 31 + 28 + 31 + 30 + 31 + 30 + ngay;
	case 8:
		if (kt)
			return 31 + 29 + 31 + 30 + 31 + 30 + 31 + ngay;
		else
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + ngay;
	case 9:
		if (kt)
			return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + ngay;
		else
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + ngay;
	case 10:
		if (kt)
			return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + ngay;
		else
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + ngay;
	case 11:
		if (kt)
			return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + ngay;
		else
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + ngay;
	case 12:
		if (kt)
			return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + ngay;
		else
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + ngay;
	}
}

void cDate::update()
{
	int d, m, y;
	cout << "Update Date : " << endl;
	cout << " Day   : ";
	cin >> d;
	cout << " Month : ";
	cin >> m;
	cout << " Year  : ";
	cin >> y;

	if (d <= max_day(m, y) && kt_month(m))
	{
		setd(d, m, y);
		setm(m);
		sety(y);
		cout << "Update thanh cong" << endl;
		xuat();
	}
	else
		cout << "Update that bai" << endl;
}

void cDate::xuat()
{
	cout << "Ngay : " << ngay << ", Thang : " << thang << ", Nam : " << nam << endl;
}

void cDate::nhap()
{
	int d, m, y;
	cout << "Update Date : " << endl;
	cout << " Day   : ";
	cin >> d;
	cout << " Month : ";
	cin >> m;
	cout << " Year  : ";
	cin >> y;

	if (d <= max_day(m, y) && kt_month(m))
	{
		setd(d, m, y);
		setm(m);
		sety(y);
		xuat();
	}
	else
		cout << "Thong tin sai" << endl;
}

cDate cDate::tangkn(int k)
{
	cDate kq;
	kq.setd(ngay, thang, nam);
	kq.setm(thang);
	kq.sety(nam);
	kq.ngay += k;
	int max = max_day(kq.thang, kq.nam);
	while (kq.ngay > max)
	{
		kq.ngay -= max;
		kq.thang++;
		if (kq.thang == 13)
		{
			kq.thang = 1;
			kq.nam++;
		}
		max = max_day(kq.thang, kq.nam);
	}

	setd(kq.ngay, kq.thang, kq.nam);
	setm(kq.thang);
	sety(kq.nam);

	return kq;
}

cDate cDate::giamkn(int k)
{
	cDate kq;
	kq.setd(ngay, thang, nam);
	kq.setm(thang);
	kq.sety(nam);
	kq.ngay -= k;
	int max = max_day(kq.thang, kq.nam);
	while (kq.ngay <1)
	{
		kq.ngay += max;
		kq.thang--;
		if (kq.thang == 0)
		{
			kq.thang = 12;
			kq.nam--;
		}
		max = max_day(kq.thang, kq.nam);
	}

	setd(kq.ngay, kq.thang, kq.nam);
	setm(kq.thang);
	sety(kq.nam);

	return kq;
}


int cDate::thungay(cDate d)
{
	cDate kq;
	cDate dtbig, dtsmall;
	kq.setd(d.ngay, d.thang, d.nam);
	kq.setm(d.thang);
	kq.sety(d.nam);
	if (kq.nam > nam)
	{
		dtbig.setd(kq.ngay, kq.thang, kq.nam);
		dtbig.setm(kq.thang);
		dtbig.sety(kq.nam);

		dtsmall.setd(ngay, thang, nam);
		dtsmall.setm(thang);
		dtsmall.sety(nam);
	}
	else
		if (kq.nam == nam)
		{
			if (kq.thang > thang)
			{
				dtbig.setd(kq.ngay, kq.thang, kq.nam);
				dtbig.setm(kq.thang);
				dtbig.sety(kq.nam);

				dtsmall.setd(ngay, thang, nam);
				dtsmall.setm(thang);
				dtsmall.sety(nam);
			}
			else
				if (kq.thang == thang)
					if (kq.ngay > ngay)
					{
						dtbig.setd(kq.ngay, kq.thang, kq.nam);
						dtbig.setm(kq.thang);
						dtbig.sety(kq.nam);

						dtsmall.setd(ngay, thang, nam);
						dtsmall.setm(thang);
						dtsmall.sety(nam);
					}
		}
		else
		{
			dtsmall.setd(kq.ngay, kq.thang, kq.nam);
			dtsmall.setm(kq.thang);
			dtsmall.sety(kq.nam);

			dtbig.setd(ngay, thang, nam);
			dtbig.setm(thang);
			dtbig.sety(nam);
		}
	int ng = dtsmall.tru(dtbig)%7;
	switch (ng)
	{
	case 0:
		cout << "Thu hai" << endl;
		break;
	case 1:
		cout << "Thu ba" << endl;
		break;
	case 2:
		cout << "Thu tu" << endl;
		break;
	case 3:
		cout << "Thu nam" << endl;
		break;
	case 4:
		cout << "Thu sau" << endl;
		break;
	case 5:
		cout << "Thu bay" << endl;
		break;
	case 6:
		cout << "Chu nhat" << endl;
		break;
	}
	return 0;
}

int cDate::tru(cDate s2)
{
	int tong = 0;

	if (nam == s2.nam)
	{
		if (thang != s2.thang)
		{
			for (int i = thang + 1; i <= s2.thang - 1;i++)
				tong += max_day(i, nam);
			tong = tong + max_day(thang, nam) - ngay + s2.ngay +2;
		}
		else
		{
			if (ngay != s2.ngay)
				tong = tong + s2.ngay - ngay + 1;
			else
				tong = 0;
		}
	}
	else
	{
		for (int i = (nam + 1); i <= (s2.nam - 1); i++)
			if (kt_namnhuan(nam))
				tong += 366;
			else
				tong += 365;
		
		tong = tong + max_day(thang, nam) - ngay;
		for (int i = thang + 1; i <= 12; i++)
			tong += max_day(i, nam);

		for (int i = 1; i <= s2.thang-1; i++)
			tong += max_day(i, s2.nam);
		tong = tong + ngay ;
	}

	return tong;
}

cDate::~cDate()
{
}
