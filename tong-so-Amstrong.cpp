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

bool SoAmstrong(int n)
{
    int s = 0;
    int tong = 0;

    while (n != 0)
    {
        n /= 10;
        s++;
        int chuSo = n % 10;
        tong += pow(chuSo,s);
        n /= 10;
    }

    return (tong == n);
}

int TongsoAmstrong(int a[MAX][MAX],int n)
{
		int tong = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(SoAmstrong(a[i][j]))
				{
					tong += a[i][j];
				}
			}
		}
		return tong;
}

int main()
{
	int a[MAX][MAX];
	int n;
	NhapMaTran(a,n);
	XuatMaTran(a,n);
	int Amstrong = TongsoAmstrong(a,n);
	cout << " Tong so Amstrong cua ma tran: " << Amstrong<<endl;
	return 0;
}
