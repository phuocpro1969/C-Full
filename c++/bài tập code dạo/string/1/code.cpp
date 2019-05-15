#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string chuoi;
	fflush(stdin);
	getline(std::cin, chuoi);
	
	int arr_sl[123];
	int chuoi_vt[123];
	int vt[26];
	for (int i = 97;i<=123;i++)
	{
		arr_sl[i] = 0;
		chuoi_vt[i] = -1;
	}
	
	for (int i = 0; i< chuoi.size(); i++)
		{
			arr_sl[(int) chuoi[i]]++;
			chuoi_vt[(int) chuoi[i]] = i;
		}
		
	int i = 97, j,dem;
	while (arr_sl[i] == 0) i++;
	while (i<123)
	{
		j = i+1;
		while (j<123)
		{
			if ((arr_sl[j] == 0) && (chuoi_vt[j] == -1))
				j++;
			else
			if((arr_sl[j] != 0) && (chuoi_vt[j] > chuoi_vt[i]) && (j<123) && (i<=123))
			{
				i = j;
				j++;
			} else
			if ((arr_sl[j] != 0) && (chuoi_vt[j] < chuoi_vt[i]) && (j<123) && (i<=123))
			{
				arr_sl[j] = 0;
				chuoi_vt[j] = -1;
				j++;
			}
			else 
			{
				break;
			}
		}
		i = j; 
		while (arr_sl[i] == 0 && chuoi_vt[i] == -1 && i<123) i++;
	}
	
	dem = 0;
	for (int i = 97; i<123; i++)
	if ((arr_sl[i] == 0) && (chuoi_vt[i] == -1))
			dem++;
	cout << dem;
	return 0;
}