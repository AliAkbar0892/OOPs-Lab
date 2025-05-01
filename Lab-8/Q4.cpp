#include "iostream"
#include "string"
using namespace std;

class Car; // Forward declaration 

// Friend function declaration
void comparePrice(const Car& car1, const Car& car2);

class Car {
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {};

    friend class InventoryManager;

    friend void comparePrice(const Car& car1, const Car& car2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
    }
    void displayCar(const Car& car) {
        cout << "Model: " << car.model << ", Price: $" << car.price << endl;
    }
};

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price)
        cout << car1.model << " is more expensive than " << car2.model << "." << endl;
    else if (car1.price < car2.price)
        cout << car2.model << " is more expensive than " << car1.model << "." << endl;
    else
        cout << car1.model << " and " << car2.model << " are priced equally." << endl;
}

int main() {
    Car car1("Toyota Camry", 30000);
    Car car2("Honda Accord", 28000);

    InventoryManager manager;

    cout << "Initial car details:" << endl;
    manager.displayCar(car1);
    manager.displayCar(car2);

    manager.updatePrice(car2, 32000); 

    cout << "\nAfter price update:" << endl;
    manager.displayCar(car1);
    manager.displayCar(car2);

    cout << "\nPrice comparison:" << endl;
    comparePrice(car1, car2);

    return 0;
}
