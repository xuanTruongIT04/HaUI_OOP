#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class SachGK;

class TacGia
{
    char tenTG[30], diaChiTG[30];
public:
    friend class SachGK;
    friend void NXBKD(SachGK *a, int n);
};

class NXB
{
    char tenNXB[30], diaChiNXB[30];
public:
    friend class SachGK;
    friend void NXBKD(SachGK *a, int n);
};

class IDSach
{
protected:
    char tenSach[30], maSach[15];
public:
    void Nhap(), Xuat();
};

void IDSach::Nhap()
{
    cout << "Nhap ten sach: ";      fflush(stdin);      gets(tenSach);
    cout << "Nhap ma sach : ";      fflush(stdin);      gets(maSach);
}

void IDSach::Xuat()
{
    cout << setw(30) << left << tenSach;
    cout << setw(15) << left << maSach;
}

class SachGK : public IDSach
{
    TacGia x;
    NXB y;
public:
    void Nhap(), Xuat();
    friend void NXBKD(SachGK *a, int n);
    friend void SapXepMS(SachGK *a, int n);
};

void SachGK::Nhap()
{
    IDSach::Nhap();
    cout << "Nhap ten tac gia: ";       fflush(stdin);      gets(x.tenTG);
    cout << "Nhap dia chi TG : ";       fflush(stdin);      gets(x.diaChiTG);
    cout << "Nhap ten NXB    : ";       fflush(stdin);      gets(y.tenNXB);
    cout << "Nhap dia chi NXB: ";       fflush(stdin);      gets(y.diaChiNXB);
}

void SachGK::Xuat()
{
    IDSach::Xuat();
    cout << setw(30) << left << x.tenTG;
    cout << setw(30) << left << x.diaChiTG;
    cout << setw(30) << left << y.tenNXB;
    cout << y.diaChiNXB << ln;
}

void title()
{
    cout << setw(30) << left << "TEN SACH";
    cout << setw(15) << left << "MA SACH";
    cout << setw(30) << left << "TEN TAC GIA";
    cout << setw(30) << left << "DIA CHI TG";
    cout << setw(30) << left << "TEN NXB";
    cout << "DIA CHI NXB" << ln;
}

void NXBKD(SachGK *a, int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(strcmp(a[i].y.tenNXB, "KIMDONG")==0 && strcmp(a[i].x.tenTG, "Pham Van At") == 0)
        {
                a[i].Xuat();
                cnt ++;
        }
    if(cnt == 0) cout << "\nKhong Co SGK Cua NXB KIMDONG, Tac Gia Pham Van At! \n";
}

void SapXepMS(SachGK *a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i].maSach < a[j].maSach)
                swap(a[i], a[j]);
    for(int i=0; i<n; i++)
        a[i].Xuat();
}

void Chen(SachGK *a, int &n, int k)
{
    do {
        cout << "Nhap vi tri can chen: ";       cin >> k;
        if(k>n) cout << "\nMOI BAN NHAP LAI!\n";
    }while(k>n);
    for(int i=k; i<n; i++)
    {
        a[k].Nhap();
        a[i] = a[i+1];
    }
    n++;
}


int main()
{
    SachGK *a;
    int n;
    do {
        cout << "Nhap so luong SGK: ";      cin >> n;
        if(n<=0) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n<=0);
    a = new SachGK[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin SGK thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    cout << "\n\n--Thong tin danh sach SGK: \n";
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();

    cout << "\n\n--Danh Sach SGK NXB KIMDONG, TG Pham Van At: \n";
    title();
    NXBKD(a, n);

    cout << "\n\n--Sap Xep SGK Theo Chieu Giam Da Cua Ma Sach: \n";
    title();
    SapXepMS(a, n);
    return 0;
}
