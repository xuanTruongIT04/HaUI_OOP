#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define ln "\n";

class Hang
{
    char maH[15], tenH[30];
    double DG;
    int SL, nam;
public:
    Hang();
    Hang(char* x, char* y, double z, int t, int r);
    friend istream& operator >> (istream &x, Hang &y);
    friend ostream& operator << (ostream&x, Hang y);
    friend void Bonus_1(Hang *k, int n);
    friend void Bonus_2(Hang *k, int n);
    friend void Bonus_3(Hang *&k, int &n);
    friend void Bonus_4(Hang *&k, int &n);
};

Hang::Hang()
{
    strcpy(maH, "");
    strcpy(tenH, "");
    DG = SL = nam = 0;
}

Hang::Hang(char* x, char* y, double z, int t, int r)
{
    strcpy(maH, x);
    strcpy(tenH, y);
    DG = z;
    SL = t;
    nam = r;
}

istream& operator >> (istream &x, Hang &y)
{
    cout << "Nhap ma hang: ";       fflush(stdin);        gets(y.maH);
    cout << "Nhap ten hang: ";      fflush(stdin);        gets(y.tenH);
    cout << "Nhap don gia : ";      x >> y.DG;
    cout << "Nhap so luong: ";      x >> y.SL;
    cout << "Nhap so nam  : ";      x >> y.nam;
    return x;
}

ostream& operator << (ostream&x, Hang y)
{
    x << setw(15) << left << y.maH;
    x << setw(25) << left << y.tenH;
    x << setw(15) << left << y.DG;
    x << setw(15) << left << y.SL;
    x << setw(15) << left << y.nam << ln;
    return x;
}

void Bonus_1(Hang* k, int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(strcmp(k[i].tenH, "IPHONE 12")==0)
            cnt ++;
    if(cnt != 0) cout << "\nCo mat hang IPHONE 12\n";
    else cout << "\nKhong co mat hang IPHONE 12 \n";
}

void Bonus_2(Hang* k, int n)
{
    for(int i=0 ;i<n; i++)
        for(int j=i+1; j<n; j++)
            if(k[i].DG * k[i].SL > k[j].DG * k[j].SL)
                swap (k[i], k[j]);
}

void Bonus_3(Hang *&k, int &n)
{
    for(int i=0; i<n; i++){
        if(strcmp(k[i].maH, "H005")==0) {
            for(int j=i; j<n-1; j++)
                k[j] = k[j+1];
            n--;
        }
    }
    k = (Hang*) realloc(k, n*sizeof(Hang));
}

void Bonus_4(Hang *&k, int &n)
{
     for(int i=0; i<n; i++){
        while(k[i].SL < 20 && i<n) {
            for(int j=i; j<n-1; j++)
                k[j] = k[j+1];
            n--;
        }
    }
    k = (Hang*) realloc(k, n*sizeof(Hang));
}


int main()
{
   Hang *k;
   int n;
   cout << "Nhap so luong mat hang: ";      cin >> n;
   k = new Hang[n];
   for(int i=0; i<n; i++){
    cout << "\nNhap thong tin hang thu " << i+1 << ": ";
    cin >> k[i];
   }

    cout << setw(15) << left << "MA HANG";
    cout << setw(25) << left << "TEN HANG";
    cout << setw(15) << left << "DON GIA";
    cout << setw(15) << left << "SO LUONG";
    cout << setw(15) << left << "NAM" << ln;
   for(int i=0; i<n; i++){
    cout << k[i];
   }

    Bonus_1(k, n);
    cout << "\nXuat danh sach tep";
    file f("D:\\HANGNHAP.DAT");
    for(int i=0 ; i<n; i++){
        f >> k[i];
    }
    fclose();

    Bonus_2(k, n);
    cout << "\nXuat danh sach tep";
    file f("D:\\HANGSORT.TXT");
    for(int i=0 ; i<n; i++){
        f >> k[i];
    }
    fclose();

    Bonus_3(k, n);
    cout << "\nXuat danh sach tep";
    file f("D:\\HANGREMOVE.TXT");
    for(int i=0 ; i<n; i++){
        f >> k[i];
    }
    fclose();

    Bonus_4(k, n);
    cout << "\nXuat danh sach tep";
    file f("D:\\HANGREMOVE.TXT");
    for(int i=0 ; i<n; i++){
        f >> k[i];
    }
    fclose();
    return 0;
}
