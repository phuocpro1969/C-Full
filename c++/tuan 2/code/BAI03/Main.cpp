#include "cSoPhuc.h"

int main()
{
	cSoPhuc sp1, sp2;
	//nhap
	sp1.nhapsp();
	sp2.nhapsp();
	//xuat
	sp1.xuatsp();
	sp2.xuatsp();
	//cong
	sp1.congsp(sp2).xuatsp();
	//tru
	sp1.trusp(sp2).xuatsp();
	//nhan
	sp1.nhansp(sp2).xuatsp();
	//chia
	sp1.chiasp(sp2).xuatsp();
}