#include <iostream>
using namespace std;
#define ln "\n";

class NSX
{
    char maNSX[15], tenNSX[25], dcNSX[30];
public:
    friend class Hang;
};

class Hang
{
    char maHang[15], tenHang[25];
    double donGia, trongLuong;
    NSX x;
public:
    void Nhap(), Xuat();
};

void Hang::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma nha san xuat: ";           gets(x.maNSX);
    cout << "Nhap ten nha san xuat: ";          gets(x.tenNSX);
    cout << "Nhap dia chi nha san xuat: ";      gets(x.dcNSX);
    cout << "Nhap ma hang: ";           gets(maHang);
    cout << "Nhap ten hang: ";          gets(tenHang);
    cout << "Nhap don gia: ";           cin >> donGia;
    cout << "Nhap trong luong: ";       cin >> trongLuong;
}

void Hang::Xuat()
{
    cout << "\n\nNhap ma nha san xuat: " << x.maNSX << ln;
    cout << "Nhap ten nha san xuat: " << x.tenNSX << ln;
    cout << "Nhap dia chi nha san xuat: " << x.dcNSX << ln;
    cout << "Nhap ma hang: " << maHang << ln;
    cout << "Nhap ten hang: " << tenHang << ln;
    cout << "Nhap don gia: " << donGia << ln;
    cout << "Nhap trong luong: " << trongLuong << ln;
}

int main()
{
    Hang a;
    a.Nhap();
    a.Xuat();
    return 0;
}
