#include <iostream>
using namespace std;
#define ln "\n";

class Mang{
    int *x;
    int n;
public:
    void Nhap();
    void Xuat();
    void SapXep();
};

void Mang::Nhap()
{
    cout << "Nhap n: ";     cin >> n;
    x = new int[n];
    for(int i=0; i<n; i++)
    {
        cout << "Nhap phan tu X["<<i<<"] = ";
        cin >> x[i];
    }
}

void Mang::Xuat()
{
    for(int i=0 ;i<n; i++)
        cout << "X["<<i<<"]= " << x[i] << "\n";
}

void Mang::SapXep()
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(x[i]>x[j]) swap(x[i], x[j]);
}

int main()
{
    Mang a;
    a.Nhap();
    a.Xuat();
    a.SapXep();
    cout << "\n\nSAP XEP MANG: \n";
    a.Xuat();
    return 0;
}

