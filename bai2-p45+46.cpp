#include <iostream>
#include <string>

using namespace std;

struct DienKe {
    string HoTen;
    string DiaChi;
    int ChiSoCu;
    int ChiSoMoi;
    int ThanhTien;
};

// Hàm nhập thông tin cho n hộ điện kế
void NhapThongTinDienKe(DienKe danhSach[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho ho so dien ke " << i + 1 << ":" << endl;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, danhSach[i].HoTen);
        cout << "Dia chi: ";
        getline(cin, danhSach[i].DiaChi);
        cout << "Chi so cu: ";
        cin >> danhSach[i].ChiSoCu;
        cout << "Chi so moi: ";
        cin >> danhSach[i].ChiSoMoi;
    }
}

// Hàm tính tổng thành tiền và in thông tin của từng hộ điện kế
void TinhTongThanhTien(DienKe danhSach[], int n) {
    for (int i = 0; i < n; i++) {
        int TienDienKep = 1000; // Tiền thuê bao điện kế
        int DinhMuc = 50; // Định mức sử dụng điện (Kw)
        int GiaDinhMuc = 450; // Giá cho phần định mức
        int PhanVuotDinhMuc = 0; // Phần vượt định mức (Kw)
        int GiaPhanVuotDinhMuc = 0; // Giá cho phần vượt định mức

        // Tính lượng điện sử dụng
        int LuongDienSuDung = danhSach[i].ChiSoMoi - danhSach[i].ChiSoCu;

        // Tính thành tiền
        if (LuongDienSuDung <= DinhMuc) {
            GiaPhanVuotDinhMuc = 0;
        } else if (LuongDienSuDung <= DinhMuc + 50) {
            PhanVuotDinhMuc = LuongDienSuDung - DinhMuc;
            GiaPhanVuotDinhMuc = PhanVuotDinhMuc * 700;
        } else if (LuongDienSuDung <= DinhMuc + 100) {
            PhanVuotDinhMuc = LuongDienSuDung - DinhMuc;
            GiaPhanVuotDinhMuc = 50 * 700 + (PhanVuotDinhMuc - 50) * 910;
        } else {
            PhanVuotDinhMuc = LuongDienSuDung - DinhMuc;
            GiaPhanVuotDinhMuc = 50 * 700 + 50 * 910 + (PhanVuotDinhMuc - 100) * 1200;
        }

        danhSach[i].ThanhTien = TienDienKep + GiaDinhMuc + GiaPhanVuotDinhMuc;

        // In thông tin của hộ điện kế
        cout << "Ho ten: " << danhSach[i].HoTen << endl;
        cout << "Dia chi: " << danhSach[i].DiaChi << endl;
        cout << "Thanh tien: " << danhSach[i].ThanhTien << " dong" << endl;
    }
}

// In thông tin các hộ vượt quá định mức tiêu thụ
void InHocVuotDinhMuc(DienKe danhSach[], int n) {
    cout << "Cac ho vuot qua dinh muc tieu thu:" << endl;
    for (int i = 0; i < n; i++) {
        int LuongDienSuDung = danhSach[i].ChiSoMoi - danhSach[i].ChiSoCu;
        int DinhMuc = 50; // Định mức sử dụng điện (Kw)

        if (LuongDienSuDung > DinhMuc) {
            cout << "Ho ten: " << danhSach[i].HoTen << endl;
            cout << "Dia chi: " << danhSach[i].DiaChi << endl;
            cout << "Luong dien su dung: " << LuongDienSuDung << " Kw" << endl;
            cout << "--------------------------------" << endl;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong ho dien ke (0 < n < 50): ";
    cin >> n;

    if (n <= 0 || n >= 50) {
        cout << "So luong ho dien ke khong hop le." << endl;
        return 1;
    }

    DienKe danhSachHoaDon[50];

    // Nhập thông tin cho n hộ điện kế
    NhapThongTinDienKe(danhSachHoaDon, n);

    // Tính tổng thành tiền và in thông tin của từng hộ điện kế
    TinhTongThanhTien(danhSachHoaDon, n);

    // In thông tin các hộ vượt quá định mức tiêu thụ
    InHocVuotDinhMuc(danhSachHoaDon, n);

    return 0;
}
