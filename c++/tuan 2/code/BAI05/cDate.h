#pragma once
class cDate
{
private:
	int ngay;
	int thang;
	int nam;
public:
	cDate();
	cDate(int, int, int);

	void setd(int,int,int);
	void setm(int);
	void sety(int);

	int getd();
	int getm();
	int gety();

	void update();
	int doingay();

	int max_day(int,int);
	bool kt_month(int);
	bool kt_namnhuan(int);

	void nhap();
	void xuat();

	cDate tangkn(int);
	cDate giamkn(int);
	int tru(cDate);
	int thungay(cDate);
	~cDate();
};

