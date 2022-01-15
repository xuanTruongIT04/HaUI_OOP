#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Person
{
protected:
    char hoTen[25], ngaySinh[15], queQuan[30];
};

class KySu : public Person
{
    char nganh[25];
    int namTN;
public:
    void Nhap(), Xuat();
    friend void kySuTNM(KySu *k, int n);
};

void KySu::Nhap()
{
    cout << "Nhap ho ten: ";            fflush(stdin);        gets(Person::hoTen);
    cout << "Nhap ngay sinh: ";         fflush(stdin);        gets(Person::ngaySinh);
    cout << "Nhap que quan : ";         fflush(stdin);        gets(Person::queQuan);
    cout << "Nhap nganh hoc: ";         fflush(stdin);        gets(nganh);
    cout << "Nhap nam tot nghiep: ";    cin >> namTN;
    fflush(stdin);
}

void KySu::Xuat()
{
    cout << setw(25) << left << Person::hoTen;
    cout << setw(15) << left << Person::ngaySinh;
    cout << setw(30) << left << Person::queQuan;
    cout << setw(25) << left << nganh;
    cout << namTN << ln;
}

void kySuTNM(KySu *k, int n){
    int namTNmax = k[0].namTN;
    for(int i=0; i<n; i++)
            if(namTNmax < k[i].namTN) namTNmax = k[i].namTN;
    for(int i=0; i<n; i++)
        if (k[i].namTN == namTNmax) k[i].Xuat();
};

int main()
{
    KySu *k;
    int n;
    cout << "Nhap so luong ky su: ";            cin >> n;
    k = new KySu[n];

    for(int i=0; i<n; i++)
    {
        cout << "\nNhap thong tin ky su thu " << i + 1 << ": \n";
        k[i].Nhap();
    }

    cout << setw(25) << left << "HO TEN";
    cout << setw(15) << left << "NGAY SINH";
    cout << setw(30) << left << "QUE QUAN";
    cout << setw(25) << left << "NGANH";
    cout << "NAM TOT NGHIEP" << ln;

    for(int i=0; i<n; i++)
        k[i].Xuat();

    cout << "\nThong tin ky su tot nghiep nam gan nhat: \n";
    kySuTNM(k, n);
    return 0;
}
