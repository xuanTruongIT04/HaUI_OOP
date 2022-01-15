#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class DoanhNghiep
{
    char tenDN[50], diaChi[30];
    int soNV;
    double doanhThu;
public:
    void Nhap();
    void Xuat();
};

void DoanhNghiep::Nhap()
{
    fflush(stdin);
    cout << "Nhap ten doanh nghiep: ";      gets(tenDN);
    cout << "Nhap dia chi dnghiep : ";      gets(diaChi);
    cout << "Nhap so nhan vien: ";          cin >> soNV;
    cout << "Nhap doanh thu :";             cin >> doanhThu;
    fflush(stdin);
}

void DoanhNghiep::Xuat()
{

    cout << setw(50) << left << tenDN;
    cout << setw(30) << left << diaChi;
    cout << setw(15) << left << soNV;
    cout <<  doanhThu << ln;
}

int main()
{
    DoanhNghiep *a;
    int n;
    cout << "Nhap so doanh nghiep: ";       cin >> n;
    a = new DoanhNghiep[n];

    // Nhap danh sach doanh nghiep
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap doanh nghiep thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    // Xuat danh sach doanh nghiep
    cout << "\n\nXUAT THONG TIN CAC DOANH NGHIEP: \n";
    cout << setw(50) << left << "TEN DOANH NGHIEP";
    cout << setw(30) << left << "DIA CHI";
    cout << setw(15) << left << "SO NHAN VIEN";
    cout << "DOANH THU" << ln;

    for(int i=0; i<n; i++)
    {
        a[i].Xuat();
        cout << ln;
    }
    return 0;
}
