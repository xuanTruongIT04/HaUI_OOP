#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define ln "\n";

class BenhNhan;

class Nguoi
{
protected:
    char hoTen[25];
    int tuoi;
public:
    void Nhap(), Xuat();
    friend int Dem(BenhNhan *k, int n);
    friend void Sua(BenhNhan *k, int n);
};

void Nguoi::Nhap()
{
    cout << "Nhap ho ten: ";        fflush(stdin);      gets(hoTen);
    cout << "Nhap tuoi  : ";        cin >> tuoi;
}

void Nguoi::Xuat()
{
    cout << setw(25) << left << hoTen;
    cout << setw(15) << left << tuoi;
}

class BenhVien
{
    char tenBV[25], diaChi[25], giamDoc[25];
public:
    friend class BenhNhan;
};

class BenhNhan : public Nguoi
{
    char maBN[15], tienSu[25], chuanDoan[25];
    BenhVien x;
public:
    void Nhap(), Xuat();
    friend void Sua(BenhNhan *k, int n);
};

void BenhNhan::Nhap()
{
    Nguoi::Nhap();
    cout << "Nhap ma benh nhan : ";      fflush(stdin);      gets(maBN);
    cout << "Nhap tien su      : ";      fflush(stdin);      gets(tienSu);
    cout << "Nhap ma chuan doan: ";      fflush(stdin);      gets(chuanDoan);
    cout << "Nhap ten benh vien: ";      fflush(stdin);      gets(x.tenBV);
    cout << "Nhap dia chi bvien: ";      fflush(stdin);      gets(x.diaChi);
    cout << "Nhap ten giam doc : ";      fflush(stdin);      gets(x.giamDoc);
}

void BenhNhan::Xuat()
{
    Nguoi::Xuat();
    cout << setw(15) << left << maBN;
    cout << setw(25) << left << tienSu;
    cout << setw(25) << left << chuanDoan;
    cout << setw(25) << left << x.tenBV;
    cout << setw(25) << left << x.diaChi;
    cout << x.giamDoc << ln;
}

void Title()
{
    cout << setw(25) << left << "HO TEN";
    cout << setw(15) << left << "TUOI";
    cout << setw(15) << left << "MA BENH NHAN";
    cout << setw(25) << left << "TIEU SU";
    cout << setw(25) << left << "CHUAN DOAN";
    cout << setw(25) << left << "TEN BENH VIEN";
    cout << setw(25) << left << "DIA CHI";
    cout << "TEN GIAM DOC" << ln;
}

int Dem(BenhNhan *k, int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(k[i].tuoi > 30) cnt ++;
    return cnt;
}

void Sua(BenhNhan *k, int n)
{
    int cnt;
    for(int i=0; i<n; i++)
    {
        if(strcmp(k[i].maBN, "BN01")==0) k[i].tuoi = 20;
        cnt ++;
    }
    if(cnt>0) cout << "\nDa sua tuoi cua benh nhan co ma BN01 thanh 20 tuoi! ";
    else cout << "\nKhong co benh nhan nao co ma BN01 ca! ";
}

int main()
{
    BenhNhan *k;
    int n;
    cout << "Nhap so luong benh nhan: ";        cin >> n;
    k = new BenhNhan[n];
    cout << "\nNHAP THONG TIN CAC BENH NHAN: \n";
    for(int i=0; i<n; i++)
    {
        cout << "Nhap thong tin benh nhan thu " << i+1 <<": \n";
        k[i].Nhap();
        cout << ln;
    }

    cout << "\n\nHIEN THI THONG TIN CAC BENH NHAN: \n";
    Title();
    for(int i=0; i<n; i++)
        k[i].Xuat();

    cout << "\nCo " << Dem(k,n) << " benh nhan lon hon 30 tuoi \n\n";

    Sua(k, n);
    cout << "\n\nHIEN THI LAI THONG TIN CAC BENH NHAN: \n";
    Title();
    for(int i=0; i<n; i++)
        k[i].Xuat();
    return 0;
}
