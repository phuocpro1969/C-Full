#pragma once
class cDiem
{
private :
	float ox;
	float oy;
public:
	cDiem();
	cDiem(float, float);
	void nhap();
	void xuat();
	cDiem tinhtien(float, float);
	void setOx(float);
	void setOy(float);
	float getOx();
	float getOy();
	~cDiem();
};

