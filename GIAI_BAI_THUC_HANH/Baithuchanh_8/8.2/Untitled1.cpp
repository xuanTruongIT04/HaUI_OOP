#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Person
{
protected:
    char hoTen[50], queQuan[50];
    int ngay, thang, nam;
};

class VanDongVien : public Person
{
protected:
    char boMon[30];
    float thuNhap;
};

class CauThu : public VanDongVien
{
    char CLB[100], viTri[100];
public:
    void Nhap(), Xuat();
    friend void CLBTT(CauThu *a, int n);
    friend void ThuNhapMax(CauThu *a, int n);
};

void CauThu::Nhap()
{
    cout << "Nhap ho ten    : ";        fflush(stdin);      gets(hoTen);
    cout << "Nhap que quan  : ";        fflush(stdin);      gets(queQuan);
    cout << "Nhap ngay sinh : ";        cin >> ngay;
    cout << "Nhap thang sinh: ";        cin >> thang;
    cout << "Nhap nam sinh  : ";        cin >> nam;
    cout << "Nhap bo mon    : ";        fflush(stdin);      gets(boMon);
    cout << "Nhap thu nhap  : ";        cin >> thuNhap;
    cout << "Nhap ten CLB   : ";        fflush(stdin);      gets(CLB);
    cout << "Nhap vi tri    : ";        fflush(stdin);      gets(viTri);
}

void CauThu::Xuat()
{
    cout << setw(30) << left << hoTen;
    cout << setw(30) << left << queQuan;
    cout << setw(7)  << left << ngay;
    cout << setw(7)  << left << thang;
    cout << setw(7)  << left << nam;
    cout << setw(20) << left << boMon;
    cout << setw(20) << left << thuNhap;
    cout << setw(30) << left << CLB;
    cout << setw(20) << left << viTri << ln;
}

void title()
{
    cout << setw(30) << left << "HO TEN";
    cout << setw(30) << left << "QUE QUAN";
    cout << setw(7)  << left << "NGAY";
    cout << setw(7)  << left << "THANG";
    cout << setw(7)  << left << "NAM";
    cout << setw(20) << left << "BO MON";
    cout << setw(20) << left << "THU NHAP";
    cout << setw(30) << left << "CAU LAC BO";
    cout << setw(20) << left << "VI TRI" << ln;
}

void CLBTT(CauThu *a, int n)
{
    for(int i=0; i<n; i++)
        if(strcmp(a[i].CLB, "T&T")==0)
            a[i].Xuat();
}

void ThuNhapMax(CauThu *a, int n)
{
    float max = 0;
    for(int i=0; i<n; i++)
        if(a[i].thuNhap > max)
            max = a[i].thuNhap;

    for(int i=0; i<n; i++)
        if(a[i].thuNhap == max)
            a[i].Xuat();
}


int main()
{
    CauThu *a;
    int n;
    do {
        cout << "Nhap so luong cau thu: ";          cin >> n;
        if(n<=0 || n>=50) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n<=0 || n>=50);
    a = new CauThu[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin cau thu thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    cout << "\n\nDanh sach cau thu CLB T&T: \n";
    title();
    CLBTT(a, n);

    cout << "\n\nThong tin nguoi co thu nhap cao nhat: \n";
    title();
    ThuNhapMax(a, n);

    return 0;
}

