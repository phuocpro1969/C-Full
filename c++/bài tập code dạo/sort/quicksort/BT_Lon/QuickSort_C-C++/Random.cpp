#include <stdio.h>
#include <cstdlib> 
#include <ctime>

#define vao "Random.inp"
#define ra "Random.out"

long n, x, y;
long a[1000000];

void nhap()
{
	FILE *f1;
    f1 = fopen(vao, "r");
    fscanf(f1, "%d", &n);		//So phan tu cua day a[]
    fscanf(f1, "%d%d", &x, &y);	//Sinh ngau nhien cac a[i] thuoc doan [x, y], x < y
    fclose(f1);	
}

void xuly()
{
	FILE *f2;
    f2 = fopen(ra, "w"); 
	fprintf(f2, "%d\n", n);
	srand(time(0));
	for (long i = 0; i < n; i++)
		a[i] = x + rand() % (y - x + 1);	//Sinh a[i] thuoc doan [x, y]
    for(long i = 0; i < n; i++)
    	fprintf(f2, "%d ", a[i]);
    fclose(f2);			
}

int main()
{
    nhap();
	xuly();
    return 0;
}
