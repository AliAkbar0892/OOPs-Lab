#include <iostream>
#include <cstring>  

using namespace std;

class Apartment {
private:
    int id;
    string address;
    char* ownerName;

public:
    Apartment(int id, string address, char* owner) : id(id), address(address) {
        ownerName = new char[strlen(owner) + 1]; 
        strcpy(ownerName, owner); 
    }

    Apartment(Apartment& other) : id(other.id), address(other.address) {
        this->ownerName = other.ownerName; 
    }

    void display() const {
        cout << "Apartment ID: " << id << "\nAddress: " << address << "\nOwner: " << ownerName << endl;
    }

    ~Apartment() {
        delete[] ownerName; 
    }
};

int main() {
    Apartment apt1(101, "Sharah-e-Faisal", "ChaudaryAli");
    apt1.display();

    Apartment apt2 = apt1;  
    apt2.display(); 

    return 0;
}
