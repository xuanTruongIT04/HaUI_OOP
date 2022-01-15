#include <iostream>
using namespace std;
#define ln "\n";

class NSX
{
    char maNSX[15], tenNSX[30], dcNSX[30];
public:
    void Nhap(), Xuat();
};

void NSX::Nhap()
{
    cout << "Nhap ma nha san xuat: ";       gets(maNSX);
    cout << "Nhap ten nha san xuat: ";      gets(tenNSX);
    cout << "Nhap dia chi nha san xuat: ";  gets(dcNSX);
}

void NSX::Xuat()
{
    cout << "Ma nha san xuat:  "<< maNSX << ln;
    cout << "Ten nha san xuat: " << tenNSX << ln;
    cout << "Dia chi nha san xuat: " << dcNSX << ln;
}

class Hang
{
    char maHang[15], tenHang[20];
    NSX x;
public:
    void Nhap(), Xuat();
};

void Hang::Nhap()
{
    cout << "Nhap ma hang: ";       gets(maHang);
    cout << "Nhap ten hang: ";      gets(tenHang);
    x.Nhap();
}

void Hang::Xuat()
{
    cout << "\nMa hang: " << maHang << ln;
    cout << "Ten hang: " << tenHang << ln;
    x.Xuat();
}

int main()
{
    Hang a;
    a.Nhap();
    a.Xuat();
    return 0;
}
