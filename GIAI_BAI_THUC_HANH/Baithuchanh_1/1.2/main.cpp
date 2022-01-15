#include <iostream>
using namespace std;
#define ln "\n";

class HCN
{
    double D, R;
public:
    void Nhap();
    void Ve();
    float DienTich();
    float ChuVi();
};

void HCN::Nhap()
{
    cout << "Nhap chieu dai: ";     cin >> D;
    cout << "Nhap chieu rong: ";    cin >> R;
}

void HCN::Ve()
{
    for(int i=0; i<D; i++)
    {
        for(int j=0; j<R; j++)
            cout << " * ";
            cout << ln;
    }
}

float HCN::DienTich()
{
    return D*R;
}

float HCN::ChuVi()
{
    return 2*(D+R);
}

int main()
{
    HCN h;
    h.Nhap();
    cout << ln;
    h.Ve();
    cout << "\n\nDien tich cua HCN: " << h.DienTich();
    cout << "\n\nChu vi cua HCN: " << h.ChuVi();
    return 0;
}
