#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class SoPhuc
{
    float thuc, ao;
public:
    SoPhuc();
    SoPhuc(float thuc, float ao);
    friend ostream& operator << (ostream &x, SoPhuc y);
    SoPhuc operator + (SoPhuc y);
    SoPhuc operator - (SoPhuc y);
};

SoPhuc::SoPhuc()
{
    thuc = ao = 0;
}

SoPhuc::SoPhuc(float thuc, float ao)
{
    this->thuc = thuc;
    this->ao   = ao;
}

ostream& operator << (ostream &x, SoPhuc y)
{
    x << y.thuc << " + i*" << y.ao << ln;
    return x;
}

SoPhuc SoPhuc::operator + (SoPhuc y)
{
    SoPhuc z;
    z.thuc = thuc + y.thuc;
    z.ao   = ao   + y.ao;
    return z;
}

SoPhuc SoPhuc::operator - (SoPhuc y)
{
    SoPhuc z;
    z.thuc = thuc - y.thuc;
    z.ao   = ao   - y.ao;
}

int main()
{
    SoPhuc a(3, 4.5);
    SoPhuc b(2, 3.4);
    SoPhuc tong = a + b;
    SoPhuc hieu = a - b;
    // In ra man hinh
    cout << a << " + " << b << " = " << tong << ln;
    cout << a << " - " << b << " = " << hieu << ln;
    ofstream f("D:/SoPhuc.txt", ios::out);
    f << a << " + " << b << " = " << tong << ln;
    f << a << " - " << b << " = " << hieu << ln;
    f.close();
    return 0;
}
