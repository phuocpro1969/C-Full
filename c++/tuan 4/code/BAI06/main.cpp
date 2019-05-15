#include "cMatrix.h"

int main()
{
	int k;
	cMatrix a, b;
	cVector c;
	cin >> c; 
	cout << " Vector vua nhap : " << endl;
	cout << c;
	
	cin >> a; 
	cout << " Matrix vua nhap : " << endl;
	cout << a;

	cin >> b; 
	cout << " Matrix vua nhap : " << endl;
	cout << b;

	cout << "Tong 2 ma tran: \n"; 
	cout << a + b << endl;

	cout << "Hieu 2 ma tran: \n"; 
	cout << a - b << endl;

	cout << "tich 2 ma tran: \n" << a * b << endl;
	cout << "tich ma tran vs vector: \n" << a * c << endl;

	cout << "Tich ma tran voi 1 so k = "; cin >> k;
	cout << "tich ma tran dau tien voi so ("<<k<<") : \n " << a * k << endl;
	return 0;
}