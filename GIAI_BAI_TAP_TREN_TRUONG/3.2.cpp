#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class NSX {
	char maNSX[15], tenNSX[25], dcNSX[20];
public:
	void Nhap();
	void Xuat();
};

void NSX::Nhap(){
	fflush(stdin);
	cout << "Nhap ma nha san xuat: ";			gets(maNSX);
	cout << "Nhap ten nha san xuat: ";		gets(tenNSX);
	cout << "Nhap dia chi nha san xuat: ";	gets(dcNSX);
}

void NSX::Xuat(){
	cout << "Ma nha san xuat: " << maNSX << ln;
	cout << "Ten nha san xuat: " << tenNSX << ln;
	cout << "Dia chi nha san xuat: " << dcNSX << ln;
}

class Hang{
	char maHang[15], tenHang[25];
	NSX x;
public:
	void Nhap();
	void Xuat();
};

void Hang::Nhap(){
	fflush(stdin);
	cout << "Nhap thong tin hang hoa: \n\n";
	cout << "Nhap ma hang: ";		gets(maHang);
	cout << "Nhap ten hang: ";		gets(tenHang);
	x.Nhap();
}

void Hang::Xuat(){
	cout << "\n\nXuat thong tin hang hoa\n";
	cout << "Ma hang: " << maHang << ln;
	cout << "Ten hang: "<< tenHang << ln;
	x.Xuat();
}

int main(){
	Hang h;
	h.Nhap();
	h.Xuat();
	return 0;
}
