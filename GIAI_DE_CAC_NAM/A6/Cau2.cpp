#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class PhanSo
{
    double TS, MS;
public:
    PhanSo();
    PhanSo(double TS, double MS);
    PhanSo operator + (PhanSo y);
    PhanSo operator * (PhanSo y);
    friend istream& operator >> (istream &x, PhanSo &y);
    friend ostream& operator << (ostream &x, PhanSo y);
};

PhanSo::PhanSo()
{
    TS = MS = 0;
}

PhanSo::PhanSo(double TS, double MS)
{
    this->TS = TS;
    this->MS = MS;
}

PhanSo PhanSo::operator + (PhanSo y)
{
    PhanSo z;
    z.TS = TS*y.MS + y.TS*MS;
    z.MS = MS * y.MS;
    return z;
}

PhanSo PhanSo::operator *(PhanSo y)
{
    PhanSo z;
    z.TS = TS * y.TS;
    z.MS = MS * y.MS;
    return z;
}

istream& operator >> (istream &x, PhanSo &y)
{
    cout << "Nhap tu so : ";     x >> y.TS;
    cout << "Nhap mau so: ";     x >> y.MS;
    return x;
}

ostream& operator << (ostream &x, PhanSo y)
{
    x << y.TS << " / " << y.MS << ln;
    return x;
}

int main()
{
    PhanSo P, Q;
    cout << "Nhap PS thu nhat: \n";         cin >> P;
    cout << "\nNhap PS thu hai : \n";       cin >> Q;
    PhanSo Tong = P + Q;
    PhanSo Tich = P * Q;
    cout << "\nPhan so thu nhat: " << P;
    cout << "\n\nPhan so thu hai : " << Q;
    cout << "\n\nTong 2 PS: " << Tong;
    cout << "\n\nTich 2 PS: " << Tich << ln;
    return 0;
}

