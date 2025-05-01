#include "iostream"
using namespace std;

class Manager; // forward develeration

class Account{
    int AccountNumber;
    int balance;
public: 
    Account(int AN, int b) : AccountNumber(AN) , balance(b) {};
    friend class Manager;
    friend void transferFunds(Account& acc2, Account& acc1, int transferingamount);
};

void transferFunds(Account& acc2, Account& acc1 , int transferingamount){
    if (transferingamount > acc1.balance){
        cout << "Insufficent balance, can't Transfer Funds." <<endl;
    }
    else{
        acc2.balance = transferingamount;
        acc1.balance -= transferingamount;
    }
}

class Manager{
public: 
    int changeAccountDetails(Account& accountobj , int deposit , int withdraw){
        cout << "Account Number: " << accountobj.AccountNumber<< endl;
        cout << "Total Balance: " << accountobj.balance<< endl;
        accountobj.balance += deposit;
        if(withdraw > accountobj.balance){
            cout << "Insufficent Funds" << endl;
        }
        else{
            accountobj.balance -= withdraw;
            return withdraw;
        }
    }
};

int main(){
    Account account1(36201 , 56000);
    Account account2(36202, 20000);
    Manager m1;
    m1.changeAccountDetails(account1 , 10000 , 5000);
    transferFunds(account2 , account1, 2000);
}