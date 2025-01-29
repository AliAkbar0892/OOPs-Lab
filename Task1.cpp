
/*  Name:  Ali Akbar 
    Section: 2C
    Roll No. : 24k-0892 
    HomeWork TASK
*/    

#include "iostream"
using namespace std;

float cityAqi[4][7] = {
    {234,342,45,454,343,23,43},
    {34,234,234,32,34,234,543},
    {32,43,23,43,345,43,23},
    {342,234,43,23,34,234,452}
};

int AQIinput(){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << "Enter AQI of City" << i+1 << " Day" << j+1 <<": ";
            cin >> cityAqi[i][j];
        }
        cout << endl;
    }
    return 0;
} 

float weeklyAVG[4];

int averageAQI(){
    float avg[4];

    for (int i = 0; i < 4; i++)
    {
        float sum = 0;
        for (int j = 0; j < 7; j++)
        {
            sum = sum + cityAqi[i][j];
        }
        avg[i] = sum / 7;
        weeklyAVG[i] = avg[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cout << "Average AQI of City" << (i+1) << " is: " << avg[i] << endl;
    } 
    float maxAQI[1]; 
    maxAQI[0] = avg[0];
    maxAQI[1] = 1; 
    for (int i = 1; i < 4; i++)
    {
        if(avg[i] > maxAQI[0]){
            maxAQI[0] = avg[i];
            maxAQI[1] = i;
        }
    }
    cout << "City" << maxAQI[1] << " has the worst AQI of " << maxAQI[0] << endl;
}

int criticalDs[4][7];

int criticalDays(){
    int c = 0; 
    int d = 0;
    cout << "Critical Days: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (cityAqi[i][j]>150)
            {
                cout << "       => City"<< i+1 << " Day"<< j+1 << "     Ciritcal AQI: "<<cityAqi[i][j]<< endl;
                for (; c < 7 && d < 7; c++ , d++ )
                {
                    criticalDs[c][d] = cityAqi[i][j];
                }
                
            }
            
        }
        cout << endl;
    }    
}

void visualRep() {
    for (int i = 0; i < 4; i++) {
        cout << "   City" << i + 1 << "     ";
        int starCount = 0; 
        for (int j = 0; j < 7; j++)
        {
            starCount += cityAqi[i][j] / 50; 
        }
        for (int k = 0; k < starCount; k++) 
        {
            cout << "* ";
        }

        cout << endl;
    }
}

int monthlyAQI[4][28] = {
    {234, 342, 45, 454, 343, 23, 43, 150, 267, 189, 420, 378, 332, 415, 125, 278, 90, 50, 210, 390, 410, 399, 275, 321, 198, 305, 280, 350},  
    {34, 234, 234, 32, 34, 234, 543, 200, 145, 377, 321, 267, 289, 344, 212, 278, 365, 123, 98, 210, 315, 450, 398, 410, 275, 250, 220, 400},  
    {32, 43, 23, 43, 345, 43, 23, 110, 176, 298, 420, 389, 410, 325, 289, 310, 278, 225, 199, 267, 312, 408, 390, 410, 320, 335, 290, 410},  
    {342, 234, 43, 23, 34, 234, 452, 270, 245, 289, 365, 321, 289, 345, 412, 298, 356, 178, 123, 367, 320, 410, 405, 380, 255, 260, 300, 370}  
};

int monthlyInput(){

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            cout << "Enter AQI of City" << i+1 << " Day" << j+1 <<": ";       // Input
            cin >> monthlyAQI[i][j];
        }
        cout << endl;
    }

}

int monthlyAverage(){
    float avg[4];

    for (int i = 0; i < 4; i++)
    {
        float sum = 0;
        for (int j = 0; j < 28; j++)
        {
            sum = sum + monthlyAQI[i][j];
        }
        avg[i] = sum / 28;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << "Average AQI of City" << (i+1) << " is: " << avg[i] << endl;
    } 
}

