#include "cTime.h"

cTime::cTime(int h, int m, int s)
{
	hour = (h < 0 || h > 23) ? 0 : h;
	minutes = (m < 0 || m > 59) ? 0 : m;
	second = (m < 0 || m > 59) ? 0 : s;
}


cTime::~cTime()
{
}

istream& operator>>(istream& in, cTime& a)
{
	cout << "h m s : ";
	in >> a.hour >> a.minutes >> a.second;
	return in;
}

ostream& operator<<(ostream& out, const cTime &a)
{
	if (a.hour < 0 || a.minutes < 0 || a.second < 0)out << "-";
	out << (a.hour < 10 && a.hour >= 0 ? "0" : "") << abs(a.hour) << ":" << (a.minutes < 10 && a.minutes >= 0 ? "0" : "") << abs(a.minutes) << ":" << (a.second < 10 && a.second >= 0 ? "0" : "") << abs(a.second);
	return out;
}

cTime cTime::operator+(const int& x)
{
	cTime kq;
	int m, h;

	m = (second + x) / 60;
	kq.second = (second + x) % 60;

	h = (minutes + m) / 60;
	kq.minutes = (minutes + m) % 60;

	kq.hour = hour + h;

	return kq;
}

cTime cTime::operator-(const int& x)
{
	cTime kq;
	int m, h;

	m = (second - x < 0) ? -1 : 0;
	kq.second = (m == -1) ? (60 + second - x) : (second - x);

	h = (m + minutes < 0) ? -1 : 0;
	kq.minutes = (h == -1) ? (60 + minutes + m) : (m + minutes);

	kq.hour = hour + h;

	if (kq.hour < 0)
	{
		m = (x - second < 0) ? -1 : 0;
		kq.second = (m == -1) ? (60 - second + x) : (x - second);

		h = (m - minutes < 0) ? -1 : 0;
		kq.minutes = (h == -1) ? (60 - minutes + m) : (m - minutes);

		kq.hour = hour - h;

		if (kq.hour == 0)
		{
			if (kq.minutes != 0)
				kq.minutes = 0 - kq.minutes;
			else
				if (kq.second != 0)
					kq.second = 0 - kq.second;
		}
		return kq;
	}
	return kq;
}

void cTime::operator++()
{
	cTime kq;
	int h, m;

	m = (second + 1) / 60;
	kq.second = (second + 1) % 60;

	h = (minutes + m) / 60;
	kq.minutes = (minutes + m) % 60;

	kq.hour = hour + h;

	hour = kq.hour;
	minutes = kq.minutes;
	second = kq.second;
}

void cTime::operator--()
{
	cTime kq;
	int h, m;
	m = (second - 1 < 0) ? -1 : 0;
	kq.second = (m == -1) ? (60 + second - 1) : (second - 1);
	h = (minutes + m) < 0 ? -1 : 0;
	kq.minutes = (h == -1) ? (60 + minutes + m) : (minutes + m);
	kq.hour = h + hour;
	if (kq.hour < 0)
	{
		m = (1 - second < 0) ? -1 : 0;
		kq.second = (m == -1) ? (60 - second + 1) : (-second + 1);
		h = (m - minutes) < 0 ? -1 : 0;
		kq.minutes = (h == -1) ? (60 - minutes + m) : (m - minutes );
		kq.hour = -(h - hour);
		if (kq.hour == 0)
		{
			if (kq.minutes != 0) kq.minutes = 0 - kq.minutes;
			else if (kq.second != 0) kq.second = 0 - kq.second;
		}
		hour = kq.hour;
		minutes = kq.minutes;
		second = kq.second;
	}
	hour = kq.hour;
	minutes = kq.minutes;
	second = kq.second;
}