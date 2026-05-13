#include "DaThuc.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

// Input : (khong) - thao tac tren doi tuong hien tai
// Output: Bac da thuc duoc cap nhat (bo cac he so 0 dau)
// Giai thuat: Giam bac den khi he so cao nhat khac 0
void DaThuc::normalize() {
    while (deg > 0 && coef[deg] == 0.0)
        deg--;
}

// Input : degree - bac da thuc
// Output: Da thuc 0 voi bac cho truoc
// Giai thuat: Cap phat mang, khoi tao tat ca he so = 0
DaThuc::DaThuc(int degree) : deg(degree) {
    if (degree < 0) throw invalid_argument("Bac phai >= 0");
    coef = new double[deg + 1]();
}

// Input : c - mang he so, degree - bac cao nhat
// Output: Da thuc voi he so cho san
// Giai thuat: Copy mang c vao coef, goi normalize
DaThuc::DaThuc(const double* c, int degree) : deg(degree) {
    coef = new double[deg + 1];
    for (int i = 0; i <= deg; i++) coef[i] = c[i];
    normalize();
}

// Input : other - da thuc can sao chep
// Output: Da thuc moi giong other
// Giai thuat: Cap phat mang moi, copy tung he so
DaThuc::DaThuc(const DaThuc& other) : deg(other.deg) {
    coef = new double[deg + 1];
    for (int i = 0; i <= deg; i++) coef[i] = other.coef[i];
}

// Input : (khong)
// Output: Giai phong bo nho mang he so
// Giai thuat: delete[] coef
DaThuc::~DaThuc() {
    delete[] coef;
}

// Input : other - da thuc nguon
// Output: *this = other (toan tu gan)
// Giai thuat: Kiem tra tu gan, giai phong cu, copy moi
DaThuc& DaThuc::operator=(const DaThuc& other) {
    if (this == &other) return *this;
    delete[] coef;
    deg  = other.deg;
    coef = new double[deg + 1];
    for (int i = 0; i <= deg; i++) coef[i] = other.coef[i];
    return *this;
}

int    DaThuc::getDegree()  const { return deg; }
double DaThuc::getCoef(int i) const {
    if (i < 0 || i > deg) return 0.0;
    return coef[i];
}

// Input : x - gia tri can tinh
// Output: Gia tri da thuc tai x
// Giai thuat: Phuong phap Horner: ((a_n*x + a_{n-1})*x + ...)*x + a_0
double DaThuc::eval(double x) const {
    double result = coef[deg];
    for (int i = deg - 1; i >= 0; i--)
        result = result * x + coef[i];
    return result;
}

// Input : dt - da thuc can cong
// Output: Da thuc tong
// Giai thuat: Lay bac max, cong tung he so tuong ung
DaThuc DaThuc::operator+(const DaThuc& dt) const {
    int maxDeg = max(deg, dt.deg);
    DaThuc result(maxDeg);
    for (int i = 0; i <= maxDeg; i++)
        result.coef[i] = getCoef(i) + dt.getCoef(i);
    result.normalize();
    return result;
}

// Input : dt - da thuc can tru
// Output: Da thuc hieu
// Giai thuat: Lay bac max, tru tung he so tuong ung
DaThuc DaThuc::operator-(const DaThuc& dt) const {
    int maxDeg = max(deg, dt.deg);
    DaThuc result(maxDeg);
    for (int i = 0; i <= maxDeg; i++)
        result.coef[i] = getCoef(i) - dt.getCoef(i);
    result.normalize();
    return result;
}

// Input : dt - da thuc can nhan
// Output: Da thuc tich (bac = deg + dt.deg)
// Giai thuat: Nhan tich chap: coef_tich[i+j] += coef_A[i] * coef_B[j]
DaThuc DaThuc::operator*(const DaThuc& dt) const {
    DaThuc result(deg + dt.deg);
    for (int i = 0; i <= deg; i++)
        for (int j = 0; j <= dt.deg; j++)
            result.coef[i + j] += coef[i] * dt.coef[j];
    result.normalize();
    return result;
}

// Input : scalar - hang so can nhan
// Output: Da thuc moi voi moi he so nhan scalar
// Giai thuat: Nhan tung he so voi scalar
DaThuc DaThuc::operator*(double scalar) const {
    DaThuc result(*this);
    for (int i = 0; i <= result.deg; i++)
        result.coef[i] *= scalar;
    result.normalize();
    return result;
}

// Input : os, dt - da thuc can xuat
// Output: Xuat dang "3x^2 + -1x^1 + 5x^0"
// Giai thuat: Duyet tu bac cao xuong, bo qua he so 0
ostream& operator<<(ostream& os, const DaThuc& dt) {
    bool first = true;
    for (int i = dt.deg; i >= 0; i--) {
        if (dt.coef[i] == 0.0 && dt.deg > 0) continue;
        if (!first && dt.coef[i] > 0) os << " + ";
        else if (!first && dt.coef[i] < 0) os << " - ";
        double val = (dt.coef[i] < 0 && !first) ? -dt.coef[i] : dt.coef[i];
        if (i == 0 || val != 1.0) os << val;
        if (i >= 2) os << "x^" << i;
        else if (i == 1) os << "x";
        first = false;
    }
    if (first) os << "0";
    return os;
}

// Input : is, dt - da thuc can nhap
// Output: dt duoc nhap tu ban phim
// Giai thuat: Nhap bac, roi nhap tung he so tu bac 0 den bac n
istream& operator>>(istream& is, DaThuc& dt) {
    int deg;
    cout << "  Nhap bac da thuc: "; is >> deg;
    delete[] dt.coef;
    dt.deg  = deg;
    dt.coef = new double[deg + 1];
    cout << "  Nhap cac he so (tu bac 0 den bac " << deg << "):" << endl;
    for (int i = 0; i <= deg; i++) {
        cout << "    He so bac " << i << ": ";
        is >> dt.coef[i];
    }
    dt.normalize();
    return is;
}
