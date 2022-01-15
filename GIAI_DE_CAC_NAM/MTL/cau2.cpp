#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Diem
{
    double x, y, z, t;
public:
    Diem();
    Diem(double x, double y, double z, double t);
    bool operator == (Diem b);
    Diem operator + (Diem b);
    friend istream& operator >> (istream &a, Diem &b);
    friend ostream& operator << (ostream &a, Diem b);
};

Diem::Diem()
{
    x = y = z = t = 0;
}

Diem::Diem(double x, double y, double z, double t)
{
    this -> x  = x;
    this -> y  = y;
    this -> z  = z;
    this -> t  = t;
}

bool Diem::operator == (Diem b) {
    if (x == b.x && y == b.y && z == b.z && t == b.t) return true;
    else return false;
}

Diem Diem::operator + (Diem b) {
    Diem c;
    c.x = x + b.x;
    c.y = y + b.y;
    c.z = z + b.z;
    c.t = t + b.t;
    return c;
}

istream& operator >> (istream &a, Diem &b)
{
    cout << "Nhap chieu dai : ";     a >> b.x;
    cout << "Nhap chieu rong: ";     a >> b.y;
    cout << "Nhap chieu cao : ";     a >> b.z;
    cout << "Nhap chieu cao : ";     a >> b.t;
    return a;
}

ostream& operator << (ostream &a, Diem b)
{
    a << "X / Y / Z / Z : " << b.x << " / " << b.y << " / " << b.z << " / " << b.t;
    return a;
}



int main()
{
    Diem P, Q;
    cout << "Nhap diem thu nhat: \n";        cin >> P;
    cout << "\nNhap diem thu hai : \n";      cin >> Q;

    // Xuat ra man hinh:
    cout << "\n\nDiem thu nhat: \n" << P;
    cout << "\n\nDiem thu hai : \n" << Q;

    if(P == Q) cout << "\n\nHai diem trung nhau! \n";
    else cout << "\n\nHai diem khong trung nhau! \n";

    Diem Tong = P + Q;
    cout << "\nTong hai diem la: \n" << Tong << ln;

    // Xuat ra file:
    ofstream f("D://Diem", ios::out);

    f << "\n\nDiem thu nhat: \n" << P;
    f << "\n\nDiem thu hai : \n" << Q;

    if(P == Q) f << "\n\nHai diem trung nhau! \n";
    else f << "\n\nHai diem khong trung nhau! \n";

    f << "\nTong hai diem la: \n" << Tong << ln;
    f.close();
    return 0;
}

