#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class Hang
{
    char maHang[15], tenHang[25];
    double donGia;
    int soLuong;
public:
    void Nhap();
    void Xuat();
};

void Hang::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma hang : ";      gets(maHang);
    cout << "Nhap ten hang: ";      gets(tenHang);
    cout << "Nhap don gia : ";      cin >> donGia;
    cout << "Nhap so luong: ";      cin >> soLuong;
    fflush(stdin);
}

void Hang::Xuat()
{
    cout << setw(15) << left << maHang;
    cout << setw(25) << left << tenHang;
    cout << setw(15) << left << donGia;
    cout << setw(15) << left << soLuong;
    cout << donGia * soLuong << ln;
}

void title()
{
    cout << setw(15) << left << "MA HANG";
    cout << setw(25) << left << "TEN HANG";
    cout << setw(15) << left << "DON GIA";
    cout << setw(15) << left << "SO LUONG";
    cout << "THANH TIEN" << ln;
}

int main()
{
    Hang *h;
    int n;
    cout << "Nhap so luong mat hang: ";     cin >> n;
    h = new Hang[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin mat hang thu " << i+1 << ": \n";
        h[i].Nhap();
        cout << ln;
    }
    cout << "\n\nHien thi thong tin cac mat hang: \n";
    title();
    for(int i=0; i<n; i++)
    {
        h[i].Xuat();
    }
    return 0;
}
