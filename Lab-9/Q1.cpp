#include "iostream"
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;

    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() override {
        cout << "In-Patient Treatment for " << name << " (ID: " << id << ")\n";
        cout << "Includes: Surgery, Hospital Stay, Medication.\n";
    }

    double calculateCost() override {
        double cost = 10000.0;
        cout << "Total Cost for In-Patient: $" << cost << endl;
        return cost;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() override {
        cout << "Out-Patient Treatment for " << name << " (ID: " << id << ")\n";
        cout << "Includes: Consultation, Lab Tests, Medication.\n";
    }

    double calculateCost() override {
        double cost = 2000.0;
        cout << "Total Cost for Out-Patient: $" << cost << endl;
        return cost;
    }
};

int main() {
    InPatient ip("Ali", "IP786");
    OutPatient op("Bob", "OP584");

    ip.displayTreatment();
    ip.calculateCost();
    cout << "-------------------------\n";
    op.displayTreatment();
    op.calculateCost();

    return 0;
}
