#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Date{
	int D, M, Y;
public:
	void Nhap();
	void Xuat();
};

void Date::Nhap(){
	cout << "Nhap ngay : ";		cin >> D;
	cout << "Nhap thang: ";		cin >> M;
	cout << "Nhap nam  :" ;		cin >> Y;
	fflush(stdin);
}

void Date::Xuat(){
	cout << "Date: " << D << " / " << M <<" / " << Y << ln;
}

class NhanSu{
	char maNS[15], hoTen[25];
	Date NS;
public:
	void Nhap();
	void Xuat();
};

void NhanSu::Nhap(){
	fflush(stdin);
	cout << "Nhap ma nhan su: ";		gets(maNS);
	cout << "Nhap ho ten : ";			gets(hoTen);
	NS.Nhap();
}

void NhanSu::Xuat(){
	cout <<"\n\nMa nhan su: " << maNS << ln;
	cout << "Ho ten: " << hoTen << ln;
	NS.Xuat();
}

int main(){
	NhanSu ns;
	ns.Nhap();
	ns.Xuat();
	return 0;
}
