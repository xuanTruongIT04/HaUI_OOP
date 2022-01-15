#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class PTBH{
	double a, b, c;
public:
	void Nhap(), Giai(), Xuat();
};

void PTBH::Nhap(){
	fflush(stdin);
	cout << "Nhap a: ";		cin >> a;
	cout << "Nhap b: ";		cin >> b;
	cout << "Nhap c: ";		cin >> c;
	fflush(stdin);
}

void PTBH::Xuat(){
	cout << "PTBH co dang: " << a << "x^2" << (b>0 ? " + ": " - ") << abs(b) << "x " << (c>0 ? " + " : " - ") << abs(c) << "= 0";
}

void PTBH::Giai(){
	if(a==0) {
		if(b==0){
			if(c==0) cout << "\nPTBH co vo so nghiem!";
			else cout << "\nPTBH vo nghiem!";
		}
		else cout << "\nPTBH co 1 nghiem duy nhat: " << -c/b;
	}
	else{
		double x1, x2, delta;
		delta = b*b - 4*a*c;
		x1 = (-b -delta)/(double)(2*a);
		x1 = (-b +delta)/(double)(2*a);
		if(delta > 0) {
			cout << "\nPTBH co 2 nghiem: ";
			cout << "\nNghiem thu nhat: " << x1;
			cout << "\nNghiem thu hai : " << x2;
		}
		else if(delta = 0) cout << "\nPTBH co 1 nghiem duy nhat: " << (-b)/(2*a);
		else cout << "\nPTBH vo nghiem!";
	}
}

int main(){
	PTBH p;
	p.Nhap();
	p.Xuat();
	p.Giai();
	return 0;
}
