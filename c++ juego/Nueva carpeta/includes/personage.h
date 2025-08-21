// arena.h
#ifndef PERSONAGE_H
#define PERSONAGE_H
#include <string>
#include "enums.h"

class Personage
{
private:
    std::string name;
    int health;
    int strength;
    int defense;
    int level;
    classGame classGamePersonage;
    std::string weapon;

public:
    Personage();
    Personage(const std::string &, int, int, int, int, classGame, const std::string &);
    Personage(const Personage &);
    Personage &operator=(const Personage &);
    ~Personage();

    void setName(const std::string &name);
    void setHealth(int);
    void setStrength(int);
    void setDefense(int);
    void setLevel(int);

    void setClassGamePersonage(classGame);
    void setWeapon(const std::string &name);

    std::string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    int getLevel() const;

    classGame getClassGamePersonage() const;
    std::string getWeapon() const;

    void see() const;
    void takeDamage(int);
    bool isAlive() const;
    void levelUp();
};

#endif