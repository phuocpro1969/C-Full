#include "cTamGiac.h"

cTamGiac::cTamGiac()
{
}

cTamGiac::cTamGiac(cDiem x, cDiem y, cDiem z)
{
	A = x;
	B = y;
	C = z;
}

cTamGiac::~cTamGiac()
{
}

void cTamGiac::nhap()
{
	int kq;
	do
	{
		kq = 0;
		cout << "Nhap dinh A" << endl;
		A.nhap();
		cout << "Nhap dinh B" << endl;
		B.nhap();
		cout << "Nhap dinh C" << endl;
		C.nhap();

		cDiem d, e;
		d = A.vector(B);
		e = A.vector(C);

		if (float(d.getox() * e.getoy()) == float(d.getoy() * e.getox()))
		{
			kq = 1;
			cout << "Day khon phai tam giac. Moi nhap lai." << endl;
		};
	} while (kq == 1);
}

void cTamGiac::xuat()
{
	cout << "Tam giac duoc tao boi 3 dinh : ";
	A.xuat(); cout << ", "; B.xuat(); cout << ", "; C.xuat();
	cout << endl;
}

void cTamGiac::tt(float m, float n)
{
	A.tt(m, n);
	B.tt(m, n);
	C.tt(m, n);
}

void cTamGiac::quay(float rad)
{
	A.quay(rad);
	B.quay(rad);
	C.quay(rad);
}

void cTamGiac::thuphong(float k)
{
	A.setxy(A.getox() * k, A.getoy() * k);
	B.setxy(B.getox() * k, B.getoy() * k);
	C.setxy(C.getox() * k, C.getoy() * k);
}