#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class ThoiGian
{
    int gio, phut, giay;
public:
    ThoiGian();
    ThoiGian(int gio, int phut, int giay);
    ThoiGian operator + (ThoiGian y);
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
    this -> gio  = gio;
    this -> phut = phut;
    this -> giay = giay;
}

ThoiGian ThoiGian::operator + (ThoiGian y)
{
    ThoiGian z;
    z.gio = gio + y.gio;
    z.phut = phut + y.phut;
    z.giay = giay + y.giay;
    return z;
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
    x << y.gio << " gio " << y.phut << " phut " << y.giay << " giay";
    return x;
}

int main()
{
    ThoiGian P(1, 2, 3);
    ThoiGian Q;
    cout << "Nhap thong tin thoi gian Q: \n";     cin >> Q;
    cout << "\n\nThong tin thoi gian P: " << P;
    cout << "\n\nThong tin thoi gian Q: " << Q;

    ThoiGian Tong = P + Q;
    ThoiGian Hieu = P - Q;

    cout << "\n\nTong 2 thoi gian: " << Tong;
    cout << "\n\nHieu 2 thoi gian: " << Hieu << ln;
    return 0;
}

