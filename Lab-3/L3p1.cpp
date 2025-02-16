/*
    Name:   Ali Akbar
    Roll No 24-0892
    Section 2C
    Qustion 1
*/  
#include "iostream"
using namespace std;

class wallet{
    private: 
        string ownerName; 
        int totalBalance;
        int trnasactionHistory[10]; 
    public: 
        wallet(string name){
            ownerName = name; 
            totalBalance = 0;
            for (int i = 0; i < 10; i++)
            {
                trnasactionHistory[i] = 0;
            }        
            cout << "This is constructor";    
        }
        int cashWithdraw(){
            cout << "Enter Amount to withdraw: ";
            int cash; 
            cin >> cash;
            if(cash > totalBalance){
                cout << "\nInsufficant Balance! ";
            }
            else{
                totalBalance = totalBalance - cash;
                for (int i = 0; i < 10; i++)
                {
                    if(trnasactionHistory[i] == 0){
                        trnasactionHistory[i] = cash - 2*cash; 
                        return 0;
                    }
                } 
            }
        }
        int depositCash(){
            cout << "\nEnter Amount to deposit: ";
            int cash;
            cin >> cash;
            totalBalance += cash;
            for (int i = 0; i < 10; i++)
            {
                if(trnasactionHistory[i] == 0){
                    trnasactionHistory[i] = cash;
                    return 0;
                }
            }
        }   
        
        void transactionHistory(){
            cout << "\nTotal Amount: ";
            cout << totalBalance;
            cout << "\nThis is previous 10 transactions: \n + = deposited cash, - = withdrawn cash: " << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << trnasactionHistory[i] << endl;
            }
            
        }
};

int main(){
    // cout << "Enter your name: ";
    string name; 
    // getline(cin , name);
    wallet w1(name);
    while (true)
    {
        cout << "\nTo enter withdraw cash, Press 1: ";
        cout << "\nTo enter cash, Press 2: ";
        cout <<"\nTo see Trasaction History, Press 3 ";
        cout << "\nTo exit, press 4: ";
        cout <<"\nEnter Choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            w1.cashWithdraw();
            break;
        case 2:
            w1.depositCash();
            break;
        case 3: 
            w1.transactionHistory();
            break;
        case 4: 
            return 0;                        
        default:
            break;
        }         
    }
    return 0;
}