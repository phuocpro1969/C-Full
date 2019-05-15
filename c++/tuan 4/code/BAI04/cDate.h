#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class cDate
{
private:
	int ngay, thang, nam;
public:
	cDate();
	~cDate(void);
	bool check(const int&, const int&, const int&);
	cDate operator+(const int&);
	cDate operator-(const int&);
	long long operator-(const cDate&);
	void operator++();
	void operator--();
	friend ostream& operator<<(ostream& out, const cDate&);
	friend istream& operator>>(istream& in, cDate&);
};
