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
    int namVaoCQ;
    float hsLuong, phCap;
public:
    void Nhap(), Xuat();
    float ThuNhap();
    friend void ThuNhapMin(CongChuc *a, int n);
    friend void SapXep(CongChuc *a, int n);
};

void CongChuc::Nhap()
{
    cout << "Nhap ho ten    : ";        fflush(stdin);      gets(hoTen);
    cout << "Nhap gioi tinh : ";        fflush(stdin);      gets(gioiTinh);
    cout << "Nhap ngay sinh : ";        cin >> ngay;
    cout << "Nhap thang sinh: ";        cin >> thang;
    cout << "Nhap nam sinh  : ";        cin >> nam;
    cout << "Nhap dia chi   : ";        fflush(stdin);      gets(diaChi);
    cout << "Nhap nganh nghe: ";        fflush(stdin);      gets(nganhNghe);
    cout << "Nhap nam vao CQ: ";        cin >> namVaoCQ;
    cout << "Nhap trinh do  : ";        fflush(stdin);      gets(trinhDo);
    cout << "Nhap hso luong : ";        cin >> hsLuong;
    cout << "Nhap phu cap   : ";        cin >> phCap;
}

void CongChuc::Xuat()
{
    cout << setw(25) << left << hoTen;
    cout << setw(10) << left << gioiTinh;
    cout << setw(5)  << left << ngay;
    cout << setw(5)  << left << thang;
    cout << setw(5)  << left << nam;
    cout << setw(25) << left << diaChi;
    cout << setw(25) << left << nganhNghe;
    cout << setw(15) << left << namVaoCQ;
    cout << setw(25) << left << trinhDo;
    cout << setw(15) << left << hsLuong;
    cout << setw(15) << left << phCap << ln;
}

float CongChuc::ThuNhap()
{
	return hsLuong * 830 + phCap;
}

void title()
{
    cout << setw(25) << left << "HO TEN";
    cout << setw(10) << left << "GIOI TINH";
    cout << setw(5)  << left << "NGAY";
    cout << setw(5)  << left << "THANG";
    cout << setw(5)  << left << "NAM";
    cout << setw(25) << left << "DIA CHI";
    cout << setw(25) << left << "NGANH NGHE";
    cout << setw(15) << left << "NAM VAO CQ";
    cout << setw(25) << left << "TRINH DO";
    cout << setw(15) << left << "HE SO LUONG";
    cout << setw(15) << left << "PHU CAP" << ln;
}

void ThuNhapMin(CongChuc *a, int n)
{
    
    for(int i=0; i<n; i++)
   {
   		float min = a[0].ThuNhap();
        if(a[i].ThuNhap() < min) 
			min = a[i].ThuNhap();
   }
			
    for(int i=0; i<n; i++)
        if(a[i].ThuNhap() == min) 
			a[i].Xuat();
}

void SapXep(CongChuc *a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(strcmp(a[i].hoTen, a[j].hoTen) > 0) swap(a[i], a[j]);
    for(int i=0; i<n; i++)
        a[i].Xuat();
}

int main()
{
    CongChuc *a;
    int n;
    do {
        cout << "Nhap so luong cong chuc: ";        cin >> n;
        if(n<=0 && n>=50) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n<=0 && n>=50);
    a = new CongChuc[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin cong chuc thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    cout << "\n\nDANH SACH SAU KHI NHAP: \n";
    title();
    for(int i=0; i<n; i++)
        a[i].Xuat();

    cout << "\n\nDANH SACH SAU KHI SAP XEP: \n";
    title();
    SapXep(a, n);

    cout << "\n\nCONG CHUC CO THU NHAP THAP NHAT: \n";
    title();
    ThuNhapMin(a, n);
    return 0;
}

