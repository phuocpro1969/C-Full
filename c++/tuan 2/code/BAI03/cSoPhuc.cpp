#include "cSoPhuc.h"
#include <iostream>
using namespace std;



cSoPhuc::cSoPhuc()
{
	fpthuc = 0;
	fpao = 0;
}

void cSoPhuc::nhapsp()
{
	cout << "Gia tri so phuc :" << endl;
	cout << "Nhap phan thuc : ";
	cin >> fpthuc;
	cout << "Nhap phan ao : ";
	cin >> fpao;
}

void cSoPhuc::xuatsp()
{
	cout << "So phuc : " << fpthuc << "+" << fpao <<"i"<< endl;
}

cSoPhuc cSoPhuc::congsp(cSoPhuc sp2)
{
	cSoPhuc kq;
	kq.fpthuc = fpthuc + sp2.fpthuc;
	kq.fpao = fpao + sp2.fpao;
	return kq;
}

cSoPhuc cSoPhuc::trusp(cSoPhuc sp2)
{
	cSoPhuc kq;
	kq.fpthuc = fpthuc - sp2.fpthuc;
	kq.fpao = fpao - sp2.fpao;
	return kq;
}

cSoPhuc cSoPhuc::nhansp(cSoPhuc sp2)
{
	cSoPhuc kq;
	kq.fpthuc = fpthuc * sp2.fpthuc - fpao * sp2.fpao;
	kq.fpao = fpthuc * sp2.fpao + fpao * sp2.fpthuc;
	return kq;
}

cSoPhuc cSoPhuc::chiasp(cSoPhuc sp2)
{
	cSoPhuc kq;
	kq.fpthuc = (fpthuc * sp2.fpthuc + fpao * sp2.fpao) / (sp2.fpthuc * sp2.fpthuc + sp2.fpao * sp2.fpao);
	kq.fpao = (sp2.fpthuc * fpao - fpthuc * sp2.fpao) / (sp2.fpthuc * sp2.fpthuc + sp2.fpao * sp2.fpao);
	return kq;
}

cSoPhuc::~cSoPhuc()
{
}
