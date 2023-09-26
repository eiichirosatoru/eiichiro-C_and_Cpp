#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc cho thông tin thí sinh
struct ThiSinh {
    string SoBaoDanh;
    string HoTen;
    int MaNganh;
    int KhuVuc;
    int DoiTuong;
    float Diem;
    float TongDiem;
    int KetQua; // 1: đậu, 0: rớt
};

// Hàm nhập thông tin cho một thí sinh
void NhapThiSinh(ThiSinh &ts) {
    cout << "Nhap So bao danh: ";
    cin >> ts.SoBaoDanh;
    cout << "Nhap Ho ten: ";
    cin.ignore();
    getline(cin, ts.HoTen);
    cout << "Nhap Ma nganh (1: Toan, 2: Ly, 3: Hoa): ";
    cin >> ts.MaNganh;
    cout << "Nhap Khu vuc (1: Khu vuc 1,2: Khu vuc 2,3: Khu vuc 3:";
    cin >> ts.KhuVuc;
    cout << "Nhap Doi tuong (1: Nhom 1,2: Nhom 2,3: Nhom 3): ";
    cin >> ts.DoiTuong;
    cout << "Nhap Diem (0 <= Toan, Ly, Hoa <= 10) : ";
    cin >> ts.Diem;
}

// Hàm tính tổng điểm
float TinhTongDiem(const ThiSinh &ts) {
    float heSo = 1.0;
    if (ts.MaNganh == 1) {
        heSo = 2.0; // Hệ số cho ngành Toán
    } else if (ts.MaNganh == 2) {
        heSo = 2.0; // Hệ số cho ngành Lý
    } else if (ts.MaNganh == 3) {
        heSo = 2.0; // Hệ số cho ngành Hóa
    }
    return ts.Diem * heSo;
}
void XacDinhKetQua(ThiSinh &ts) {
    float diemChuan = 0.0;

    if (ts.DoiTuong == 1) {
        if (ts.KhuVuc == 1) {
            diemChuan = 22.0;
        } else if (ts.KhuVuc == 2) {
            diemChuan = 23.0;
        } else if (ts.KhuVuc == 3) {
            diemChuan = 24.0;
        }
    } else if (ts.DoiTuong == 2) {
        if (ts.KhuVuc == 1) {
            diemChuan = 22.5;
        } else if (ts.KhuVuc == 2) {
            diemChuan = 23.5;
        } else if (ts.KhuVuc == 3) {
            diemChuan = 24.5;
        }
    } else if (ts.DoiTuong == 3) {
        if (ts.KhuVuc == 1) {
            diemChuan = 23.0;
        } else if (ts.KhuVuc == 2) {
            diemChuan = 24.0;
        } else if (ts.KhuVuc == 3) {
            diemChuan = 25.0;
        }
    }

    if (ts.TongDiem >= diemChuan) {
        ts.KetQua = 1; // Đậu
    } else {
        ts.KetQua = 0; // Rớt
    }
}
void XuatThiSinhTrungTuyen(const ThiSinh &ts) {
    // Kiểm tra nếu thí sinh đã trúng tuyển (KetQua == 1)
    if (ts.KetQua == 1) {
        cout << "So bao danh: " << ts.SoBaoDanh << endl;
        cout << "Ho ten: " << ts.HoTen << endl;
        cout << "Ma nganh: " << ts.MaNganh << endl;
        cout << "Khu vuc: " << ts.KhuVuc << endl;
        cout << "Doi tuong: " << ts.DoiTuong << endl;
        cout << "Tong diem: " << ts.TongDiem << endl;
        cout << "Ket qua: Trung tuyen" << endl;
        cout << "--------------------------------" << endl;
    }
}
int main() {
    int n;
    cout << "Nhap so luong thi sinh (0<=n<=50): ";
    cin >> n;

    if (n < 0 || n > 50) {
        cout << "So luong thi sinh khong hop le." << endl;
        return 1;
    }

    ThiSinh danhSachThiSinh[50];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho thi sinh " << i + 1 << ":" << endl;
        NhapThiSinh(danhSachThiSinh[i]);
        danhSachThiSinh[i].TongDiem = TinhTongDiem(danhSachThiSinh[i]);
        XacDinhKetQua(danhSachThiSinh[i]); // Xác định kết quả dựa trên điểm chuẩn
    }

    cout << "Danh sach thi sinh va ket qua:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Thi sinh " << i + 1 << ":" << endl;
        cout << "So bao danh: " << danhSachThiSinh[i].SoBaoDanh << endl;
        cout << "Ho ten: " << danhSachThiSinh[i].HoTen << endl;
        cout << "Tong diem: " << danhSachThiSinh[i].TongDiem << endl;
        if (danhSachThiSinh[i].KetQua == 1) {
            cout << "Ket qua: Dau" << endl;
        } else {
            cout << "Ket qua: Rot" << endl;
        }
        cout << "--------------------------------" << endl;
    }
    cout << "Danh sach thi sinh trung tuyen:" << endl;
    for (int i = 0; i < n; i++) {
        XuatThiSinhTrungTuyen(danhSachThiSinh[i]);
    }

    return 0;
}
