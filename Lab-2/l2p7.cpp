/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 7
*/


#include <iostream>
using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> rows1 >> cols1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> rows2 >> cols2;
    if (cols1 != rows2) 
    {
        cout << "Matrix multiplication is not possible.\n";
        return 1;
    }

    int **matrix1 = new int *[rows1];
    int **matrix2 = new int *[rows2];
    int **result = new int *[rows1];
    for (int i = 0; i < rows1; i++)
    {
        matrix1[i] = new int[cols1];
    }    
    for (int i = 0; i < rows2; i++)
    {
        matrix2[i] = new int[cols2];
    }        
    for (int i = 0; i < rows1; i++)
    {
        result[i] = new int[cols2];
    }        
    cout << "Enter elements of first matrix " << rows1 << "x"<< cols1 <<endl;
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols1; j++){
            cin >> matrix1[i][j];
        }    
    }
    cout << "Enter elements of second matrix " << rows2 << "x" << cols2 <<endl;
    for (int i = 0; i < rows2; i++){
        for (int j = 0; j < cols2; j++){
            cin >> matrix2[i][j];
        }            
    }        

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "\nResultant Matrix " << rows1 << "x" << cols2 <<endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << result[i][j] << " ";
        }    
        cout << endl;
    }

    for (int i = 0; i < rows1; i++) delete[] matrix1[i];
    for (int i = 0; i < rows2; i++) delete[] matrix2[i];
    for (int i = 0; i < rows1; i++) delete[] result[i];

    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
    return 0;
}
