#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class PTBH
{
    double a, b, c;
public:
    PTBH();
    PTBH(double aNew, double bNew, double cNew);
    void Nhap(), Xuat(), Giai();
};

PTBH::PTBH()
{
    a = b = c = 0;
}

PTBH::PTBH(double aNew, double bNew, double cNew)
{
    a = aNew;
    b = bNew;
    c = cNew;
}

void PTBH::Nhap()
{
    cout << "Nhap a: ";     cin >> a;
    cout << "Nhap b: ";     cin >> b;
    cout << "Nhap c: ";     cin >> c;
}

void PTBH::Xuat()
{
    cout << a << "x^2" << (b>0? " + " : " - ") << abs(b) << "x" << (c>0 ? " + " : " - ") << abs(c) << " = 0";
}

void PTBH::Giai()
{
    double x1, x2, delta;
    delta = b*b - 4*a*c;
    if(a==0)
    {
        if(b==0){
            if(c==0) cout << "\nPTBH co vo so nghiem!";
            else cout << "\nPTBH vo nghiem!";
        }
        else cout << "\nPTBH co 1 nghiem: x= " << -c/b;
    }
    else
    {
        if(delta > 0)
            {
            cout << "\nPTBH co 2 nghiem phan biet:";
            cout << "\nX1 = " << (-b-sqrt(delta))/(double)(2*a);
            cout << "\nX2 = " << (-b+sqrt(delta))/(double)(2*a);
        }
        else if(delta = 0)
        {
            cout << "\nPTBH co 1 nghiem: X1 = X2 =" << (-b)/(double)(2*a);
        }
        else cout << "\nPTBH vo nghiem!";
    }

}
int main()
{
    PTBH Q;
    /*PTBH P(3, 4, 5);
    P.Xuat();
    P.Giai();*/

    Q.Nhap();
    Q.Xuat();
    Q.Giai();
    return 0;
}
