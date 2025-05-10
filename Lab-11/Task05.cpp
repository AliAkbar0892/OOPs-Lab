#include "iostream"
#include "stdexcept"

using namespace std;

class InventoryException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "An inventory error occurred.";
    }
};

class NegativeStockException : public InventoryException {
};

class OverCapacityException : public InventoryException {
};

template <typename T>
class InventoryItem {
private:
    T stock;         
    T maxStockLimit; 

public:
    InventoryItem(T maxStockLimit) : maxStockLimit(maxStockLimit), stock(0) {}

    T getStock() const {
        return stock;
    }

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        }
        if (newStock > maxStockLimit) {
            throw OverCapacityException();  
        }
        stock = newStock; 
    }

    T getMaxStockLimit() const {
        return maxStockLimit;
    }
};

int main() {
    try {
        InventoryItem<int> item(100);
        cout << "Attempting to set stock to -5 ..." << endl;
        item.setStock(-5); 
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    } catch (const InventoryException& e) {
        cout << "Caught a general InventoryException - what(): " << e.what() << endl;
    }

    try {
        InventoryItem<int> item(100);
        cout << "Attempting to set stock to 120 (max 100) ..." << endl;
        item.setStock(120); 
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    } catch (const InventoryException& e) {
        cout << "Caught a general InventoryException - what(): " << e.what() << endl;
    }

    return 0;
}
