#include "cDate.h"

cDate::cDate()
{
}

cDate::~cDate(void)
{
}

bool cDate::check(const int& d, const int& m, const int& y)
{
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d <= 0 || d > 31)
			return false;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (d <= 0 || d > 30)
			return false;
		break;
	case 2:
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		{
			if (d <= 0 || d > 29)
				return false;
		}
		else
			if (d <= 0 || d > 28)
				return false;
		break;
	default:
		return false;
	}
	return true;
}

istream& operator>>(istream & in, cDate & d)
{
	bool k;
	do
	{
		k = false;
		cout << "ngay = ";
		in >> d.ngay;

		cout << "thang = ";
		in >> d.thang;

		cout << "nam = ";
		in >> d.nam;

		k = d.check(d.ngay, d.thang, d.nam);

		if (!k) cout << "Khong hop le" << endl;
	} while (!k);
	return in;
}

ostream& operator<<(ostream & out, const cDate & d)
{
	out << d.ngay << "/" << d.thang << "/" << d.nam;
	return out;
}

cDate cDate::operator+(const int& x)
{
	cDate d;
	d.ngay = ngay;
	d.thang = thang;
	d.nam = nam;

	int k = d.ngay + x;
	do
	{
		switch (d.thang)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (k > 31)
			{
				d.thang++;
				if (d.thang > 12)
				{
					d.thang = 1;
					d.nam++;
				}
				k -= 31;
			}
			else
			{
				d.ngay = k;
				k = 0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (k > 30)
			{
				d.thang++;
				k -= 30;
			}
			else
			{
				d.ngay = k;
				k = 0;
			}
			break;
		case 2:
			if (d.nam % 400 == 0 || (d.nam % 4 == 0 && d.nam % 100 != 0))
			{
				if (k > 29)
				{
					d.thang++;
					k -= 29;
				}
				else
				{
					d.ngay = k;
					k = 0;
				}
			}
			else
			{
				if (k > 28)
				{
					d.thang++;
					k -= 28;
				}
				else
				{
					d.ngay = k;
					k = 0;
				}
			}
			break;
		default:
			break;
		}
	} while (k > 0);
	return d;
}

cDate cDate::operator-(const int& x)
{
	cDate d;
	d.ngay = ngay;
	d.thang = thang;
	d.nam = nam;

	int k = x;
	do
	{
		if (d.ngay > k)
		{
			d.ngay -= k;
			k = 0;
		}
		else
		{
			k -= d.ngay;
			d.thang--;
			switch (d.thang)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				d.ngay = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				d.ngay = 30;
				break;
			case 2:
				if (d.nam % 400 == 0 || (d.nam % 4 == 0 && d.nam % 100 != 0))
					d.ngay = 29;
				else
					d.ngay = 28;
				break;
			case 0:
				d.thang = 12;
				d.nam--;
				d.ngay = 31;
				break;
			}
		}
	} while (k > 0);
	return d;
}

long long cDate::operator-(const cDate & d)
{
	cDate x;
	x.ngay = ngay;
	x.thang = thang;
	x.nam = nam;

	long long a = x.ngay;
	do
	{
		switch (x.thang)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			a += 31;
			x.thang--;
			if (x.thang == 0)
			{
				x.nam--;
				x.thang = 12;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			a += 30;
			x.thang--;
			break;

		case 2:
			if (x.nam % 400 == 0 || (x.nam % 4 == 0 && x.nam % 100 != 0))
			{
				a += 29;
				x.thang--;
			}
			else
			{
				a += 28;
				x.thang--;
			}
			break;
		}
	} while (x.nam > 0);

	x.ngay = d.ngay;
	x.thang = d.thang;
	x.nam = d.nam;
	long long b = x.ngay;
	do
	{
		switch (x.thang)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			b += 31;
			x.thang--;
			if (x.thang == 0)
			{
				x.nam--;
				x.thang = 12;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			b += 30;
			x.thang--;
			break;

		case 2:
			if (x.nam % 400 == 0 || (x.nam % 4 == 0 && x.nam % 100 != 0))
			{
				b += 29;
				x.thang--;
			}
			else
			{
				b += 28;
				x.thang--;
			}
			break;
		}
	} while (x.nam > 0);
	return a - b;
}

void cDate::operator++()
{
	ngay++;
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (ngay > 31)
		{
			ngay = 1;
			thang++;
			if (thang == 13)
			{
				thang = 1;
				nam++;
			}
		}
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if (ngay > 30)
		{
			ngay = 1;
			thang++;
		}
		break;

	case 2:
		if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
		{
			if (ngay > 29)
			{
				ngay = 1;
				thang++;
			}
			else
				if (ngay > 28)
				{
					ngay = 1;
					thang++;
				}
		}
		break;

	default:
		break;
	}
}

void cDate::operator--()
{
	ngay--;
	if (ngay == 0)
	{
		thang--;
		switch (thang)
		{
		case 0:
			ngay = 31;
			thang = 12;
			nam--;
			break;

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			ngay = 31;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			ngay = 30;
			break;

		case 2:
			if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
				ngay = 29;
			else
				ngay = 28;
			break;
		default:
			break;
		}
	}
}