#include <iostream>
#include <climits> // Thêm thư viện để sử dụng INT_MAX
#define MAX 100
#define bool
using namespace std;

void Nhap(int a[MAX], int &n)
{
    do
    {
        cout << "Nhap so luong phan tu: ";
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
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}

void Xuat(int a[MAX], int n)
{
    cout << "Mang vua nhap la: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void songuyento(int a[MAX], int n)
{
    int f;
    cout << "Cac so nguyen to co trong mang:";
    for(int i = 0; i < n;i++)
    {
        f=1;
        if(a[i]<2)
            f=0;
            for(int k = 2; k <=a[i]/2; k++)
            {
                if(a[i]%k == 0)
                    f=0;
            }
            if(f==1)
            {
                cout << a[i] << " ";
            }
    }
    cout <<endl;
}
void songuyentodautien(int a[MAX], int n)
{   
    int i, f, kt;
    bool kt = false;
    for(i = 0; i < n; i++)
    {
        f=1;
        if(a[i]<2)
            f=0;
        for(int k = 2; k <= a[i]/2; k++)
        {
            if(a[i]%k == 0)
                f=0;
        }
        if(f==1)
        {
            kt=true;
            break;
        }
    }
    if(kt==true)
    {
        cout << "So nguyen to dau tien trong mang la " << a[i] <<endl;
    }
    else
    {
        cout <<endl<<-1;
    }
}

int main()
{
    int a[MAX];
    int n;

    Nhap(a, n);
    Xuat(a, n);
    songuyento(a, n);
    songuyentodautien(a,n);

    return 0;
}
