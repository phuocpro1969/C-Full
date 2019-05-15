#include "cListCandidate.h"



cListCandidate::cListCandidate()
{
}

cListCandidate::cListCandidate(int s)
{
	setsots(s);
	list = new cCandidate[sots+1];
}

void cListCandidate::setsots(int s)
{
	sots = s;
	list = new cCandidate[sots+1];
}

int cListCandidate::getsots()
{
	return sots;
}

void cListCandidate::nhap()
{
	int so;
	cout << "Danh sach Thi sinh" << endl;
	cout << " So luong thi sinh : ";
	cin >> so;
	setsots(so);
	list = new cCandidate[so+1];

	for (int i = 0; i < so; i++)
	{
		cout << " Thi sinh thu " << (i+1) << endl;
		list[i].nhap();
	}
}

void cListCandidate::xuat()
{
	for (int i = 0; i < sots; i++)
	{
		cout << " Thi sinh thu " << i+1 << endl;
		list[i].xuat();
	}
}

void cListCandidate::tongdiemlon15()
{
	int j = 0;
	for (int i = 0; i < sots; i++)
		if (list[i].tongdiem() > 15)
	{
		j++;
		cout << " Thi sinh thu " << j << endl;
		list[i].xuat();
	}
}

int cListCandidate::vtmaxtd()
{
	int maxx = 0, vtr = 0;
	for (int i = 0; i < sots; i++)
		if (list[i].tongdiem() > maxx)
		{
			vtr = i;
			maxx = list[i].tongdiem();
		}
	return vtr;
}

void cListCandidate::cttsmax()
{
	int vt = vtmaxtd();
	list[vt].xuat();
}

void cListCandidate::sort()
{
	cCandidate* arr;
	arr = new cCandidate[sots + 1];
	for (int i = 0; i < sots; i++)
		arr[i] = list[i];
	quicksort(arr, 0, sots);
	for (int i = sots; i >= 0; i--)
		arr[i].xuat();
}



void cListCandidate::quicksort(cCandidate arr[], int l, int r)
{
	int key;
	int i, j;
	if (l < r)
	{
		key = arr[(l + r) / 2].tongdiem();
		i = l;
		j = r;

		while (i <= j)
		{
			while (int(arr[i].tongdiem()) < key) i++;
			while (int(arr[j].tongdiem()) > key) j--;
			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++; j--;
			}
		}
		if (i < r) quicksort(arr, i, r);
		if (j > l) quicksort(arr, l, j);
	}
}

cListCandidate::~cListCandidate()
{
}
