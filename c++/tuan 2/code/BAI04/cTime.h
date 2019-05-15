#pragma once
class cTime
{
private:
	int hours;
	int minutes;
	int seconds;

public:
	cTime();
	cTime(int, int, int);
	cTime(int);
	void seth(int);
	void setm(int);
	void sets(int);
	int get_hour();
	int get_minute();
	int get_second();

	void nhap();
	void xuat();
	void update();
	bool kt_gio(int);
	bool kt_phut_giay(int);
	int doi_giay();
	cTime tangks(int);
	cTime giamks(int);

	~cTime();
};

