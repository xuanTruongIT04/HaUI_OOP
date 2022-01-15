#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Diem
{
    double x, y, z;
public:
    Diem();
    Diem(double x, double y, double z);
    Diem operator + (Diem b);
    friend istream& operator >> (istream &a, Diem &b);
    friend ostream& operator << (ostream &a, Diem b);
};

Diem::Diem()
{
    x = y = z = 0;
}

Diem::Diem(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Diem Diem::operator + (Diem b)
{
    Diem c;
    c.x = x + b.x;
    c.y = y + b.y;
    c.z = z + b.z;
    return c;
}

istream& operator >> (istream &a, Diem &b)
{
    cout << "Nhap x: ";     a >> b.x;
    cout << "Nhap y: ";     a >> b.y;
    cout << "Nhap z: ";     a >> b.z;
    return a;
}

ostream& operator << (ostream &a, Diem b)
{
    a << "X = " << b.x << ln;
    a << "Y = " << b.y << ln;
    a << "Z = " << b.z << ln;
    return a;
}

int main()
{
    Diem P, Q;
    cout << "Nhap diem thu nhat: \n";     cin >> P;
    cout << "\nNhap diem thu hai : \n";   cin >> Q;
    Diem Tong = P + Q;
    cout << "\nTong cua hai diem: \n" << Tong << ln;
    return 0;
}

