/*  
    Name:       Ali AKbar
    Roll No:    24k-0892
    Section:    BCS-2C
    Question:   2 
        Ramadam Mubarak :)
*/
#include "iostream"
using namespace std;

class vehicle{
public: 
    string brand;
    int speed;
    vehicle(string n, int s) : brand(n) , speed(s){};
    void displayDetails(){
        cout << "Brand Name: " << brand << " \tTotal Speed: " << speed;    }

};

class car : public vehicle{
public: 
    int seats;
    car(string n, int s, int b) : vehicle(n, s), seats(b) {}; 
    void displayDetails(){
        vehicle :: displayDetails();
        cout << "\tTotal Seats: " << seats;
    }
};

class electricCar : public car{
public: 
    electricCar(string n, int s, int b) : car(n,  s,  b) {}; 
    void displayDetails(){
        car :: displayDetails();
    }
};

int main(){
    electricCar m1("Tesla", 100, 4);
    m1.displayDetails();
    return 0 ;
}