#include <iostream>
#include <climits> // Thêm thư viện để sử dụng INT_MAX
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
void giaTriDuongNhoNhatVaViTri(int a[MAX], int n)
{
    int giaTriDuongNhoNhat = INT_MAX; // Giả sử giá trị dương nhỏ nhất là giá trị lớn nhất của kiểu int ban đầu
    int viTri = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] < giaTriDuongNhoNhat)
        {
            giaTriDuongNhoNhat = a[i];
            viTri = i;
        }
    }

    if (viTri != -1)
    {
        cout << "Gia tri duong nho nhat la " << giaTriDuongNhoNhat << " o vi tri " << viTri << endl;
    }
    else
    {
        cout << "Khong co gia tri duong trong mang." << endl;
    }
}

int main()
{
    int a[MAX];
    int n;

    Nhap(a, n);
    Xuat(a, n);
    giaTriDuongNhoNhatVaViTri(a, n);

    return 0;
}
