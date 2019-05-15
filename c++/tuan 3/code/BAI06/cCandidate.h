#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class cCandidate
{
private:
	string mats;
	string tents;
	string ngaysinhts;
	int toan;
	int van;
	int anh;

public:
	cCandidate();
	cCandidate(string, string, string, int, int, int);
	void nhap();
	void xuat();
	int tongdiem();

	void setmats(string);
	void settents(string);
	void setngaysinhts(string);
	void settoan(int);
	void setvan(int);
	void setanh(int);

	string getmats();
	string gettents();
	string getngaysinhts();
	int gettoan();
	int getvan();
	int getanh();


	~cCandidate();
};
