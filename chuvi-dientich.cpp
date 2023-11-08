#include <iostream>
#include <cmath>

using namespace std;
const int sodinhtoida=20;

struct diem
{
	double x;
	double y;
};
struct dagiac
{
	int sodinh;
	diem dinh[sodinhtoida];	
};

void Nhap(dagiac &dg)
{
	int i;
	do
	{
		cout <<" So dinh: ";
		cin >> dg.sodinh;
	}while(dg.sodinh<3);
	
	for(i=0;i<dg.sodinh;i++)
	{
		cout <<" Hoanh do dinh ["<< i <<"] ";
		cin >> dg.dinh[i].x;
		cout <<" Tung do dinh ["<< i <<"] ";
		cin >> dg.dinh[i].y;
	}
}

double Khoangcach(diem m, diem n)
{
	int kq=1;
	double dx, dy;
	dx=fabs(m.x-n.x);
	dy=fabs(m.y-n.y);
	kq=sqrt(dx*dx+dy*dy);
	return kq;
}
int kiemtra(dagiac dg)
{
	int kq=1;
	double d1,d2;
	for(int i =1; i<=dg.sodinh && kq == 1; i++)
	{
		d1=Khoangcach(dg.dinh[i-1],dg.dinh[i]);
		d2=Khoangcach(dg.dinh[i], dg.dinh[(i+1)%dg.sodinh]);
		if(d1 != d2)
			kq=0;
	}
	return kq;
}
double Chuvi(dagiac dg)
{
    double chuvi = 0.0;
    for (int i = 0; i < dg.sodinh; i++)
    {
        chuvi += Khoangcach(dg.dinh[i], dg.dinh[(i + 1) % dg.sodinh]);
    }
    return chuvi;
}

double Dientich(dagiac dg)
{
    double dientich = 0.0;
    for (int i = 0; i < dg.sodinh; i++)
    {
        dientich += dg.dinh[i].x * dg.dinh[(i + 1) % dg.sodinh].y - dg.dinh[i].y * dg.dinh[(i + 1) % dg.sodinh].x;
    }
    return fabs(dientich) / 2.0;
}
int main()
{
	dagiac dg;
	Nhap(dg);
	if(kiemtra(dg)==0)
		cout <<" Khong phai da giac deu"<<endl;
	else
		cout <<" La da giac deu"<<endl;
	float cv = Chuvi(dg);
	float dt = Dientich(dg);
	cout <<" Chu vi da giac la: "<< cv <<endl;
	cout <<" Dien tich da giac la: " << dt <<endl;
}
