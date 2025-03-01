#include <iostream>
using namespace std;

class Level {
public:
    string levelName;
    int difficulty;

    Level(string name, int diff) : levelName(name), difficulty(diff) {}

    void display() {
        cout << "Level: " << levelName << " (Difficulty: " << difficulty << ")\n";
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level* levels[5]; 
    int levelCount;

public:
    VideoGame(string t, string g, string levelNames[], int difficulties[], int count): title(t), genre(g), levelCount(count) {
        for (int i = 0; i < levelCount; i++) {
            levels[i] = new Level(levelNames[i], difficulties[i]);
        }
    }

    ~VideoGame() {
        cout << "Game '" << title << "' is being destroyed!\n";
        for (int i = 0; i < levelCount; i++) {
            delete levels[i]; 
        }
    }

    void displayGame() {
        cout << " Game: " << title << " (Genre: " << genre << ")\nLevels:\n";
        for (int i = 0; i < levelCount; i++) {
            levels[i]->display();
        }
    }
};

int main() {
    
    string levelNames[] = {"BrotherHood", "BlackFlag", "Mirage"};
    int difficulties[] = {3, 5, 7};

    VideoGame game("Assassin's Creed", "Far Cry", levelNames, difficulties, 3);

    game.displayGame();

    return 0;
}
