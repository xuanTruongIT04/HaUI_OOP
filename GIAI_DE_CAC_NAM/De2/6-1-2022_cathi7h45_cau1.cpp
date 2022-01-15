#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class NhanSu
{
protected:
    char hoTen[50], gioiTinh[5], diaChi[100];
    int ngay, thang, nam;
};

class CongChuc : public NhanSu
{
    char nganhNghe[20], trinhDo[50];
    int namvaoCQ;
    float hsLuong, phCap;
public:
    void Nhap(), Xuat();
    float ThuNhap();
    friend void ThuNhapMin(CongChuc *a, int n);
    friend void SapXepHT(CongChuc *a, int n);
};

void CongChuc::Nhap()
{
    cout << "Nhap ho ten    : ";        fflush(stdin);      gets(hoTen);
    cout << "Nhap gioi tinh : ";        fflush(stdin);      gets(gioiTinh);
    cout << "Nhap dia chi   : ";        fflush(stdin);      gets(diaChi);
    cout << "Nhap ngay sinh : ";                            cin >> ngay;
    cout << "Nhap thang sinh: ";                            cin >> thang;
    cout << "Nhap nam sinh  : ";                            cin >> nam;
    cout << "Nhap nganh nghe: ";        fflush(stdin);      gets(nganhNghe);
    cout << "Nhap trinh do  : ";        fflush(stdin);      gets(trinhDo);
    cout << "Nhap nam vao CQ: ";                            cin >> namvaoCQ;
    cout << "Nhap hso luong : ";                            cin >> hsLuong;
    cout << "Nhap phu cap   : ";                            cin >> phCap;
}

float CongChuc::ThuNhap()
{
    return hsLuong * 830 + phCap;
}

void CongChuc::Xuat()
{
    cout << setw(25) << left << hoTen;
    cout << setw(10) << left << gioiTinh;
    cout << setw(25) << left << diaChi;
    cout << setw(7)  << left << ngay;
    cout << setw(7)  << left << thang;
    cout << setw(7)  << left << nam;
    cout << setw(25) << left << nganhNghe;
    cout << setw(25) << left << trinhDo;
    cout << setw(15)  << left << namvaoCQ;
    cout << setw(15) << left << hsLuong;
    cout << phCap << ln;
}

void title()
{
    cout << setw(25) << left << "HO TEN";
    cout << setw(10) << left << "GIOI TINH";
    cout << setw(25) << left << "DIA CHI";
    cout << setw(7)  << left << "NGAY";
    cout << setw(7)  << left << "THANG";
    cout << setw(7)  << left << "NAM";
    cout << setw(25) << left << "NGANH NGHE";
    cout << setw(25) << left << "TRINH DO";
    cout << setw(15)  << left << "NAM VAO CQ";
    cout << setw(15) << left << "HE SO LUONG";
    cout << "PHU CAP" << ln;
}

void ThuNhapMin(CongChuc *a, int n)
{
    float min = 0;
    for(int i=0; i<n; i++)
        if(a[i].ThuNhap() < min)
            min = a[i].ThuNhap();

    for(int k=0; k<n; k++)
        if(a[k].ThuNhap() == min)
            a[k].Xuat();
}

void SapXepHT(CongChuc *a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(strcmp(a[i].hoTen, a[j].hoTen) < 0) swap(a[i], a[j]);
    for(int i=0; i<n; i++)
        a[i].Xuat();
}

int main()
{
    CongChuc *a;
    int n;
    do {
        cout << "Nhap so luong cong chuc: ";     cin >> n;
        if(n>50 || n<=0) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n>50 || n<=0);
    a = new CongChuc[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin cong chuc thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    cout << "\n\nSap Xep Theo Ho Ten: \n";
    title();
    SapXepHT(a, n);

    cout << "\n\nThong tin cong chuc co thu nhap thap nhat: \n";
    title();
    ThuNhapMin(a, n);
    return 0;
}

