#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define ln "\n";

class PTBH
{
    double a, b, c;
public:
    void Nhap(), Xuat(), Giai();
};

void PTBH::Nhap()
{
    cout << "Nhap a: ";     cin >> a;
    cout << "Nhap b: ";     cin >> b;
    cout << "Nhap c: ";     cin >> c;
}

void PTBH::Xuat()
{
    cout << "\nPTBH dang: " << a << "x^2 " << (b>0 ? " + " : " - ") << b  <<"x" << (c>0 ? " + " : " - ") << c << " = 0";
}

void PTBH::Giai()
{
    double x1, x2, delta;
    delta = b*b -4*a*c;
    if(a==0)
    {
        if(b==0)
        {
            if(c==0) cout << "\nPTBH vo so nghiem! \n";
            else cout << "\nPTBH vo nghiem!\n";
        }
        else cout << "PTBH co mot nghiem duy nhat: x= " << -c/b;
    }
    else{
        if(delta > 0)
        {
            cout << "\n\nPTBH co 2 nghiem phan biet: ";
            cout << "\nX1= " << (-b - sqrt(delta))/(double)(2*a);
            cout << "\nX2= " << (-b + sqrt(delta))/(double)(2*a);
        }
        else if(delta = 0) cout << "\nPTBH co 1 nghiem duy nhat: x= " << (-b)/(double)(2*a);
        else cout << "\nPTBH vo nghiem! ";
    }
}

int main()
{
    PTBH p;
    p.Nhap();
    p.Xuat();
    p.Giai();
    return 0;
}
