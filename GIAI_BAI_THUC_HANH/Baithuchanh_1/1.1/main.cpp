#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class SinhVien
{
    char maSV[15], hoTen[25];
    int tuoi;
    double diem;
public:
    void Nhap();
    void Xuat();
};

void SinhVien::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma sinh vien: ";      gets(maSV);
    cout << "Nhap ho ten svien: ";      gets(hoTen);
    cout << "Nhap tuoi: ";              cin >> tuoi;
    cout << "Nhap diem: ";              cin >> diem;
    fflush(stdin);
}

void SinhVien::Xuat()
{
    cout << setw(15) << left << maSV;
    cout << setw(25) << left << hoTen;
    cout << setw(10) << left << tuoi;
    cout << diem << ln;
}

void title()
{
    cout << setw(15) << left << "MA SV";
    cout << setw(25) << left << "HO TEN";
    cout << setw(10) << left << "TUOI";
    cout << "DIEM" << ln;
}

int main()
{
    SinhVien a, b;
    cout << "Nhap thong tin cua sinh vien thu nhat: \n";
    a.Nhap();
    cout << "\nNhap thong tin cua sinh vien thu hai: \n";
    b.Nhap();
    cout << "\nHien thi thong tin cua hai sinh vien:\n\n";
    title();
    a.Xuat();
    b.Xuat();
    return 0;
}
