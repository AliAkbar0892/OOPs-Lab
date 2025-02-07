/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 2
*/


#include "iostream"
using namespace std;

int main(){
    cout << "\nEnter Number of Rows of matrix 1: ";
    int rows1;
    cin >> rows1;
    cout << "\nEnter Number of columns of matrix 1: ";
    int cols1;
    cin >> cols1;
    cout << "\nEnter Number of Rows of matrix 2: ";
    int rows2;
    cin >> rows2;        
    cout << "\nEnter Number of columns of matrix 2: ";
    int cols2;
    cin >> cols2;     
    if(rows1 != rows2 || cols1 != cols2) {
        cout << "matrix addition not possible!";
        return 0;
    }
    int** matrix1 = new int*[rows1];

    for (int i = 0; i < rows1; i++)
    {
        matrix1[i] = new int [cols1];
    }

    int** matrix2 = new int*[rows2];

    for (int i = 0; i < rows2; i++)
    {
        matrix2[i] = new int [cols2];
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << "\nEnter array element" << i+1 <<" "<< j+1 <<":  ";
            cin >> matrix1[i][j];
        }
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << "\nEnter array element" << i+1 <<" "<< j+1;
            cin >> matrix2[i][j];
        }
    }    

    int** resultMatrix1 = new int*[rows1];
    int** resultMatrix2 = new int*[rows2];
    for (int i = 0; i < rows1; i++)
    {
        resultMatrix1[i] = new int [cols1];
        resultMatrix2[i] = new int[cols2];
    }
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {                                                                   // calculating
            resultMatrix1[i][j] = matrix1[i][j] + matrix2[i][j];
            resultMatrix2[i][j] = matrix1[i][j] - matrix2[i][j];

        }
        
    }
    cout << "Sum of matrices:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << resultMatrix1[i][j] << " ";
        }
        cout << endl;                                           // Displaying results
    }
    cout << "subs of matrices:\n";
    for (int i = 0; i < rows2; i++) {                             
        for (int j = 0; j < cols2; j++) {
            cout << resultMatrix2[i][j] << " ";
        }
        cout << endl;
    } 

    for (int i = 0; i < rows1; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] resultMatrix1[i];                // Freeing space
        delete[] resultMatrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultMatrix1;
    delete[] resultMatrix2;
    return 0;       
     
}