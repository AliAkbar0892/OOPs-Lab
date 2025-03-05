/*  
    Name:       Ali AKbar
    Roll No:    24k-0892
    Section:    BCS-2C
    Question:   4 
        Ramadam Mubarak :)
*/
#include "iostream"
using namespace std; 

class Account{
public: 
    int accountNumber;
    float balance;
    Account(int n, float b) : accountNumber(n) , balance(b){};
    void displayDetails(){
        cout << "Account Number: " << accountNumber << " Balance: " << balance;
    }    
};

class SavingsAccount : public Account{
public: 
    float interestRate;
    SavingsAccount(int n, float b, float r) : Account(n ,b) , interestRate(r) {};
    void displayDetails(){
        Account :: displayDetails();
        cout << " Interest Rate: " << interestRate <<endl << endl;
    }
};

class CheckingAccount : public Account{
public: 
    float overdraftLimit;
    CheckingAccount(int n, float b, float o) : Account(n , b) , overdraftLimit(o) {};
    void displayDetails(){
        Account :: displayDetails();
        cout << " Overdraft Limit: " << overdraftLimit <<endl << endl;        
    }        
};

int main(){

    SavingsAccount account1(12345 , 5600.0 , 26.7);
    account1.displayDetails();

    CheckingAccount account2(67890, 7600.0 ,364.3);
    account2.displayDetails();

    return 0;
}