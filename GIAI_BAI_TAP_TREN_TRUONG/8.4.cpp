#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class MaTran
{
    double **a;
    int m, n;
public:
    MaTran operator + (MaTran y);
    MaTran operator - (MaTran y);
    MaTran operator ! ();
    friend istream& operator >> (istream& x, MaTran &y);
    friend ostream& operator << (ostream& x, MaTran y);
};

istream& operator >> (istream& x, MaTran &y)
{
    cout << "Nhap n: ";     x >> y.n;
    cout << "Nhap m: ";     x >> y.m;
    y.a = new double*[y.n];
    for(int i=0; i<y.n; i++)
        y.a[i] = new double[y.m];
    for(int i=0; i<y.n; i++)
        for(int j=0; j<y.m; j++)
    {
        cout << "A[" << i<< "][" << j <<"]= ";
        x >> y.a[i][j];
    }
    return x;
}

ostream& operator << (ostream& x, MaTran y)
{
    for(int i=0; i<y.n; i++)
        for(int j=0; j<y.m; j++)
    {
        x << y.a[i][j] << " ";
        x << ln;
    }
    return x;
}

MaTran MaTran::operator + (MaTran y)
{
    MaTran z;
    if(m==y.m && n==y.n)
    {
        z.n = n;
        z.m = m;
        z.a = new double *[n];
        for(int i=0; i<n; i++)
            z.a[i] = new double[m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            z.a[i][j] = a[i][j] + y.a[i][j];
    }else
    {
        cout << "Hai ma tran khong cung kich thuoc! " << ln;
        z.n = z.m = 0;
    }
    return z;
}

MaTran MaTran::operator - (MaTran y)
{
    MaTran z;
    if(m==y.m && n==y.n)
    {
        z.n = n;
        z.m = m;
        z.a = new double *[n];
        for(int i=0; i<n; i++)
            z.a[i] = new double[m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            z.a[i][j] = a[i][j] - y.a[i][j];
    }else
    {
        cout << "Hai ma tran khong cung kich thuoc! " << ln;
        z.n = z.m = 0;
    }
    return z;
}

MaTran MaTran::operator!()
{
    for(int i=0; i<n; i++)
    {
            for(int j=0; j<m; j++)
            a[i][j] = -a[i][j];
    }
    return *this;
}


int main()
{
    MaTran P, Q;
    cout << "Nhap ma tran P: \n";       cin >> P;
    cout << "\nNhap ma tran Q: \n";     cin >> Q;
    P = !P;
    Q = !Q;
    cout << "Ma Tran P: \n";            cout << P;
    cout << "Ma Tran Q: \n";            cout << Q;
    MaTran Tong = P + Q;
    MaTran Hieu = P - Q;
    cout << P << " + " << Q << " = " << Tong << ln;
    cout << P << " - " << Q << " = " << Hieu << ln;
    ofstream f("D:/MaTran.txt", ios::out);
    f << P << " + " << Q << " = " << Tong << ln;
    f << P << " - " << Q << " = " << Hieu << ln;
    f.close();
    return 0;
}
