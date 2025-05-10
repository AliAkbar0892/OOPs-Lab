#include <iostream>
#include <fstream>
#include <cstring>  // for strncpy


struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem itemToSave;
    itemToSave.itemID = 101;
    std::strncpy(itemToSave.itemName, "SuperWidget", sizeof(itemToSave.itemName) - 1);
    itemToSave.itemName[sizeof(itemToSave.itemName) - 1] = '\0';  

    
    std::ofstream outFile("inventory.dat", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }
    outFile.write(reinterpret_cast<char*>(&itemToSave), sizeof(itemToSave));
    outFile.close();

    
    InventoryItem itemLoaded;
    std::ifstream inFile("inventory.dat", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&itemLoaded), sizeof(itemLoaded));
    inFile.close();

    std::cout << "Loaded Item ID: " << itemLoaded.itemID << "\n";
    std::cout << "Loaded Item Name: " << itemLoaded.itemName << "\n";

    return 0;
}
