#include <iostream>
#include "CTime.h"
using namespace std;

int main() {
    CTime t;
    cout << "=== Nhap thoi gian ===" << endl;
    cin >> t;

    cout << "\nThoi gian: " << t << endl;
    cout << "Cong 90 giay : " << (t + 90)  << endl;
    cout << "Tru 120 giay : " << (t - 120) << endl;

    cout << "\nTang 1 giay (++t): ";
    ++t;
    cout << t << endl;

    cout << "Giam 1 giay (--t): ";
    --t;
    cout << t << endl;

    // Tran ngay: cong qua 23:59:59
    CTime cuoiNgay(23, 59, 55);
    cout << "\nCuoi ngay    : " << cuoiNgay << endl;
    cout << "Cong 10 giay : " << (cuoiNgay + 10) << " (quay lai dau ngay)" << endl;

    return 0;
}
