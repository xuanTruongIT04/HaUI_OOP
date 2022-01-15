#include <iostream>
using namespace std;
#define ln "\n";

class Vehicle
{
protected:
    char nhanHieu[20], hang[30];
    int namSX;
public:
    void Nhap(), Xuat();
};

void Vehicle::Nhap()
{
    cout << "Nhap nhan hieu : ";        fflush(stdin);      gets(nhanHieu);
    cout << "Nhap hang sxuat: ";        fflush(stdin);      gets(hang);
    cout << "Nhap nam sxuat : ";        cin >> namSX;
}

void Vehicle::Xuat()
{
    cout << "Nhan hieu : " << nhanHieu << ln;
    cout << "Hang sxuat: " << hang << ln;
    cout << "Nam sxuat : " << namSX << ln;
}

class OTo : public Vehicle
{
    int soChoNgoi;
    float dungTich;
public:
    void Nhap(), Xuat();
    friend void Sua(OTo &a);
};

void OTo::Nhap()
{
    Vehicle::Nhap();
    cout << "Nhap so cho ngoi: ";       cin >> soChoNgoi;
    cout << "Nhap dung tich  : ";       cin >> dungTich;
}

void OTo::Xuat()
{
    Vehicle::Xuat();
    cout << "So cho ngoi: " << soChoNgoi << ln;
    cout << "Dung tich  : " << (float)dungTich << ln;
}

class MoTo : public Vehicle
{
    int phanKhoi;
public:
    void Nhap(), Xuat();
};

void MoTo::Nhap()
{
    Vehicle::Nhap();
    cout << "Nhap phan khoi: ";       cin >> phanKhoi;
}

void MoTo::Xuat()
{
    Vehicle::Xuat();
    cout << "Phan khoi: " << phanKhoi << ln;
}

void Sua(OTo &a)
{
    a.dungTich = 3.0;
}

int main()
{
    OTo a;
    MoTo b;
    cout << "Nhap thong tin xe o to: \n";
    a.Nhap();
    Sua(a);
    cout << "\nNhap thong tin xe mo to: \n";
    b.Nhap();

    cout << "\nXuat thong tin xe o to: \n";
    a.Xuat();
    cout << "\nXuat thong tin xe mo to: \n";
    b.Xuat();
    return 0;
}
