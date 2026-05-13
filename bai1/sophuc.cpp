#include "SoPhuc.h"
#include <stdexcept>

// Input : r = phan thuc, i = phan ao (mac dinh 0)
// Output: doi tuong SoPhuc duoc khoi tao
// Giai thuat: Gan gia tri cho thanh vien real va imag
SoPhuc::SoPhuc(double r, double i) : real(r), imag(i) {}

// Input : sp - so phuc can cong
// Output: SoPhuc ket qua
// Giai thuat: Cong tung phan tuong ung (real + real, imag + imag)
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
    return SoPhuc(real + sp.real, imag + sp.imag);
}

// Input : sp - so phuc can tru
// Output: SoPhuc ket qua
// Giai thuat: Tru tung phan tuong ung (real - real, imag - imag)
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
    return SoPhuc(real - sp.real, imag - sp.imag);
}

// Input : sp - so phuc can nhan
// Output: SoPhuc ket qua
// Giai thuat: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
    return SoPhuc(real * sp.real - imag * sp.imag,
                  real * sp.imag + imag * sp.real);
}

// Input : sp - so phuc chia
// Output: SoPhuc ket qua
// Giai thuat: (a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c^2+d^2)
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
    double denom = sp.real * sp.real + sp.imag * sp.imag;
    if (denom == 0) throw runtime_error("Khong the chia cho 0!");
    return SoPhuc((real * sp.real + imag * sp.imag) / denom,
                  (imag * sp.real - real * sp.imag) / denom);
}

// Input : sp - so phuc can so sanh
// Output: true neu bang nhau, false neu khac
// Giai thuat: So sanh ca phan thuc va phan ao
bool SoPhuc::operator==(const SoPhuc& sp) const {
    return (real == sp.real) && (imag == sp.imag);
}

// Input : sp - so phuc can so sanh
// Output: true neu khac nhau
// Giai thuat: Phu dinh cua ==
bool SoPhuc::operator!=(const SoPhuc& sp) const {
    return !(*this == sp);
}

// Input : os - output stream, sp - so phuc can xuat
// Output: Xuat ra man hinh dang "a+bi" hoac "a-bi"
// Giai thuat: Kiem tra dau cua phan ao de dinh dang cho dep
ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.real;
    if (sp.imag >= 0)
        os << "+" << sp.imag << "i";
    else
        os << sp.imag << "i";
    return os;
}

// Input : is - input stream, sp - so phuc can nhap
// Output: Doi tuong sp duoc gan gia tri tu ban phim
// Giai thuat: Nhap lan luot phan thuc va phan ao
istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "  Nhap phan thuc: "; is >> sp.real;
    cout << "  Nhap phan ao  : "; is >> sp.imag;
    return is;
}
