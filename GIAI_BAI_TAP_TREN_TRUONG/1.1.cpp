#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Student{
	char codeS[10], nameS[20];
	int age;
	double point;
public:
	void Input();
	void Output();
};

void Student::Input(){
	fflush(stdin);
	cout << "Enter code student: ";		gets(codeS);
	cout << "Enter name student: ";		gets(nameS);
	cout << "Enter age student : ";		cin >> age;
	cout << "Enter point student: ";	cin >> point; 
}

void Student::Output(){
	cout << "Code student: " << codeS << ln;
	cout << "Name student: " << nameS << ln;
	cout << "Age student: "  << age << ln;
	cout << "Point student: " << point << ln;
}

int main(){
	Student s;
	cout << "Enter information student: \n";
	s.Input();
	cout << "\n\nDisplay information student: \n";
	return 0;
}
