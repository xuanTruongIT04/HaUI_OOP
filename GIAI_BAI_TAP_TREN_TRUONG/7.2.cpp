#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class Person;
class Faculty;
class Student;

class School{
	string nameS, dateS;
public:
	friend class Faculty;
};

class Faculty{
	string nameF, dateF;
	School x;
public:
	void Input();
	void Output();
	friend class Student;
};

void Faculty::Input(){
	fflush(stdin);
	cout << "Enter name faculty: ";		getline(cin, nameF);
	cout << "Enter date faculty: ";		getline(cin, dateF);
	cout << "Enter name school : ";		getline(cin, x.nameS);
	cout << "Enter date school : ";		getline(cin, x.dateS);
}

void Faculty::Output(){
	cout << "Name faculty: " << nameF << ln;
	cout << "Date faculty: " << dateF << ln;
	cout << "Name school: " << x.nameS << ln;
	cout << "Date school: " << x.dateS << ln;
}

class Student{
	Faculty y;
	string classSt;
	double scoreSt;
public:
	void Input();
	void Output();
	friend class Person;
};

void Student::Input(){
	fflush(stdin);
	cout << "Enter class student: ";		getline(cin, classSt);
	cout << "Enter score student: ";		cin >> scoreSt;
	y.Input();
	fflush(stdin);	
}

void Student::Output(){
	cout << "Class student: " << classSt << ln;
	cout << "Score student: " << scoreSt << ln;
}

class Person{
	string nameP, birthP, adressP;
	Student s;
public:
	void Input();
	void Output();
};

void Person::Input(){
	fflush(stdin);
	cout << "Enter name person: ";		getline(cin, nameP);
	cout << "Enter birth person: ";		getline(cin, birthP);
	cout << "Enter adress person: ";	getline(cin, adressP);
	s.Input();
}

void Person::Output(){
	cout << "Name person : " << nameP << ln;
	cout << "Birth person: " << birthP << ln;
	cout << "Adress person: " << adressP << ln;
	s.Output();
}

int main(){
	Person P;
	cout << "Enter information person: \n";
	P.Input();
	cout << "\n\nDisplay information person: \n";
	P.Output();
	return 0;
}
