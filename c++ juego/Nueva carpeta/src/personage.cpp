
#include <iostream>
#include "personage.h"

Personage::Personage()
    : name{},
      health{},
      strength{},
      defense{},
      level{},
      classGamePersonage{},
      weapon{}
{
}

Personage::Personage(const std::string &name_, int health_, int strength_, int defense_, int level_, classGame classGamePersonage_, const std::string &weapon_)

    : name{name_},
      health{health_},
      strength{strength_},
      defense{defense_},
      level{level_},
      classGamePersonage{classGamePersonage_},
      weapon{weapon_}
{
}
Personage::Personage(const Personage &anotherCharacter)
    : name{anotherCharacter.name},
      health{anotherCharacter.health},
      strength{anotherCharacter.strength},
      defense{anotherCharacter.defense},
      level{anotherCharacter.level},
      classGamePersonage{anotherCharacter.classGamePersonage},
      weapon{anotherCharacter.weapon} {}
Personage &Personage::operator=(const Personage &anotherCharacter)
{

    if (this != &anotherCharacter)
    {

        this->name = anotherCharacter.name;
        this->health = anotherCharacter.health;
        this->strength = anotherCharacter.strength;
        this->defense = anotherCharacter.defense;
        this->level = anotherCharacter.level;
        this->classGamePersonage = anotherCharacter.classGamePersonage;
        this->weapon = anotherCharacter.weapon;
    }

    return *this;
}
Personage::~Personage()
{
}

void Personage::setName(const std::string &name)
{
    this->name = name;
}
void Personage::setHealth(int health)
{
    this->health = health;
}
void Personage::setStrength(int strength)
{
    this->strength = strength;
}
void Personage::setDefense(int defense)
{
    this->defense = defense;
}
void Personage::setLevel(int level)
{
    this->level = level;
}

void Personage::setClassGamePersonage(classGame classGamePersonage)
{
    this->classGamePersonage = classGamePersonage;
}
void Personage::setWeapon(const std::string &weapon)
{
    this->weapon = weapon;
}

std::string Personage::getName() const
{

    return this->name;
}
int Personage::getHealth() const
{
    return this->health;
}
int Personage::getStrength() const
{
    return this->strength;
}
int Personage::getDefense() const
{
    return this->defense;
}
int Personage::getLevel() const
{
    return this->level;
}

classGame Personage::getClassGamePersonage() const
{

    return this->classGamePersonage;
}
std::string Personage::getWeapon() const
{
    return this->weapon;
}

void Personage::see() const
{
    std::cout << "-----------------------------------------------------------------------------------------" << name << std::endl;
    std::cout << "Su persona: " << this->name << std::endl;
    std::cout << "vida: " << this->health << std::endl;
    std::cout << "Su strength: " << this->strength << std::endl;
    std::cout << "Su defense: " << this->defense << std::endl;
    if (this->classGamePersonage == classGame::GUERRERO)
    {
        std::cout << "Su persona es guerrero" << std::endl;
    }
    if (this->classGamePersonage == classGame::ARQUERO)
    {
        std::cout << "Su persona es arquero" << std::endl;
    }
    if (this->classGamePersonage == classGame::MAGO)
    {
        std::cout << "Su persona es mago" << std::endl;
    }
    std::cout << "Su weapon: " << this->weapon << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << name << std::endl;
}
void Personage::takeDamage(int quantity)
{

    int residual{quantity};

    if (this->defense > 0)
    {
        if (defense >= residual)
        {
            defense -= residual;
            residual = 0;
        }
        else
        {
            residual -= defense;
            defense = 0;
        }
    }

    if (residual > 0)
    {
        health -= residual;
        if (health < 0)
            health = 0;
    }

    bool alive = isAlive();
    if (!alive)
    {
        std::cout << "Su personaje esta muerto " << std::endl;
    }
}
bool Personage::isAlive() const
{

    if (this->health == 0)
    {

        return false;
    }

    return true;
}
void Personage::levelUp()
{
    std::cout << "Usted subio de nivel" << std::endl;
    this->level += 1;
    this->health += 10;
    this->strength += 10;
    this->defense += 10;
}