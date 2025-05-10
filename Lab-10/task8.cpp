#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string filename = "config.txt";

    {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error creating file.\n";
            return 1;
        }
        outFile << "AAAAABBBBBCCCCC"; 
        outFile.close();
    }

    {
        std::fstream file(filename, std::ios::in | std::ios::out);
        if (!file) {
            std::cerr << "Error opening file for update.\n";
            return 1;
        }

        file.seekp(5);
        file << "XXXXX";  

        file.close();
    }

    {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error reading file.\n";
            return 1;
        }

        std::string content;
        std::getline(inFile, content);
        std::cout << "File content after update: " << content << std::endl;

        inFile.close();
    }

    return 0;
}
