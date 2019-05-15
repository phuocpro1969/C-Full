#include "cPhanSo.h"

int main()
{
	cPhanSo a, b;
	cin >> a >> b;
	cout << a << endl;
	cout << b << endl;

	cout << "Tong   : " << a + b << endl;
	cout << "Hieu   : " << a - b << endl;
	cout << "Tich   : " << a * b << endl;
	cout << "Thuong : " << a / b << endl;

	cout << "so sanh > : "; 
	if (a > b)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	cout << "so sanh >= : ";
	if (a >= b)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	cout << "so sanh < : ";
	if (a < b)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	cout << "so sanh <= : ";
	if (a <= b)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	return 0;
}