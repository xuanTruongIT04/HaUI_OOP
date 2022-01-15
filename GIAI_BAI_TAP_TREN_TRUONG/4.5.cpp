#include <iostream>
#include <iomanip>
using namespace std;
#define ln "\n";

class Arrai
{
    int *value;
    int n;
public:
    Arrai();
    Arrai(int *value, int n);
    ~Arrai();
    void Nhap(), Xuat();
}

Arrai::Arrai()
{
    n = 0;
}

Arrai::Arrai(int *value, int nNew)
{
    n = nNew;
    value = new int[nNew];
    for(int i=0; i< nNew; i++)
        value[i] = 0;
}

Arrai::~Arrai()
{
    n = 0;
    delete value[];
}

void Arrai::Nhap()
{
    for(int i=0; i<n; i++)
    {
        cout << "\nNhap Value["<<i<<"]= ";
        cin >> value[i];
    }
}

void Arrai::Xuat()
{
    for(int i=0; i<n; i++)
        cout << "Value["<< i << "]= " << value[i] << ln;
}
int main()
{
    Arrai a;
    a.Nhap();
    a.Xuat();
    return 0;
}
