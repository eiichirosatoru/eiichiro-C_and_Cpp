#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100;

void NhapMaTran(int a[][MAX], int &n)
{
    do
    {
        cout << "Nhap n: ";
        cin >> n;
        if (n < 1 || n > MAX)
        {
            cout << "So phan tu khong hop le. Xin kiem tra lai !" << endl;
        }
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap vao a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool KiemTraSoNguyenTo(int n)
{
    if (n <= 1)
    {
        return false;
    }

    int canBacHai = sqrt(n);
    for (int i = 2; i <= canBacHai; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void KiemTraSoNguyenToMaTran(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (KiemTraSoNguyenTo(a[i][j]))
            {
                cout << "Ma tran[" << i << "][" << j << "] la so nguyen to." << endl;
            }
            else
            {
                cout << "Ma tran[" << i << "][" << j << "] khong phai la so nguyen to." << endl;
            }
        }
    }
}

void HoanViSoNguyenToMaTran(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (KiemTraSoNguyenTo(a[i][i]) && KiemTraSoNguyenTo(a[j][j]))
            {
                swap(a[i][i], a[j][j]);
            }
        }
    }
}

int main()
{
    int n;
    int a[MAX][MAX];

    NhapMaTran(a, n);
    cout << "Ma tran ban dau:" << endl;
    XuatMaTran(a, n);

    HoanViSoNguyenToMaTran(a, n);
    cout << "Ma tran sau khi hoan vi cac so nguyen to tren duong cheo chinh:" << endl;
    XuatMaTran(a, n);

    return 0;
}

