#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class DonVi
{
    char maDV[15], tenDV[30], diaChi[30], tenTruongDV[30];
public:
    void Nhap(), Xuat();
};

void DonVi::Nhap()
{
    cout << "Nhap ma don vi    : ";         fflush(stdin);      gets(maDV);
    cout << "Nhap ten don vi   : ";         fflush(stdin);      gets(tenDV);
    cout << "Nhap dia chi dv   : ";         fflush(stdin);      gets(diaChi);
    cout << "Nhap ten truong dv: ";         fflush(stdin);      gets(tenTruongDV);
}

void DonVi::Xuat()
{
    cout << "Ma don vi: \t" << maDV;
    cout << "\t\tTen don vi:  " << tenDV << ln;
    cout << "Dia chi don vi:  " << diaChi;
    cout << "\t\tTruong don vi: " << tenTruongDV << ln;
}

class TaiSan
{
    char maTS[15], tenTS[30], donViTinh[15];
    int giaTri;
public:
    void Nhap(), Xuat();
    friend class Phieu;
};

void TaiSan::Nhap()
{
    cout << "Nhap ma tai san : ";        fflush(stdin);      gets(maTS);
    cout << "Nhap ten tai san: ";        fflush(stdin);      gets(tenTS);
    cout << "Nhap don vi tinh: ";        fflush(stdin);      gets(donViTinh);
    cout << "Nhap gia tri ts : ";        cin >> giaTri;
}

void TaiSan::Xuat()
{
    cout << setw(15) << left << maTS;
    cout << setw(30) << left << tenTS;
    cout << setw(15) << left << donViTinh;
    cout << setw(15) << left << giaTri << ln;
}

class Phieu
{
    char ngayLap[15], nguoiLap[30];
    DonVi x;
    TaiSan *y;
    int n;
public:
    void Nhap(), Xuat();
};

void Phieu::Nhap()
{
    cout << "Nhap ngay lap : ";      fflush(stdin);      gets(ngayLap);
    cout << "Nhap nguoi lap: ";      fflush(stdin);      gets(nguoiLap);
    x.Nhap();
    cout << "Nhap so luong tai san: ";      cin >> n;
    y = new TaiSan[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin tai san thu " << i+1 <<": \n";
        y[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cout << "TONG CONG TY ABC" << ln;
    cout << "=======================BANG THONG KE TAI SAN=======================\n";
    cout << "Ngay lap:\t" << ngayLap;
    cout << "\t\tNguoi lap: " << nguoiLap << ln;
    x.Xuat();
    cout << setw(15) << left << "MA TAI SAN";
    cout << setw(30) << left << "TEN TAI SAN";
    cout << setw(15) << left << "DON VI TINH";
    cout << setw(15) << left << "GIA TRI" << ln;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        y[i].Xuat();
        sum += y[i].giaTri;
    }
    cout << "Tong so luong thiet bi:   \t\t\t\t" << sum << ln;
    cout << "\n\tGiam doc" << "\tPhong quan ly" << "\tNguoi lap" << ln;
    cout << "\n==================================================================\n";
}

int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}

