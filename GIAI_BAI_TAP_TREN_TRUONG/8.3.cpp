#include <bits/stdc++.h>
using namespace std;
#define ln "\n";

class TTBH
{
    float a, b, c;
public:
    TTBH();
    TTBH(float a, float b, float c);
    TTBH operator !();
    TTBH operator -(TTBH y);
    TTBH operator + (TTBH y);
    friend ostream& operator << (ostream& x, TTBH y);
};

TTBH::TTBH()
{
    a = b = c = 0;
}

TTBH::TTBH(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

ostream& operator << (ostream& x, TTBH y)
{
    x << y.a << "x" << (char)178 << " + " << y.b << "x + " << y.c;
    return x;
}

TTBH TTBH::operator ! ()
{
    TTBH z;
    z.a = -a;
    z.b = -b;
    z.c = -c;
    return z;
}


TTBH TTBH::operator - (TTBH y)
{
    TTBH z;
    z.a = a - y.a;
    z.b = b - y.b;
    z.c = c - y.c;
    return z;
}

TTBH TTBH::operator + (TTBH y)
{
    TTBH z;
    z.a = a + y.a;
    z.b = b + y.b;
    z.c = c + y.c;
    return z;
}

int main()
{
    TTBH a(1, 2, 3);
    TTBH b(4, 5, 6);
    cout << "TTBH thu nhat: " << !a << ln;
    cout << "TTBH thu hai: " << !b << ln;
    TTBH T = a + b;
    TTBH H = a - b;
    cout << a << " + " << b << " = " << T << ln;
    cout << a << " - " << b << " = " << H << ln;
    ofstream f("D:/TamThucBacHai.txt", ios::out);
    f << a << " + " << b << " = " << T << ln;
    f << a << " - " << b << " = " << H << ln;
    f.close();
    return 0;
}
