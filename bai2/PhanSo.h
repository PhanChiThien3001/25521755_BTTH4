#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

    int UCLN(int a, int b);   // Ham tinh uoc chung lon nhat
    void rutGon();             // Ham rut gon phan so

public:
    // so nguyen la truong hop dac biet: mau = 1
    PhanSo(int t = 0, int m = 1);

    PhanSo operator+(const PhanSo& ps) const;
    PhanSo operator-(const PhanSo& ps) const;
    PhanSo operator*(const PhanSo& ps) const;
    PhanSo operator/(const PhanSo& ps) const;

    bool operator==(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps)  const;
    bool operator<(const PhanSo& ps)  const;

    friend ostream& operator<<(ostream& os, const PhanSo& ps);
    friend istream& operator>>(istream& is, PhanSo& ps);
};

#endif
