#include "iostream"
#include "string"

using namespace std;

class DimensionMismatchException {
private:
    int rowsA, colsA, rowsB, colsB;
    string message;

public:
    DimensionMismatchException(int rA, int cA, int rB, int cB)
        : rowsA(rA), colsA(cA), rowsB(rB), colsB(cB) {
        message = "DimensionMismatchException - Matrices must have same dimensions (" +
                  to_string(rowsA) + "x" + to_string(colsA) + " vs " +
                  to_string(rowsB) + "x" + to_string(colsB) + ") !";
    }

    const char* what() const {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) const {
        return data[r][c];
    }

    Matrix<T> add(const Matrix<T>& other) {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw DimensionMismatchException(this->rows, this->cols, other.rows, other.cols);
        }

        Matrix<T> result(this->rows, this->cols);
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                result.set(i, j, this->get(i, j) + other.get(i, j));
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        A.set(0, 0, 1);
        A.set(0, 1, 2);
        A.set(1, 0, 3);
        A.set(1, 1, 4);

        Matrix<int> B(3, 3);
        B.set(0, 0, 5);
        B.set(0, 1, 6);
        B.set(0, 2, 7);
        B.set(1, 0, 8);
        B.set(1, 1, 9);
        B.set(1, 2, 10);
        B.set(2, 0, 11);
        B.set(2, 1, 12);
        B.set(2, 2, 13);

        cout << "Matrix A:" << endl;
        A.display();
        cout << "Matrix B:" << endl;
        B.display();

        cout << "Matrix A + Matrix B:" << endl;
        Matrix<int> C = A.add(B);  
        C.display();
    } catch (const DimensionMismatchException& e) {
        cout << e.what() << endl;  
    }

    return 0;
}
