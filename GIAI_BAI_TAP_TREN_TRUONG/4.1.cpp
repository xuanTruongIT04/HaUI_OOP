#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class SinhVien{
	char maSV[15], hoTen[25];
	double diemToan, diemLy, diemHoa;
public:
	void Nhap();
	void Xuat();
	friend float TongDiem();
};

void SinhVien::Nhap(){
	fflush(stdin);
	cout << "Nhap ma sinh vien: ";		gets(maSV);
	cout << "Nhap ho ten svien: ";		gets(hoTen);
	cout << "Nhap diem toan: ";			cin >> diemToan;
	cout << "Nhap diem ly  : ";			cin >> diemLy;
	cout << "Nhap diem hoa : ";			cin >> diemHoa;
	fflush(stdin);
}

void SinhVien::Xuat(){
	cout << setw(15) << left << maSV;
	cout << setw(25) << left << hoTen;
	cout << setw(10) << left << diemToan;
	cout << setw(10) << left << diemLy;
	cout << setw(10) << left << diemHoa << ln;
	
}

void title(){
	cout << setw(15) << left << "MA SV";
	cout << setw(25) << left << "HO TEN";
	cout << setw(10) << left << "DIEM TOAN";
	cout << setw(10) << left << "DIEM LY";
	cout << setw(10) << left << "DIEM HOA" << ln;
}

float TongDiem(){
	return diemToan + diemLy + diemHoa;
}

int main(){
	SinhVien *s;
	int n;
	cout << "Nhap so sinh vien: ";		cin >> n;
	s = new SinhVien[n];
	for(int i=0; i<n; i++){
		cout << "Nhap thong tin sinh vien thu " << i+1 <<": \n";
		s[i].Nhap();
		cout << ln;	
	}
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(s[i].TongDiem() > s[j].TongDiem()) swap(s[i], s[j]);
		}
	}
	cout << "\n\nXuat thong tin sinh vien: \n\n";
	title();
	for(int i=0; i<n; i++){
		s[i].Xuat();
	}
	return 0;
}
