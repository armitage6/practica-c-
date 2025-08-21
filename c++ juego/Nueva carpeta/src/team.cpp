#include <iostream>
#include <stdexcept>
#include "team.h"

Team::Team()

    : name{},
      member{nullptr},
      memberQuantity{}
{
}

Team::Team(const std::string &name_, Personage **member_, int memberQuantity_)
    : name{name_},
      member{nullptr},
      memberQuantity{memberQuantity_}
{

    if (memberQuantity_ < 0)
    {
        throw std::invalid_argument("Error: cantidad no valida menor a 0");
    }

    if (memberQuantity_ > 0 && member_ != nullptr)
    {
        member = new Personage *[memberQuantity_];
        for (int i = 0; i < memberQuantity_; i++)
        {
            member[i] = new Personage(*member_[i]);
        }
    }
    else
    {
        member = nullptr;
        memberQuantity = 0;
    }
}

Team::Team(const Team &other)
    : name{other.name},
      member{nullptr},
      memberQuantity{other.memberQuantity}
{

    if (other.memberQuantity < 0)
    {
        throw std::invalid_argument("Error: cantidad no valida menor a 0");
    }

    if (memberQuantity > 0 && member != nullptr)
    {
        member = new Personage *[other.memberQuantity];
        for (int i = 0; i < other.memberQuantity; i++)
        {
            member[i] = new Personage(*other.member[i]);
        }
    }
    else
    {
        member = nullptr;
        memberQuantity = 0;
    }
}
Team &Team::operator=(const Team &other)
{
    if (this == &other) // Evitamos autoasignación
        return *this;

    // Liberamos lo que ya teníamos
    if (member != nullptr)
    {
        for (int i = 0; i < memberQuantity; i++)
        {
            delete member[i]; // liberar cada Personage*
        }
        delete[] member; // liberar el arreglo de punteros
    }

    name = other.name;
    memberQuantity = other.memberQuantity;

    if (memberQuantity > 0 && other.member != nullptr)
    {
        member = new Personage *[memberQuantity];
        for (int i = 0; i < memberQuantity; i++)
        {
            member[i] = new Personage(*other.member[i]);
        }
    }
    else
    {
        member = nullptr;
        memberQuantity = 0;
    }

    return *this;
}
Team::~Team()
{
    if (member != nullptr)
    {
        for (int i = 0; i < memberQuantity; i++)
        {
            delete member[i];
        }
        delete[] member;
    }

    std::cout << "Se ejecuto el destructor Team" << std::endl;
}

void Team::setName(const std::string &name_)
{
    name = name_;
}
void Team::setMember(Personage **member_, int memberQuantity_)
{

    if (member != nullptr)
    {
        for (int i = 0; i < memberQuantity; i++)
        {
            delete member[i];
        }
        delete[] member;
    }

    memberQuantity = memberQuantity_;

    if (memberQuantity > 0 && member_ != nullptr)
    {
        member = new Personage *[memberQuantity];
        for (int i = 0; i < memberQuantity; i++)
        {
            member[i] = new Personage(*member_[i]);
        }
    }
    else
    {
        member = nullptr;
        memberQuantity = 0;
    }
}

void Team::setMemberQuantity(int getMemberQuantity_)
{
    memberQuantity = getMemberQuantity_;
}

std::string Team::getName() const
{

    return name;
}
Personage *const *Team::getMember() const
{
    return member;
}
int Team::getMemberQuantity() const
{

    return memberQuantity;
}

void Team::see() const
{
    std::cout << "-----------------------------------------------------------------------------------------" << name << std::endl;
    std::cout << "nombre: " << name << std::endl;
    std::cout << "Equipos: " << memberQuantity << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << name << std::endl;
}
void Team::addMember(Personage *personage_)
{

    Personage **newPersonage = new Personage *[memberQuantity + 1];

    for (int i = 0; i < memberQuantity; i++)
    {
        newPersonage[i] = new Personage(*member[i]);
    }

    newPersonage[memberQuantity] = new Personage(*personage_);

    for (int i = 0; i < memberQuantity; i++)
    {
        delete member[i];
    }
    delete[] member;

    member = newPersonage;
    memberQuantity++;
}

void Team::removeMember(const std::string &name_)
{
    int poss = -1;

    for (int i = 0; i < memberQuantity; i++)
    {
        if (member[i]->getName() == name_)
        {
            poss = i;
            break;
        }
    }

    if (poss == -1)
        return;

    Personage **newPersonage = new Personage *[memberQuantity - 1];

    int aux{};
    for (int i = 0; i < memberQuantity; i++)
    {
        if (poss != i)
        {
            newPersonage[aux++] = new Personage(*member[i]);
        }
    }

    for (int i = 0; i < memberQuantity; i++)
    {
        delete member[i];
    }
    delete[] member;

    member = newPersonage;
    memberQuantity--;
}
// copia
Personage *Team::searchMember(const std::string &name_)
{
    Personage *newPersonage;

    for (int i = 0; i < memberQuantity; i++)
    {
        if (member[i]->getName() == name_)
        {
            newPersonage = new Personage(*member[i]);
            return newPersonage;
        }
    }

    return nullptr;
}
// no hay copia hace referencia al member
Personage *Team::getStronger() const
{
    Personage *aux = member[0];
    for (int i = 0; i < memberQuantity; i++)
    {
        if (member[i]->getStrength() > aux[i].getStrength())
        {
            aux = member[i];
        }
    }

    return aux;
}