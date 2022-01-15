#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class May{
	char maMay[15], kieuMay[15], tinhTrang[10];
public:
	void Nhap();
	void Xuat();
};

void May::Nhap(){
	fflush(stdin);
	cout << "Nhap ma may: ";		gets(maMay);
	cout << "Nhap kieu may: ";		gets(kieuMay);
	cout << "Nhap tinh trang: ";	gets(tinhTrang);
}

void May::Xuat(){
	cout << setw(15) << left << maMay;
	cout << setw(15) << left << kieuMay;
	cout << setw(10) << left << tinhTrang << ln;
}

class QuanLy{
	char maQL[15], hoTen[25];
public:
	void Nhap();
	void Xuat();
};

void QuanLy::Nhap(){
	fflush(stdin);
	cout << "Nhap ma quan ly: ";		gets(maQL);
	cout << "Nhap ho ten qly: ";		gets(hoTen);
}

void QuanLy::Xuat(){
	cout << "Ma quan ly: " << maQL << ln;
	cout << "Ho ten qly: " << hoTen << ln;
}

class PhongMay{
	char maPhong[15], tenPhong[25];
	double dienTich;
	QuanLy x;
	May *y;
	int n;
public:
	void Nhap();
	void Xuat();
};

void PhongMay::Nhap(){
	fflush(stdin);
	cout << "Nhap ma phong : ";		gets(maPhong);
	cout << "Nhap ten phong: ";		gets(tenPhong);
	cout << "Nhap dien tich: ";		cin >> dienTich;
	fflush(stdin);
	x.Nhap();
	cout << "Nhap so luong may tinh: ";		cin >> n;
	y = new May[n];
	for(int i=0; i<n; i++){
		cout << "\nNhap thong tin may thu " << i+1 <<": \n";
		y[i].Nhap();
		cout << ln;
	} 
}

void PhongMay::Xuat(){
	cout << "Ma phong : " << maPhong << ln;
	cout << "Ten phong: " << tenPhong << ln;
	cout << "Dien tich: " << dienTich << ln;
	x.Xuat();
	cout << setw(15) << left << "MA MAY";
	cout << setw(15) << left << "KIEU MAY";
	cout << setw(10) << left << "TINH TRANG" << ln;
	for(int i=0; i<n; i++){
		y[i].Xuat();
	}
}

int main(){
	PhongMay pm;
	pm.Nhap();
	pm.Xuat();
	return 0;
}
