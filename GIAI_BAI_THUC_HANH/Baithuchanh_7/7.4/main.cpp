#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class Hang
{
    char tenH[25];
    double donGia;
    int soLuong;
public:
    void Nhap(), Xuat();
    friend class Phieu;
};

void Hang::Nhap()
{
    cout << "Nhap ten hang: ";      fflush(stdin);      gets(tenH);
    cout << "Nhap don gia : ";      cin >> donGia;
    cout << "Nhap so luong: ";      cin >> soLuong;
}

void Hang::Xuat()
{
    cout << setw(25) << left << tenH;
    cout << setw(15) << left << donGia;
    cout << setw(15) << left << soLuong;
    cout << setw(15) << left << donGia * soLuong << ln;
}

class Phieu
{
    char maP[15], ngayLap[15];
    Hang *x;
    int n;
public:
    void Nhap(), Xuat();
};

void Phieu::Nhap()
{
    cout << "Nhap ma phieu: ";      fflush(stdin);      gets(maP);
    cout << "Nhap ngay lap: ";      fflush(stdin);      gets(ngayLap);
    cout << "Nhap so luong hang hoa: ";                 cin >> n;
    x = new Hang[n];
    for(int i=0; i<n; i++)
    {
        cout << "Nhap thong tin hang thu " << i+1 << ": \n";
        x[i].Nhap();
        cout << ln;
    }
}

void Phieu::Xuat()
{
    cout << "====================PHIEU MUA HANG====================\n";
    cout << "Ma phieu:  " << maP;
    cout << "\t\t\tNgay lap:  " << ngayLap << ln;
    cout << setw(25) << left << "TEN HANG";
    cout << setw(15) << left << "DON GIA";
    cout << setw(15) << left << "SO LUONG";
    cout << setw(15) << left << "THANH TIEN" << ln;
    double sum = 0;
    for(int i=0; i<n; i++){
        x[i].Xuat();
        sum += x[i].donGia * x[i].soLuong;
    }
    cout << setw(55) << left << "Cong thanh tien: "  << sum;
}

int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}
