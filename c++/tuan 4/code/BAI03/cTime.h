#pragma once
#include <iostream>
using namespace std;
class cTime
{
private:
	int hour, minutes, second;
public:
	cTime(int = 0, int = 0, int = 0);
	cTime operator+(const int&);
	cTime operator-(const int&);

	void operator++();
	void operator--();

	friend ostream& operator<<(ostream& out, const cTime& a);
	friend istream& operator>>(istream& in, cTime& a);
	~cTime();
};

