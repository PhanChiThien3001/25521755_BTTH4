#include <iostream>
#include "PhanSo.h"
using namespace std;

int main() {
    PhanSo a, b;
    cout << "=== Nhap phan so a ===" << endl;
    cin >> a;
    cout << "=== Nhap phan so b ===" << endl;
    cin >> b;

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;

    cout << "\na + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;

    try {
        cout << "a / b = " << (a / b) << endl;
    } catch (const exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    cout << "\na == b: " << (a == b ? "Dung" : "Sai") << endl;
    cout << "a >  b: " << (a >  b ? "Dung" : "Sai") << endl;
    cout << "a <  b: " << (a <  b ? "Dung" : "Sai") << endl;

    // So nguyen la phan so dac biet (mau = 1)
    PhanSo soNguyen(7);
    cout << "\nSo nguyen 7 bieu dien la phan so: " << soNguyen << endl;

    return 0;
}
