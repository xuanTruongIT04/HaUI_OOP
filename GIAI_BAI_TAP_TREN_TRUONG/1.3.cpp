#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Goods{
	char codeG[10], nameG[20];
	double unitPrice;
	int quantity;
public:
	void Input();
	void Output();
};

void Goods::Input(){
	fflush(stdin);
	cout << "Enter code goods: ";		gets(codeG);
	cout << "Enter name goods: ";		gets(nameG);
	cout << "Enter unit price goods: ";	cin >> unitPrice;
	cout << "Enter quantity goods  : ";	cin >> quantity;
	fflush(stdin);
}

void Goods::Output(){
	cout << setw(10) << left << codeG;
	cout << setw(20) << left << nameG;
	cout << setw(15) << left << unitPrice;
	cout << quantity << ln;
}

void title(){
	cout << setw(10) << left << "CODEG";
	cout << setw(20) << left << "NAMEG";
	cout << setw(15) << left << "UNITPRICE";
	cout << "QUANTITY" << ln;
}

int main(){
	Goods *g;
	int n;
	cout << "Enter quantity goods: ";		cin >> n;
	g = new Goods[n];
	for(int i=0; i<n; i++){
		cout << "Enter information goods number " << i+1 << ": \n";
		g[i].Input();
		cout << ln;
	}
	title();
	for(int i=0; i<n; i++){
		g[i].Output();
	}
	return 0;
}
