#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

class DieuHoa;

class SanPham
{
protected:
    char maSP[15], tenSP[25], ngayNhap[15];
public:
    void Nhap(), Xuat();
};

void SanPham::Nhap()
{
    cout << "Nhap ma san pham : ";       fflush(stdin);      gets(maSP);
    cout << "Nhap ten san pham: ";       fflush(stdin);      gets(tenSP);
    cout << "Nhap ngay nhap sp: ";       fflush(stdin);      gets(ngayNhap);
};

void SanPham::Xuat()
{
    cout << setw(15) << left << maSP;
    cout << setw(25) << left << tenSP;
    cout << setw(15) << left << ngayNhap;
}

class DieuHoa : public SanPham
{
    double congSuat, giaBan;
    char tenHSX[25];
public:
    void Nhap(), Xuat();
    friend double giaMin(DieuHoa *a, int n);
    friend void HangE(DieuHoa *a, int n);
};

void DieuHoa::Nhap()
{
    SanPham::Nhap();
    cout << "Nhap cong suat: ";     cin >> congSuat;
    cout << "Nhap ten hang : ";     fflush(stdin);      gets(tenHSX);
    cout << "Nhap gia ban  : ";     cin >> giaBan;
}

void DieuHoa::Xuat()
{
    SanPham::Xuat();
    cout << setw(15) << left << congSuat;
    cout << setw(25) << left << tenHSX;
    cout << setw(15) << left << giaBan << ln;
}

double giaMin(DieuHoa *a, int n)
{
    double min = a[0].giaBan;
    for(int i=0; i<n; i++)
    {
        if(min > a[i].giaBan) min = a[i].giaBan;
    }
    return min;
}

void HangE(DieuHoa *a, int n)
{
    for(int i=0 ; i<n; i++)
    {
        if(strcmp(a[i].tenHSX, "Electrolux") == 0 && giaMin(a, n)) {
            a[i].Xuat();
        }
    }
}

int main()
{
    DieuHoa *a;
    int n;
    cout << "Nhap so luong dieu hoa: ";     cin >> n;
    a = new DieuHoa[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin dieu hoa thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    cout << setw(15) << left << "MA SP";
    cout << setw(25) << left << "TEN SP";
    cout << setw(15) << left << "NGAY NHAP";
    cout << setw(15) << left << "CONG SUAT";
    cout << setw(25) << left << "TEN HANG";
    cout << setw(15) << left << "GIA BAN" << ln;
    for(int i=0; i<n; i++)
    {
        a[i].Xuat();
    }

    cout << "\nDanh sach dieu hoa co HSX Electrolux va gia ban thap nhap la: \n";
    HangE(a, n);

    return 0;
}
