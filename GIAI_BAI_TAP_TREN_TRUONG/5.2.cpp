#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class SinhVien
{
    char maSV[15], tenSV[25], lop[15];
    int khoa;
public:
    void Nhap(), Xuat();
};

void SinhVien::Nhap()
{
    cout << "Nhap ma SV : ";      fflush(stdin);      gets(maSV);
    cout << "Nhap ten SV: ";      fflush(stdin);      gets(tenSV);
    cout << "Nhap lop SV: ";      fflush(stdin);      gets(lop);
    cout << "Nhap khoa  : ";      cin >> khoa;
}

void SinhVien::Xuat()
{
    cout << "Ma sinh vien:  " << maSV;
    cout << "\tTen sinh vien: " << tenSV << ln;
    cout << "Lop:  \t" << lop;
    cout << "\tKhoa: " << maSV << ln;

}

class MonHoc
{
    char tenMon[25];
    int soTrinh, diem;
public:
    void Nhap(), Xuat();
    friend class Phieu;
};
void MonHoc::Nhap()
{
    cout << "Nhap ten MH  : ";      fflush(stdin);       gets(tenMon);
    cout << "Nhap so trinh: ";      cin >> soTrinh;
    cout << "Nhap so diem : ";      cin >> diem;
}

void MonHoc::Xuat()
{
    cout << setw(25) << left << tenMon;
    cout << setw(15) << left << soTrinh;
    cout << setw(15) << left << diem << ln;
}

class Phieu
{
    SinhVien x;
    MonHoc *y;
    int n;
public:
    void Nhap(), Xuat();
};

void Phieu::Nhap()
{
    x.Nhap();
    cout << "Nhap so luong mon hoc: ";        cin >> n;
    y = new MonHoc[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin mon hoc thu " << i+1 << ": \n";
        y[i].Nhap();
    }
}

void Phieu::Xuat()
{
    cout << "\n=================PHIEU BAO DIEM===============\n";
    x.Xuat();
    cout << setw(25) << left << "TEN MON";
    cout << setw(15) << left << "SO TRINH";
    cout << setw(15) << left << "DIEM" << ln;
    int sumT = 0;
    int sumD = 0;
    for(int i=0; i<n; i++)
    {
        y[i].Xuat();
        sumT += y[i].soTrinh;
        sumD += y[i].diem * y[i].soTrinh;
    }
    cout << "\t\t\tDiem trung binh:" << ((double)sumD / sumT);
    cout << "\n===================================================";
}

int main()
{
    Phieu k;
    k.Nhap();
    k.Xuat();
    return 0;
}
