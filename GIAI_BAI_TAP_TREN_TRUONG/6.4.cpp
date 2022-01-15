#include <iostream>
#include <string.h>
using namespace std;
#define ln "\n";

class Electronic
{
protected:
    double congSuat, dienAp;
public:
    Electronic(double congSuat, double dienAp);
};

Electronic::Electronic(double congSuat, double dienAp)
{
    this->congSuat = congSuat;
    this->dienAp = dienAp;
}

class MayGiat : public Electronic
{
    double dungTich;
    char loai[15];
public:
    MayGiat(double congSuat, double dienAp ,double dungTich, char* loai);
    void Xuat();
};

MayGiat::MayGiat(double congSuat, double dienAp ,double dungTich, char* loai) : Electronic(congSuat, dienAp)
{
    this->dungTich = dungTich;
    strcpy(this->loai, loai);
}

void MayGiat::Xuat()
{
    cout << "Cong suat: " << Electronic::congSuat << ln;
    cout << "Dien ap  : " << Electronic::dienAp << ln;
    cout << "Dung tich: " << dungTich << ln;
    cout << "Loai     : " << loai << ln;
}

class TuLanh : public Electronic
{
    double dungTich;
    int soNgan;
public:
    TuLanh(double congSuat, double dienAp, double dungTich, int soNgan);
    void Xuat();
};

TuLanh::TuLanh(double congSuat, double dienAp ,double dungTich, int soNgan) : Electronic(congSuat, dienAp)
{
    this->dungTich = dungTich;
    this->soNgan = soNgan;
}

void TuLanh::Xuat()
{
    cout << "Cong suat: " << Electronic::congSuat << ln;
    cout << "Dien ap  : " << Electronic::dienAp << ln;
    cout << "Dung tich: " << dungTich << ln;
    cout << "So ngan  : " << soNgan << ln;
}
int main()
{
    MayGiat a(2250, 220, 80, "Panasony");
    cout <<"Xuat thong tin cua may giat: \n";
    a.Xuat();

    TuLanh b(170, 110, 60, 10);
    cout <<"Xuat thong tin cua tu lanh: \n";
    b.Xuat();
    return 0;
}
