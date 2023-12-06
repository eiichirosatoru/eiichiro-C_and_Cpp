#include<iostream>
#include<conio.h>

struct  LuanVan
{
    char MaLuanVan[10], 
	TenLuanVan[100], 
	TenSinhVien[30], 
	TenGiangVienHD[30];
    int NamThucHien;
	float diem;
};
typedef struct LuanVan LUANVAN;

void NhapLuanVan(LUANVAN &lv)
{
    fflush(stdin);
    printf("\nNhap ma luan van: ");
    gets(lv.MaLuanVan);

    fflush(stdin);
    printf("\nNhap ten luan van: ");
    gets(lv.TenLuanVan);

    fflush(stdin);
    printf("\nNhap ten sinh vien thuc hien: ");
    gets(lv.TenSinhVien);

    fflush(stdin);
    printf("\nNhap ten giang vien huong dan: ");
    gets(lv.TenGiangVienHD);

    printf("\nNhap nam thuc hien: ");
    scanf("%d", &lv.NamThucHien);
    printf("\nNhap diem: ");
    scanf("%f", &lv.diem);

}
void XuatLuanVan(LUANVAN lv)
{
    printf("\nMa luan van: %s", lv.MaLuanVan);
    printf("\nTen luan van: %s", lv.TenLuanVan);
    printf("\nTen sinh vien thuc hien: %s", lv.TenLuanVan);
    printf("\nTen giang vien huong dan: %s", lv.TenGiangVienHD);
    printf("\nNam thuc hien: %d", lv.NamThucHien);
    printf("\nDiem: %2.f", lv.diem);
}
void NhapDSLV(LUANVAN lv[], int &n)
{
	printf("nhap so LV:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	NhapLuanVan(lv[i]);	
}
void XuatDSLV(LUANVAN lv[], int n)
{
	printf("danh sach LV: \n");
	for(int i=0;i<n;i++)
	XuatLuanVan(lv[i]);
	
}
int DemNam(LUANVAN lv[], int n, int nam)
{
	int dem=0;
	for(int i=0;i<n;i++)
		if (lv[i].NamThucHien==nam)
			dem=dem+1;
	return dem;
}
void LietKeNamMax(LUANVAN lv[], int n)
{
	int max=DemNam(lv,n,lv[0].NamThucHien);
	int maxnam=lv[0].NamThucHien;
	for(int i=0;i<n;i++)
		if (DemNam(lv,n,lv[i].NamThucHien)>max)
		{
			max=DemNam(lv,n,lv[i].NamThucHien);
			maxnam=lv[i].NamThucHien;
		}
	printf("Nam co nhieu LV nhat la nam %d\n Cac thong tin: \n",maxnam);
	for(int i=0;i<n;i++)
		if (lv[i].NamThucHien==maxnam)
			XuatLuanVan(lv[i]);
}
int LuanVanDau(LUANVAN lv[], int n)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(lv[i].diem > 5)
		{
			dem = dem + 1;
		}
	}
}

int main()
{
    LUANVAN a[100];
    int n;
    NhapDSLV(a,n);
    XuatDSLV(a,n);
    LietKeNamMax(a,n);
	int dau = LuanVanDau(a,n);
	std::cout <<" So luan van dau: " << dau;
    getch();
    return 0;
}
