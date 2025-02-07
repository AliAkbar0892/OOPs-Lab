#include <iostream>
#include <string>
using namespace std;

void collectParticipants(string participants[], int maxParticipants, string eventName) {
    cout << "Enter names of participants for the " << eventName << ":" << endl;
    for (int i = 0; i < maxParticipants; i++) {
        cout << "Participant " << i + 1 << ": ";
        getline(cin, participants[i]);
    }
}

void isRegistered(string event1[], string event2[]) {

    string nameToCheck;
    cout << "\nEnter a participant's name to check registration: ";
    getline(cin, nameToCheck);

    for (int i = 0; i < 5; i++) {
        if (event1[i] == nameToCheck) {
            cout << nameToCheck << " is registered in either of the Events." << endl;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (event2[i] == nameToCheck) {
            cout << nameToCheck << " is not registered in either of the Events." << endl;
        }
    }
    
}

int calculateDonation(string event1[], string event2[], int maxParticipants) {
    const int donationAmount = 10;
    int totalDonation = 0;

    for (int i = 0; i < maxParticipants; i++) {
        if (!event1[i].empty()) {
            totalDonation += donationAmount;
        }
    }
    for (int i = 0; i < maxParticipants; i++) {
        if (!event2[i].empty()) {
            totalDonation += donationAmount;
        }
    }
    cout << "\nTotal donation amount collected from both events: $" << totalDonation << endl;
    return 0;
}

void reverseString(string &str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

void displayParticipantsInReverse(string participants[], int maxParticipants, string eventName) {
    cout << "Participants for " << eventName << " in reverse name order:" << endl;
    for (int i = 0; i < maxParticipants; i++) {
        reverseString(participants[i]);  // Reverse the name
        cout << participants[i] << endl;
        reverseString(participants[i]);  // Reverse back to the original for further use
    }
}

void displayBarChart(string event1[], string event2[], int maxParticipants) {
    int count1 = 0, count2 = 0;

    for (int i = 0; i < maxParticipants; i++) {
        if (!event1[i].empty()) {
            count1++;
        }
    }
    for (int i = 0; i < maxParticipants; i++) {
        if (!event2[i].empty()) {
            count2++;
        }
    }

    cout << "\nEvent 1 Bar Chart: ";
    for (int i = 0; i < count1; i++) {
        cout << "* ";
    }
    cout << "\nTotal Participants: " << count1 << endl;

    cout << "Event 2 Bar Chart: ";
    for (int i = 0; i < count2; i++) {
        cout << "* ";
    }
    cout << "\nTotal Participants: " << count2 << endl;
}

int main() {

    string event1[5], event2[5];

    cout << "Event Managment System"<< endl;
 
    while (true)
    {
        cout << "To enter Names for events, Press 1: " << endl;
        cout << "TO Chech if a participant is registered, Press 2: " << endl;
        cout << "To Calculate Total donations, PRess 3: " << endl;
        cout << "TO display name in reverse, Press 4: " << endl;
        cout << "TO see bar chart, Press 5: " << endl;
        cout << "To Exit, Press 6: " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            collectParticipants(event1 , 5, "Event 1");
            collectParticipants(event2 , 5, "Event 2");
            break;
        case 2:
            isRegistered(event1, event2);
            break;    
        case 3: 
            calculateDonation(event1 , event2, 5);
        case 4:
            displayParticipantsInReverse(event1 , 5, "Event 1");
            displayParticipantsInReverse(event2 , 5, "Event 2");
            break;
        case 5: 
            displayBarChart(event1 , event2 , 5);
            break;
        case 6:
            return 0;            
        default:
            break;
        }
    }    
}
