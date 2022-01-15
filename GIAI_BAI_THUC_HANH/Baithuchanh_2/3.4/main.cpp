#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class May
{
    char maMay[15], kieuMay[15], tinhTrang[15];
public:
    void Nhap(), Xuat();
};

void May::Nhap()
{
    cout << "Nhap ma may: ";        gets(maMay);
    cout << "Nhap kieu may: ";      gets(kieuMay);
    cout << "Nhap tinh trang: ";    gets(tinhTrang);
}

void May::Xuat()
{
    cout << setw(15) << left << maMay;
    cout << setw(15) << left << kieuMay;
    cout << setw(15) << left << tinhTrang << ln;
}

class QuanLy
{
    char maQl[15], hoTen[15];
public:
    void Nhap(), Xuat();
};

void QuanLy::Nhap()
{
    cout << "Nhap ma quan ly: ";        gets(maQl);
    cout << "Nhap ho ten qly: ";        gets(hoTen);
}

void QuanLy::Xuat()
{
    cout << "Ma quan ly: " << maQl << ln;
    cout << "Ho ten qly: " << hoTen << ln;
}

class PhongMay
{
    char maPhong[15], tenPhong[15];
    double dienTich;
    QuanLy x;
    May *y;
    int n;
public:
    void Nhap(), Xuat();
};

void PhongMay::Nhap()
{
    cout << "Nhap ma phong : ";      gets(maPhong);
    cout << "Nhap ten phong: ";      gets(tenPhong);
    cout << "Nhap dien tich: ";      cin >> dienTich;
    fflush(stdin);
    x.Nhap();
    cout << "Nhap so luong may: ";   cin >> n;
    fflush(stdin);
    y = new May[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin may thu " << i+1 << ": \n";
        y[i].Nhap();
        cout << ln;
    }
}

void PhongMay::Xuat()
{
    cout << "\nXUAT THONG TIN PHONG MAY:\n";
    cout << "Ma phong : " << maPhong  << ln;
    cout << "Ten phong: " << tenPhong << ln;
    cout << "Dien tich: " << dienTich << ln;
    x.Xuat();
    cout << setw(15) << left << "MA MAY";
    cout << setw(15) << left << "KIEU MAY";
    cout << setw(15) << left << "TINH TRANG" << ln;
    for(int i=0; i<n; i++)
        y[i].Xuat();
}

int main()
{
    PhongMay a;
    a.Nhap();
    a.Xuat();
    return 0;
}
