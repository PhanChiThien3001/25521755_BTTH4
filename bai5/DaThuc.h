#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
using namespace std;

class DaThuc {
private:
    double* coef;  // coef[i] = he so bac i
    int     deg;   // bac cao nhat

    void    normalize(); // Loai bo cac he so 0 o dau

public:
    DaThuc(int degree = 0);                      // Da thuc 0
    DaThuc(const double* c, int degree);         // Tu mang he so
    DaThuc(const DaThuc& other);                 // Copy constructor
    ~DaThuc();

    DaThuc& operator=(const DaThuc& other);

    int     getDegree() const;
    double  getCoef(int i) const;
    double  eval(double x) const;                // Tinh gia tri tai x

    DaThuc  operator+(const DaThuc& dt) const;
    DaThuc  operator-(const DaThuc& dt) const;
    DaThuc  operator*(const DaThuc& dt) const;
    DaThuc  operator*(double scalar)    const;

    friend ostream& operator<<(ostream& os, const DaThuc& dt);
    friend istream& operator>>(istream& is, DaThuc& dt);
};

#endif
