#include "CVector.h"
#include <cmath>
#include <stdexcept>

// Input : dimension - so chieu vector
// Output: Vector 0 voi so chieu cho truoc
// Giai thuat: Cap phat mang, khoi tao tat ca phan tu = 0
CVector::CVector(int dimension) : dim(dimension) {
    if (dim <= 0) throw invalid_argument("So chieu phai > 0");
    data = new double[dim]();
}

// Input : arr - mang gia tri, dimension - so chieu
// Output: Vector duoc khoi tao tu mang
// Giai thuat: Copy mang arr vao data
CVector::CVector(const double* arr, int dimension) : dim(dimension) {
    data = new double[dim];
    for (int i = 0; i < dim; i++) data[i] = arr[i];
}

// Input : other - vector can sao chep
// Output: Vector moi giong other
// Giai thuat: Cap phat mang moi, copy tung phan tu
CVector::CVector(const CVector& other) : dim(other.dim) {
    data = new double[dim];
    for (int i = 0; i < dim; i++) data[i] = other.data[i];
}

// Input : (khong)
// Output: Giai phong bo nho
// Giai thuat: delete[] data
CVector::~CVector() { delete[] data; }

// Input : other - vector nguon
// Output: *this = other (toan tu gan)
// Giai thuat: Kiem tra tu gan, giai phong cu, copy moi
CVector& CVector::operator=(const CVector& other) {
    if (this == &other) return *this;
    delete[] data;
    dim  = other.dim;
    data = new double[dim];
    for (int i = 0; i < dim; i++) data[i] = other.data[i];
    return *this;
}

int CVector::getDim() const { return dim; }

// Input : i - chi so (0-based)
// Output: Tham chieu phan tu thu i (co the gan)
// Giai thuat: Kiem tra chi so hop le, tra ve data[i]
double& CVector::operator[](int i) {
    if (i < 0 || i >= dim) throw out_of_range("Chi so ngoai pham vi!");
    return data[i];
}

double CVector::operator[](int i) const {
    if (i < 0 || i >= dim) throw out_of_range("Chi so ngoai pham vi!");
    return data[i];
}

// Input : v - vector can cong (cung so chieu)
// Output: Vector tong
// Giai thuat: Cong tung phan tu: result[i] = data[i] + v[i]
CVector CVector::operator+(const CVector& v) const {
    if (dim != v.dim) throw invalid_argument("Khong cung so chieu!");
    CVector result(dim);
    for (int i = 0; i < dim; i++) result.data[i] = data[i] + v.data[i];
    return result;
}

// Input : v - vector can tru (cung so chieu)
// Output: Vector hieu
// Giai thuat: Tru tung phan tu: result[i] = data[i] - v[i]
CVector CVector::operator-(const CVector& v) const {
    if (dim != v.dim) throw invalid_argument("Khong cung so chieu!");
    CVector result(dim);
    for (int i = 0; i < dim; i++) result.data[i] = data[i] - v.data[i];
    return result;
}

// Input : scalar - hang so
// Output: Vector moi voi moi phan tu nhan scalar
// Giai thuat: result[i] = data[i] * scalar
CVector CVector::operator*(double scalar) const {
    CVector result(dim);
    for (int i = 0; i < dim; i++) result.data[i] = data[i] * scalar;
    return result;
}

// Input : v - vector can tinh tich vo huong (cung so chieu)
// Output: Gia tri tich vo huong (so thuc)
// Giai thuat: dot = sum(data[i] * v[i]) voi i tu 0 den dim-1
double CVector::dot(const CVector& v) const {
    if (dim != v.dim) throw invalid_argument("Khong cung so chieu!");
    double sum = 0;
    for (int i = 0; i < dim; i++) sum += data[i] * v.data[i];
    return sum;
}

// Input : (khong)
// Output: Do dai (chuan Euclidean) cua vector
// Giai thuat: norm = sqrt(sum(data[i]^2))
double CVector::norm() const {
    double sum = 0;
    for (int i = 0; i < dim; i++) sum += data[i] * data[i];
    return sqrt(sum);
}

// Input : v - vector can tinh tich co huong (chi dung cho 3D)
// Output: Vector vuong goc voi ca 2 vector
// Giai thuat: Cong thuc tich co huong 3D:
//   result[0] = a[1]*b[2] - a[2]*b[1]
//   result[1] = a[2]*b[0] - a[0]*b[2]
//   result[2] = a[0]*b[1] - a[1]*b[0]
CVector CVector::cross(const CVector& v) const {
    if (dim != 3 || v.dim != 3)
        throw invalid_argument("Tich co huong chi dinh nghia cho vector 3 chieu!");
    double res[3] = {
        data[1]*v.data[2] - data[2]*v.data[1],
        data[2]*v.data[0] - data[0]*v.data[2],
        data[0]*v.data[1] - data[1]*v.data[0]
    };
    return CVector(res, 3);
}

// Input : os, v - vector can xuat
// Output: Xuat dang "(v1, v2, ..., vn)"
// Giai thuat: Duyet tung phan tu, them dau phay
ostream& operator<<(ostream& os, const CVector& v) {
    os << "(";
    for (int i = 0; i < v.dim; i++) {
        os << v.data[i];
        if (i < v.dim - 1) os << ", ";
    }
    os << ")";
    return os;
}

// Input : is, v - vector can nhap
// Output: v duoc nhap tu ban phim
// Giai thuat: Nhap so chieu, cap phat lai, nhap tung phan tu
istream& operator>>(istream& is, CVector& v) {
    cout << "  Nhap so chieu: "; is >> v.dim;
    delete[] v.data;
    v.data = new double[v.dim];
    cout << "  Nhap " << v.dim << " phan tu:" << endl;
    for (int i = 0; i < v.dim; i++) {
        cout << "    v[" << i << "] = "; is >> v.data[i];
    }
    return is;
}
