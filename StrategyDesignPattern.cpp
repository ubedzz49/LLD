#include <bits/stdc++.h>
using namespace std;

class SpeakBehavior {
public:
    virtual void speak() const = 0;
    virtual ~SpeakBehavior() = default;
};

class RunBehavior {
public:
    virtual void run() const = 0;
    virtual ~RunBehavior() = default;
};

class HitBehavior {
public:
    virtual void hit() const = 0;
    virtual ~HitBehavior() = default;
};

class HindiSpeak : public SpeakBehavior {
public:
    void speak() const override {
        cout << "Speaking: नमस्ते! (Namaste!)" << endl;
    }
};

class EnglishSpeak : public SpeakBehavior {
public:
    void speak() const override {
        cout << "Speaking: Hello there!" << endl;
    }
};

class NoSpeak : public SpeakBehavior {
public:
    void speak() const override {
        cout << "Speaking: (Cannot speak)" << endl;
    }
};

class FastRun : public RunBehavior {
public:
    void run() const override {
        cout << "Running: at 18 kmph (Fast)" << endl;
    }
};

class MediumRun : public RunBehavior {
public:
    void run() const override {
        cout << "Running: at 15 kmph (Medium)" << endl;
    }
};

class SlowRun : public RunBehavior {
public:
    void run() const override {
        cout << "Running: at 12 kmph (Slow)" << endl;
    }
};

class GunHit : public HitBehavior {
public:
    void hit() const override {
        cout << "Hitting: with a Gun (Pew pew!)" << endl;
    }
};

class SwordHit : public HitBehavior {
public:
    void hit() const override {
        cout << "Hitting: with a Sword (Swish!)" << endl;
    }
};

class PunchHit : public HitBehavior {
public:
    void hit() const override {
        cout << "Hitting: with a Punch (Wham!)" << endl;
    }
};

class Robot {
private:
    unique_ptr<SpeakBehavior> speakStrategy;
    unique_ptr<RunBehavior> runStrategy;
    unique_ptr<HitBehavior> hitStrategy;
    string name;

public:
    Robot(string name, unique_ptr<SpeakBehavior> speak, unique_ptr<RunBehavior> run, unique_ptr<HitBehavior> hit)
        : name(std::move(name)), speakStrategy(std::move(speak)), runStrategy(std::move(run)), hitStrategy(std::move(hit)) {
        cout << "Robot " << this->name << " created." << endl;
    }

    void performSpeak() const {
        cout << name << " is ";
        if (speakStrategy) {
            speakStrategy->speak();
        } else {
            cout << "unable to perform speak action (no strategy set)." << endl;
        }
    }

    void performRun() const {
        cout << name << " is ";
        if (runStrategy) {
            runStrategy->run();
        } else {
            cout << "unable to perform run action (no strategy set)." << endl;
        }
    }

    void performHit() const {
        cout << name << " is ";
        if (hitStrategy) {
            hitStrategy->hit();
        } else {
            cout << "unable to perform hit action (no strategy set)." << endl;
        }
    }

    void setSpeakBehavior(unique_ptr<SpeakBehavior> newSpeak) {
        speakStrategy = std::move(newSpeak);
        cout << name << "'s speak behavior changed." << endl;
    }

    void setRunBehavior(unique_ptr<RunBehavior> newRun) {
        runStrategy = std::move(newRun);
        cout << name << "'s run behavior changed." << endl;
    }

    void setHitBehavior(unique_ptr<HitBehavior> newHit) {
        hitStrategy = std::move(newHit);
        cout << name << "'s hit behavior changed." << endl;
    }

    string getName() const {
        return name;
    }
};

int main() {
    cout << "--- Creating Different Robots ---" << endl;

    Robot heroBot("HeroBot",
                  make_unique<EnglishSpeak>(),
                  make_unique<MediumRun>(),
                  make_unique<GunHit>());

    cout << "\n--- HeroBot's Initial Actions ---" << endl;
    heroBot.performSpeak();
    heroBot.performRun();
    heroBot.performHit();

    Robot ninjaBot("NinjaBot",
                   make_unique<HindiSpeak>(),
                   make_unique<FastRun>(),
                   make_unique<SwordHit>());

    cout << "\n--- NinjaBot's Initial Actions ---" << endl;
    ninjaBot.performSpeak();
    ninjaBot.performRun();
    ninjaBot.performHit();

    Robot gruntBot("GruntBot",
                   make_unique<NoSpeak>(),
                   make_unique<SlowRun>(),
                   make_unique<PunchHit>());

    cout << "\n--- GruntBot's Initial Actions ---" << endl;
    gruntBot.performSpeak();
    gruntBot.performRun();
    gruntBot.performHit();

    cout << "\n--- Changing HeroBot's Behavior at Runtime ---" << endl;
    heroBot.setSpeakBehavior(make_unique<HindiSpeak>());
    heroBot.setHitBehavior(make_unique<SwordHit>());

    cout << "\n--- HeroBot's New Actions ---" << endl;
    heroBot.performSpeak();
    heroBot.performRun();
    heroBot.performHit();

    cout << "\n--- Changing GruntBot's Behavior at Runtime ---" << endl;
    gruntBot.setRunBehavior(make_unique<FastRun>());
    gruntBot.setHitBehavior(make_unique<GunHit>());

    cout << "\n--- GruntBot's New Actions ---" << endl;
    gruntBot.performSpeak();
    gruntBot.performRun();
    gruntBot.performHit();

    cout << "\n--- End of Demonstration ---" << endl;

    return 0;
}
