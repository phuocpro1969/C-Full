#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class cDathuc
{
private:
	float* hs;
	int n;
public:
	cDathuc();
	cDathuc(float a[], int);
	cDathuc(const cDathuc& f);
	~cDathuc();
	friend ostream& operator<<(ostream&, cDathuc&);
	friend istream& operator>>(istream&, cDathuc&);
	float operator[](int) const;
	bool operator==(const cDathuc&);
	cDathuc& operator=(const cDathuc&);
	cDathuc operator+(const cDathuc&);
	cDathuc operator-(const cDathuc&);
	cDathuc operator*(const cDathuc&);
	cDathuc operator*(float);
	float operator()(float)const;
	float evalue(float)const;
};

