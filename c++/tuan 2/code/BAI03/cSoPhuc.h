#pragma once
class cSoPhuc
{
private:
	float fpthuc;
	float fpao;
public:
	cSoPhuc();
	cSoPhuc(float, float);
	void nhapsp();
	void xuatsp();
	
	cSoPhuc congsp(cSoPhuc);
	cSoPhuc trusp(cSoPhuc);
	cSoPhuc nhansp(cSoPhuc);
	cSoPhuc chiasp(cSoPhuc);
	~cSoPhuc();
};

