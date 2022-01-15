#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class NhiThuc
{
    double a, b;
public:
    NhiThuc();
    NhiThuc(double a, double b);
    NhiThuc operator !();
    friend istream& operator >> (istream &x, NhiThuc &y);
    friend ostream& operator << (ostream &x, NhiThuc y);
};

NhiThuc::NhiThuc()
{
    a = b = 0;
}

NhiThuc::NhiThuc(double a, double b)
{
    this->a = a;
    this->b = b;
}

NhiThuc NhiThuc::operator!()
{
    NhiThuc z;
    z.a = -a;
    z.b = -b;
    return z;
}

istream& operator >> (istream &x, NhiThuc &y)
{
    cout << "Nhap a: ";     x >> y.a;
    cout << "Nhap b: ";     x >> y.b;
    return x;
}

ostream& operator << (ostream &x, NhiThuc y)
{
    x << y.a << "x" << (y.b>0?" + ":" - ") << abs(y.b);
    return x;
}

int main()
{
    NhiThuc P;
    cin >> P;
    cout << "\nNhi thuc P: " << P << ln;
    cout << "Doi dau nhi thuc P: " << !P << ln;
    return 0;
}
