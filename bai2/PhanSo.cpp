#include "PhanSo.h"
#include <stdexcept>
#include <cstdlib>

// Input : a, b - hai so nguyen
// Output: Uoc chung lon nhat cua a va b
// Giai thuat: Dung de quy Euclid: UCLN(a,b) = UCLN(b, a%b) cho den khi b=0
int PhanSo::UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

// Input : (khong co tham so - thao tac tren doi tuong hien tai)
// Output: Phan so duoc rut gon, mau luon duong
// Giai thuat: Chia tu va mau cho UCLN, chuyen dau am ve tu
void PhanSo::rutGon() {
    if (mau < 0) { tu = -tu; mau = -mau; }
    int ucln = UCLN(abs(tu), abs(mau));
    if (ucln != 0) { tu /= ucln; mau /= ucln; }
}

// Input : t = tu so, m = mau so (mac dinh 1 => bieu dien so nguyen)
// Output: Doi tuong PhanSo da duoc rut gon
// Giai thuat: Khoi tao va goi rutGon() ngay
PhanSo::PhanSo(int t, int m) : tu(t), mau(m) {
    if (mau == 0) throw runtime_error("Mau so khong duoc bang 0!");
    rutGon();
}

// Input : ps - phan so can cong
// Output: PhanSo ket qua da rut gon
// Giai thuat: a/b + c/d = (a*d + c*b) / (b*d)
PhanSo PhanSo::operator+(const PhanSo& ps) const {
    return PhanSo(tu * ps.mau + ps.tu * mau, mau * ps.mau);
}

// Input : ps - phan so can tru
// Output: PhanSo ket qua da rut gon
// Giai thuat: a/b - c/d = (a*d - c*b) / (b*d)
PhanSo PhanSo::operator-(const PhanSo& ps) const {
    return PhanSo(tu * ps.mau - ps.tu * mau, mau * ps.mau);
}

// Input : ps - phan so can nhan
// Output: PhanSo ket qua da rut gon
// Giai thuat: a/b * c/d = (a*c) / (b*d)
PhanSo PhanSo::operator*(const PhanSo& ps) const {
    return PhanSo(tu * ps.tu, mau * ps.mau);
}

// Input : ps - phan so can chia
// Output: PhanSo ket qua da rut gon
// Giai thuat: a/b / c/d = (a*d) / (b*c)
PhanSo PhanSo::operator/(const PhanSo& ps) const {
    if (ps.tu == 0) throw runtime_error("Khong the chia cho 0!");
    return PhanSo(tu * ps.mau, mau * ps.tu);
}

// Input : ps - phan so can so sanh
// Output: true neu bang nhau
// Giai thuat: a/b == c/d khi a*d == c*b
bool PhanSo::operator==(const PhanSo& ps) const {
    return tu * ps.mau == ps.tu * mau;
}

// Input : ps - phan so can so sanh
// Output: true neu lon hon
// Giai thuat: a/b > c/d khi a*d > c*b (mau duong sau rutGon)
bool PhanSo::operator>(const PhanSo& ps) const {
    return tu * ps.mau > ps.tu * mau;
}

// Input : ps - phan so can so sanh
// Output: true neu nho hon
// Giai thuat: a/b < c/d khi a*d < c*b
bool PhanSo::operator<(const PhanSo& ps) const {
    return tu * ps.mau < ps.tu * mau;
}

// Input : os - output stream, ps - phan so can xuat
// Output: Xuat ra dang "tu/mau", neu mau=1 chi xuat tu
// Giai thuat: Kiem tra mau, neu =1 xuat nhu so nguyen
ostream& operator<<(ostream& os, const PhanSo& ps) {
    if (ps.mau == 1) os << ps.tu;
    else             os << ps.tu << "/" << ps.mau;
    return os;
}

// Input : is - input stream, ps - phan so can nhap
// Output: Doi tuong ps duoc nhap va rut gon
// Giai thuat: Nhap tu va mau, kiem tra mau != 0, sau do rut gon
istream& operator>>(istream& is, PhanSo& ps) {
    cout << "  Nhap tu so : "; is >> ps.tu;
    do {
        cout << "  Nhap mau so (khac 0): "; is >> ps.mau;
    } while (ps.mau == 0);
    ps.rutGon();
    return is;
}
