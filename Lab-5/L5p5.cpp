#include <iostream>
using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    int experience;

    Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}

    void display() const {
        cout << "Dr. " << name << " (" << specialization << ", " << experience << " years experience)\n";
    }
};

class Hospital {
public:
    string hospitalName;
    Doctor* doctors[10]; 
    int doctorCount = 0;

    Hospital(string name) : hospitalName(name) {}

    void addDoctor(Doctor* doc) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = doc; 
        } else {
            cout << "Cannot add more doctors, limit reached!\n";
        }
    }

    void displayHospital() const {
        cout << " Hospital: " << hospitalName << "\nDoctors:\n";
        for (int i = 0; i < doctorCount; i++) {
            doctors[i]->display();
        }
    }
};

int main() {

    Doctor d1("Ibrahim Lodhi", "Cardiology", 15);
    Doctor d2("Zaheer ud din Baber", "Neurology", 10);
    Doctor d3("Rana Sangha", "Orthopedics", 8);

    Hospital h1("Pani Patt Hospital ");
    Hospital h2("khanwa Medical Center");

    h1.addDoctor(&d1);
    h1.addDoctor(&d2);
    h2.addDoctor(&d3);

    h1.displayHospital();
    h2.displayHospital();

    return 0;
}
