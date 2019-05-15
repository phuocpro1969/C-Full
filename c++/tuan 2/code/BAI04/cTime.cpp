#include "cTime.h"
#include <iostream>
using namespace std;

cTime::cTime()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

cTime::cTime(int t)
{
	hours = (t / 3600) % 24;
	minutes = (t % 3600) / 60;
	seconds = (t % 3600) % 60;
}

cTime::cTime(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

void cTime::seth(int h)
{
	if(kt_gio(h))
	hours = h;
}

void cTime::setm(int m)
{
	if (kt_phut_giay(m))
		minutes = m;
}

void cTime::sets(int s)
{
	if (kt_phut_giay(s))
		seconds = s;
}

int cTime::get_hour()
{
	return hours;
}

int cTime::get_minute()
{
	return minutes;
}

int cTime::get_second()
{
	return seconds;
}

void cTime::nhap()
{
	khoitao:
	try
	{
		do
		{
			cout << "Nhap gio  : ";
			cin >> hours;
		} while (!kt_gio(hours));

		do
		{
			cout << "Nhap phut : ";
			cin >> minutes;
		} while (!kt_phut_giay(minutes));

		do
		{
			cout << "Nhap giay : ";
			cin >> seconds;
		} while (!kt_phut_giay(seconds));
	}
	catch (int t)
	{
		cout << "Nhap sai";
		goto khoitao;
	}
}

bool cTime::kt_gio(int h)
{
	return (h >= 0 && h < 24);
}

bool cTime::kt_phut_giay(int t)
{
	return (t >= 0 && t < 60);
}

void cTime::xuat()
{
	cout << hours<<" Gio, " << minutes << " Phut, " << seconds << " Giay " << endl;
}

int cTime::doi_giay()
{
	return hours * 3600 + minutes * 60 + seconds;
}

cTime cTime::tangks(int k)
{
	cTime t;
	t.hours = hours;
	t.minutes = minutes;
	t.seconds = seconds;
	int t2 = t.doi_giay() + k;
	seth(t.hours);
	setm(t.minutes);
	sets(t.seconds);
	seth(cTime(t2).hours);
	setm(cTime(t2).minutes);
	sets(cTime(t2).seconds);
	return cTime(t2);
}


cTime cTime::giamks(int k)
{
	cTime t;
	t.hours = hours;
	t.minutes = minutes;
	t.seconds = seconds;
	int t2 = t.doi_giay() - k;
	if (t2 >= 0)
	{
		seth(cTime(t2).hours);
		setm(cTime(t2).minutes);
		sets(cTime(t2).seconds);
		return cTime(t2);
	}
	else
	{
		cout << "khong giam time duoc" << endl;
		return t;
	}
}

void cTime::update()
{
	int h, m, s;
		cout << "Nhap gio update : ";
		cin >> h;

		cout << "Nhap phut update : ";
		cin >> m;

		cout << "Nhap giay update : ";
		cin >> s;
		
		if (kt_gio(h) && kt_phut_giay(m) && kt_phut_giay(s))
		{
			seth(h);
			setm(m);
			sets(s);
			xuat();
		}
		else
			cout << "Nhap sai khong update thanh cong" <<endl;
}

cTime::~cTime()
{
}
