#include "cCandidate.h"

cCandidate::cCandidate()
{
}

cCandidate::cCandidate(string ma, string name, string date, int t, int v, int a)
{
	setmats(ma);
	settents(name);
	setngaysinhts(date);
	settoan(t);
	setvan(v);
	setanh(a);
}

void cCandidate::setmats(string ma)
{
	mats = ma;
}

void cCandidate::settents(string name)
{
	tents = name;
}

void cCandidate::setngaysinhts(string date)
{
	ngaysinhts = date;
}

void cCandidate::settoan(int t)
{
	toan = t;
}

void cCandidate::setvan(int v)
{
	van = v;
}

void cCandidate::setanh(int a)
{
	anh = a;
}

string cCandidate::getmats()
{
	return mats;
}

string cCandidate::gettents()
{
	return tents;
}

string cCandidate::getngaysinhts()
{
	return ngaysinhts;
}

int cCandidate::gettoan()
{
	return toan;
}

int cCandidate::getvan()
{
	return van;
}

int cCandidate::getanh()
{
	return anh;
}

void cCandidate::nhap()
{
	string ma;
	string name;
	string date;
	int t;
	int v;
	int a;
	cout << "Nhap thong tin thi sinh : " << endl;
	
	cout << "Ma so      : ";
	cin >> ma;

	cout << "Ho ten     : ";
	cin >> name;

	cout << "Ngay sinh  : ";
	cin >> date;

	cout << " Diem toan : ";
	cin >> t;

	cout << " Diem van  : ";
	cin >> v;

	cout << " Diem anh  : ";
	cin >> a;

	setmats(ma);
	settents(name);
	setngaysinhts(date);
	settoan(t);
	setvan(v);
	setanh(a);
}

void cCandidate::xuat()
{
	cout << "Thong tin thi sinh : " << endl;

	cout << "Ma so      : " << mats << endl;

	cout << "Ho ten     : " << tents << endl;

	cout << "Ngay sinh  : " << ngaysinhts << endl;

	cout << " Diem toan : " << toan << endl;

	cout << " Diem van  : " << van << endl;
	
	cout << " Diem anh  : " << anh << endl;
}

int cCandidate::tongdiem()
{
	return (toan + van + anh);
}

cCandidate::~cCandidate()
{
}
