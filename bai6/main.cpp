#include <iostream>
#include "CVector.h"
using namespace std;

int main() {
    CVector a, b;
    cout << "=== Nhap vector A ===" << endl; cin >> a;
    cout << "=== Nhap vector B ===" << endl; cin >> b;

    cout << "\nA = " << a << endl;
    cout << "B = " << b << endl;
    cout << "A + B  = " << (a + b)   << endl;
    cout << "A - B  = " << (a - b)   << endl;
    cout << "A * 3  = " << (a * 3.0) << endl;
    cout << "A . B  = " << a.dot(b)  << " (tich vo huong)" << endl;
    cout << "|A|    = " << a.norm()  << " (do dai)"       << endl;

    if (a.getDim() == 3 && b.getDim() == 3) {
        cout << "A x B  = " << a.cross(b) << " (tich co huong)" << endl;
    }

    return 0;
}
