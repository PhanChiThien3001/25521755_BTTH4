#include "CTime.h"
#include <iomanip>

// Input : (khong) - thao tac tren doi tuong hien tai
// Output: Gio/phut/giay duoc chuan hoa trong khoang hop le
// Giai thuat: Chuyen tat ca thanh tong giay, roi dung % de tach ra,
//             xu ly am bang cach cong them 86400 (tong giay 1 ngay)
void CTime::normalize() {
    int total = hour * 3600 + minute * 60 + second;
    total = ((total % 86400) + 86400) % 86400; // Xu ly am
    hour   = total / 3600;
    minute = (total % 3600) / 60;
    second = total % 60;
}

// Input : h = gio, m = phut, s = giay
// Output: Doi tuong CTime hop le
// Giai thuat: Khoi tao roi goi normalize() de dam bao hop le
CTime::CTime(int h, int m, int s) : hour(h), minute(m), second(s) {
    normalize();
}

// Input : seconds - so giay can cong (co the am)
// Output: CTime moi sau khi cong
// Giai thuat: Tao ban sao, cong giay vao roi normalize
CTime CTime::operator+(int seconds) const {
    CTime t = *this;
    t.second += seconds;
    t.normalize();
    return t;
}

// Input : seconds - so giay can tru
// Output: CTime moi sau khi tru
// Giai thuat: Tao ban sao, tru giay roi normalize
CTime CTime::operator-(int seconds) const {
    return *this + (-seconds);
}

// Input : (khong)
// Output: Doi tuong hien tai sau khi tang 1 giay
// Giai thuat: Cong 1 giay, normalize, tra ve *this
CTime& CTime::operator++() {
    second++;
    normalize();
    return *this;
}

// Input : (khong)
// Output: Doi tuong hien tai sau khi giam 1 giay
// Giai thuat: Tru 1 giay, normalize, tra ve *this
CTime& CTime::operator--() {
    second--;
    normalize();
    return *this;
}

// Input : os - output stream, t - thoi gian can xuat
// Output: Xuat ra dang "HH:MM:SS"
// Giai thuat: Dung setw(2) va setfill('0') de dinh dang 2 chu so
ostream& operator<<(ostream& os, const CTime& t) {
    os << setfill('0')
       << setw(2) << t.hour   << ":"
       << setw(2) << t.minute << ":"
       << setw(2) << t.second;
    return os;
}

// Input : is - input stream, t - doi tuong can nhap
// Output: Doi tuong t duoc nhap tu ban phim
// Giai thuat: Nhap gio phut giay, kiem tra hop le, normalize
istream& operator>>(istream& is, CTime& t) {
    cout << "  Nhap gio   (0-23): "; is >> t.hour;
    cout << "  Nhap phut  (0-59): "; is >> t.minute;
    cout << "  Nhap giay  (0-59): "; is >> t.second;
    t.normalize();
    return is;
}
