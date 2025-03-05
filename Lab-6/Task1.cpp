/*  
    Name:       Ali AKbar
    Roll No:    24k-0892
    Section:    BCS-2C
    Question:   1 
        Ramadam Mubarak :)
*/
#include "iostream"
using namespace std;

class Employee{
public: 
    string name;
    float salary;
    Employee(string n, float s) : name(n) , salary(s){};
    void displayDetails(){
        cout << "Employee Name: " << name << " \tEmployee Salary: ";   }

};

class manager : public Employee{
public: 
    float bonus;
    manager(string n, float s, float b) : Employee(n, s), bonus(b) {}; 
    void displayDetails(){
        Employee :: displayDetails();
        cout << "\tManager bonus: " << bonus;
    }
};

int main(){
    manager m1("Ali Butt", 70000.0, 10000.0);
    m1.displayDetails();
    return 0 ;
}