#include "CDate.h"
#include <iomanip>
#include <stdexcept>

// Input : y - nam can kiem tra
// Output: true neu la nam nhuan
// Giai thuat: Nam nhuan khi chia het 400, hoac chia het 4 va khong chia het 100
bool CDate::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Input : m = thang, y = nam
// Output: So ngay trong thang do
// Giai thuat: Dung bang so ngay, rieng thang 2 kiem tra nam nhuan
int CDate::daysInMonth(int m, int y) const {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m - 1];
}

// Input : (khong) - thao tac tren doi tuong hien tai
// Output: Ngay/thang/nam duoc chuan hoa
// Giai thuat: Dung chuyen doi qua Julian Day Number de don gian hoa
void CDate::normalize() {
    *this = fromJulian(toJulian());
}

// Input : (khong) - thao tac tren doi tuong hien tai
// Output: Julian Day Number (so ngay tinh tu 01/01/4713 TCN)
// Giai thuat: Cong thuc tieu chuan chuyen doi lich Gregorian -> JDN
long CDate::toJulian() const {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + (153*m + 2)/5 + 365L*y + y/4 - y/100 + y/400 - 32045;
}

// Input : jd - Julian Day Number
// Output: Doi tuong CDate tuong ung
// Giai thuat: Cong thuc tieu chuan chuyen doi JDN -> lich Gregorian
CDate CDate::fromJulian(long jd) {
    long a = jd + 32044;
    long b = (4*a + 3) / 146097;
    long c = a - (146097*b) / 4;
    long d = (4*c + 3) / 1461;
    long e = c - (1461*d) / 4;
    long m = (5*e + 2) / 153;
    int day   = e - (153*m + 2)/5 + 1;
    int month = m + 3 - 12*(m/10);
    int year  = 100*b + d - 4800 + m/10;
    return CDate(day, month, year);
}

// Input : d = ngay, m = thang, y = nam
// Output: Doi tuong CDate hop le
// Giai thuat: Khoi tao, kiem tra co ban, sau do normalize
CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) {
    if (m < 1 || m > 12) throw runtime_error("Thang khong hop le!");
}

// Input : days - so ngay can cong (co the am)
// Output: CDate moi sau khi cong
// Giai thuat: Chuyen sang JDN, cong so ngay, chuyen lai
CDate CDate::operator+(int days) const {
    return fromJulian(toJulian() + days);
}

// Input : days - so ngay can tru
// Output: CDate moi sau khi tru
// Giai thuat: Goi operator+ voi so am
CDate CDate::operator-(int days) const {
    return *this + (-days);
}

// Input : (khong)
// Output: Doi tuong hien tai sau khi tang 1 ngay
// Giai thuat: Goi operator+, gan lai, tra ve *this
CDate& CDate::operator++() {
    *this = *this + 1;
    return *this;
}

// Input : (khong)
// Output: Doi tuong hien tai sau khi giam 1 ngay
// Giai thuat: Goi operator-, gan lai, tra ve *this
CDate& CDate::operator--() {
    *this = *this - 1;
    return *this;
}

// Input : other - ngay can tinh khoang cach
// Output: So ngay chenh lech (co the am)
// Giai thuat: Lay hieu hai Julian Day Number
long CDate::operator-(const CDate& other) const {
    return toJulian() - other.toJulian();
}

// Input : os - output stream, d - ngay can xuat
// Output: Xuat ra dang "DD/MM/YYYY"
// Giai thuat: Dung setw va setfill de dinh dang
ostream& operator<<(ostream& os, const CDate& d) {
    os << setfill('0')
       << setw(2) << d.day   << "/"
       << setw(2) << d.month << "/"
       << setw(4) << d.year;
    return os;
}

// Input : is - input stream, d - doi tuong can nhap
// Output: Doi tuong d duoc nhap va kiem tra hop le
// Giai thuat: Nhap ngay/thang/nam, kiem tra pham vi tung gia tri
istream& operator>>(istream& is, CDate& d) {
    cout << "  Nhap nam : "; is >> d.year;
    do {
        cout << "  Nhap thang (1-12) : "; is >> d.month;
    } while (d.month < 1 || d.month > 12);
    int maxDay = d.daysInMonth(d.month, d.year);
    do {
        cout << "  Nhap ngay (1-" << maxDay << ")  : "; is >> d.day;
    } while (d.day < 1 || d.day > maxDay);
    return is;
}
