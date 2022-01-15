#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class NSX
{
    char tenNSX[25], diaChi[25];
public:
    void Nhap(), Xuat();
    friend class Hang;
};

void NSX::Nhap()
{
    cout << "Nhap ten nha san xuat : ";     fflush(stdin);      gets(tenNSX);
    cout << "Nhap dia chi nha sxuat: ";     fflush(stdin);      gets(diaChi);
}

void NSX::Xuat()
{
    cout << setw(25) << left << tenNSX;
    cout << setw(25) << left << diaChi;
}

class Hang
{
protected:
    char tenHang[25];
    NSX x;
    double donGia;
public:
    void Nhap(), Xuat();
    Hang();
    Hang(char *tenHang, char *x.tenNSX, char *x.diaChi, double donGia);
};

Hang::Hang()
{
    strcpy(tenHang, "");
    strcpy(x.tenNSX, "");
    strcpy(x.diaChi, "");
    donGia = 0;
}

Hang::Hang(char* tenHang, char* x.tenNSX, char* x.diaChi, double donGia)
{
    strcpy(this->tenHang, tenHang);
    strcpy(this->x.tenNSX, x.tenNSX);
    strcpy(this->x.diaChi, x.diaChi);
    this->donGia = donGia;
}

void Hang::Nhap()
{
    cout <<" Nhap ten hang: ";      fflush(stdin);      gets(tenHang);
    x.Nhap();
    cout << "Nhap don gia : ";      cin >> donGia;
}

void Hang::Xuat()
{
    cout << setw(25) << left << tenHang;
    x.Xuat();
    cout << setw(25) << left << donGia;
}

class Date
{
    int D, M, Y;
public:
    void Nhap(), Xuat();
    friend class TiVi;
};

void Date::Nhap()
{
    cout << "Nhap ngay : ";      cin >> D;
    cout << "Nhap thang: ";      cin >> M;
    cout << "Nhap nam  : ";      cin >> Y;
}

void Date::Xuat()
{
    cout << setw(15) << left << D;
    cout << setw(15) << left << M;
    cout << setw(15) << left << Y;
}

class TiVi : public Hang
{
    double kichThuoc;
    Date ngayNhap;
public:
    void Nhap(), Xuat();
    TiVi();
    TiVi(char* tenHang, char* x.tenNSX, char* x.diaChi, double donGia, double kichThuoc, int ngayNhap.D, int ngayNhap.M, int ngayNhap.Y);
};

TiVi::TiVi() : Hang(tenHang,x.tenNSX, x.diaChi, donGia)
{
    kichThuoc = ngayNhap.D = ngayNhap.M = ngayNhap.Y = 0;
}

void TiVi::Nhap()
{
    Hang::Nhap();
    cout << "Nhap kich thuoc: ";        cin >> kichThuoc;
    ngayNhap.Nhap();
}

void TiVi::Xuat()
{
    Hang::Xuat();
    cout << setw(15) << left << kichThuoc;
    ngayNhap.Xuat();
}


int main()
{
    TiVi *a;
    int n;
    cout << "Nhap so luong tivi: ";     cin >> n;
    a = new TiVi[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin tivi thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    for(int i=0; i<n; i++)
    {
        a[i].Xuat();
    }
    return 0;
}
