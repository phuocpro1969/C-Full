#include <string>
#pragma once
class cChuoi
{
private:
	char *chuoi;
	int isl;
	const static int ipos = -1;

public:
	cChuoi(void);
	cChuoi(int);
	cChuoi(char*);
	bool empty();

	int size() const;
	char* data() const;

	void copy(string b);
	void dao();
	char upper();
	char lower();

	void nhap();
	void xuat();
	~cChuoi(void);
};

