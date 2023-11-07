#include <iostream>
#define MAX 100
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
        cout << a[i] <<endl;
    }
}
int Sochancuoicung(int a[MAX], int n)
{
    int sochancuoi = -1;
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] % 2 == 0)
        {
            sochancuoi = a[i];
            break;
        }
        
    }
    return sochancuoi;
}
int main()
{
    int a[MAX];
    int n;
    
    Nhap(a,n);
    Xuat(a,n);
    
    int sochan = Sochancuoicung(a,n);
    if(sochan != -1)
    {
        cout <<"So chan cuoi cung trong mang la: " << sochan <<endl;
    }
    else
    {
        cout <<"Khong ton tai trong mang: "; 
    }
    return 0;
}