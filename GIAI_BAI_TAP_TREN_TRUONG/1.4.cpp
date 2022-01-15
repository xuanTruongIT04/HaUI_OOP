#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Sach {
	char maSach[15], tenSach[20], NXB[20];
	int soTrang;
	double giaTien;
public:
	void Nhap();
	void Xuat();
};

void Sach::Nhap(){
	fflush(stdin);
	cout << "Nhap ma sach: ";		gets(maSach);
	cout << "Nhap ten sach: ";		gets(tenSach);
	cout << "Nhap nha xuat ban: ";	gets(NXB);
	cout << "Nhap so trang: ";		cin >> soTrang;
	cout << "Nhap gia tien: ";		cin >> giaTien;
	fflush(stdin);
}

void Sach::Xuat(){
	cout << setw(15) << left << maSach;
	cout << setw(20) << left << tenSach;
	cout << setw(20) << left << NXB;
	cout << setw(10) << left << soTrang;
	cout << setw(10) << left << giaTien << ln;
}

void title(){
	cout << setw(15) << left << "MA SACH";
	cout << setw(20) << left << "TEN SACH";
	cout << setw(20) << left << "NHA XUAT BAN";
	cout << setw(10) << left << "SO TRANG";
	cout << setw(10) << left << "GIA TIEN" << ln;
}

int main(){
	Sach *s;
	int n;
	cout << "Nhap so cuon sach: ";		cin >> n;
	s = new Sach[n];
	for(int i=0; i<n; i++){
		cout << "Nhap thong tin cuon sach thu " << i+1 << ": \n";
		s[i].Nhap();
		cout << ln;
	}
	title();
	for(int i=0; i<n; i++){
		s[i].Xuat();
	}
	return 0;
}
