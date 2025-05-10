#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file 'sensor_log.txt'\n";
        return 1;
    }

    string sensorData1 = "Temperature: 24.5C\n";
    outFile << sensorData1;
    streampos pos1 = outFile.tellp();
    cout << "After writing first line, put pointer at: " << pos1 << endl;

    string sensorData2 = "Humidity: 60%\n";
    outFile << sensorData2;
    streampos pos2 = outFile.tellp();
    cout << "After writing second line, put pointer at: " << pos2 << endl;

    outFile.close();
    return 0;
}
