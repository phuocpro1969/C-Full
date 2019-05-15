#include "cDathuc.h"

int main()
{
	float a[] = { 1.0f, -1.2f };
	float k;
	cDathuc f1;
	cDathuc f2;
	cin >> f1;
	cin >> f2;
	cout << "F1 = ";
	cout << f1 << endl;
	cout << "F2 = ";
	cout << f2 << endl;
	cout << "k = ";
	cin >> k;
	cDathuc t = f1 + f2;
	cDathuc h = f1 - f2;
	cDathuc tich1 = f1 * f2;
	cout << "Tong 2 da thuc : ";
	cout << t << endl;
	cout << "Hieu 2 da thuc : "; 
	cout << h << endl;
	cout << "Tich 2 da thuc : "; 
	cout << tich1 << endl;
	cDathuc tich2 = f1 * k;
	cout << "Tich da thuc f1 voi so <<(" << k << "): ";
	cout << tich2;
}