#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class LopHoc;

class Nguoi
{
protected:
    char hoTen[30], ngaySinh[15], queQuan[20];
public:
    void Nhap(), Xuat();
};

void Nguoi::Nhap()
{
    cout << "Nhap ho ten   : ";        fflush(stdin);      gets(hoTen);
    cout << "Nhap ngay sinh: ";        fflush(stdin);      gets(ngaySinh);
    cout << "Nhap quequan  : ";        fflush(stdin);      gets(queQuan);
}

void Nguoi::Xuat()
{
    cout << setw(30) << left << hoTen;
    cout << setw(15) << left << ngaySinh;
    cout << setw(20) << left << queQuan;
}

class SinhVien : public Nguoi
{
    char maSV[20], nganh[15];
    int khoaHoc;
public:
    void Nhap(), Xuat();
    friend class LopHoc;
    friend void KhoaMuoiMot(LopHoc k);
    friend void SapXep(LopHoc k);
};

void SinhVien::Nhap()
{
    Nguoi::Nhap();
    cout << "Nhap ma sinh vien: ";      fflush(stdin);      gets(maSV);
    cout << "Nhap nganh svien : ";      fflush(stdin);      gets(nganh);
    cout << "Nhap khoa hoc    : ";      cin >> khoaHoc;
    fflush(stdin);
}

void SinhVien::Xuat()
{
    Nguoi::Xuat();
    cout << setw(20) << left << maSV;
    cout << setw(15) << left << nganh;
    cout << khoaHoc << ln;
}

class LopHoc
{
    char maLH[20], tenLH[30], ngayMo[20], giaoVien[30];
    SinhVien *x;
    int n;
public:
    void Nhap(), Xuat();
    friend void KhoaMuoiMot(LopHoc k);
    friend void SapXep(LopHoc k);
};

void LopHoc::Nhap()
{

    cout << "Nhap ma lop hoc : ";       fflush(stdin);      gets(maLH);
    cout << "Nhap ten lop hoc: ";       fflush(stdin);      gets(tenLH);
    cout << "Nhap ngay mo lop: ";       fflush(stdin);      gets(ngayMo);
    cout << "Nhap ten gvien  : ";       fflush(stdin);      gets(giaoVien);
    cout << "Nhap so sinh vien: ";      cin >> n;
    x = new SinhVien[n];
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin sinh vien thu " << i+1 <<": \n";
        x[i].Nhap();
    }

}

void LopHoc::Xuat()
{
    cout << "\n==================================================LOP HOC================================================\n";
    cout << "Ma lop hoc: " << maLH << "\t\t\t\tTen lop hoc: " << tenLH << ln;
    cout << "\nNgay mo lop: " << ngayMo << "\t\t\t\tTen giao vien: " << giaoVien << ln;

    cout << setw(30) << left << "\nHO TEN";
    cout << setw(15) << left << "NGAY SINH";
    cout << setw(20) << left << "QUE QUAN";
    cout << setw(20) << left << "MA SINH VIEN";
    cout << setw(15) << left << "NGANH";
    cout << "KHOA HOC" << ln
    for(int i=0; i<n; i++)
        x[i].Xuat();
    cout << "\n========================================================================================================\n";
}

void KhoaMuoiMot(LopHoc k)
{
    int dem = 0;
    for(int i=0 ;i<k.n; i++)
        if(k.x[i].khoaHoc == 11) dem++;
    cout << "\nCo " << dem << " lop hoc khoa 11";
}

void SapXep(LopHoc k)
{
    for(int i=0; i<k.n; i++)
        for(int j=i+1; j<k.n; j++)
            if(k.x[i].khoaHoc > k.x[j].khoaHoc) swap(k.x[i], k.x[j]);
}

int main()
{
    LopHoc k;
    k.Nhap();
    k.Xuat();
    cout << "\n\n";
    KhoaMuoiMot(k);
    cout << "\nSAP XEP TANG DAN THEO KHOA HOC: \n";
    SapXep(k);
    k.Xuat();
    return 0;
}
