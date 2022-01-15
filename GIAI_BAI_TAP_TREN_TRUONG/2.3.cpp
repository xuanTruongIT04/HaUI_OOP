#include <iostream>
using namespace std;
#define ln "\n";

class Mang
{
    float *a;
    int n;
public:
    void Nhap(), Xuat();
    float Max();
    float Min();
};

void Mang::Nhap()
{
    cout << "Nhap n: ";     cin >> n;
    a = new float[n];
    for(int i=0; i<n; i++)
    {
        cout << "Nhap A["<<i<<"]= ";
        cin >> a[i];
    }
}

void Mang::Xuat()
{
    for(int i=0; i<n; i++)
        cout << "A["<<i<<"]= " << a[i] << "\n";
}

float Mang::Max()
{
    float max = a[0];
    for(int i=0; i<n; i++)
        if(max < a[i]) max = a[i];
    return max;
}

float Mang::Min()
{
    float min = a[0];
    for(int i=0; i<n; i++)
        if(min > a[i]) min = a[i];
    return min;
}

int main()
{
    Mang m;
    m.Nhap();
    m.Xuat();
    cout << "\nMin: "<< m.Min();
    cout << "\nMax: "<< m.Max();
    return 0;
}
