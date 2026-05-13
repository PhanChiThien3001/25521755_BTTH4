#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include "CVector.h"
using namespace std;

class CMatrix {
private:
    double** data;
    int      rows, cols;

    void allocate();
    void deallocate();

public:
    CMatrix(int r = 2, int c = 2);
    CMatrix(const CMatrix& other);
    ~CMatrix();

    CMatrix& operator=(const CMatrix& other);

    int    getRows() const;
    int    getCols() const;
    double& at(int r, int c);
    double  at(int r, int c) const;

    CMatrix operator+(const CMatrix& m) const;
    CMatrix operator-(const CMatrix& m) const;
    CMatrix operator*(const CMatrix& m) const;   // Tich hai ma tran
    CVector operator*(const CVector& v) const;   // Tich ma tran voi vector
    CMatrix operator*(double scalar)    const;   // Nhan vo huong
    CMatrix transpose()                 const;   // Ma tran chuyen vi

    friend ostream& operator<<(ostream& os, const CMatrix& m);
    friend istream& operator>>(istream& is, CMatrix& m);
};

#endif
