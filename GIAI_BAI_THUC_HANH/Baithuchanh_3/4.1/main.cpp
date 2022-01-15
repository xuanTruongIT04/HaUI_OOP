#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class SinhVien
{
    char maSV[15], hoTen[25];
    double diemToan, diemLy, diemHoa;
public:
    void Nhap(), Xuat();
    friend void Sap(SinhVien *a, int n);
};

void SinhVien::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma sinh vien : ";     gets(maSV);
    cout << "NHap ten sinh vien: ";     gets(hoTen);
    cout << "Nhap diem toan: ";         cin >> diemToan;
    cout << "Nhap diem ly: ";           cin >> diemLy;
    cout << "Nhap diem hoa: ";          cin >> diemHoa;
    fflush(stdin);
}

void SinhVien::Xuat()
{
    cout << setw(15) << left << maSV;
    cout << setw(25) << left << hoTen;
    cout << setw(15) << left << diemToan;
    cout << setw(15) << left << diemLy;
    cout << setw(15) << left << diemHoa;
    cout << setw(15) << left << diemToan + diemLy + diemHoa << ln;
}

void Sap(SinhVien *a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if((a[i].diemToan + a[i].diemLy + a[i].diemHoa) > (a[j].diemToan + a[j].diemLy + a[j].diemHoa)) swap(a[i], a[j]);
}

int main()
{
    SinhVien *a;
    int n;
    cout << "Nhap so sinh vien: ";      cin >> n;
    fflush(stdin);
    a = new SinhVien[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin sinh vien thu " << i+1 << ": \n";
        a[i].Nhap();
    }
    Sap(a, n);
    cout << ln;
    cout << setw(15) << left << "MA SINH VIEN";
    cout << setw(25) << left << "HO TEN";
    cout << setw(15) << left << "DIEM TOAN";
    cout << setw(15) << left << "DIEM LY";
    cout << setw(15) << left << "DIEM HOA";
    cout << setw(15) << left << "TONG DIEM" << ln;
    for(int i=0; i<n; i++)
        a[i].Xuat();
    return 0;
}
