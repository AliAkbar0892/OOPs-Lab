/*
    Name:   Ali Akbar
    Roll No 24-0892
    Section 2C
    Qustion 5
*/ 

#include <iostream>
using namespace std;

class MusicPlayer {
private:
    string playlist[10];
    string currentPlayingSong;

public:
    MusicPlayer() {
        string temp[10] = {"Song1", "Song2", "Song3", "Song4", "Song5", "Song6", "Song7", "Song8", "Song9", "Song10"};
        for (int i = 0; i < 10; i++) {
            playlist[i] = temp[i];
        }
        currentPlayingSong = "None";
    }

    void displayPlaylist() {
        cout << "\nPlaylist:\n";
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << playlist[i] << endl;
        }
    }

    void addSong() {
        cout << "\nEnter the index where you want to replace a song (1-10): ";
        int index;
        cin >> index;
        cin.ignore(); // To clear input buffer
        if (index < 1 || index > 10) {
            cout << "Invalid index!\n";
            return;
        }
        cout << "Enter new song name: ";
        string newSong;
        getline(cin, newSong);
        playlist[index - 1] = newSong;
    }

    void removeSong() {
        cout << "\nEnter the index of the song you want to remove (1-10): ";
        int index;
        cin >> index;
        if (index < 1 || index > 10) {
            cout << "Invalid index!\n";
            return;
        }
        playlist[index - 1] = "Empty Slot";
        cout << "Song removed successfully!\n";
    }

    void playSong() {
        cout << "\nEnter the index of the song you want to play (1-10): ";
        int index;
        cin >> index;
        if (index < 1 || index > 10 || playlist[index - 1] == "Empty Slot") {
            cout << "Invalid choice or slot is empty!\n";
            return;
        }
        currentPlayingSong = playlist[index - 1];
        cout << "Now playing: " << currentPlayingSong << endl;
    }
};

int main() {
    MusicPlayer mp;
    while (true) {
        cout << "\nTo Display Playlist, Press 1: ";
        cout << "\nTo Add a Song, Press 2: ";
        cout << "\nTo Remove a Song, PRess 3: ";
        cout << "\nTo Play a Song, pRess 4: ";
        cout << "\nTo Exit, Press 5: ";
        cout << "\nEnter Your Choice: ";
        
        int choice;
        cin >> choice;
        cin.ignore(); // To avoid input issues

        switch (choice) {
        case 1:
            mp.displayPlaylist();
            break;
        case 2:
            mp.addSong();
            break;
        case 3:
            mp.removeSong();
            break;
        case 4:
            mp.playSong();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice, please try again!\n";
        }
    }
}
