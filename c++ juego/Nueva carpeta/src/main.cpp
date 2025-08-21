
#include <iostream>
#include <limits>
#include "personage.h"
#include "team.h"
#include "enums.h"

void createCharacters(Personage *&mago, Personage *&gurrero, Personage *&arquero, std::string);
void menu(Personage *&, Personage *&, Personage *&);
void menuEquipment(Personage *, Team **&);
void chooseTeam(Personage *, Team **&, const std::string &);

int main()
{
    Team **teamMembers = new Team *[2];

    Personage *team2[3] = {
        new Personage("Aurora", 90, 15, 10, 1, classGame::MAGO, "Báculo"),
        new Personage("Leonidas", 150, 30, 25, 1, classGame::GUERRERO, "Espada"),
        new Personage("Legolas", 95, 20, 14, 1, classGame::ARQUERO, "Arco")};

    teamMembers[0] = new Team("Los Nacidos de la Luz", team2, 3);

    for (int i = 0; i < 3; i++)
    {
        delete team2[i];
    }

    Personage *maga = nullptr;
    Personage *guerrero = nullptr;
    Personage *arquero = nullptr;

    menu(maga, guerrero, arquero);

    if (maga != nullptr)
    {
        menuEquipment(maga, teamMembers);
        delete maga;
    }
    if (guerrero != nullptr)
    {
        menuEquipment(guerrero, teamMembers);
        delete guerrero;
    }
    if (arquero != nullptr)
    {
        menuEquipment(arquero, teamMembers);
        delete arquero;
    }

    for (int i = 0; i < 2; i++)
    {
        Personage *const *aux = teamMembers[i]->getMember();

        for (int j = 0; j < 3; j++)
        {
            aux[j]->see();
        }
    }

    return 0;
}

void menu(Personage *&mago, Personage *&gurrero, Personage *&arquero)
{

    bool activeMenu{true};

    do
    {
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
        std::cout << "Bienvenido a combate de arena" << std::endl;
        std::cout << "Para empezar debe elegir un personaje" << std::endl;
        std::cout << "Alera la maga" << std::endl;
        std::cout << "Abuelo el guerrero" << std::endl;
        std::cout << "Mishir el arquero" << std::endl;
        std::cout << "salir yes" << std::endl;
        std::cout << "-------------------------------------------------------------------------------" << std::endl;

        std::string optionClass{};
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::getline(std::cin, optionClass);

        for (int i = 0; optionClass[i] != '\0'; i++)
        {

            if (optionClass[i] >= 'A' && optionClass[i] <= 'Z')
            {
                optionClass[i] = optionClass[i] + 32;
            }
        }

        if (optionClass == "yes")
        {
            activeMenu = false;
        }
        else
        {

            if (mago != nullptr)
            {
                delete mago;
                mago = nullptr;
            }
            if (gurrero != nullptr)
            {
                delete gurrero;
                gurrero = nullptr;
            }
            if (arquero != nullptr)
            {
                delete arquero;
                arquero = nullptr;
            }

            createCharacters(mago, gurrero, arquero, optionClass);
        }

    } while (activeMenu);
}
void createCharacters(Personage *&mago, Personage *&guerrero, Personage *&arquero, std::string optionClass)
{
    classGame auxOption{};
    if (optionClass == "mago")
        auxOption = classGame::MAGO;
    else if (optionClass == "guerrero")
        auxOption = classGame::GUERRERO;
    else if (optionClass == "arquero")
        auxOption = classGame::ARQUERO;
    else
        auxOption = classGame::NONE;

    switch (auxOption)
    {
    case classGame::MAGO:

        mago = new Personage("AleraXXX", 80, 15, 5, 1, classGame::MAGO, "Báculo");
        break;
    case classGame::GUERRERO:

        guerrero = new Personage("AbueloXXX", 120, 20, 15, 1, classGame::GUERRERO, "Espada");
        break;
    case classGame::ARQUERO:

        arquero = new Personage("MishirXXX", 90, 18, 10, 1, classGame::ARQUERO, "Arco");
        break;

    default:
        std::cout << "Caracter no valido, elija de nuevo" << std::endl;
        break;
    }
}

void menuEquipment(Personage *personage, Team **&team)
{
    int optionTeam{};
    do
    {

        std::cout
            << "-------------------------------------------------------------------------------" << std::endl;
        std::cout << "Ahora debes elegir un equipo" << std::endl;
        std::cout << "Los Sucios 1" << std::endl;
        std::cout << "Los nacidos de la Luz 2" << std::endl;
        std::cout << "Los Abuelos 3" << std::endl;
        std::cout << "salir  4" << std::endl;
        std::cout << "-------------------------------------------------------------------------------" << std::endl;

        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> optionTeam;

        switch (optionTeam)
        {
        case 1:
            chooseTeam(personage, team, "Los Sucios");
            break;
        case 2:
            chooseTeam(personage, team, "Los nacidos de la Luz");
            break;
        case 3:
            chooseTeam(personage, team, "Los Abuelos");
            break;
        case 4:
            std::cout << "Saliendo..." << std::endl;
            break;

        default:
            std::cout << "Equipo no valido eliga nuevamente" << std::endl;
            break;
        }

    } while (optionTeam != 4);
}

void chooseTeam(Personage *personage, Team **&team, const std::string &nameTeam)
{

    classGame nameClass = personage->getClassGamePersonage();

    switch (nameClass)
    {
    case classGame::MAGO:
    {
        Personage *team1[3]{
            new Personage("Abuelo", 70, 12, 8, 1, classGame::GUERRERO, "Espadon"),
            new Personage("Mishir", 130, 25, 20, 1, classGame::ARQUERO, "Arco"),
            new Personage(*personage)};
        team[1] = new Team(nameTeam, team1, 3);

        for (int i = 0; i < 3; i++)
        {
            delete team1[i];
        }
        break;
    }

    case classGame::GUERRERO:
    {
        Personage *team1[3]{
            new Personage("Luna", 70, 12, 8, 1, classGame::MAGO, "Varita"),
            new Personage("Mishir", 130, 25, 20, 1, classGame::ARQUERO, "Arco"),
            new Personage(*personage)};
        team[1] = new Team(nameTeam, team1, 3);

        for (int i = 0; i < 3; i++)
        {
            delete team1[i];
        }
        break;
    }

    case classGame::ARQUERO:
    {
        Personage *team1[3]{
            new Personage("Luna", 70, 12, 8, 1, classGame::MAGO, "Varita"),
            new Personage("Thor", 130, 25, 20, 1, classGame::GUERRERO, "Martillo"),
            new Personage(*personage)};

        team[1] = new Team(nameTeam, team1, 3);

        for (int i = 0; i < 3; i++)
        {
            delete team1[i];
        }
        break;
    }

    default:
        break;
    }
}