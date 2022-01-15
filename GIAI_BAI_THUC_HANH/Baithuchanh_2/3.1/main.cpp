#include <iostream>
using namespace std;
#define ln "\n";

class Date
{
    int D, M, Y;
public:
    void Nhap(), Xuat();
};

void Date::Nhap()
{
    cout << "Nhap ngay: ";      cin >> D;
    cout << "Nhap thang: ";     cin >> M;
    cout << "Nhap nam : ";      cin >> Y;
}

void Date::Xuat()
{
    cout << "Date: " << D <<" / " << M << " / " << Y << "\n";
}

class NhanSu
{
    char maNS[15], hoTen[25];
    Date NS;
public:
    void Nhap(), Xuat();
};

void NhanSu::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma nhan su: ";        gets(maNS);
    cout << "Nhan ho ten nsu: ";        gets(hoTen);
    NS.Nhap();
}

void NhanSu::Xuat()
{
    cout << "\nMa nhan su: " << maNS << ln;
    cout << "Ho ten nsu: " << hoTen << ln;
    NS.Xuat();

}

int main()
{
    NhanSu x;
    x.Nhap();
    x.Xuat();
    return 0;
}
