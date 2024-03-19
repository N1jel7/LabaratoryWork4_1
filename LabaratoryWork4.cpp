#include <iostream>
#include <string>

using namespace std;  

// Абстрактный класс Item
class Item abstract {
protected:
    int damage;
};

// Абстрактный класс Character
class Character abstract {
protected:
    string name;
    int HP;
public:
    void getHP() {
    }

    void getName() {
    }
};

// Интерфейс IInteractive
class IInteractive abstract {
public:
    void use() {
    }
};

// Интерфейс ITalkable
class ITalkable abstract{
public:
    void talking() {
    }
};

// Интерфейс IMovable
class IMovable abstract{
public:
    void moving() {
    }
};

class Bulava : Item { // 1
private:
    int damage = 100;
public:
    int return_damage() {
        return this->damage;
    }
};

class Molotok : Item { // 2
private:
    int damage = 75;
public:
    int return_damage() {
        return this->damage;
    }
};

class Knife : Item { // 3
private:
    int damage = 50;
public:
    int return_damage() {
        return this->damage;
    }
};



class Hero : Character, ITalkable, IMovable, IInteractive {

public:

    int boss_hp = 0;

    void use(int damage) {
        srand(time(0));

        int attempts = 1 + rand() % 5;
        cout << "Вам выпало " << attempts << " атаки." << endl;

        upper:
        for (int i = 0; i < attempts; i++) {
            boss_hp = boss_hp - damage;
            if (boss_hp <= 0) {
                cout << "Аттака номер " << i + 1 << ". Босс убит" << endl;
            }
            else
            {
                cout << "Аттака номер " << i + 1 << ". Здоровье босса: " << boss_hp << endl;
            }
            
            if (boss_hp <= 0) {
                cout << "Вы выйграли!" << endl;
                break;
            }
            else if (boss_hp > 0 && i == attempts-1) {
                cout << "Вы проиграли." << endl;
            }
        }
    }

    void game() {
        srand(time(NULL));

        boss_hp = 150 + rand() % 400;
        cout << "Уровень здоровья босса: " << boss_hp << endl;
        int choice = 1 + rand() % 3;
        int damage = 0;

        Bulava bulava;
        Molotok molotok;
        Knife knife;

        switch (choice) {
        case 1: 
            
            damage = bulava.return_damage();
            cout << "Вам повезло, вам выпала булава!!!" << endl;
            cout << "Урон оружия: " << damage << endl;
            use(damage);
            
            break;
        case 2:
            
            damage = molotok.return_damage();
            cout << "Вам выпал молоток." << endl;
            cout << "Урон оружия: " << damage << endl;
            use(damage);
            break;
        case 3:
            
            damage = knife.return_damage();
            cout << "Вам не повезло, вам выпал нож." << endl;
            cout << "Урон оружия: " << damage << endl;
            use(damage);
            break;
        default:
            cout << "Error" << endl;
        }
    }

    void talking() {
        cout << "Герой говорит." << endl;
    }

    void moving() {
        cout << "Герой дёрнулся." << endl;
    }
};


int main() {
    bool isRunning = true;
    while (isRunning) {
        Hero hero;
        hero.game();
        cout << "Хотите попробовать еще раз? (0 - NO, 1 - YES)" << endl;
        cin >> isRunning;
        if (isRunning) {
            system("cls");
        }
        
    }
    
}