#include "iostream"
using namespace std;

class AlarmSystem{
public: 
    string securitylevel;
    
    AlarmSystem(string Sl) : securitylevel(Sl) {
        cout<<"\n\nAlarm system created. \n Nothing can pass NorthEast Defence sector NEADS" << endl;
    };
    ~AlarmSystem(){ cout << "Alarm System destroyed!!! \n They turned off transponder, Connection lost! "; }

};

class SmartHome{
public: 
    AlarmSystem system1;
    
    SmartHome(string st) : system1(st) {
        cout << "Smart Home Created! \n WELCOME TO TWIN TOWER " << endl;
    };

    ~SmartHome(){
        cout <<"Smart house destroyed! \n Ops 9/11 " << endl; 
    }
};

int main(){

    SmartHome("high");
    SmartHome("Medium");

    return 0;
}