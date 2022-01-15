#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class Oto
{
    char maO[15];
    double giaO, khauHao;
    int tuoiO;
public:
    void Nhap();
    void Xuat();
};

void Oto::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma o to  : ";             gets(maO);
    cout << "Nhap gia o to : ";             cin >> giaO;
    cout << "Nhap tuoi o to: ";             cin >> tuoiO;
    cout << "Nhap ti le khau hau/nam: ";    cin >> khauHao;
}

void Oto::Xuat()
{
    cout << setw(15) << left << maO;
    cout << setw(15) << left << giaO;
    cout << setw(15) << left << tuoiO;
    cout << setw(15) << left << khauHao;
    for(int i=0; i<tuoiO; i++)
        giaO -= giaO * khauHao;
    cout << giaO << ln;
}

int main()
{
    Oto *a;
    int n;
    cout << "Nhap so xe o to: ";        cin >> n;       fflush(stdin);
    a = new Oto[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin o to thu " << i+1 << ": \n";
        a[i].Nhap();
        cout << ln;
    }

    cout << setw(15) << left << "MA O TO";
    cout << setw(15) << left << "GIA O TO";
    cout << setw(15) << left << "TUOI O TO";
    cout << setw(15) << left << "KHAU HAO";
    cout << "GIA TRI HIEN TAI" << ln;
    for(int i=0; i<n; i++)
        a[i].Xuat();

    return 0;
}
