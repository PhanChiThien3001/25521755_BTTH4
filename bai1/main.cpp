#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main() {
    SoPhuc a, b;
    cout << "=== Nhap so phuc a ===" << endl;
    cin >> a;
    cout << "=== Nhap so phuc b ===" << endl;
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
    cout << "a != b: " << (a != b ? "Dung" : "Sai") << endl;

    // So thuc la so phuc dac biet (imag = 0)
    SoPhuc soThuc(5.0);
    cout << "\nSo thuc 5.0 bieu dien la so phuc: " << soThuc << endl;

    return 0;
}
