#include "cChuoi.h"
#include <string.h>
#include <iostream>

using namespace std;

cChuoi::cChuoi(void )
{
	chuoi = new char[20];
	memset(chuoi, 0, 20);
	isl = 20;
}

cChuoi::cChuoi(int isize) 
{
	chuoi = new char[isize];
	memset(chuoi, 0, isize);
	isl = isize;
}

cChuoi::cChuoi(const char* value)
{
	if (value)
	{
		int isize = strlen(value) + 1;
		chuoi = new char[isize];
		memset(chuoi, 0, isize);
		isl = isize;
		memcpy(chuoi, value, isl);
	}
}

bool cChuoi::empty()
{
	if (chuoi)
	{
		if (memset(chuoi, 0, strlen(chuoi)) == 0)
			return true;
		else
			return false;
	}
}

int cChuoi::size() const
{
	if (chuoi)
		return strlen(chuoi);
	else
		return 0;
	
}

int cChuoi::data() const
{
	if (chuoi)
		return chuoi;
	else
		return NULL;
}

void cChuoi::copy(string b) 
{
	strcpy(chuoi, b);
}

void cChuoi::dao()
{

}
char cChuoi::upper()
{
	return upper(chuoi);
}
char cChuoi::lower()
{
	return lower(chuoi);
}

void cChuoi::nhap()
{
	cin.ignore();
	cout << "Nhap chuoi : ";
	getline(std::cin, chuoi);
}
void cChuoi::xuat()
{
	cout << chuoi;
}

cChuoi::~cChuoi()
{
	delete chuoi;
}
