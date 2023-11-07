#include <iostream>
#include <cmath>
#include <cfloat>
#define MAX 100
using namespace std;

void Nhap(float a[MAX], int &n)
{
    do
    {
        cout << "Nhap vao so phan tu cua mang: ";
        cin >> n;
        if (n < 1 || n > MAX)
        {
            cout << "So vua nhap khong hop le. Nhap lai." << endl;
        }
        else
            break;
    } while (true);

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao a[" << i << "]: ";
        cin >> a[i];
    }
}

void Xuat(float a[MAX], int n)
{
    cout << "Mang vua nhap la: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void TimsoMax(float a[MAX], int n)
{
    int vitri = 0;
    bool coMax = false;
    float max = -FLT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            vitri = i;
            coMax = true;
        }
    }

    if(coMax==true)
	    cout << "Gia tri lon nhat trong mang la " << max << " tai vi tri " << vitri <<endl;
}

int main()
{
    float a[MAX];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    TimsoMax(a, n);

    return 0;
}
