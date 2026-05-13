#include <iostream>
#include "DaThuc.h"
using namespace std;

int main() {
    DaThuc a, b;
    cout << "=== Nhap da thuc A ===" << endl; cin >> a;
    cout << "=== Nhap da thuc B ===" << endl; cin >> b;

    cout << "\nA = " << a << endl;
    cout << "B = " << b << endl;
    cout << "A + B = " << (a + b) << endl;
    cout << "A - B = " << (a - b) << endl;
    cout << "A * B = " << (a * b) << endl;
    cout << "A * 2 = " << (a * 2.0) << endl;

    double x;
    cout << "\nNhap x de tinh A(x): "; cin >> x;
    cout << "A(" << x << ") = " << a.eval(x) << endl;

    return 0;
}
