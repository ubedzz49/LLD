#include <bits/stdc++.h>
using namespace std;

// ===== Base Character Class =====
class Character {
public:
    virtual void hit() = 0;
    virtual void walk() = 0;
    virtual ~Character() {}
};

// ===== Hero Classes =====
class Hero : public Character {
public:
    void hit() override {
        cout << "Hero uses punch 💥" << endl;
    }
    void walk() override {
        cout << "Hero walks 🚶‍♂️" << endl;
    }
};

class Fighter : public Character {
public:
    void hit() override {
        cout << "Fighter uses sword 🗡️" << endl;
    }
    void walk() override {
        cout << "Fighter runs 🏃‍♂️" << endl;
    }
};

class Warrior : public Character {
public:
    void hit() override {
        cout << "Warrior uses hammer 🔨" << endl;
    }
    void walk() override {
        cout << "Warrior rides horse 🐎" << endl;
    }
};

// ===== Villain Classes =====
class Villain : public Character {
public:
    void hit() override {
        cout << "Villain uses slap 👋" << endl;
    }
    void walk() override {
        cout << "Villain walks slowly 😈" << endl;
    }
};

class SuperVillain : public Character {
public:
    void hit() override {
        cout << "SuperVillain uses fireball 🔥" << endl;
    }
    void walk() override {
        cout << "SuperVillain flies 🕊️" << endl;
    }
};

class Devil : public Character {
public:
    void hit() override {
        cout << "Devil uses dark magic 🧙‍♂️" << endl;
    }
    void walk() override {
        cout << "Devil teleports 🌪️" << endl;
    }
};

// ===== Abstract Factory =====
class CharacterFactory {
public:
    virtual Character* createCharacter(const string& type) = 0;
    virtual ~CharacterFactory() {}
};

// ===== Hero Factory =====
class HeroFactory : public CharacterFactory {
public:
    Character* createCharacter(const string& type) override {
        if (type == "hero") return new Hero();
        else if (type == "fighter") return new Fighter();
        else if (type == "warrior") return new Warrior();
        else {
            cout << "Unknown hero type!" << endl;
            return nullptr;
        }
    }
};

// ===== Villain Factory =====
class VillainFactory : public CharacterFactory {
public:
    Character* createCharacter(const string& type) override {
        if (type == "villain") return new Villain();
        else if (type == "supervillain") return new SuperVillain();
        else if (type == "devil") return new Devil();
        else {
            cout << "Unknown villain type!" << endl;
            return nullptr;
        }
    }
};

// ===== Main =====
int main() {
    CharacterFactory* heroFactory = new HeroFactory();
    CharacterFactory* villainFactory = new VillainFactory();

    vector<string> heroes = {"hero", "fighter", "warrior"};
    vector<string> villains = {"villain", "supervillain", "devil"};

    cout << "=== Heroes ===\n";
    for (auto& h : heroes) {
        Character* ch = heroFactory->createCharacter(h);
        if (ch) {
            cout << "\nCreated Hero: " << h << endl;
            ch->hit();
            ch->walk();
            delete ch;
        }
    }

    cout << "\n=== Villains ===\n";
    for (auto& v : villains) {
        Character* ch = villainFactory->createCharacter(v);
        if (ch) {
            cout << "\nCreated Villain: " << v << endl;
            ch->hit();
            ch->walk();
            delete ch;
        }
    }

    delete heroFactory;
    delete villainFactory;

    return 0;
}
