#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class PhanSo
{
    float TS, MS;
public:
    PhanSo operator * (PhanSo y);
    PhanSo operator / (PhanSo y);
    PhanSo operator + (PhanSo y);
    PhanSo operator - (PhanSo y);
    double operator !();
    friend istream& operator >> (istream &x, PhanSo &y);
    friend ostream& operator << (ostream &x, PhanSo y);
};

PhanSo PhanSo::operator *(PhanSo y)
{
    PhanSo z;
    z.TS = TS * y.TS;
    z.MS = MS * y.MS;
    return z;
}

PhanSo PhanSo::operator / (PhanSo y)
{
    PhanSo z;
    z.TS = TS * y.MS;
    z.MS = MS * y.TS;
    return z;
}

PhanSo PhanSo::operator + (PhanSo y)
{
    PhanSo z;
    z.TS = TS*y.MS + y.TS*MS;
    z.MS = MS * y.MS;
    return z;
}

PhanSo PhanSo::operator - (PhanSo y)
{
    PhanSo z;
    z.TS = TS * y.MS - y.TS*MS;
    z.MS = MS * y.MS;
    return z;
}

double PhanSo::operator!()
{
    return TS/MS;
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

int main(){
    PhanSo a, b;
    cout << "Nhap PS thu nhat: \n";       cin >> a;
    cout << "Nhap PS thu hai : \n";       cin >> b;
    PhanSo tich   = a * b;
    PhanSo thuong = a / b;
    PhanSo tong   = a + b;
    PhanSo hieu   = a - b;
    ofstream f("D:/PhanSo.txt", ios::out);
    f << a << " * " << b << " = " << tich << " = " << !tich <<    ln;
    f << a << " * " << b << " = " << thuong << " = " << !thuong <<  ln;
    f << a << " * " << b << " = " << tong << " = " << !tong <<  ln;
    f << a << " * " << b << " = " << hieu << " = " << !hieu <<  ln;
    f.close();
    return 0;
}
