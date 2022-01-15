#include <iostream>
using namespace std;
#define ln "\n";

class Mang
{
    float *Value;
    int n;
public:
    Mang operator ++ ();
    Mang operator -- ();
    friend istream& operator >>(istream& x, Mang& y);
    friend ostream& operator << (ostream& x, Mang y);
};

Mang Mang::operator ++ ()
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(Value[i] > Value[j]) swap(Value[i], Value[j]);
    return *this;
}

Mang Mang::operator -- ()
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(Value[i] < Value[j]) swap(Value[i], Value[j]);
    return *this;
}

istream& operator >> (istream& x, Mang& y)
{
    cout << "Nhap n: ";     x >> y.n;
    y.Value = new float[y.n];
    for(int i=0; i<y.n; i++)
    {
        cout << "Value[" << i << "]= ";
        x >> y.Value[i];
    }
    return x;
}

ostream& operator << (ostream &x, Mang y)
{
    for(int i=0; i<y.n; i++)
        x  << y.Value[i] << "\t";
    return x;
}

int main()
{
    Mang a;
    cin >> a;
    cout << "Sap xep mang tang dan: \n";
    a = ++a;
    cout << a;
    cout << "\nSap xep mang giam dan: \n";
    a = --a;
    cout << a;

    return 0;
}
