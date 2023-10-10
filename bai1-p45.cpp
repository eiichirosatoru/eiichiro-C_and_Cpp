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
    float Toan, Ly, Hoa;
    float TongDiem;
    int KetQua; // 1: đậu, 0: rớt
};

// Hàm nhập thông tin cho một thí sinh
void Nhap1TS(ThiSinh &ts) 
{
    cout << "Nhap So bao danh: ";
    cin >> ts.SoBaoDanh;
    cout << "Nhap Ho ten: ";
    cin.ignore();
    getline(cin, ts.HoTen);
    cout << "Nhap Ma nganh (1: Toan, 2: Ly, 3: Hoa): ";
    cin >> ts.MaNganh;
    cout << "Nhap Khu vuc (1: Khu vuc 1, 2: Khu vuc 2, 3: Khu vuc 3): ";
    cin >> ts.KhuVuc;
    cout << "Nhap Doi tuong (1: Nhom 1, 2: Nhom 2, 3: Nhom 3): ";
    cin >> ts.DoiTuong;
    cout << "Nhap Diem Toan: ";
    cin >> ts.Toan;
    cout << "Nhap Diem Ly: ";
    cin >> ts.Ly;
    cout << "Nhap Diem Hoa: ";
    cin >> ts.Hoa;
}

void NhapDSTS(ThiSinh ts[], int &n)
{
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin cua thi sinh thu " << i + 1 << ":\n";
        Nhap1TS(ts[i]);
    }
}

void Xuat1TS(ThiSinh ts)
{
    cout <<" So bao danh: " << ts.SoBaoDanh << endl;
    cout <<" Ho ten thi sinh: " << ts.HoTen << endl;
    cout <<" Ma nganh: " << ts.MaNganh << endl;
    cout <<" Khu vuc: " << ts.KhuVuc << endl;
    cout <<" Doi tuong: " << ts.DoiTuong << endl;
    cout <<" Diem Toan: " << ts.Toan << endl;
    cout <<" Diem Ly: " << ts.Ly << endl;
    cout <<" Diem Hoa: " << ts.Hoa << endl;
    cout <<" Tong diem: " << ts.TongDiem << endl;
    cout <<" Ket qua: " << (ts.KetQua == 1 ? "Trung tuyen" : "Rot") << endl;
    cout << "--------------------------------" << endl;
}

void XuatDSTS(ThiSinh ts[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout <<" Thong tin thi sinh thu " << i + 1 << ":\n";
        Xuat1TS(ts[i]);
    }
}

// Hàm tính tổng điểm
void TongDiem(ThiSinh &ts)
{
    if(ts.MaNganh == 1)
    {
        ts.TongDiem = ts.Toan * 2 + ts.Ly + ts.Hoa;
    }
    else if(ts.MaNganh == 2)
    {
        ts.TongDiem = ts.Toan + ts.Ly * 2 + ts.Hoa;
    }
    else if(ts.MaNganh == 3)
    {
        ts.TongDiem = ts.Toan + ts.Ly + ts.Hoa * 2;
    }
}

// Hàm xác định kết quả đậu/rớt
void XacDinhKetQua(ThiSinh &ts) 
{
    float diemchuan[3][3] = {{22,23,24},{22.5,23.5,24.5},{23,24,25}};
    TongDiem(ts);
    
    if(ts.TongDiem > diemchuan[ts.DoiTuong-1][ts.KhuVuc-1])
        ts.KetQua = 1;
    else
        ts.KetQua = 0;
}

void XuatThiSinhTrungTuyen(const ThiSinh &ts) 
{
    // Kiểm tra nếu thí sinh đã trúng tuyển (KetQua == 1)
    if (ts.KetQua == 1) 
    {
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

int main() 
{
    ThiSinh ts[50];
    int n;
    NhapDSTS(ts, n);
    XuatDSTS(ts, n);

    cout << "Danh sach thi sinh trung tuyen:" << endl;
    for (int i = 0; i < n; i++) {
        XacDinhKetQua(ts[i]);
        XuatThiSinhTrungTuyen(ts[i]);
    }

    return 0;
}
