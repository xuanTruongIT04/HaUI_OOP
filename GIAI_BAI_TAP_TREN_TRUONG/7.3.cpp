#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Truong;
class TruongDH;

class Khoa{
private:
	string maKhoa, tenKhoa, truongKhoa;
	friend class TruongDH;
};

class Ban{
private:
	string maBan, tenBan, ngayThanhLap;
	friend class TruongDH;
};

class TruongDH{
	Khoa *x;
	int n;
	Ban *y;
	int m;
	friend class Truong;
public:
	void Nhap();
	void Xuat();
};

void TruongDH::Nhap(){
	x = new Khoa[n];
	y = new Ban[m];
	fflush(stdin);
	cout << "Nhap thong tin n khoa: \n";
	for(int i=0; i<n; i++){
		cout << "\nNhap ma khoa: ";		cin >> this->x[i].maKhoa;
		cout << "\nNhap ten khoa: ";	cin >> this->x[i].tenKhoa;
		cout << "\nNhap truong khoa: ";	cin >> this->x[i].truongKhoa;
		cout << ln;
	}
	
	cout << "\nNhap thong tin m ban: \n";
	for(int i=0; i<m; i++){
		cout << "\nNhap ma ban: ";		cin >> this->y[i].maBan;
		cout << "\nNhap ten ban: ";		cin >> this->y[i].tenBan;
		cout << "\nNgay thanh lap: ";	cin >> this->y[i].ngayThanhLap;
		cout << ln;
	}
}

void TruongDH::Xuat(){
	cout << "\nXuat thong tin n khoa: ";
	for(int i=0; i<n; i++){
		cout << "Ma khoa: "<< this->x[i].maKhoa << ln;
		cout << "Ten khoa: " << this->x[i].tenKhoa << ln;
		cout << "Truong khoa: " << this->x[i].truongKhoa << ln;
	}
	
	cout << "\nXuat thong tin n khoa: ";
	for(int i=0; i<n; i++){
		cout << "Ma ban: "<< this->y[i].maBan << ln;
		cout << "Ten ban: " << this->y[i].tenBan << ln;
		cout << "Ngay thanh lap: " << this->y[i].ngayThanhLap << ln;
	}
}

class Truong{
	string maTruong, tenTruong, diaChi;
public:
	void Nhap();
	void Xuat();
};

void Truong::Nhap(){
	fflush(stdin);
	cout << "\nNhap ma truong: ";		cin >> maTruong;
	cout << "\nNhap ten truog: ";		cin >> tenTruong;
	cout << "\nNhap dia chi  : ";		cin >> diaChi;
}

void Truong::Xuat(){
	cout << "Ma truong: " << maTruong << ln;
	cout << "Ten truong: " << tenTruong << ln;
	cout << "Dia chi: " << diaChi << ln;
}

int main(){
	Truong lp;
	cout << "Nhap thong tin truong: ";
	lp.Nhap();
	cout << "\nHien thi thong tin truong: ";
	lp.Xuat();
	return 0;
}
