#include "cVector.h"

cVector::cVector()
{
	vector = NULL;
}

cVector::cVector(int d)
{
	n = d;
	vector = new int[n];
}

cVector::cVector(const cVector& a)
{
	n = a.n;
	vector = new int[n];
	for (int i = 0; i < a.n; i++)
		vector[i] = a.vector[i];
}

cVector::~cVector()
{
	delete[]vector;
}

istream& operator>>(istream& in, cVector& a) {
	cout << "nhap so luong phan tu cua vector: "; in >> a.n;
	a.vector = new int[a.n];
	cout << "nhap vector : " << endl;
	for (int i = 0; i < a.n; i++)
		in >> a.vector[i];
	return in;
}

ostream& operator<<(ostream& out, const cVector& a) {
	out << "(";
	for (int i = 0; i < a.n - 1; i++)
		out << a.vector[i] << " , ";
	out << a.vector[a.n - 1] << ")" << endl;
	return out;
}

cVector cVector::operator+(const cVector& a) {
	cVector b(a.n);
	for (int i = 0; i < n; i++)
		b.vector[i] = vector[i] + a.vector[i];
	return b;
}
cVector cVector::operator-(const cVector & a) {
	cVector b(a.n);
	for (int i = 0; i < a.n; i++)
		b.vector[i] = this->vector[i] - a.vector[i];
	return b;
}
cVector cVector::operator*(int& a) {
	cVector b(n);
	for (int i = 0; i < n; i++)
		b.vector[i] = a * vector[i];
	return b;
}
long cVector::scalar(cVector & a) {
	long Scalar = 0, f;
	for (int i = 0; i < n; i++) {
		f = vector[i] * a.vector[i];
		Scalar += f;
	}
	return Scalar;
}