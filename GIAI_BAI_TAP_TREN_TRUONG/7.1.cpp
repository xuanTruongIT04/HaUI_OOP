#include <iostream>
#include <string.h>
using namespace std;
#define ln "\n";

class Date
{
    int D, M, Y;
public:
    void Nhap(), Xuat();
    friend class TiVi;
};

void Date::Nhap()
{
    cout << "Nhap ngay : ";     cin >> D;
    cout << "Nhap thang: ";     cin >> M;
    cout << "Nhap nam  : ";     cin >> Y;
}

void Date::Xuat()
{
    cout << "\nDate: " << D << " / " << M << " / " << Y << ln;
}


class NSX
{
    char tenNSX[25], diaChi[25];
public:
    void Nhap(), Xuat();
    friend class Hang;
};

void NSX::Nhap()
{
    cout << "Nhap ten NSX: ";       fflush(stdin);     gets(tenNSX);
    cout << "Nhap dia chi NSX: ";   fflush(stdin);     gets(diaChi);
}

void NSX::Xuat()
{
    cout << "Ten NSX: " << tenNSX << ln;
    cout << "Dia chi NSX: " << diaChi << ln;
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
};

Hang::Hang(){
    strcpy(tenHang, "");
    strcpy(x.tenNSX, "");
    strcpy(x.diaChi, "");
    donGia = 0;
}

void Hang::Nhap()
{
    cout << "Nhap ten hang: ";      fflush(stdin);      gets(tenHang);
    x.Nhap();
    cout << "Nhap don gia: ";       cin >> donGia;
}

void Hang::Xuat()
{
    cout << "Ten hang: " << tenHang << ln;
    x.Xuat();
    cout << "Don gia : " << donGia << ln;
}

class TiVi : public Hang
{
    double kichThuoc;
    Date ngayNhap;
public:
    void Nhap(), Xuat();
    TiVi();
};

TiVi::TiVi()
{
    kichThuoc = 0;
    ngayNhap.D = 0;
    ngayNhap.M = 0;
    ngayNhap.Y = 0;
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
    cout << "Kich thuoc: " << kichThuoc;
    ngayNhap.Xuat();
}

int main()
{
    TiVi k;
    cout << "Nhap thong tin cua 1 Tivi: \n";
    k.Nhap();
    cout << "\n\nXuat thong tin cua 1 Tivi: \n";
    k.Xuat();
    return 0;
}
