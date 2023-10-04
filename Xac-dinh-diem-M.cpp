#include <iostream>
#include <cmath> // Include <cmath> for C++ standard functions
using namespace std;

typedef struct DIEM
{
    float x;
    float y;
} DIEM;

typedef struct DUONG_THANG
{
    float a;
    float b;
    float c;
} DUONG_THANG;

DIEM M;
DUONG_THANG D;
DUONG_THANG D1;
DIEM H;

void NhapDiem(DIEM &M)
{
    printf(" Nhap toa do cua x: ");
    scanf("%f", M.x)
    printf(" Nhap toa do cua y: ");
    scanf("%f",M.y);
}

void Nhap_Duong_Thang(DUONG_THANG &D)
{
    do
    {
      printf("He so a: ");
      scanf("%f", &a);

      printf("He so b: "); 
      scanf("%f", &b);

      printf("He so c: ");
      scanf("%f", &c);
    } while (D.a * D.a + D.b * D.b <= 0);
}

DUONG_THANG TAO_DUONG_VUONG_GOC(DIEM M, DUONG_THANG D)
{
    DUONG_THANG kq;
    kq.a = -D.b;
    kq.b = D.a;
    kq.c = kq.b * M.x + kq.a * M.y;
    return kq;
}

DIEM XAC_DINH_GIAO_DIEM(DUONG_THANG D1, DUONG_THANG D)
{
    DIEM kq;
    float delta;
    float Deltax;
    float Deltay;

    delta = D.a * D1.b - D.b * D1.a;
    Deltax = D.b * D1.c - D1.b * D.c;
    Deltay = D1.a * D.c - D1.c * D.a;

    kq.x = Deltax / delta;
    kq.y = Deltay / delta;
    return kq;
}

void Xuat_Diem(DIEM M)
{
    printf("Toa do hinh chieu cua diem M tren duong thang D la: \n");
    printf("(%f, %f)", M.x, M.y);
}

int main()
{
    DIEM M;
    DUONG_THANG D;
    DIEM H;
    DUONG_THANG D1;
    NhapDiem(M);
    Nhap_Duong_Thang(D);
    D1 = TAO_DUONG_VUONG_GOC(M, D);
    H = XAC_DINH_GIAO_DIEM(D1, D);
    Xuat_Diem(M);
}
