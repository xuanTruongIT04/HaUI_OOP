#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class MoTo;

class NhaSanXuat
{
    char tenNSX[30], diaChi[30];
public:
    void Nhap(), Xuat();
    friend void NSXHD(MoTo *a, int n);
    friend void Xoa(MoTo *a, int &n);
};

void NhaSanXuat::Nhap()
{
    cout << "Nhap ten NSX    : ";      fflush(stdin);      gets(tenNSX);
    cout << "Nhap dia chi NSX: ";      fflush(stdin);      gets(diaChi);
}

void NhaSanXuat::Xuat()
{
    cout << setw(30) << left << tenNSX;
    cout << setw(30) << left << diaChi;
}

class HangHoa
{
protected:
    char nhanHieu[15];
    NhaSanXuat x;
public:
    void Nhap(), Xuat();
    friend void NSXHD(MoTo *a, int n);
    friend void Xoa(MoTo *a, int &n);
};

void HangHoa::Nhap()
{
    cout << "Nhap nhan hieu:   ";     fflush(stdin);      gets(nhanHieu);
    x.Nhap();
}

void HangHoa::Xuat()
{
    cout << setw(15) << left << nhanHieu;
    x.Xuat();
}

class MoTo : public HangHoa
{
    int phanKhoi;
    float giaThanh;
public:
    void Nhap(), Xuat();
    friend void SapXep(MoTo *a, int n);
};

void MoTo::Nhap()
{
    HangHoa::Nhap();
    cout << "Nhap phan khoi:   ";     cin >> phanKhoi;
    cout << "Nhap gia thanh:   ";     cin >> giaThanh;
}

void MoTo::Xuat()
{
    HangHoa::Xuat();
    cout << setw(15) << left << phanKhoi;
    cout << giaThanh << ln;
}

void title()
{
    cout << setw(15) << left << "NHAN HIEU";
    cout << setw(30) << left << "TEN NSX";
    cout << setw(30) << left << "DIA CHI";
    cout << setw(15) << left << "PHAN KHOI";
    cout << "GIA THANH" << ln;
}

void NSXHD(MoTo *a, int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(strcmp(a[i].x.tenNSX, "HuynDai") == 0)
            {
                a[i].Xuat();
                cnt++;
            }
    if(cnt == 0) cout << "\nKhong co chiec xe Moto co ten NSX la HuynDai! \n";
}

void SapXep(MoTo *a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i].giaThanh > a[j].giaThanh)
                swap(a[i], a[j]);
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();
}

void Xoa(MoTo *a, int &n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(strcmp(a[i].x.tenNSX, "HonDa") == 0)
        {
            for(int j=i+1; j<n; j++)
                a[i] = a[j];
            i--;
            n--;
            cnt ++;
        }
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();

    if(cnt == 0) cout << "Khong co chiec xe Moto co ten NSX la HonDa! \n";
}

int main()
{
    MoTo *a;
    int n;
    do {
        cout << "Nhap so luong xe moto: ";      cin >> n;
        if(n<2 || n>20) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n<2 || n>20);
    a = new MoTo[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin mo to thu " << i+1 << ": \n";
        a[i].Nhap();
    }
    cout << "\n\n-Hien thi danh sach Moto: \n";
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();

    cout << "\n\n-Hien Thi Danh Sach MoTo Co Ten NSX HuynDai: \n";
    title();
    NSXHD(a, n);

    cout << "\n\n-Sap Xep Danh Sach MoTo Theo Chieu Tang Dan Cua Gia Thanh: \n";
    SapXep(a, n);

    cout << "\n\n-Xoa MoTo Cua NSX HonDa: \n";
    Xoa(a, n);
    return 0;
}
