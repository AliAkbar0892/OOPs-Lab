/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 9
*/

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};

int main() {
    int numProducts;

    cout << "Enter the number of products: ";
    cin >> numProducts;
    Product *inventory = new Product[numProducts];
    cout << "Enter details for " << numProducts << " products:\n";
    for (int i = 0; i < numProducts; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Product ID: ";
        cin >> inventory[i].productID;
        cin.ignore();
        cout << "Name: ";
        getline(cin, inventory[i].name);
        cout << "Quantity: ";
        cin >> inventory[i].quantity;
        cout << "Price: ";
        cin >> inventory[i].price;
    }
    double totalValue = 0;
    for (int i = 0; i <= numProducts; i++) 
    { 
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    cout << "\nProduct Inventory:\n";
    for (int i = 0; i < numProducts; i++)
    {
        cout << "ID: " << inventory[i].productID
             << ", Name: " << inventory[i].name
             << ", Quantity: " << inventory[i].quantity
             << ", Price: " << inventory[i].price
             << ", Total: " << inventory[i].quantity * inventory[i].price << endl;
    }

    cout << "\nTotal Inventory Value: " << totalValue << endl;
    delete[] inventory;
    return 0;
}
