#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class Hang
{
    char maHang[15], tenHang[20];
    double donGia;
public:
    void Nhap(), Xuat();
};

void Hang::Nhap()
{
    cout << "Nhap ma hang : ";      gets(maHang);
    cout << "Nhap ten hang: ";      gets(tenHang);
    cout << "Nhap don gia : ";      cin >> donGia;
    fflush(stdin);
}

void Hang::Xuat()
{
    cout << setw(15) << left << maHang;
    cout << setw(25) << left << tenHang;
    cout << setw(15) << left << donGia << ln;
}

class Phieu
{
    char maPhieu[15];
    Hang *x;
    int n;
public:
    void Nhap(), Xuat();
};

void Phieu::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma phieu: ";      gets(maPhieu);
    cout << "Nhap so mat hang: ";   cin >> n;
    fflush(stdin);
    x = new Hang[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap mat hang thu " << i+1 << ": \n";
        x[i].Nhap();
        cout << ln;
    }
}

void Phieu::Xuat()
{
    cout << "Ma phieu: " << maPhieu << ln;
    cout << setw(15) << left << "MA HANG";
    cout << setw(25) << left << "TEN HANG";
    cout << setw(15) << left << "DON GIA" << ln;
    for(int i=0; i<n; i++)
        x[i].Xuat();
}

int main()
{
    Phieu p;
    p.Nhap();
    p.Xuat();
    return 0;
}
