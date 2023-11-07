#include <iostream>
#include <float.h>
#define MAX 100
#define bool
using namespace std;

void Nhap(int a[MAX], int &n)
{
    do
    {
        cout <<"Nhap so luong phan tu: ";
        cin >> n;
        if(n<1||n>MAX)
        {
            cout << "So vua nhap khong hop le: ";
        }
        else
            break;
    }while(true);
    for (int i = 0; i < n;i++)
    {

            cout << "Nhap a["<<i<<"]: ";
            cin >> a[i];
    }
}
void Xuat(int a[MAX], int n)
{
    cout <<" Mang vua nhap la: ";
    for(int i = 0; i<n; i++)
    {
        cout << a[i] <<" ";
    }
    cout << endl;
}
void vitrinhonhat(int a[MAX], int n)
{
    int kt, vitri=0;
    bool kt = false;
    float min=FLT_MAX;
    for(int i = 0; i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            vitri=i;
            kt=true;
        }
    }
    if(kt==true)
    {
        cout << "Gia tri nho nhat la " << min << " tai vi tri "<< vitri <<endl;
    }
}
int main()
{
    int a[MAX];
    int n;
    
    Nhap(a,n);
    Xuat(a,n);
    vitrinhonhat(a,n);
    return 0;
}