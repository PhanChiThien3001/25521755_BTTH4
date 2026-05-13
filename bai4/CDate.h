#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;

class CDate {
private:
    int day;
    int month;
    int year;

    bool  isLeapYear(int y) const;
    int   daysInMonth(int m, int y) const;
    void  normalize();           // Chuan hoa sau cac phep tinh
    long  toJulian() const;      // Chuyen sang Julian Day Number
    static CDate fromJulian(long jd); // Chuyen tu Julian Day

public:
    CDate(int d = 1, int m = 1, int y = 2000);

    // Cong/tru so ngay
    CDate operator+(int days) const;
    CDate operator-(int days) const;

    // Tang/giam 1 ngay (prefix)
    CDate& operator++();
    CDate& operator--();

    // Khoang cach giua 2 ngay (tinh bang ngay)
    long operator-(const CDate& other) const;

    // Xuat / Nhap
    friend ostream& operator<<(ostream& os, const CDate& d);
    friend istream& operator>>(istream& is, CDate& d);
};

#endif
