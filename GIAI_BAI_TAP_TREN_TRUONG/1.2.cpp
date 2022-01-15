#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Rectangular{
	double length, width;
public:
	void Input();
	void Output();
	float Area();
	float Draw();
};

void Rectangular::Input(){
	cout << "Enter length: ";		cin >> length;
	cout << "Enter width : ";		cin >> width;
	fflush(stdin);
}

void Rectangular::Draw(){
	for(int i=0; i<length; i++){
		for(int j=0; j<width; j++){
			cout << " * ";
			cout << ln;
		}
	}
}

float Rectangular::Peri(){
	return 2*(length+width);
}

float Rectangular::Area(){
	return length*width;
}

int main(){
	Rectangular r;
	cout << "Enter information rectangular: ";
	r.Input();
	cout << "\nDraw rectangular: \n\n";
	r.Draw();
	cout << "\n\nPerimeter rectanguler: " <<r.Peri();
	cout <<"\nArea rectangular: " <<r.Area();
	return 0;
}
