/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 5
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    cout << "Sum of array elements: " << sum << endl;
    delete[] arr;
    return 0;
}
