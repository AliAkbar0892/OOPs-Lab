#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

int main() {
    std::ifstream inputFile("vehicles.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file 'vehicles.txt'" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#' || (line.size() >= 2 && line[0] == '/' && line[1] == '/')) {
            continue;
        }

        std::istringstream ss(line);

        std::string type, id, name, year, extraData, certification;

        std::getline(ss, type, ',');
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, year, ',');
        std::getline(ss, extraData, ',');
        std::getline(ss, certification, ',');

        std::cout << "Type: " << type << "\n"
                  << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Year: " << year << "\n"
                  << "ExtraData: " << extraData << "\n"
                  << "Certification: " << certification << "\n"
                  << "------------------------" << std::endl;
    }

    inputFile.close();
    return 0;
}
