#include<iostream>
#include<math.h>
#define MAX 100
using namespace std;
void NhapMaTran(int a[][MAX], int &n)
{
    do
    {
        printf("\nNhap n: ");
        scanf("%d", &n);
        if(n < 1 || n > MAX)
        {
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    }while(n < 1 || n > MAX);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("\nNhap vao a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void XuatMaTran(int a[][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n\n");
    }
}

bool kiemtrachinhphuong(int n)
{
	int canbac2 = sqrt(n);
	return (canbac2 * canbac2 == n);
}

int sochinhphuong(int a[MAX][MAX],int n, int dong)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(kiemtrachinhphuong(a[dong][j]))
			{
				cout << a[dong][j] <<" ";
			}
		}
	}
}

void InChinhPhuongMaxDong(int a[MAX][MAX], int n)
{
	int max;
	int k;
	for(int i=0;i<n;i++)
	{
		max=-1;
		for(int j=0;j<n;j++)
		{
			if (kiemtrachinhphuong(a[i][j])) 
				max=a[i][j];
			for(int k=j+1;k<n;k++)
				if(kiemtrachinhphuong(a[i][k]) && a[i][k]>max) 
					max=a[i][k];
		}
		if (max!=-1) 
			printf("so CP lon nhat tren dong %d la %d\n",i,max);
	}
}

int main()
{
	int a[MAX][MAX];
	int n;
	int dong;
	NhapMaTran(a,n);
	XuatMaTran(a,n);
	InChinhPhuongMaxDong(a,n);
	return 0;
}
