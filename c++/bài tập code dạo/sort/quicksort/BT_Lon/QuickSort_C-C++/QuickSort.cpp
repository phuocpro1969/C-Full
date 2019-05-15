#include <stdio.h>
#include <time.h>
#include <cstdlib>

#define vao "QuickSort.inp"
#define ra "QuickSort.out"

long n;
long a[1000000];

void nhap()
{
	FILE *f1;
    f1 = fopen(vao, "r");
    fscanf(f1, "%d", &n);
    for (long i = 0; i < n; i++)
    	fscanf(f1, "%d", &a[i]);
    fclose(f1);	
}

void quick(long l, long r)
{
	long i, j;
	i = l;
	j = r;
	long pivot = a[(l+r)/2];	//Chot trung vi
	//long pivot = a[l]; 			//Chot la gia tri dau tien
	//long pivot = a[rand()];
	do
	{
		while (a[i] < pivot)	i++;
		while (a[j] > pivot)	j--;
		if (i <= j)
		{
			if (i < j)
			{
				long t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			i++;
			j--;
		}
	}
	while (i <= j);
	if (l < j)	
		quick(l, j);
	if (i < r)
		quick(i, r);
}
void insertion(long k)
{
	long x;
    a[0]=-1000000;
    for(long i=2;i<k;i++)
    {
        x=a[i];
        long j=i-1;
        //while((j>0)&&(x<a[j]))
        while(x<a[j])
        {
            a[j+1]=a[j];
            j--;
        } 
        a[j+1]=x;
    }
}
void xuly()
{
	quick(0, n - 1);
	//insertion(n-1);
}

void xuat()
{
	FILE *f2;
    f2 = fopen(ra, "w");    
    for(long i = 0; i < n; i++)
    	fprintf(f2, "%d ", a[i]);
    fclose(f2);	
}

int main()
{
	clock_t time;
    time = clock();	//Thoi diem bat dau
    nhap();
	xuly();
	xuat();
    time = clock() - time;	//Khoang thoi gian
    printf("\n%0.9f giay", time * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
