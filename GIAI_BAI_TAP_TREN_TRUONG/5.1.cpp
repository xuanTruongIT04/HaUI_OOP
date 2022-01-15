#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class NCC
{
    char maNCC[15], tenNCC[15], diaChi[25];
public:
    void Nhap(), Xuat();
};

void NCC::Nhap(){
    cout << "Nhap ma NCC  : ";       fflush(stdin);      gets(maNCC);
    cout << "Nhap ten NCC : ";       fflush(stdin);      gets(tenNCC);
    cout << "Nhap dia chi : ";       fflush(stdin);      gets(diaChi);
}

void NCC::Xuat(){
    cout << "Ma NCC:  " << maNCC;
    cout << "\t\tTen NCC:  " << tenNCC << ln;
    cout << "Dia chi:  " << diaChi << ln;
}


class Hang
{
    char tenHang[25];
    double donGia;
    int soLuong;
public:
    void Nhap(), Xuat();
    friend class Phieu;
};

void Hang::Nhap()
{
    cout << "Nhap ten hang: ";      fflush(stdin);      gets(tenHang);
    cout << "Nhap don gia : ";      cin >> donGia;
    cout << "Nhap so luong: ";      cin >> soLuong;
}

void Hang::Xuat()
{
    cout << setw(25) << left << tenHang;
    cout << setw(15) << left << donGia;
    cout << setw(15) << left << soLuong;
    cout << donGia * soLuong << ln;
}

class Phieu
{
    char maPhieu[15], ngayLap[15];
    NCC x;
    Hang *y;
    int n;
public:
    void Nhap(), Xuat();
};

void Phieu::Nhap()
{
    cout << "Nhap ma phieu: ";      fflush(stdin);      gets(maPhieu);
    cout << "Nhap ngay lap: ";      fflush(stdin);      gets(ngayLap);
    x.Nhap();
    cout << "Nhap so luong hang: ";                     cin >> n;
    y = new Hang[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap hang thu " << i+1 <<": \n";
        y[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cout << "\n\n================================================================\n";
    cout << "Ma Phieu:  " << maPhieu;
    cout << "\t\tNgay lap:  " << ngayLap << ln;
    double sum = 0;
    cout << setw(25) << left << "TEN HANG";
    cout << setw(15) << left << "DON GIA";
    cout << setw(15) << left << "SO LUONG";
    cout << "THANH TIEN" << ln;
    for(int i=0; i<n; i++){
        y[i].Xuat();
        sum += y[i].donGia * y[i].soLuong;
    }
    cout << "\t\t\t\t   Cong thanh tien:   " << sum << ln;
    cout << "================================================================";
}

int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}
