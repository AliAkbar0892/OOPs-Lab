/*
    Name        Ali Akbar 
    Section     2C
    Roll No     24k-0892
    Problem No. 1 
*/

#include "iostream"
#include "string"
using namespace std;

struct library{
    string title;
    string arthor;
    int year;
};


void inputBooks(int n, library* books){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for book " << i + 1 << endl;
        cin.ignore();
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].arthor);
        cout << "Year: ";
        cin >> books[i].year;
    }  

    // for (int i = 0; i < n; i++) {
    //     cout << "Book " << i + 1 << ": " << endl;
    //     cout << "Title: " << books[i].title << endl;
    //     cout << "Author: " << books[i].arthor << endl;
    //     cout << "Year: " << books[i].year << endl;
    // }
        
}

void displayBooks(int n, library* books){
    cout << "Enter Year For Books search" << endl;
    int y;
    cin >> y;
    for (int i = 0; i < n; i++)
    {
        if (y >= books[i].year)
        {
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].arthor << endl;
            cout << "Year: " << books[i].year << endl;
        }
    }
    
}

int main(){
    int n;
    cout << "Enter Number of Books: ";
    cin >> n;
    library* books = new library[n];
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
            inputBooks(n, books);
            break;
        case 2: 
            displayBooks(n, books);
            break;
        case 3:
            delete[] books; 
            return 0;    
        default:
            break;
        }
    }
    

}