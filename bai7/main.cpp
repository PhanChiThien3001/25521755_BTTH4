#include <iostream>
#include "CMatrix.h"
#include "CVector.h"
using namespace std;

int main() {
    cout << "=== TEST MA TRAN ===" << endl;

    // Ma tran 2x3 va 3x2 de test nhan
    double dataA[2][3] = {{1,2,3},{4,5,6}};
    double dataB[3][2] = {{7,8},{9,10},{11,12}};

    CMatrix A(2,3), B(3,2);
    for (int i=0;i<2;i++) for (int j=0;j<3;j++) A.at(i,j)=dataA[i][j];
    for (int i=0;i<3;i++) for (int j=0;j<2;j++) B.at(i,j)=dataB[i][j];

    cout << "\nA (2x3):" << endl << A;
    cout << "B (3x2):" << endl << B;
    cout << "A * B (2x2):" << endl << (A * B);
    cout << "A^T (3x2):"  << endl << A.transpose();

    // Tich ma tran voi vector
    double dataC[2][2] = {{1,0},{0,1}};
    CMatrix C(2,2);
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) C.at(i,j)=dataC[i][j];
    double vd[2] = {3, 5};
    CVector v(vd, 2);
    cout << "\nC (2x2 - don vi):" << endl << C;
    cout << "v = " << v << endl;
    cout << "C * v = " << (C * v) << endl;

    // Nhap tuy chinh
    cout << "\n=== Nhap ma tran M ===" << endl;
    CMatrix M;
    cin >> M;
    cout << "M:" << endl << M;
    cout << "M^T:" << endl << M.transpose();
    cout << "M * 2:" << endl << (M * 2.0);

    return 0;
}
