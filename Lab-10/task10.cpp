#include "iostream"
#include "fstream"

int main() {
    const std::string filename = "data_records.txt";

    {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error creating file.\n";
            return 1;
        }
        outFile << "Record 1\n";
        outFile << "Record 2\n";
        outFile << "Record 3\n";
        outFile << "Record 4\n";
        outFile.close();
    }

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }

    std::streampos offset = 18; 

    inFile.seekg(offset, std::ios::beg);
    if (!inFile) {
        std::cerr << "seekg failed.\n";
        return 1;
    }

    std::string record;
    std::getline(inFile, record);
    std::cout << "Third record: " << record << std::endl;

    inFile.close();
    return 0;
}
