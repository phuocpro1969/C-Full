#include "cArray.h"



cArray::cArray()
{
}

void cArray::setn(int sl)
{
	sopt = sl;
}

int cArray::getn()
{
	return sopt;
}

cArray::cArray(int sl)
{
	setn(sl);
	arr = new long[sopt];
}

void cArray::random()
{
	srand(time(NULL));
	int so = 1 + rand() % 10000;
	setn(so);
	arr = new long[sopt];
	for (int i = 0; i < sopt; i++)
		arr[i] = rand();
}

int cArray::demx(long x)
{
	int dem = 0;
	for (int i = 0; i < sopt; i++)
		if (arr[i] == x)
			dem++;
	return dem;
}

void cArray::xuat()
{
	for (int i = 0; i < sopt; i++)
		cout << arr[i] << " ";
}

bool cArray::kt_tang()
{
	for (int i = 0; i < sopt; i++)
		if (arr[i] > arr[i + 1])
			return false;
	return true;
}

long cArray::tim_min_le()
{
	int vt = 0, i;
	long min = 0;
	for (i = 0; i < sopt; i++)
	if (arr[i] % 2 != 0)
	{
		min = arr[i];
		vt = i;
		break;
	}

	if (vt == sopt)
		return 0;

	for (i = vt + 1; i < sopt; i++)
	if ((arr[i] % 2 != 0) && (arr[i] < min))
		min = arr[i];
	return min;
}

long cArray::tim_max()
{
	int i;
	long max = arr[0];

	for (i = 1; i < sopt; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void cArray::prime()
{
	int max = tim_max();
	sangnt = new bool[max+1];

	for (int i = 0; i <= max + 1; i++)
		sangnt[i] = false;

	for (int i = 2; i <= max; i++)
		sangnt[i] = true;

	for (int i = 2; i * i <= max; ++i)
		if (sangnt[i])
			for (int j = i * i; j <= max; j += i)
				sangnt[j] = false;
}

long cArray::tim_max_snt()
{
	int vt = 0, i;
	long max = 0;
	for (i = 0; i < sopt; i++)
		if (sangnt[arr[i]])
		{
			max = arr[i];
			vt = i;
			break;
		}

	if (vt == sopt)
		return 0;

	for (i = vt + 1; i < sopt; i++)
		if ((sangnt[arr[i]]) && (arr[i] > max))
			max = arr[i];
	return max;
}

void cArray::quicksort(long arr[], int l, int r)
{
	long key;
	int i, j;
	if (l < r)
	{
		key = arr[(l+r)/2];
		i = l;
		j = r;

		while (i <= j)
		{
			while (arr[i] < key) i++;
			while (arr[j] > key) j--;
			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++; j--;
			}
		}
		if (i<r) quicksort(arr, i, r);
		if (j>l) quicksort(arr, l, j);
	}
}

void cArray::sort()
{
	quicksort(arr, 0, (sopt-1));
	xuat();
}

cArray::~cArray()
{
}