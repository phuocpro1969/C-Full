#include "cPhanSo.h"
#include <iostream>

using namespace std;

int main()
{
	cPhanSo ps1, ps2;
	//nhap
	ps1.nhapps();
	ps2.nhapps();
	//xuat
	ps1.xuatps();
	ps2.xuatps();
	//cong
	ps1.congps(ps2).rutgonps().xuatps();
	//tru
	ps1.trups(ps2).rutgonps().xuatps();
	//nhan
	ps1.nhanps(ps2).rutgonps().xuatps();
	//chia
	ps1.chiaps(ps2).rutgonps().xuatps();

	return 0;
}