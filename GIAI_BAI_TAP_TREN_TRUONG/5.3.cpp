#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class NhanVien
{
    char tenNV[25], chucVu[15];
public:
    void Nhap(), Xuat();
};

void NhanVien::Nhap()
{
    cout << "Nhap ten nhan vien: ";     fflush(stdin);      gets(tenNV);
    cout << "Nhap chuc vu nvien: ";     fflush(stdin);      gets(chucVu);
}

void NhanVien::Xuat()
{
    cout << "Nhan vien kiem ke:  " << tenNV;
    cout << "\t\tChuc vu:   " << chucVu << ln;
}

class Phong
{
    char tenP[25], maP[15], tenTruongP[25];
public:
    void Nhap(), Xuat();
};

void Phong::Nhap()
{
    cout << "Nhap ten phong: ";             fflush(stdin);      gets(tenP);
    cout << "Nhap ma phong : ";             fflush(stdin);      gets(maP);
    cout << "Nhap ten truong phong: ";      fflush(stdin);      gets(tenTruongP);
}

void Phong::Xuat()
{
    cout << "Kiem ke tai phong:  " << tenP;
    cout << "\t\tMa phong:  " << tenP << ln;
    cout << "Truong phong:  " << tenP << ln;
}

class TaiSan
{
    char tenTS[25], tinhTrang[15];
    int soLuong;
public:
    void Nhap(), Xuat();
    friend class Phieu;
};

void TaiSan::Nhap()
{
    cout << "Nhap ten tai san: ";       fflush(stdin);      gets(tenTS);
    cout << "Nhap so luong ts: ";       cin >> soLuong;
    cout << "Nhap tinh trang : ";       fflush(stdin);      gets(tinhTrang);
}

void TaiSan::Xuat()
{
    cout << setw(25) << left << tenTS;
    cout << setw(25) << left << soLuong;
    cout << tinhTrang << ln;
}

class Phieu
{
    char maPhieu[15], ngayKK[15];
    NhanVien x;
    Phong y;
    TaiSan *z;
    int n;
public:
    void Nhap(), Xuat();
};

void Phieu::Nhap()
{
    x.Nhap();
    y.Nhap();
    cout << "Nhap so luong tai san: ";      cin >> n;
    z = new TaiSan[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin tai san thu " << i+1 << ": \n";
        z[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cout << "\n=====================PHIEU KIEM KE TAI SAN====================\n\n";
    x.Xuat();
    y.Xuat();
    int sumTS = 0;
    cout << setw(25) << left << "TEN TAI SAN";
    cout << setw(25) << left << "SO LUONG";
    cout << "TINH TRANG" << ln;
    for(int i=0; i<n; i++)
    {
        z[i].Xuat();
        sumTS += z[i].soLuong;
    }
    cout << "So tai san da kiem ke:   " << n;
    cout << "\t   Tong so luong: " << sumTS;
    cout << "\n\n=============================================================\n";
}



int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}
