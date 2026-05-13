#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>
using namespace std;

class SoPhuc {
private:
    double real;
    double imag;

public:
    // Constructor duy nhat: so thuc la truong hop dac biet (imag = 0)
    SoPhuc(double r = 0, double i = 0);

    // Cac phep toan so hoc
    SoPhuc operator+(const SoPhuc& sp) const;
    SoPhuc operator-(const SoPhuc& sp) const;
    SoPhuc operator*(const SoPhuc& sp) const;
    SoPhuc operator/(const SoPhuc& sp) const;

    // Phep toan so sanh
    bool operator==(const SoPhuc& sp) const;
    bool operator!=(const SoPhuc& sp) const;

    // Phep toan xuat / nhap
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);
    friend istream& operator>>(istream& is, SoPhuc& sp);
};

#endif
