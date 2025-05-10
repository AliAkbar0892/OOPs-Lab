#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("vehicles.txt"); 

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file 'vehicles.txt'" << endl;
        return 1; 
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#' || (line.size() >= 2 && line[0] == '/' && line[1] == '/')) {
            continue;
        }

        cout << line << endl;
    }

    inputFile.close(); 
    return 0;
}
