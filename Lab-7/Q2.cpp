#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double productPrice;
    int stockQuantity;

public:
    Product(int id, string name, double pr, int stock = 0) : productID(id), productName(name), productPrice(pr), stockQuantity(stock) {}

    virtual void applyDiscount(double discountPercentage) {
        productPrice -= (productPrice * discountPercentage / 100.0);
    }

    virtual double calculateTotalPrice(int quantity) {
        return productPrice * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "Product ID: " << productID << "\n"<< "Product Name: " << productName << "\n"<< "Price: $" << productPrice << "\n"<< "Stock Quantity: " << stockQuantity << "\n";
    }

    friend double operator+(const Product& p1, const Product& p2) {
        return p1.productPrice + p2.productPrice;
    }

    friend ostream& operator<<(ostream& os, const Product& product) {
        os << "Product ID: " << product.productID << "\n"
           << "Product Name: " << product.productName << "\n"
           << "Price: $" << product.productPrice << "\n";
        return os;
    }
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double pr, int stock, int warranty, string br): Product(id, name, pr, stock), warrantyPeriod(warranty), brand(br) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Warranty Period: " << warrantyPeriod << " months\n"<< "Brand: " << brand << "\n";
    }
};

class Clothing : public Product {
    string size, color, fabricMaterial;

public:
    Clothing(int id, string name, double pr, int stock, string sz, string clr, string fabric) : Product(id, name, pr, stock), size(sz), color(clr), fabricMaterial(fabric) {}

    void applyDiscount(double discountPercentage) override {
        double seasonalDiscount = 5.0; // Example discount
        Product::applyDiscount(discountPercentage + seasonalDiscount);
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size << "\n" << "Color: " << color << "\n" << "Fabric Material: " << fabricMaterial << "\n";
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double pr, int stock, string expDate, int cal) : Product(id, name, pr, stock), expirationDate(expDate), calories(cal) {}

    double calculateTotalPrice(int quantity) override {
        double total = Product::calculateTotalPrice(quantity);
        if (quantity > 10) { 
            total *= 0.9; // 10% discount  
        }
        return total;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Expiration Date: " << expirationDate << "\n" << "Calories: " << calories << "\n";
    }
};

class Book : public Product {
    string author, genre;

public:
    Book(int id, string name, double pr, int stock, string auth, string gen) : Product(id, name, pr, stock), author(auth), genre(gen) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author << "\n" << "Genre: " << genre << "\n";
    }
};

int main() {
    Electronics laptop(101, "Laptop", 1200.0, 10, 24, "Dell");
    Clothing tshirt(201, "T-Shirt", 20.0, 50, "M", "Blue", "Cotton");
    FoodItem apple(301, "Apple", 2.0, 100, "2025-01-01", 95);
    Book novel(401, "Novel", 15.0, 30, "Author Name", "Fiction");

    laptop.displayProductInfo();
    cout << endl;

    tshirt.applyDiscount(10.0);
    tshirt.displayProductInfo();
    cout << endl;

    cout << "Total Price for 15 apples: $" << apple.calculateTotalPrice(15) << "\n";
    cout << endl;

    novel.displayProductInfo();
    cout << endl;

    return 0;
}
