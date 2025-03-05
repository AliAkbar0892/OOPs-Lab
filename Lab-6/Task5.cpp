/*  
    Name:       Ali AKbar
    Roll No:    24k-0892
    Section:    BCS-2C
    Question:   5 
        Ramadam Mubarak :)
*/
#include "iostream"
using namespace std;

class Device{
public: 
    int deviceID;
    bool status;
    Device(int id, bool s) : deviceID (id) , status (s) {};
    void displayDetails(){
        cout << " DeviceID: " << deviceID <<endl<< " Status" << status <<endl ;
    }    
};

class SmartPhone : public Device{
public: 
    float screenSize;
    SmartPhone(int id, bool s, float sz) : Device (id , s), screenSize (sz) {};
    void displayDetails(){
        Device :: displayDetails();
        cout << " Screen Size: " << screenSize <<endl;
    }
};

class smartWatch : public SmartPhone{
public: 
    bool heartRateMonitor; 
    smartWatch(int id, bool s, float sz , bool hrM) : SmartPhone(id , s, sz) , heartRateMonitor(hrM) {};
    void displayDetails(){
        SmartPhone :: displayDetails();
        cout << " Heart Rate Monitor Status: " << heartRateMonitor <<endl;
    }    
};

class SmartWearable : public smartWatch{
public: 
    int stepCounter;
    SmartWearable(int id, bool s, float sz , bool hrM, int sc) : smartWatch(id, s, sz , hrM) , stepCounter(sc) {};
    void displayDetails(){
        smartWatch :: displayDetails();
        cout << " Step Counted: " << stepCounter << endl << endl;
    }
};

int main(){

    SmartWearable smart1 (73849, true , 4.2 , false , 100);
    smart1.displayDetails();

    return 0;
}