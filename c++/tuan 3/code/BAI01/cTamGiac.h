#pragma once
#include "cDiem.h"

class cTamGiac
{
	private:
		cDiem A, B, C;
	public:
		cTamGiac();
		cTamGiac(cDiem, cDiem, cDiem);
		void nhap();
		void xuat();
		void tt(float, float);
		void quay(float);
		void thuphong(float);
		~cTamGiac();
};

