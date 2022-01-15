#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class NhanSu
{
protected:
    char hoTen[30], gioiTinh[15];
    int ngay, thang, nam;
public:
    void Nhap(), Xuat();
};

void NhanSu::Nhap()
{
    cout << "Nhap ho ten    : ";        fflush(stdin);      gets(hoTen);
    cout << "Nhap ngay sinh : ";                            cin >> ngay;
    cout << "Nhap thang sinh: ";                            cin >> thang;
    cout << "Nhap nam sinh  : ";                            cin >> nam;
    cout << "Nhap gioi tinh : ";        fflush(stdin);      gets(gioiTinh);
}

void NhanSu::Xuat()
{
    cout << setw(30) << left << hoTen;
    cout << setw(10) << left << ngay;
    cout << setw(10) << left << thang;
    cout << setw(10) << left << nam;
    cout << setw(15) << left << gioiTinh;
}

class NhanVien : public NhanSu
{
    char phongBan[15], diaChi[30];
    double heSoLuong, hsPhuCap, giamTru;
public:
    void Nhap(), Xuat();
    friend double TongThuNhap(NhanVien *a, int n);
    friend void SapXep(NhanVien *a, int n);
    friend void SuaPB(NhanVien *&a, int n);
};

void NhanVien::Nhap()
{
    NhanSu::Nhap();
    cout << "Nhap phong ban: ";     fflush(stdin);      gets(phongBan);
    cout << "Nhap dia chi  : ";     fflush(stdin);      gets(diaChi);
    cout << "Nhap hs luong : ";                         cin >> heSoLuong;
    cout << "Nhap hs ph cap: ";                         cin >> hsPhuCap;
    cout << "Nhap giam tru : ";                         cin >> giamTru;
}

void NhanVien::Xuat()
{
    NhanSu::Xuat();
    cout << setw(15) << left << phongBan;
    cout << setw(30) << left << diaChi;
    cout << setw(15) << left << heSoLuong;
    cout << setw(15) << left << hsPhuCap;
    cout << giamTru << ln;
}

void title()
{
    cout << setw(30) << left << "HO TEN";
    cout << setw(10) << left << "NGAY";
    cout << setw(10) << left << "THANG";
    cout << setw(10) << left << "NAM";
    cout << setw(15) << left << "GIOI TINH";
    cout << setw(15) << left << "PHONG BAN";
    cout << setw(30) << left << "DIA CHI";
    cout << setw(15) << left << "HS LUONG";
    cout << setw(15) << left << "HS PHU CAP";
    cout << "GIAM TRU" << ln;
}

double TongThuNhap(NhanVien *a, int n)
{
    int cnt = 0;
    double thuNhap = 0;
    for(int i=0; i<n; i++)
        if(strcmp(a[i].phongBan, "Hanh chinh") == 0 )
        {
            cnt ++;
            thuNhap += ((a[i].heSoLuong + a[i].hsPhuCap) * 830 - a[i].giamTru);
        }
    if(cnt == 0) cout << "\nKhong co phong ban Hanh chinh! \n";
    return thuNhap;
}

void SapXep(NhanVien *a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=i+i; j<n; j++)
            if(a[i].heSoLuong > a[j].heSoLuong)
                swap(a[i], a[j]);
}


void SuaPB(NhanVien *&a, int n)
{
    for(int i=0; i<n; i++)
        if(strcmp(a[i].hoTen, "NV01")==0)
            strcpy(a[i].phongBan, "Kinh doanh");
}

int main()
{
    NhanVien *a;
    int n;
    do{
        cout << "Nhap so luong nhan vien: ";        cin >> n;
        if(n>=100 || n<=0) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n>=100 || n<=0);
    a = new NhanVien[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin nhan vien thu " << i+1 <<": \n";
        a[i].Nhap();
    }

    cout << "\n\n--Tong thu nhap cua phong ban Hanh Chinh: " << TongThuNhap(a, n);


    cout << "\n\n--Sap xep nhan vien tang dan theo he so luong: \n";
    SapXep(a, n);
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();

    cout << "\n\n--Sua lai phong ban cua nhan vien NV01: \n";
    SuaPB(a, n);
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();
    cout << ln;
    return 0;
}

