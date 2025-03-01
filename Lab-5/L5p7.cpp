#include <iostream>
#include <cstring>  
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;

    Product(){}

    Product(int Pid, string Pname, int Pquantity) : id(Pid) , name(Pname) , quantity(Pquantity) {};

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

// Function to sort products
void sortProducts(Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].name > products[j + 1].name) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}

// Function to search for a product by ID
void searchByID(Product products[], int count, int searchID) {
    for (int i = 0; i < count; i++) {
        if (products[i].id == searchID) {
            cout << "Product Found: ";
            products[i].display();
            return;
        }
    }
    cout << "Product with ID " << searchID << " not found.\n";
}

int main() {
    const int MAX_PRODUCTS = 5;
    Product inventory[MAX_PRODUCTS];

    cout << "Enter details for " << MAX_PRODUCTS << " products (ID Name Quantity):\n";
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        int id, quantity;
        string name;
        cin >> id >> name >> quantity;
        inventory[i] = Product(id, name, quantity);
    }

    sortProducts(inventory, MAX_PRODUCTS);
    cout << "\nSorted Inventory:\n";
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        inventory[i].display();
    }

    int searchID;
    cout << "\nEnter product ID to search: ";
    cin >> searchID;
    searchByID(inventory, MAX_PRODUCTS, searchID);

    return 0;
}
