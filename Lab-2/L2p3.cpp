/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 3 
*/

#include "iostream"
#include "string"
using namespace std;

struct employeeRecord{
    string name;
    int hoursWorked;
    int hourlyRate;
    int totalSalary;
};

void inputEmployees(int n, employeeRecord* employees){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for Employee " << i + 1 << endl;
        cin.ignore();
        cout << "Name: ";
        getline(cin, employees[i].name);
        cout << "hoursWorked: ";
        cin >> employees[i].hoursWorked;
        cout << "hourlyRate: ";
        cin >> employees[i].hourlyRate;
    }  
        
}

void calculateSalary(int n, employeeRecord* employee){
    for (int i = 0; i < n; i++)
    {
        employee[i].totalSalary = employee[i].hourlyRate * employee[i].hoursWorked;
        cout << "\nName: " <<employee[i].name<< "\tSalary: "<<employee[i].totalSalary;
    }
    
}

int main(){
    int n;
    cout << "Enter Number of Employees: ";
    cin >> n;
    employeeRecord* employee = new employeeRecord[n];    
    while (true)
    {
        cout << "\nTo enter data, press 1: ";
        cout << "\nTo view data, press 2: ";
        cout << "\nTo Exit, press 3: ";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            inputEmployees(n, employee);
            break;
        case 2: 
            calculateSalary(n, employee);
            break;
        case 3:
            delete[] employee; 
            return 0;    
        default:
            break;
        }
    }    
}

