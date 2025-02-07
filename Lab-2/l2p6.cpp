/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 6 
*/

#include "iostream"
#include "string"
using namespace std;

struct studentsRecords{
    string name;
    int rollNo;
    int marks[3];
    float avgMarks;
};

void inputStidents(int n, studentsRecords* students){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for Studenst " << i + 1 << endl;
        cin.ignore();
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll No. : ";
        cin >> students[i].rollNo;
        cout << "Marks in subject 1: ";
        cin >> students[i].marks[0];
        cout << "Marks in subject 2: ";
        cin >> students[i].marks[1];
        cout << "Marks in subject 3: ";
        cin >> students[i].marks[2];                
    }  
        
}
void averageMarks(int n, studentsRecords* students){
    for (int i = 0; i < n; i++)
    {
        students[i].avgMarks = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3;  
    }
    
}

void displayMarks(int n, studentsRecords* students){
    for (int i = 0; i < n; i++)
    {
        cout <<"\nName: " <<students[i].name<<"\nRoll No. :  " << students[i].rollNo << "\nAverage Marks: " << students[i].avgMarks;
    }
    
}

int main(){
    int n;
    cout << "Enter Number of Employees: ";
    cin >> n;
    studentsRecords* students = new studentsRecords[n];   
    inputStidents(n, students);
    averageMarks(n, students);
    displayMarks(n, students);
    delete[] students;
}