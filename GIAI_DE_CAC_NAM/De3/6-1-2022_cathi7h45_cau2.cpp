#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Vector
{
    double x, y;
public:
    Vector();
    Vector(double x, double y);
    Vector operator + (Vector b);
    Vector operator - (Vector b);
    friend istream& operator >> (istream &a, Vector &b);
    friend ostream& operator << (ostream &a, Vector b);
};


Vector::Vector()
{
    x = y = 0;
}

Vector::Vector(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector Vector::operator + (Vector b)
{
    Vector c;
    c.x = x + b.x;
    c.y = y + b.y;
    return c;
}

Vector Vector::operator - (Vector b)
{
    Vector c;
    c.x = x - b.x;
    c.y = y - b.y;
    return c;
}

istream& operator >> (istream &a, Vector &b)
{
    cout << "Nhap x: ";     a >> b.x;
    cout << "Nhap y: ";     a >> b.y;
    return a;
}

ostream& operator << (ostream &a, Vector b)
{
    a << "X = " << b.x << ln;
    a << "Y = " << b.y << ln;
    return a;
}

int main()
{
    Vector P, Q;
    cout << "Nhap vector thu nhat: \n";         cin >> P;
    cout << "\nNhap vector thu hai : \n";       cin >> Q;
    Vector Tong = P + Q;
    Vector Hieu = P - Q;
    cout << "\nTong cua 2 vector: \n" << Tong << ln;
    cout << "Hieu cua 2 vector: \n" << Hieu << ln;
    return 0;
}

