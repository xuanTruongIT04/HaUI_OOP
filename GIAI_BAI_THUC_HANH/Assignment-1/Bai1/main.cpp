#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#define ln "\n";

using namespace std;

class Phieu;

class NV {
    char tenNV[25], chucVu[15];
public:
    void Nhap(), Xuat();
};

void NV::Nhap(){
    fflush(stdin);
    cout << "Nhap ten nhan vien: ";     gets(tenNV);
    cout << "Nhap chuc vu nvien: ";     gets(chucVu);
}

void NV::Xuat(){
    cout << setw(25) << left << tenNV;
    cout << setw(15) << left << chucVu << ln;
}

class Phong{
    char tenPhong[15], maPhong[15], truongPhong[25];
public:
    void Nhap(), Xuat();
};

void Phong::Nhap(){
    fflush(stdin);
    cout << "Nhap ten phong: ";         gets(tenPhong);
    cout << "Nhap ma phong : ";         gets(maPhong);
    cout << "Nhap ten truong phong: ";  gets(truongPhong);
}

void Phong::Xuat(){
    cout << setw(15) << left << tenPhong;
    cout << setw(15) << left << maPhong << ln;
    cout << setw(25) << left << truongPhong;
}

class TaiSan{
    char tenTS[25], tinhTrang[15];
    int soLuongTS;
public:
    void Nhap(), Xuat();
    friend class Phieu;
    friend void TimKiem(Phieu a);
    friend void Sap(Phieu a);
};

void TaiSan::Nhap(){
    fflush(stdin);
    cout << "Nhap ten tai san: ";       gets(tenTS);
    cout << "Nhap so luong ts: ";       cin >> soLuongTS;       fflush(stdin);
    cout << "Nhap tinh trang : ";       gets(tinhTrang);
}

void TaiSan::Xuat(){
    cout << setw(25) << left << tenTS;
    cout << setw(10) << left << soLuongTS;
    cout << setw(15) << left << tinhTrang << ln;
}

class Phieu{
    char maPhieu[10], ngayKK[15];
    NV x;
    Phong y;
    TaiSan *z;
    int n;
public:
    void Nhap();
    void Xuat();
    friend void TimKiem(Phieu a);
    friend void Sap(Phieu a);
};

void Phieu::Nhap(){
    fflush(stdin);
    cout << "Nhap ma phieu: ";      gets(maPhieu);
    cout << "Nhap ngay kiem ke: ";  gets(ngayKK);
    x.Nhap();
    y.Nhap();
    cout << "\nNhap so luong tai san can kiem ke: ";
    cin >> n;
    z = new TaiSan[n];
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin cho tai san thu " << i+1 <<": \n";
        z[i].Nhap();
        cout << ln;
    }

}

void Phieu::Xuat(){
    cout << setw(15) << left << "Ma phieu: " << maPhieu;
    cout << "Ngay kiem ke: " << ngayKK << ln;
    x.Xuat();
    y.Xuat();
    cout << ln;
    cout << setw(25) << left << "TEN TAI SAN";
    cout << setw(10) << left << "SO LUONG";
    cout << setw(15) << left << "TINH TRANG" << ln;
    for(int i=0; i<n; i++)
        z[i].Xuat();
    cout << "So luong tai san da kiem ke: " << n;
    int T=0;
    for(int i=0; i<n; i++){
        T += z[i].soLuongTS;
    }
    cout << "\t Tong so luong: " << T;
}

void TimKiem(Phieu a){
    int dem = 0;
    for(int i=0; i<a.n; i++)
        if(strcmp(a.z[i].tenTS, "May tinh") == 0)
            dem ++;
    if(dem == 0) cout << "\nKhong co May tinh";
    else cout << "\nCo tai san ten May tinh";
}

void Sap(Phieu a){
    for(int i=0; i<a.n; i++)
        for(int j=i+1; j<a.n; j++)
        if(a.z[i].soLuongTS > a.z[j].soLuongTS) swap(a.z[i], a.z[j]);
}

int main()
{
    Phieu a;
    a.Nhap();
    a.Xuat();
    TimKiem(a);
    Sap(a);
    return 0;
}
