#include <iostream>
using namespace std;

// Forward declaration 
class Matrix2x2;
class MatrixHelper;
int determinant(const Matrix2x2& m);

class Matrix2x2 {
private:
    int a, b, c, d; // Matrix elements

    friend class MatrixHelper;
    friend int determinant(const Matrix2x2& m);
    friend ostream& operator<<(ostream& os, const Matrix2x2& m);

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) : a(a), b(b), c(c), d(d) {};

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            a * other.a + b * other.c,  a * other.b + b * other.d,
            c * other.a + d * other.c,  c * other.b + d * other.d
        );
    }
};

int determinant(const Matrix2x2& m) {
    return (m.a * m.d) - (m.b * m.c);
}

class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int row, int col, int newVal) {
        if (row == 0 && col == 0) m.a = newVal;
        else if (row == 0 && col == 1) m.b = newVal;
        else if (row == 1 && col == 0) m.c = newVal;
        else if (row == 1 && col == 1) m.d = newVal;
        else cout << "Invalid position!" << endl;
    }
};

ostream& operator<<(ostream& os, const Matrix2x2& m) {
    os << "[ " << m.a << "  " << m.b << " ]" << endl;
    os << "[ " << m.c << "  " << m.d << " ]";
    return os;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\n" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "\nAddition Result:\n" << sum << endl;
    cout << "\nSubtraction Result:\n" << diff << endl;
    cout << "\nMultiplication Result:\n" << prod << endl;

    cout << "\nDeterminant of Matrix 1: " << determinant(m1) << endl;
    cout << "Determinant of Matrix 2: " << determinant(m2) << endl;

    MatrixHelper helper;
    cout << "\nUpdating element (0,1) of Matrix 1 to 99...\n";
    helper.updateElement(m1, 0, 1, 99);

    cout << "\nUpdated Matrix 1:\n" << m1 << endl;

    return 0;
}
