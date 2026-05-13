#include "CMatrix.h"
#include <stdexcept>
#include <iomanip>

// Input : (khong) - dung rows va cols hien tai
// Output: Bo nho 2D duoc cap phat
// Giai thuat: Cap phat mang con tro kep rows x cols
void CMatrix::allocate() {
    data = new double*[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[cols]();
}

// Input : (khong)
// Output: Bo nho 2D duoc giai phong
// Giai thuat: Xoa tung hang, sau do xoa mang con tro
void CMatrix::deallocate() {
    for (int i = 0; i < rows; i++) delete[] data[i];
    delete[] data;
}

// Input : r - so hang, c - so cot
// Output: Ma tran 0 kich thuoc r x c
// Giai thuat: Khoi tao rows/cols, cap phat va dien 0
CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0) throw invalid_argument("Kich thuoc phai > 0");
    allocate();
}

// Input : other - ma tran can sao chep
// Output: Ma tran moi giong other
// Giai thuat: Cap phat moi, copy tung phan tu
CMatrix::CMatrix(const CMatrix& other) : rows(other.rows), cols(other.cols) {
    allocate();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = other.data[i][j];
}

// Input : (khong)
// Output: Giai phong bo nho 2D
// Giai thuat: Goi deallocate()
CMatrix::~CMatrix() { deallocate(); }

// Input : other - ma tran nguon
// Output: *this = other (toan tu gan)
// Giai thuat: Kiem tra tu gan, giai phong cu, cap phat va copy moi
CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this == &other) return *this;
    deallocate();
    rows = other.rows; cols = other.cols;
    allocate();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = other.data[i][j];
    return *this;
}

int CMatrix::getRows() const { return rows; }
int CMatrix::getCols() const { return cols; }

// Input : r - hang, c - cot
// Output: Tham chieu phan tu [r][c] (co the gan)
// Giai thuat: Kiem tra pham vi, tra ve data[r][c]
double& CMatrix::at(int r, int c) {
    if (r<0||r>=rows||c<0||c>=cols) throw out_of_range("Chi so ngoai pham vi!");
    return data[r][c];
}
double CMatrix::at(int r, int c) const {
    if (r<0||r>=rows||c<0||c>=cols) throw out_of_range("Chi so ngoai pham vi!");
    return data[r][c];
}

// Input : m - ma tran can cong (cung kich thuoc)
// Output: Ma tran tong
// Giai thuat: Cong tung phan tu tuong ung
CMatrix CMatrix::operator+(const CMatrix& m) const {
    if (rows!=m.rows||cols!=m.cols) throw invalid_argument("Ma tran khong cung kich thuoc!");
    CMatrix result(rows, cols);
    for (int i=0;i<rows;i++) for (int j=0;j<cols;j++)
        result.data[i][j] = data[i][j] + m.data[i][j];
    return result;
}

// Input : m - ma tran can tru (cung kich thuoc)
// Output: Ma tran hieu
// Giai thuat: Tru tung phan tu tuong ung
CMatrix CMatrix::operator-(const CMatrix& m) const {
    if (rows!=m.rows||cols!=m.cols) throw invalid_argument("Ma tran khong cung kich thuoc!");
    CMatrix result(rows, cols);
    for (int i=0;i<rows;i++) for (int j=0;j<cols;j++)
        result.data[i][j] = data[i][j] - m.data[i][j];
    return result;
}

// Input : m - ma tran can nhan (this.cols == m.rows)
// Output: Ma tran tich (rows x m.cols)
// Giai thuat: result[i][j] = sum_k( data[i][k] * m[k][j] )
CMatrix CMatrix::operator*(const CMatrix& m) const {
    if (cols != m.rows)
        throw invalid_argument("Kich thuoc khong hop le cho nhan ma tran!");
    CMatrix result(rows, m.cols);
    for (int i=0;i<rows;i++)
        for (int j=0;j<m.cols;j++)
            for (int k=0;k<cols;k++)
                result.data[i][j] += data[i][k] * m.data[k][j];
    return result;
}

// Input : v - vector can nhan (so chieu == cols)
// Output: Vector ket qua (so chieu == rows)
// Giai thuat: result[i] = sum_j( data[i][j] * v[j] )
CVector CMatrix::operator*(const CVector& v) const {
    if (cols != v.getDim())
        throw invalid_argument("Kich thuoc khong hop le cho nhan ma tran-vector!");
    CVector result(rows);
    for (int i=0;i<rows;i++) {
        double sum = 0;
        for (int j=0;j<cols;j++) sum += data[i][j] * v[j];
        result[i] = sum;
    }
    return result;
}

// Input : scalar - hang so
// Output: Ma tran moi voi moi phan tu nhan scalar
// Giai thuat: result[i][j] = data[i][j] * scalar
CMatrix CMatrix::operator*(double scalar) const {
    CMatrix result(*this);
    for (int i=0;i<rows;i++) for (int j=0;j<cols;j++)
        result.data[i][j] *= scalar;
    return result;
}

// Input : (khong)
// Output: Ma tran chuyen vi (cols x rows)
// Giai thuat: result[j][i] = data[i][j]
CMatrix CMatrix::transpose() const {
    CMatrix result(cols, rows);
    for (int i=0;i<rows;i++) for (int j=0;j<cols;j++)
        result.data[j][i] = data[i][j];
    return result;
}

// Input : os, m - ma tran can xuat
// Output: Xuat dang bang voi setw(8) moi phan tu
// Giai thuat: Duyet tung hang, xuat tung cot, xuong dong sau moi hang
ostream& operator<<(ostream& os, const CMatrix& m) {
    for (int i=0;i<m.rows;i++) {
        os << "  [ ";
        for (int j=0;j<m.cols;j++)
            os << setw(8) << m.data[i][j];
        os << " ]" << endl;
    }
    return os;
}

// Input : is, m - ma tran can nhap
// Output: m duoc nhap tu ban phim
// Giai thuat: Nhap rows va cols, cap phat lai, nhap tung phan tu
istream& operator>>(istream& is, CMatrix& m) {
    int r, c;
    cout << "  Nhap so hang: "; is >> r;
    cout << "  Nhap so cot : "; is >> c;
    m.deallocate();
    m.rows = r; m.cols = c;
    m.allocate();
    cout << "  Nhap " << r << "x" << c << " phan tu:" << endl;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++) {
            cout << "    m[" << i << "][" << j << "] = "; is >> m.data[i][j];
        }
    return is;
}
