/*
    Name:   Ali Akbar
    Roll No 24-0892
    Section 2C
    Qustion 2
*/ 
#include "iostream"
using namespace std;

class fitnessTracker{
    private: 
        string userName; 
        int dailyStepGoals;
        int stepsTakken;
        int caloriesBurned;
        int progress[10];
    public: 
        fitnessTracker(string name){
            userName = name;
            dailyStepGoals = 100;
            stepsTakken = 0;
            caloriesBurned = 0;
            for (int i = 0; i < 10; i++)
            {
                progress[i] = 0;
            }
        }
        void logsSteps(){
            cout << "\nEnter steps takken today: ";
            cin >> stepsTakken;
            cout << "\nYour Daily Goal: " <<dailyStepGoals;
            cout << "\nYour Steps: "<<stepsTakken; 
            if(stepsTakken >= dailyStepGoals){
                cout << "\nDaily Goal Completed! ";
            }           
        }
        void changeGoals(){
            cout << "\nCurrent Daily goal: " <<dailyStepGoals;
            cout << "\nEnter New daily Goal: ";
            cin >> dailyStepGoals;
        }
        void calculateCaloriesBurned(){
            cout << "\nEnter Your Weight in kg";
            int weight;
            cin >> weight;
            int calories_per_steps = 0.05 * weight;
            caloriesBurned = calories_per_steps * stepsTakken;
            for (int i = 0; i < 10; i++)
            {
                progress[i] = caloriesBurned;
            }
        }
        void seeProgress(){
            cout << "\nProgress over last 10 days: ";
            for (int i = 0; i < 10; i++)
            {
                cout << progress[i] <<endl;
            }
            
        }

};

int main(){
    cout << "Enter your name: ";
    string name; 
    getline(cin , name);
    fitnessTracker f1(name);
    while (true)
    {
        cout << "\nTo enter steps takken today, Press 1: ";
        cout << "\nTo change daily step goals, Press 2: ";
        cout << "\nTo see Calories burned, Press 3: ";
        cout << "\nTo see Progress, Press 4: ";
        cout << "\nPress 5 to exit. ";
        cout << "\nEnter Choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            f1.logsSteps();
            break;
        case 2:
            f1.changeGoals();
            break;            
        case 3: 
            f1.calculateCaloriesBurned();
            break;
        case 4:
            f1.seeProgress();
            break;
        case 5: 
            return 0;                        
        default:
            break;
        }
    }
    
}  