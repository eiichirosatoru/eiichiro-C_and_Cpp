#include <iostream>
#define MAX 100
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

bool DaylaSoHoanThien(int n)
{
    if (n <= 0)
        return false;

    int tongUoc = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            tongUoc += i;
        }
    }

    return (tongUoc == n);
}

void vitriSoHoanThienCuoiCung(int a[MAX], int n)
{
    int soHoanThienCuoiCung = -1;
    int vitri = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (DaylaSoHoanThien(a[i]))
        {
            soHoanThienCuoiCung = a[i];
            vitri = i;
            break;
        }
    }

    if (soHoanThienCuoiCung != -1)
    {
        cout << "So hoan thien cuoi cung la " << soHoanThienCuoiCung << " o vi tri " << vitri << endl;
    }
    else
    {
        cout << "Khong co so hoan thien trong mang." << endl;
    }
}

int main()
{
    int a[MAX];
    int n;

    Nhap(a, n);
    Xuat(a, n);
    vitriSoHoanThienCuoiCung(a, n);

    return 0;
}
