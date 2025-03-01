#include "iostream"
using namespace std;

class Employee{
    public: 
        string name, designation;
        Employee(string n, string d) : name(n) , designation(d){} ;

        void displayEmployees(){
            cout << "Emplyee Name: " << name << "\t Designation: " << designation <<endl;
        }
    };

class Project{
    public: 
        string title , deadline;
        Employee* employees[10];
        int count = 0;
        Project(string t, string d) : title(t) , deadline(d){} ;

        void addEmployees(Employee* emp){
            employees[count++] = emp;
        }

        void displayProject(){
            cout << "\n\nProject Title: " << title << "\t Project Deadline: " << deadline << endl;
            cout <<"Assingned Employees: \n";
            for (int i = 0; i < count; i++) employees[i] -> displayEmployees();
        }   
        ~Project(){
            delete[] employees;
        }
    };

    int main(){
        Employee e1("Ch.RehmantAli" , "projectmanager"), e2("Hussain Sahurwardi" , "SoftwareEngnier") , e3("BachaKhan", "ProjectCoordinator");
        Project p1("AI Development" , "25-6-2025") , p2("cloud computing" , "14-4-2025");

        p1.addEmployees(&e1);
        p1.addEmployees(&e2);
        p2.addEmployees(&e1);
        p2.addEmployees(&e3);
        p1.displayProject();
        p2.displayProject();

        return 0;
    }



