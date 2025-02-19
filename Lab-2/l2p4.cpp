/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 4
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); 

    string *strings = new string[n];

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, strings[i]);
    }

    sort(strings, strings + n);

    cout << "\nSorted strings:\n";
    for (int i = 0; i < n; i++) {
        cout << strings[i] << endl;
    }

    delete[] strings;

    return 0;
}
