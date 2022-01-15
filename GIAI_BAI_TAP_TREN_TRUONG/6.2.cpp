#include <iostream>
using namespace std;
#define ln "\n";

class Printer
{
protected:
    double trongLuong;
    char hangSX[30];
    int namSX, tocDo;
};

class DotP : public Printer
{
    char matDoKim[25];
public:
    void Nhap(), Xuat();
    friend void Sua(DotP &a);
};

void DotP::Nhap()
{
    cout << "Nhap trong luong: ";       cin >> Printer::trongLuong;
    cout << "Nhap toc do :";            cin >> Printer::tocDo;
    cout << "Nhap hang san xuat: ";     fflush(stdin);              gets(Printer::hangSX);
    cout << "Nhap nam san xuat : ";     cin >> Printer::namSX;
    cout << "Nhap mat do kim   : ";     cin >> matDoKim;
}

void DotP::Xuat()
{
    cout << "Trong luong: "     << Printer::trongLuong << ln;
    cout << "Toc do :"          << Printer::tocDo << ln;
    cout << "Hang san xuat: "   << Printer::hangSX << ln;
    cout << "Nam san xuat : "   << Printer::namSX << ln;
    cout << "Mat do kim   : "   << matDoKim << ln;
}

class LaserP : public Printer
{
    char doPG[15];
public:
    void Nhap(), Xuat();
    friend void Sua(LaserP &b);
};

void LaserP::Nhap()
{
    cout << "Nhap trong luong: ";       cin >> Printer::trongLuong;
    cout << "Nhap toc do :";            cin >> Printer::tocDo;
    cout << "Nhap hang san xuat: ";     fflush(stdin);              gets(Printer::hangSX);
    cout << "Nhap nam san xuat : ";     cin >> Printer::namSX;
    cout << "Nhap do phan giai   : ";   fflush(stdin);              gets(doPG);
}

void LaserP::Xuat()
{
    cout << "Trong luong: "     << Printer::trongLuong << ln;
    cout << "Toc do :"          << Printer::tocDo << ln;
    cout << "Hang san xuat: "   << Printer::hangSX << ln;
    cout << "Nam san xuat : "   << Printer::namSX << ln;
    cout << "Mat do kim   : "   << doPG << ln;
}

void Sua(DotP &a)
{
    a.namSX = 2021;
}

void Sua(LaserP &b)
{
    b.namSX = 2021;
}


int main()
{
    DotP a;
    LaserP b;
    cout << "Nhap thong tin may in kim: \n";
    a.Nhap();
    Sua(a);
    cout << "\nNhap thong tin may in laser: \n";
    b.Nhap();
    Sua(b);
    cout << "\nXuat thong tin may in kim: \n";
    a.Xuat();
    cout << "\nXuat thong tin may in laser: \n";
    b.Xuat();


    return 0;
}
