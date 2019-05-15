#pragma once
#include "cCandidate.h"

class cListCandidate
{
private:
	int sots;
	cCandidate* list;
public:
	cListCandidate();
	cListCandidate(int);
	void setsots(int);
	int getsots();
	void nhap();
	void xuat();
	void tongdiemlon15();
	int vtmaxtd();
	void cttsmax();
	void sort();
	void quicksort(cCandidate*, int, int);
	~cListCandidate();
};

