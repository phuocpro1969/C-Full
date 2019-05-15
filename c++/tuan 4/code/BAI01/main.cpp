#include "cSoPhuc.h"
int main()
{
	cSoPhuc a, b, c;
	cin >> a >> b;
	cout <<"Tong   : "<< a + b << endl;
	cout <<"Hieu   : "<< a - b << endl;
	cout <<"Tich   : "<< a * b << endl;
	cout <<"Thuong : "<< a / b << endl;

	if (a > b)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	if (a >= b)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	if (a < b)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	if (a <= b)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	if (a == b)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	if (a != b)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}