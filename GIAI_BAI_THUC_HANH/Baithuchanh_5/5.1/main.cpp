#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class NCC
{
    char maNCC[15], tenNCC[20], diaChi[40];
public:
    void Nhap(), Xuat();
};

void NCC::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma nha cung cap : ";       gets(maNCC);
    cout << "Nhap ten nha cung cap: ";       gets(tenNCC);
    cout << "Nhap dia chi nha cung cap: ";   gets(diaChi);
}

void NCC::Xuat()
{
    cout << "Ma NCC:  " << maNCC;
    cout << "\t\t\tTen NCC:  " << tenNCC << ln;
    cout << "Dia chi:  " << diaChi << ln;
}

class Hang
{
    char tenHang[15];
    double donGia;
    int soLuong;
public:
    void Nhap(), Xuat();
    friend class Phieu;
};

void Hang::Nhap()
{
    fflush(stdin);
    cout << "Nhap ten hang: ";          gets(tenHang);
    cout << "Nhap don gia : ";          cin >> donGia;
    cout << "Nhap so luong: ";          cin >> soLuong;
    fflush(stdin);
}

void Hang::Xuat()
{
    cout << setw(15) << left << tenHang;
    cout << setw(15) << left << donGia;
    cout << setw(15) << left << soLuong;
    cout << setw(15) << left << donGia*soLuong << ln;
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

    cout << "Nhap ma phieu: ";          fflush(stdin);    gets(maPhieu);
    cout << "Nhap ngay lap: ";          fflush(stdin);    gets(ngayLap);
    x.Nhap();
    cout << "Nhap so luong hang: ";     cin >> n;
    y = new Hang[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap hang hoa thu " << i+1 << ": \n";
        y[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cout << "\n\n=====================PHIEU NHAP HANG=====================\n";
    cout << "Ma phieu:  " << maPhieu;
    cout << "\t\t\tNgay lap:  " << ngayLap << ln;
    x.Xuat();
    cout << setw(15) << left << "TEN HANG";
    cout << setw(15) << left << "DON GIA";
    cout << setw(15) << left << "SO LUONG";
    cout << setw(15) << left << "THANH TIEN" << ln;
    double tong = 0;
    for(int i=0; i<n; i++)
    {
        tong += (y[i].soLuong * y[i].donGia);
        y[i].Xuat();
    }
    cout << "\t\t\t\t\t\tTong thanh tien: " << tong;
    cout << "\n===========================================================";
}

int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}
