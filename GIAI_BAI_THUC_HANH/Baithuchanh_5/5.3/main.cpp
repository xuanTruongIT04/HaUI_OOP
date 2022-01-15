#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define ln "\n";

class Phieu;

class NhanVien
{
    char tenNV[30], chuVu[20];
public:
    void Nhap(), Xuat();
};

void NhanVien::Nhap()
{
    cout << "Ten nhan vien: ";      fflush(stdin);      gets(tenNV);
    cout << "Chuc vu nvien: ";      fflush(stdin);      gets(chuVu);
}

void NhanVien::Xuat()
{
    cout << "Nhan vien kiem ke:  " << tenNV;
    cout <<"\t\tChuc vu:  " << chuVu << ln;
}

class Phong
{
    char tenPhong[30], maPhong[20], tenTP[20];
public:
    void Nhap(), Xuat();
};

void Phong::Nhap()
{
    cout << "Nhap ten phong: ";             fflush(stdin);      gets(tenPhong);
    cout << "Nhap ma phong : ";             fflush(stdin);      gets(maPhong);
    cout << "Nhap ten truong phong: ";      fflush(stdin);      gets(tenTP);
}

void Phong::Xuat()
{
    cout << "Kiem ke tai phong:  " << tenPhong;
    cout << "\t\tMa phong:  " << maPhong << ln;
    cout << "Truong phong: " << tenTP << ln;
}

class TaiSan
{
    char tenTS[30], tinhTrang[30];
    int soLuong;
public:
    void Nhap(), Xuat();
    friend class Phieu;
    friend void SuaThongTin(Phieu k);
    friend void SapXep(Phieu k);
};

void TaiSan::Nhap()
{
    cout << "Nhap ten tai san: ";       fflush(stdin);      gets(tenTS);
    cout << "Nhap so luong: ";          cin >> soLuong;
    cout << "Nhap tinh trang : ";       fflush(stdin);      gets(tinhTrang);
}

void TaiSan::Xuat()
{
    cout << setw(30) << left << tenTS;
    cout << setw(20) << left << soLuong;
    cout << setw(30) << left << tinhTrang << ln;
}

class Phieu
{
    char maPhieu[20], ngayKiemKe[15];
    NhanVien x;
    Phong y;
    TaiSan *z;
    int n;
public:
    void Nhap(), Xuat();
    friend void SuaThongTin(Phieu k);
    friend void SapXep(Phieu k);
};

void Phieu::Nhap()
{
    cout << "Nhap ma phieu: ";      fflush(stdin);      gets(maPhieu);
    cout << "Nhap ngay kiem ke: ";  fflush(stdin);      gets(ngayKiemKe);
    x.Nhap();
    y.Nhap();
    cout << "Nhap so tai san: ";        cin >> n;
    z = new TaiSan[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap tai san thu " << i+1 << ": \n";
        z[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cout << "\n\n===============PHIEU KIEM KE TAI SAN=============================\n\n";
    cout << "Ma phieu: " << maPhieu;
    cout << "\t\tNgay kiem ke: " << ngayKiemKe << ln;
    x.Xuat();
    y.Xuat();
    int tongSL = 0;
    cout << setw(30) << left << "\nTEN TAI SAN";
    cout << setw(20) << left << "SO LUONG";
    cout << setw(30) << left << "TINH TRANG" << ln;
    for(int i=0; i<n; i++)
    {
        z[i].Xuat();
        tongSL += z[i].soLuong;
    }
    cout << setw(30) << left << "So tai san da kiem ke: " << n;
    cout << "Tong so luong: " << tongSL;
    cout << "\n\n==================================================================";
}

void SuaThongTin(Phieu k)
{
    for(int i=0; i<k.n; i++)
    {
        if(strcmp(k.z[i].tenTS, "May vi tinh")==0){
            k.z[i].soLuong = 20;
        }
    }
}

void SapXep(Phieu k)
{
    for(int i=0; i<k.n; i++)
        for(int j=i+1; j<k.n; j++)
            if(k.z[i].soLuong > k.z[j].soLuong) swap(k.z[i], k.z[j]);
}

int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}
