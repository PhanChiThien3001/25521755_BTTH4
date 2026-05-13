#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>
using namespace std;

class CVector {
private:
    double* data;
    int     dim;   // So chieu

public:
    CVector(int dimension = 3);
    CVector(const double* arr, int dimension);
    CVector(const CVector& other);
    ~CVector();

    CVector& operator=(const CVector& other);

    int    getDim() const;
    double& operator[](int i);
    double  operator[](int i) const;

    CVector operator+(const CVector& v) const;
    CVector operator-(const CVector& v) const;
    CVector operator*(double scalar)    const;   // Nhan vo huong
    double  dot(const CVector& v)       const;   // Tich vo huong
    double  norm()                      const;   // Do dai (chuan)
    CVector cross(const CVector& v)     const;   // Tich co huong (chi 3D)

    friend ostream& operator<<(ostream& os, const CVector& v);
    friend istream& operator>>(istream& is, CVector& v);
};

#endif
