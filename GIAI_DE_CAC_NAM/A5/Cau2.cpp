#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Mang
{
    int *a;
    int n;
public:
    Mang operator ++ ();
    Mang operator ! ();
    friend istream& operator >>(istream& x, Mang& y);
    friend ostream& operator << (ostream& x, Mang y);
};

Mang Mang::operator ++ ()
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i] > a[j]) swap(a[i], a[j]);
    return *this;
}

Mang Mang::operator ! ()
{
    for(int i=0; i<n; i++)
        a[i] = -a[i];
    return *this;
}



istream& operator >> (istream& x, Mang& y)
{
    cout << "Nhap n: ";     x >> y.n;
    y.a = new int[y.n];
    for(int i=0; i<y.n; i++)
    {
        cout << "A[" << i << "]= ";
        x >> y.a[i];
    }
    return x;
}

ostream& operator << (ostream &x, Mang y)
{
    for(int i=0; i<y.n; i++)
        x  << y.a[i] << "\t";
    return x;
}

int main()
{
    Mang P, Q;
    cout << "Nhap mang thu nhat: \n";           cin >> P;
    cout << "\nNhap mang thu hai : \n";         cin >> Q;
    cout << "\n\n--Sap Xep Mang P Tang Dan: \n" << ++P;
    cout << "\n\n--Doi Dau Mang Q: \n" << !Q << ln;
    return 0;
}

