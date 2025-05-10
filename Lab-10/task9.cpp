#include <iostream>
#include <fstream>

int main() {
    const std::string filename = "large_log.txt";

    {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error creating file.\n";
            return 1;
        }
        outFile << "Line1: System start\n";
        outFile << "Line2: Sensor active\n";
        outFile << "Line3: Logging ongoing\n";
        outFile.close();
    }

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    char buffer1[11] = {0};  
    inFile.read(buffer1, 10);
    std::cout << "First 10 characters: " << buffer1 << std::endl;
    std::streampos pos1 = inFile.tellg();
    std::cout << "Position after first read: " << pos1 << std::endl;

    char buffer2[11] = {0};
    inFile.read(buffer2, 10);
    std::cout << "Next 10 characters: " << buffer2 << std::endl;
    std::streampos pos2 = inFile.tellg();
    std::cout << "Position after second read: " << pos2 << std::endl;

    inFile.close();
    return 0;
}
