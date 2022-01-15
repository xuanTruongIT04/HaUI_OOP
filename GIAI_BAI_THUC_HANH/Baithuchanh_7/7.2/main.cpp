#include <iostream>
#include <string.h>
using namespace std;
#define ln "\n";

class School
{
    char nameS[25], dateS[15];
    friend class Faculty;
    friend class Student;
};

class Faculty
{
    char nameF[25], dateF[15];
    School x;
public:
    void Input(), Output();
    friend class Student;
};

void Faculty::Input()
{
    cout << "Enter name faculty: ";     fflush(stdin);      gets(nameF);
    cout << "Enter date faculty: ";     fflush(stdin);      gets(dateF);
    cout << "Enter name school : ";     fflush(stdin);      gets(x.nameS);
    cout << "Enter date school : ";     fflush(stdin);      gets(x.dateS);
}

void Faculty::Output()
{
    cout << "Name faculty: " << nameF << ln;
    cout << "Date faculty: " << dateF << ln;
    cout << "Name school : " << x.nameS << ln;
    cout << "Date school : " << x.dateS << ln;
}

class Person
{
protected:
    char nameP[25], birth[15], address[25];
public:
    void Input(), Output();
    Person();
};

Person::Person()
{
    strcpy(nameP, "");
    strcpy(birth, "");
    strcpy(address, "");
}

void Person::Input()
{
    cout << "Enter name person   : ";       fflush(stdin);      gets(nameP);
    cout << "Enter birth person  : ";       fflush(stdin);      gets(birth);
    cout << "Enter address person: ";       fflush(stdin);      gets(address);
}

void Person::Output()
{
    cout << "Name person   : " << nameP   << ln;
    cout << "Birth person  : " << birth   << ln;
    cout << "Address person: " << address << ln;
}

class Student : public Person
{
    Faculty y;
    char Class[15];
    double score;
public:
    void Input(), Output();
    Student();
};

Student::Student()
{
    strcpy(y.nameF, "");
    strcpy(y.dateF, "");
    strcpy(y.x.nameS, "");
    strcpy(y.x.dateS, "");
}

void Student::Input()
{
    cout << "Enter information of student: \n";
    Person::Input();
    y.Input();
    cout << "Enter class student: ";        fflush(stdin);      gets(Class);
    cout << "Enter score student: ";        fflush(stdin);      cin >> score;
}

void Student::Output()
{
    cout << "\n\nDisplay information of student: \n";
    Person::Output();
    y.Output();
    cout << "Class student: " << Class << ln;
    cout << "Score student: " << score << ln;
}


int main()
{
    Student k;
    k.Input();
    k.Output();
    return 0;
}
