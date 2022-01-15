#include <iostream>
#include <iomanip>
#define ln "\n";

using namespace std;

class Phieu;

class NhaCungCap
{
    char maNCC[15], tenNCC[30];
public:
    void Nhap(), Xuat();
};

void NhaCungCap::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma nha cung cap : ";       gets(maNCC);
    cout << "Nhap ten nha cung cap: ";       gets(tenNCC);
}

void NhaCungCap::Xuat()
{
    cout << setw(20) << left << "Ma nha cung cap: " << maNCC;
    cout << "\t\tTen nha cung cap: " << tenNCC << ln;
}

class LienHe
{
    char diaChi[30], SDT[15];
public:
    void Nhap(), Xuat();
};

void LienHe::Nhap()
{
    fflush(stdin);
    cout << "Nhap dia chi: ";       gets(diaChi);
    cout << "Nhap so dien thoai: "; gets(SDT);
}

void LienHe::Xuat()
{
    cout << "Dia chi: " << diaChi;
    cout << "\t\t\tSDT: " << SDT << ln;
}

class SanPham
{
    char maSP[15], tenSP[20];
    int soLuong;
    double donGia;
public:
    void Nhap(), Xuat();
    friend class Phieu;
    friend void TimKiem(Phieu a);
    friend void SapXep(Phieu a);
};

void SanPham::Nhap()
{
    fflush(stdin);
    cout << "Nhap ma san pham : ";      gets(maSP);
    cout << "Nhap ten san pham: ";      gets(tenSP);
    cout << "Nhap so luong    : ";      cin >> soLuong;
    cout << "Nhap don gia     : ";      cin >> donGia;
    fflush(stdin);
}

void SanPham::Xuat()
{
    cout << setw(15) << left << maSP;
    cout << setw(20) << left << tenSP;
    cout << setw(15) << left << soLuong;
    cout << setw(15) << left << donGia;
    cout << soLuong * donGia << ln;
}


class Phieu
{
    char maPhieu[15], ngayLap[15];
    NhaCungCap x;
    LienHe y;
    SanPham  *z;
    int n;
public:
    void Nhap(), Xuat();
    friend void TimKiem(Phieu a);
    friend void SapXep(Phieu a);
};

void Phieu::Nhap()
{
    cout << "Nhap ma phieu: ";      gets(maPhieu);
    cout << "Nhap ngay lap: ";      gets(ngayLap);
    x.Nhap();
    y.Nhap();
    cout << "Nhap so luong san pham: ";     cin >> n;   fflush(stdin);
    z = new SanPham[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap san pham thu " << i+1 << ": \n";
        z[i].Nhap();
        cout << ln;
    }
}

void Phieu::Xuat()
{
    cout << "\n==============================================================================\n\n";
    cout << setw(20) << left << "Ma phieu: " << maPhieu;
    cout << "\t\tNgay lap: " << ngayLap << ln;
    x.Xuat();
    y.Xuat();
    cout << setw(15) << left << "MA SP";
    cout << setw(20) << left << "TEN SAN PHAM";
    cout << setw(15) << left << "SO LUONG";
    cout << setw(15) << left << "DON GIA";
    cout << "THANH TIEN" << ln;
    for(int i=0; i<n; i++)
        z[i].Xuat();
    double T=0;
    for(int i=0; i<n; i++)
    {
        T += z[i].soLuong * z[i].donGia;
    }
    cout << "\t\t\t\t===TONG===   \t\t\t " << T << ln;
    cout << "\tHieu truong" << "\t\tPhong tai chinh" << "\t\t\tNguoi lap";
    cout << "\n\n==============================================================================\n";
}
void TimKiem(Phieu a)
{
    int dem=0;
    for(int i=0; i<a.n; i++)
    {
        if(a.z[i].soLuong < 80) dem++;
    }
    cout << "\nCo " << dem << " san pham co so luong nhap nho hon 80!\n";
}


void SapXep(Phieu a)
{
    for(int i=0; i<a.n; i++)
        for(int j=i+1; j<a.n; j++)
            if(a.z[i].donGia > a.z[j].donGia) swap(a.z[i], a.z[j]);
}


int main()
{
    Phieu a;
    a.Nhap();
    a.Xuat();
    cout << "\n\n\n\n";
    TimKiem(a);
    cout << "SAU KHI SAP XEP:\n";
    SapXep(a);
    a.Xuat();
    return 0;
}