int changeAQI(){
    float avg1;
    float avg2;

    float impAvg[4];

    for (int i = 0; i < 4; i++)
    {
        float sum = 0;
        for (int j = 0; j < 7; j++)
        {
            sum = sum + monthlyAQI[i][j];
        }
        avg1 = sum / 7;
        sum = 0;
        for (int k = 21; k < 28; k++)
        {
            sum = sum + monthlyAQI[i][k];
        }
        avg2 = sum / 7;
        impAvg[i] = avg1 - avg2;

        cout << "Increase / Decrease in Air Quality of City" << i+1 << " is: " << impAvg[i] << endl;
    }

    float maxDrop[1]; 
    maxDrop[0] = impAvg[0];
    maxDrop[1] = 1; 
    for (int i = 1; i < 4; i++)
    {
        if(impAvg[i] > maxDrop[0]){
            maxDrop[0] = impAvg[i];
            maxDrop[1] = i;
        }
    }
    cout << "City" << maxDrop[1] << " has the Largest Drop of AQI of " << maxDrop[0] << endl;    

}

int main()
{
    cout << " Welcome to AQI Tracker " << endl;
    cout << " For Weekly AQI Data, Press 1: " << endl;
    cout << " For monthly AQI Data, Press 2: "<< endl;
    cout << " For Summery Report, Press 3: "<< endl;
    cout << " Enter Choice : ";
    int choice1;
    cin >> choice1;
    if (choice1 == 1){
        cout << "If you want to Input Weekly AQI of Cities, Press 0"<< endl << "Otherwise skip, Program can run on sample data.";
        int choice2;
        cout << "For average, Press 1: " << endl;
        cout << "For Critical Pollution days, Press 2: "<< endl;
        cout << "For Visual repersentation, Press 3: "<< endl;
        cout << "For monthly AQI comparison, Press 4"<< endl;
        cout << "Enter Choice : ";
        cin >> choice2 ;
        if(choice2 == 0){
            AQIinput(); 
        }
        switch (choice2){
            case 1:
                averageAQI();           // TASK 1
                break;
            case 2:
                criticalDays();         // TASK 2
                break;
            case 3:
                visualRep();            // TASK 3
                break;
            default:
                break;    
        }
    }
    else if(choice1 == 2){
        cout << "If you want to Input monthly AQI of Cities, Press 0"<< endl << "Otherwise skip, Program can run on sample data."<<endl;
        cout << "For average, Press 1: " << endl;
        cout << "For AQI change, Press 2: "<< endl;
        cout << "Enter Choice : ";
        int choice3;
        cin >> choice3;
        if (choice3 == 0)
        {
            monthlyInput(); 
        }
        switch (choice3)
        {
        case 1:
            monthlyAverage();
            break;
        case 2: 
            changeAQI();
        default:
            break;
        }   
    }
    else if(choice1 == 3){
        cout << "Weekly average for each city: " <<endl;
        for (int i = 0; i < 4; i++)
        {
            cout << " City" << i+1 << " : " << weeklyAVG[i] << ".    ";
        }
        cout << "Critical Pollution Days FOr each city: "<< endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << " City" << i+1 << " Day" << j+1 << "  : " << criticalDs[i][j];
            }   
        }
        cout << "Highest and Lowest AQI values recoreded during month: ";
        int highest[1], lowest[1];
        for (int i = 0; i < 4; i++) {
            highest[0] = monthlyAQI[i][0];  
            lowest[0] = monthlyAQI[i][0];  
            highest[1] = 0;   
            lowest[1] = 0; 
            for (int j = 1; j < 28; j++) {
                if (monthlyAQI[i][j] > highest[0]) {
                    highest[0] = monthlyAQI[i][j];
                    highest[1] = j;
                }
                if (monthlyAQI[i][j] < lowest[0]) {
                    lowest[0] = monthlyAQI[i][j];
                    lowest[1] = j;
                }
            }
            cout << "City" << i + 1 << ": " << endl;
            cout << "Highest AQI: " << highest[0] << " On Day" << highest[1] + 1 << endl;
            cout << "Lowest AQI: " << lowest[0] << " On day " << lowest[1] + 1 << endl;
        }
    }
}            
    

