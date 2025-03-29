#include "iostream"
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "") : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks with " << (weaponType.empty() ? "bare hands" : weaponType)<< endl;
    }

    virtual void defend() {
        cout << name << " defends against the attack!" << endl;
    }

    virtual void displayStats() {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        if (!weaponType.empty()) {
            cout << "Weapon Type: " << weaponType << endl;
        }
    }

    virtual ~Character() {}
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, int armor, int damage, string weapon = "Sword") : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " swings their weapon and deals " << meleeDamage << " melee damage!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength << endl;
        cout << "Melee Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int power, string weapon = "Staff") : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() override {
        cout << name << " conjures a magical barrier with " << manaPoints << " mana points!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << endl;
        cout << "Spell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy, string weapon = "Bow") : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        if (arrowCount > 0) {
            cout << name << " fires an arrow with " << rangedAccuracy << "accuracy!" << endl;
            arrowCount--;
        } else {
            cout << name << " is out of arrows!" << endl;
        }
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Arrow Count: " << arrowCount << endl;
        cout << "Ranged Accuracy: " << rangedAccuracy << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int agil, string weapon = "Daggers") : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agil) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior1(101, "Thor", 5, 200, 50, 30);
    cout << "Warrior Stats:" << endl;
    warrior1.displayStats();
    warrior1.attack();
    warrior1.defend();
    cout << endl;

    Mage mage1(102, "Althea", 7, 150, 100, 40);
    cout << "Mage Stats:" << endl;
    mage1.displayStats();
    mage1.attack();
    mage1.defend();
    cout << endl;

    Archer archer1(103, "Robin Hood", 4, 120, 20, 85);
    cout << "Archer Stats:" << endl;
    archer1.displayStats();
    archer1.attack();
    archer1.attack(); 
    cout << endl;

    Rogue rogue1(104, "Shadow", 6, 140, 80, 90);
    cout << "Rogue Stats:" << endl;
    rogue1.displayStats();
    rogue1.attack();
    rogue1.defend();
    cout << endl;

    return 0;
}
