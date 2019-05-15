#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class cArray
{
private:
	int sopt;
	long* arr;
	bool* sangnt;
public:
	cArray();
	void setn(int);
	int  getn();	
	long tim_max();
	void prime();
	cArray(int);
	void random();
	int demx(long);
	bool kt_tang();
	long tim_min_le();
	long tim_max_snt();
	void quicksort(long*, int , int);
	void sort();
	void xuat();
	~cArray();
};

