#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class ThoiGian
{
    int gio, phut, giay;
public:
    ThoiGian();
    ThoiGian(int gio, int phut, int giay);
    ThoiGian operator - (ThoiGian y);
    friend istream& operator >> (istream &x, ThoiGian &y);
    friend ostream& operator << (ostream &x, ThoiGian y);
};

ThoiGian::ThoiGian()
{
    gio = phut = giay = 0;
}

ThoiGian::ThoiGian(int gio, int phut, int giay)
{
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
}

ThoiGian ThoiGian::operator - (ThoiGian y)
{
    ThoiGian z;
    z.gio  = gio  - y.gio;
    z.phut = phut - y.phut;
    z.giay = giay - y.giay;
    return z;
}

istream& operator >> (istream &x, ThoiGian &y)
{
    cout << "Nhap gio : ";       x >> y.gio;
    cout << "Nhap phut: ";       x >> y.phut;
    cout << "Nhap giay: ";       x >> y.giay;
    return x;
}

ostream& operator << (ostream &x, ThoiGian y)
{
    x << "Gio : " << y.gio  << ln;
    x << "Phut: " << y.phut << ln;
    x << "Giay: " << y.giay << ln;
    return x;
}


int main()
{
    ThoiGian P, Q;
    cout << "Nhap thoi gian thu nhat: \n";     cin >> P;
    cout << "\nNhap thoi gian thu hai : \n";   cin >> Q;
    ThoiGian Hieu = P - Q;
    cout << "\nHieu cua hai thoi gian: \n" << Hieu << ln;
    return 0;
}

