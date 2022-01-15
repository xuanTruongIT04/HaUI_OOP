#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class SinhVien
{
    char maSV[15], tenSV[30], lop[15];
    int khoa;
public:
    void Nhap(), Xuat();
};

void SinhVien::Nhap()
{
    cout << "Nhap ma sinh vien : ";      fflush(stdin);      gets(maSV);
    cout << "Nhap ten sinh vien: ";      fflush(stdin);      gets(tenSV);
    cout << "Nhap lop sinh vien: ";      fflush(stdin);      gets(lop);
    cout << "Nhap khoa sinh vien: ";     cin >> khoa;
    fflush(stdin);
}

void SinhVien::Xuat()
{
    cout << setw(15) << left << "  Ma sinh vien: " << maSV;
    cout << "\t\tTen sinh vien: " << tenSV << ln;
    cout << setw(15) << left << "  Lop: " << lop;
    cout << "\t\tKhoa: " << khoa << ln;
}

class Mon
{
    char tenMon[30];
    int soTrinh;
    double diem;
public:
    void Nhap(), Xuat();
    friend class Phieu;
};

void Mon::Nhap()
{
    cout << "Nhap ten mon : ";      fflush(stdin);      gets(tenMon);
    cout << "Nhap so trinh: ";      cin >> soTrinh;
    cout << "Nhap so diem : ";      cin >> diem;
    fflush(stdin);
}

void Mon::Xuat()
{
    cout << setw(30) << left << tenMon;
    cout << setw(20) << left << soTrinh;
    cout << diem << ln;
}

class Phieu
{
    SinhVien x;
    Mon *y;
    int n;
public:
    void Nhap(), Xuat();
};

void Phieu::Nhap()
{
    x.Nhap();
    cout << "Nhap so mon: ";        cin >> n;
    y = new Mon[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap mon hoc thu " << i+1 <<": \n";
        y[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cout << "\n\n=======================PHIEU BAO DIEM=======================\n";
    x.Xuat();
    int tongDiem = 0;
    int tongTrinh = 0;
    cout <<"\nBang diem: \n";
    cout << setw(30) << left << "TEN MON";
    cout << setw(20) << left << "SO TRINH";
    cout << "DIEM" << ln;
    for(int i=0; i<n; i++)
    {
        tongDiem += (y[i].soTrinh * y[i].diem);
        tongTrinh += y[i].soTrinh;
        y[i].Xuat();
    }
    cout << "\t\tDiem trung binh:\t" << tongDiem/tongTrinh;
    cout << "\n============================================================";
}


int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}
