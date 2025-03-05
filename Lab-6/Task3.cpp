/*  
    Name:       Ali AKbar
    Roll No:    24k-0892
    Section:    BCS-2C
    Question:   3 
        Ramadam Mubarak :)
*/
#include "iostream"
using namespace std;

class Person{
public: 
    string name;
    int age;
    Person(string n, int s) : name(n) , age(s){};
    void displayDetails(){
        cout << "Name: " << name << " \n Age: " << age;    }

};

class Teacher : public Person{
public: 
    string subject;
    Teacher(string n, int s, string sub) : Person(n, s), subject(sub) {}; 
    void displayDetails(){
        Person :: displayDetails();
        cout << "\nSubject: " << subject;
    }
};

class Resercher : public Person{
public: 
    string researchArea;
    Resercher(string n, int s, string Ra): Person(n, s), researchArea(Ra) {}; 
    void displayDetails(){
        Person :: displayDetails();
        cout << "\nResearch Area: " << researchArea;
    }
    void displayResearch(){
        cout << "\nReasearch Area: " << researchArea <<endl;
    }
};

class Professor : public Teacher , public Resercher{
public:     
    int publications; 
    Professor(string n, int s, string sub, string Ra, int pub) : Teacher(n, s, sub) , Resercher(n, s, Ra) , publications(pub){};
    void displayDetails(){
        Teacher :: displayDetails();
        Resercher :: displayResearch();
    }

}; 

int main(){
    Professor p1("Butt Sahab", 40 , "Physics" , "QuantamPhysics" , 100);
    p1.displayDetails();
    return 0 ;
}