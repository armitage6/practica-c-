#ifndef TEAM_H
#define TEAM_H
#include <string>
#include "personage.h"

class Team
{

private:
    std::string name;
    Personage **member;
    int memberQuantity;

public:
    Team();
    Team(const std::string &, Personage **, int);
    Team(const Team &);
    Team &operator=(const Team &);
    ~Team();

    void setName(const std::string &name);
    void setMember(Personage **, int);
    void setMemberQuantity(int);

    std::string getName() const;
    Personage *const *getMember() const;
    int getMemberQuantity() const;

    void see() const;
    void addMember(Personage *);
    void removeMember(const std::string &);
    Personage *searchMember(const std::string &);
    Personage *getStronger() const;
};
#endif