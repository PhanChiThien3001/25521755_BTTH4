#include <iostream>
#include <iomanip>
#include "CDate.h"
using namespace std;

// Bai toan tinh lai suat tien gui ngan hang
void tinhLaiSuat() {
    cout << "\n=== BAI TOAN LAI SUAT TIEN GUI NGAN HANG ===" << endl;

    double vonGoc;
    double laiSuatNam; // %/nam
    CDate ngayGui, ngayRut;

    cout << "Von goc (VND): "; cin >> vonGoc;
    cout << "Lai suat (%/nam): "; cin >> laiSuatNam;
    cout << "\nNgay gui:" << endl; cin >> ngayGui;
    cout << "Ngay rut:" << endl; cin >> ngayRut;

    long soNgay = ngayRut - ngayGui;
    if (soNgay <= 0) {
        cout << "Ngay rut phai sau ngay gui!" << endl;
        return;
    }

    double laiSuatNgay = laiSuatNam / 100.0 / 365.0;
    double tienLai = vonGoc * laiSuatNgay * soNgay;
    double tongTien = vonGoc + tienLai;

    cout << fixed << setprecision(2);
    cout << "\n--- KET QUA ---" << endl;
    cout << "Ngay gui     : " << ngayGui  << endl;
    cout << "Ngay rut     : " << ngayRut  << endl;
    cout << "So ngay gui  : " << soNgay   << " ngay" << endl;
    cout << "Von goc      : " << vonGoc   << " VND" << endl;
    cout << "Lai suat     : " << laiSuatNam << " %/nam" << endl;
    cout << "Tien lai     : " << tienLai  << " VND" << endl;
    cout << "Tong nhan    : " << tongTien << " VND" << endl;
}

int main() {
    // Test cac phep toan co ban
    CDate d;
    cout << "=== Nhap ngay ===" << endl;
    cin >> d;

    cout << "\nNgay         : " << d << endl;
    cout << "Cong 30 ngay : " << (d + 30) << endl;
    cout << "Tru 10 ngay  : " << (d - 10) << endl;

    CDate d2(1, 1, 2025);
    cout << "\nKhoang cach tu " << d2 << " den " << d
         << " la " << (d - d2) << " ngay" << endl;

    cout << "\nTang 1 ngay (++d): ";
    ++d; cout << d << endl;

    cout << "Giam 1 ngay (--d): ";
    --d; cout << d << endl;

    // Ung dung: tinh lai suat
    tinhLaiSuat();

    return 0;
}
