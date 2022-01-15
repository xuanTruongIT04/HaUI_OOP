#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Nha
{
protected:
    double dienTich, kinhPhiXD;
    int namXD;
};

class NhaCaoTang : public Nha
{
    int soTang, soPhong;
public:
    void Nhap(), Xuat();
    friend void SapXepDT(NhaCaoTang *a, int n);
    friend void SoTangYC(NhaCaoTang *a, int n);
};

void NhaCaoTang::Nhap()
{
    cout << "Nhap dien tich   : ";     cin >> dienTich;
    cout << "Nhap nam xay dung: ";     cin >> namXD;
    cout << "Nhap kinh phi xd : ";     cin >> kinhPhiXD;
    cout << "Nhap so tang nha : ";     cin >> soTang;
    cout << "Nhap so phong nha: ";     cin >> soPhong;
}

void NhaCaoTang::Xuat()
{
    cout << setw(15) << left << dienTich;
    cout << setw(15) << left << namXD;
    cout << setw(15) << left << kinhPhiXD;
    cout << setw(15) << left << soTang;
    cout << soPhong << ln;
}

void title()
{
    cout << setw(15) << left << "DIEN TICH";
    cout << setw(15) << left << "NAM XAY DUNG";
    cout << setw(15) << left << "KINH PHI";
    cout << setw(15) << left << "SO TANG";
    cout << "SO PHONG" << ln;
}

void SapXepDT(NhaCaoTang *a, int n)
{
// SAP XEP GIAM DAN THEO DIEN TICH
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i].dienTich > a[j].dienTich)
                swap(a[i], a[j]);
    for(int k=0; k<n; k++)
        a[k].Xuat();
}

void SoTangYC(NhaCaoTang *a, int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)

        if(a[i].soTang > 5)
        {
            a[i].Xuat();
            cnt ++;
        }
    if(cnt == 0) cout << "\nKhong co nha cao tang nao co so tang >5!\n";
}

int main()
{
    NhaCaoTang *a;
    int n;
    do {
        cout << "Nhap so luong nha cao tang: ";     cin >> n;
        if(n<=0 || n>=20) cout << "\nMOI BAN NHAP LAI!\n";
    }while(n<=0 || n>=20);
    a = new NhaCaoTang[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin nha cao tang thu " << i+1 << ": \n";
        a[i].Nhap();
    }

    cout << "\n\nSap Xep Giam Dan Theo Dien Tich: \n";
    title();
    SapXepDT(a, n);

    cout << "\n\nThong Tin Danh Sach Cac Nha Co So Tang >5: \n";
    title();
    SoTangYC(a, n);
    return 0;
}

