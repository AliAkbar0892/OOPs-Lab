#include "iostream"
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p) : dishName(name), price(p) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double p) : MenuItem(name, p) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << " Price: " << price << endl;
    }

    void prepare() override {
        cout << "Preparing appetizer: " << dishName <<endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double p) : MenuItem(name, p) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << " Price: " << price << endl;
    }

    void prepare() override {
        cout << "Preparing main course: " << dishName <<endl;
    }
};

int main() {
    MenuItem* menu[2];

    menu[0] = new Appetizer("Garlic Bread", 4.99);
    menu[1] = new MainCourse("Beef Steak", 17.49);

    for (int i = 0; i < 2; i++) {
        menu[i]->showDetails();
        menu[i]->prepare();
        cout << "-----------------------\n";
    }

    for (int i = 0; i < 2; i++) {   // freeeing spcae
        delete menu[i];
    }

    return 0;
}
