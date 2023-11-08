#include <iostream>
#include <cstring>

using namespace std;

struct Nhanvien
{
    char manv[10];
    char hoten[30];
    int loaisp;
    int soluongsp;
    int luong;
};

void Nhap1NV(Nhanvien &nv)
{
    cout << "Nhap ma nhan vien: ";
    cin >> nv.manv;
    cin.ignore(); // Ð? xóa d?u enter còn t?n d?ng trong b? nh? d?m
    cout << "Nhap ho ten nhan vien: ";
    cin.getline(nv.hoten, 30);
    cout << "Nhap loai san pham: ";
    cin >> nv.loaisp;
    cout << "Nhap so luong san pham: ";
    cin >> nv.soluongsp;
    cout << "Nhap luong nhan vien: ";
    cin >> nv.luong;
}

void NhapDSNV(Nhanvien staff[], int &n)
{
    cout << "Nhap vao so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        Nhap1NV(staff[i]);
    }
}

void Xuat1NV(Nhanvien nv)
{
    cout << "Ma nhan vien: " << nv.manv << endl;
    cout << "Ho ten nhan vien: " << nv.hoten << endl;
    cout << "Loai san pham: " << nv.loaisp << endl;
    cout << "So luong san pham: " << nv.soluongsp << endl;
    cout << "Luong nhan vien: " << nv.luong << endl;
}

void XuatDSNV(Nhanvien staff[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin nhan vien thu " << i + 1 << endl;
        Xuat1NV(staff[i]);
    }
}

void TinhLuong(Nhanvien staff[], int n)
{
    int dongia[3][3] = {
        {32, 30, 28},
        {35, 32, 29},
        {38, 35, 30}};

    for (int i = 0; i < n; i++)
    {
        int dong;
        if (staff[i].soluongsp <= 30)
            dong = 0;
        else if (staff[i].soluongsp <= 50)
            dong = 1;
        else
            dong = 2;

        staff[i].luong = staff[i].soluongsp * dongia[dong][staff[i].loaisp];
    }
}

int main()
{
    int n;
    Nhanvien staff[100];

    NhapDSNV(staff, n);
    cout << "\nDanh sach nhan vien:\n";
    XuatDSNV(staff, n);

    TinhLuong(staff, n);

    cout << "\nDanh sach nhan vien sau khi tinh luong:\n";
    XuatDSNV(staff, n);

    return 0;
}

