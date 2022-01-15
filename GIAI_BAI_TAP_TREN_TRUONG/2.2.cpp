#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Number{
	int *a, n;
public:
	void Nhap();
	void SapXep();
	void Xuat();
};

void Number::Nhap(){
	a = new int[n];
	for(int i=0; i<n; i++){
		cout << "Nhap A["<<i<<"]= ";
		cin >> a[i];
	}
}

void Number::SapXep(){
	for(int i=0; i<n; i++)
	for(int j=i+1; j<n; j++)
	if(a[i]>a[j]) swap(a[i], a[j]);
}

void Number::Xuat(){
	for(int i=0; i<n; i++){
		cout << "A["<<i<<"]= " << a[i] << "\n";
	}
}

int main(){
	Number n;
	cout << "Nhap n: ";		cin >> n;
	n.Nhap();
	n.Xuat();
	n.SapXep();
	return 0;
}
