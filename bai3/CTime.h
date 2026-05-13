#ifndef CTIME_H
#define CTIME_H
#include <iostream>
using namespace std;

class CTime {
private:
    int hour;
    int minute;
    int second;

    void normalize(); // Chuan hoa (xu ly tran/am)

public:
    CTime(int h = 0, int m = 0, int s = 0);

    // Cong/tru mot so giay nguyen
    CTime operator+(int seconds) const;
    CTime operator-(int seconds) const;

    // Tang/giam 1 giay (prefix)
    CTime& operator++();
    CTime& operator--();

    // Xuat / Nhap
    friend ostream& operator<<(ostream& os, const CTime& t);
    friend istream& operator>>(istream& is, CTime& t);
};

#endif
