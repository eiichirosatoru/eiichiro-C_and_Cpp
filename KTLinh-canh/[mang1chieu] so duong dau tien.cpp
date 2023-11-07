#include <iostream>
#include <float.h>
#define MAX 100
#define bool
using namespace std;

void Nhap(float a[MAX], int &n)
{
    do
    {
        cout << "Nhap so luong phan tu (1 <= n <= " << MAX << "): ";
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
    cout << "Mang vua nhap la:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

float DuongDauTien(float a[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            return a[i];
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy số dương nào trong mảng
}

int main()
{
    float a[MAX];
    int n;
    Nhap(a, n);
    Xuat(a, n);

    float soDuongDauTien = DuongDauTien(a, n);
    if (soDuongDauTien != -1)
    {
        cout << "So duong dau tien la " << soDuongDauTien << endl;
    }
    else
    {
        cout << "Khong co so duong trong mang." << endl;
    }

    return 0;
}
