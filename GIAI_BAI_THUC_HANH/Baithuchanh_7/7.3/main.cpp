#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class Khoa
{
    char maK[15], tenK[25], truongKhoa[15];
    friend class TruongDH;
};

class Ban
{
    char maB[15], tenB[25], ngayThanhLap[15];
    friend class TruongDH;
};

class Truong
{
    char maT[15], tenT[25], diaChi[25];
public:
    void Nhap(), Xuat();
};

void Truong::Nhap()
{
    cout << "Nhap ma truong : ";     fflush(stdin);      gets(maT);
    cout << "Nhap ten truong: ";     fflush(stdin);      gets(tenT);
    cout << "Nhap dia chi   : ";     fflush(stdin);      gets(diaChi);
}

void Truong::Xuat()
{
    cout << "Ma truong: " << maT;
    cout << "\t\t\tTen truong: " << tenT << ln;
    cout << "Dia chi: " << diaChi << ln;
}

class TruongDH : public Truong
{
    Khoa *x;
    int n;
    Ban *y;
    int m;
public:
    void Nhap(), Xuat();
};

void TruongDH::Nhap()
{
    cout << "NHAP THONG TIN CUA TRUONG DAI HOC: \n";
    Truong::Nhap();
    cout << "Nhap so luong khoa: ";     cin >> n;
    x = new Khoa[n];
    for(int i=0; i<n; i++)
    {
        cout << "Nhap thong tin khoa thu " << i+1 << ": \n";
        cout << "Nhap ma khoa    : ";          fflush(stdin);      gets(x[i].maK);
        cout << "Nhap ten khoa   : ";          fflush(stdin);      gets(x[i].tenK);
        cout << "Nhap truong khoa: ";          fflush(stdin);      gets(x[i].truongKhoa);
        cout << ln;
    }

    cout << "Nhap so luong ban : ";     cin >> m;
    y= new Ban[m];
    for(int i=0; i<m; i++)
    {
        cout << "Nhap thong tin ban thu " << i+1 << ": \n";
        cout << "Nhap ma ban    : ";          fflush(stdin);      gets(y[i].maB);
        cout << "Nhap ten ban   : ";          fflush(stdin);      gets(y[i].tenB);
        cout << "Nhap truong ban: ";          fflush(stdin);      gets(y[i].ngayThanhLap);
        cout << ln;
    }
}

void TruongDH::Xuat()
{
    cout << "\n\nXUAT THONG TIN CUA TRUONG DAI HOC:\n";
    Truong::Xuat();
    cout << setw(15) << left << "MA KHOA";
    cout << setw(25) << left << "TEN KHOA";
    cout << setw(25) << left << "TRUONG KHOA";
    cout << setw(15) << left << "MA BAN";
    cout << setw(25) << left << "TEN BAN";
    cout << setw(25) << left << "NGAY THANH LAP" << ln;

    for(int i=0; i<n; i++)
    {
        cout << setw(15) << left << x[i].maK;
        cout << setw(25) << left << x[i].tenK;
        cout << setw(25) << left << x[i].truongKhoa << ln;
    }

    for(int i=0; i<m; i++)
    {
            cout << setw(15) << left << y[i].maB;
            cout << setw(25) << left << y[i].tenB;
            cout << setw(25) << left << y[i].ngayThanhLap << ln;
    }
}

int main()
{
    TruongDH k;
    k.Nhap();
    k.Xuat();
    return 0;
}
