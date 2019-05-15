#pragma once
#include <iostream>
using namespace std;

class cSoPhuc
{
private:
	float t, a;
public:
	cSoPhuc(float = 0, float = 0);
	~cSoPhuc(void);
	float dodai();
	cSoPhuc operator+(const cSoPhuc&);
	cSoPhuc operator-(const cSoPhuc&);
	cSoPhuc operator*(const cSoPhuc&);
	cSoPhuc operator/(const cSoPhuc&);
	bool operator<(cSoPhuc&);
	bool operator<=(cSoPhuc&);
	bool operator>(cSoPhuc&);
	bool operator>=(cSoPhuc&);
	bool operator==(cSoPhuc&);
	bool operator!=(cSoPhuc&);

	friend ostream &operator<<(ostream& out, const cSoPhuc& a);
	friend istream &operator>>(istream& in, cSoPhuc& a);
};

