#include "cMatrix.h"

cMatrix::cMatrix()
{
	matran = NULL;
}

cMatrix::cMatrix(int r, int c)
{
	row = r; column = c;
	matran = new double* [row];
	for (int i = 0; i < row; i++)
		matran[i] = new double[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matran[i][j] = 0;
}

cMatrix::cMatrix(const cMatrix& a)
{
	row = a.row;
	column = a.column;
	matran = new double* [a.row];

	for (int i = 0; i < a.row; i++)
		matran[i] = new double[a.column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matran[i][j] = a.matran[i][j];
}

cMatrix::~cMatrix()
{
	for (int i = 0; i < row; i++)
		delete[]matran[i];
	delete[]matran;
	matran = NULL;
	row = 0; column = 0;
}

ostream& operator<<(ostream& out, const cMatrix& a) {
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.column; j++)
			out << a.matran[i][j] << "\t";
		out << "\n";
	}
	return out;
}

istream& operator>>(istream & in, cMatrix& a) {
	cout << "nhap so hang, so cot ma tran: ";
	in >> a.row >> a.column;
	a.matran = new double* [a.row];

	cout << " Nhap ma tran : " << endl;
	for (int i = 0; i < a.row; i++)
		a.matran[i] = new double[a.column];
	for (int i = 0; i < a.row; i++)
		for (int j = 0; j < a.column; j++)
			in >> a.matran[i][j];
	return in;
}

cMatrix cMatrix::operator+(const cMatrix& a)
{
	cMatrix b(0, 0);
	if (row == a.row && column == a.column)
	{
		cMatrix b(row, column);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				b.matran[i][j] = matran[i][j] + a.matran[i][j];
		return b;
	}
	else
		cout << " Khong cong duoc" << endl;
	return b;
}

cMatrix cMatrix::operator-(const cMatrix& a)
{
	cMatrix b(0, 0);
	if (row == a.row && column == a.column)
	{
		cMatrix b(row, column);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				b.matran[i][j] = matran[i][j] - a.matran[i][j];
		return b;
	}
	else
		cout << " Khong cong duoc" << endl;
	return b;
}

cMatrix cMatrix::operator*(int& k)
{
	cMatrix b(row, column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			b.matran[i][j] = matran[i][j] * k;
	return b;
}

cMatrix cMatrix::operator*(cVector& a)
{
	cMatrix b(0, 0);
	if (column == a.n)
	{
		cMatrix b(row, a.n);

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				for (int k = 0; k < a.n; k++)
					b.matran[i][j] += matran[i][k] * a.vector[j];

		return b;
	}
	return b;
}

cMatrix cMatrix::operator*(const cMatrix& a)
{
	cMatrix b(0, 0);
	if (column == a.row)
	{
		cMatrix b(row, a.column);

		for (int i = 0; i < row; i++)
			for (int j = 0; j < a.column; j++)
				for (int k = 0; k < column; k++)
					b.matran[i][j] += matran[i][k] * a.matran[k][j];

		return b;
	}
	else
		cout << "Khong the nhan" << endl;
	return b;
}
