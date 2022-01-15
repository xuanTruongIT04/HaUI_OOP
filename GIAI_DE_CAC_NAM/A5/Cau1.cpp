#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class MayIn;

class NhaSanXuat
{
    char tenNSX[30], diaChi[30];
public:
    void Nhap(), Xuat();
    friend void NSXHP(MayIn *a, int n);
};

void NhaSanXuat::Nhap()
{
    cout << "Nhap ten NSX  : ";       fflush(stdin);      gets(tenNSX);
    cout << "Nhap dchi NSX : ";       fflush(stdin);      gets(diaChi);
}

void NhaSanXuat::Xuat()
{
    cout << setw(30) << left << tenNSX;
    cout << setw(30) << left << diaChi;
}

class May
{
protected:
    char nhanHieu[15];
    NhaSanXuat x;
    float giaThanh;
public:
    void Nhap(), Xuat();
};

void May::Nhap()
{
    cout << "Nhap nhan hieu: ";     fflush(stdin);      gets(nhanHieu);
    x.Nhap();
    cout << "Nhap gia thanh: ";     cin >> giaThanh;
}

void May::Xuat()
{
    cout << setw(15) << left << nhanHieu;
    x.Xuat();
    cout << setw(15) << left << giaThanh;
}

class MayIn : public May
{
    int tocDo, doPhanGiai;
public:
    void Nhap(), Xuat();
    friend void NhanHieuMF(MayIn *a, int n);
    friend void NSXHP(MayIn *a, int n);
    friend void ChenMI(MayIn *a, MayIn b ,int &n, int k);
};

void MayIn::Nhap()
{
    May::Nhap();
    cout << "Nhap toc do   : ";        cin >> tocDo;
    cout << "Nhap do PG    : ";        cin >> doPhanGiai;
}

void MayIn::Xuat()
{
    May::Xuat();
    cout << setw(15) << left << tocDo;
    cout << doPhanGiai << ln;
}

void title()
{
    cout << setw(15) << left << "NHAN HIEU";
    cout << setw(30) << left << "TEN NSX";
    cout << setw(30) << left << "DIA CHI";
    cout << setw(15) << left << "GIA THANH";
    cout << setw(15) << left << "TOC DO";
    cout << "DO PHAN GIAI" << ln;
}
void NhanHieuMF(MayIn *a, int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(strcmp(a[i].nhanHieu, "MF242e")==0)
        {
            a[i].Xuat();
            cnt ++ ;
        }
    if(cnt == 0) cout << "\nKhong Co May In Nao Nhan Hieu MF242e\n";
}

void NSXHP(MayIn *a, int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(strcmp(a[i].x.tenNSX, "HP") == 0)
        {
            a[i].Xuat();
            cnt ++;
        }
    if(cnt == 0) cout << "\nKhong Co May In Nao NSX HP\n";
}

void ChenMI(MayIn *a, MayIn b ,int &n, int k)
{
    a = (MayIn*)realloc(a, (n+1)*sizeof(MayIn));
    for(int i=n; i>k-1; i--)
        a[i] = a[i-1];
    n++;
    a[k-1] = b;
}


int main()
{
    MayIn *a;
    int n;
    do {
        cout << "Nhap so luong may in: ";       cin >> n;
        if(n<0) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n<0);
    a = new MayIn[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin may in thu " << i+1 << ": \n";
        a[i].Nhap();
    }
    cout << "\n\n--Xuat Thong Tin Danh Sach May In: \n";
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();

    cout << "\n\n--Xuat Thong Tin Danh Sach May In Co Nhan Hieu MF242e: \n";
    title();
    NhanHieuMF(a, n);

    cout << "\n\n--Xuat Thong Tin Danh Sach May In NSX HP: \n";
    title();
    NSXHP(a, n);

    cout << "\n\n--Chen Them Mot May In Moi: \n";
    MayIn b;
    b.Nhap();
    int k;
    do {
        cout << "\nNhap vi tri can chen: ";       cin >> k;
        if(k>=n) cout << "\nMOI BAN NHAP LAI!\n";
    }while(k>=n);
    ChenMI(a, b, n, k);
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();

    return 0;
}
