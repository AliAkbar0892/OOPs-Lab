/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 8
*/

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int **arr = new int *[size];

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) 
    {
        arr[i] = new int; 
        cin >> *arr[i];  
    }

    cout << "\nArray elements: ";
    for (int i = 0; i < size; i++) 
    {
        cout << *arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        delete arr[i]; 
    }
    delete[] arr; 
    return 0;
}
