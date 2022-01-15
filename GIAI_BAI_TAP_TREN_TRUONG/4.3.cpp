#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Hang;

class Date
{
    int D, M, Y;
public:
    friend class Hang;
};

class Hang
{
    char maHang[15], tenHang[25];
    Date ngaySX;
public:
    void Nhap(), Xuat();
};

void Hang::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma hang: ";           gets(maHang);
    cout << "Nhap ten hang: ";          gets(tenHang);
    cout << "Nhap ngay san xuat: ";     cin >> ngaySX.D;
    cout << "Nhap thang san xuat: ";    cin >> ngaySX.M;
    cout << "Nhap nam san xuat: ";      cin >> ngaySX.Y;
    fflush(stdin);
}

void Hang::Xuat()
{
    cout << setw(15) << left << maHang;
    cout << setw(25) << left << tenHang;
    cout << setw(10) << left << ngaySX.D;
    cout << setw(10) << left << ngaySX.M;
    cout << setw(10) << left << ngaySX.Y << ln;
}

int main()
{
    Hang *a;
    int n;
    cout << "Nhap so luong hang hoa: ";      cin >> n;
    fflush(stdin);
    for(int i=0; i<n; i++)
    {
       cout << "\nNhap thong tin hang thu " << i+1 <<": \n";
       a[i].Nhap();
    }
    cout << ln;
    cout << setw(15) << left << "MA HANG";
    cout << setw(25) << left << "TEN HANG";
    cout << setw(10) << left << "NGAY SX";
    cout << setw(10) << left << "THANG SX";
    cout << setw(10) << left << "NAM SX" << ln;
    for(int i=0; i<n; i++)
    a[i].Xuat();


    return 0;
}
