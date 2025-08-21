// // arena.h
// #ifndef ARENA_H
// #define ARENA_H
// #include <string>
// #include "team.h"

// class Arena
// {
// private:
//     std::string name;
//     Team **equipment;
//     int equipmentQuantity;

// public:
//     Arena();
//     Arena(const std::string &, Team **, int);
//     Arena(const Arena &);
//     Arena &operator=(const Arena &);
//     ~Arena();

//     void setName(const std::string &);
//     void setEquipment(Team **);
//     void setEquipmentQuantity(int);

//     std::string getName() const;
//     Arena **getEquipment() const;
//     int getEquipmentQuantity() const;

//     void see() const;
//     void agregarEquipo(Team *);
//     void eliminarEquipo(const std::string &);
//     Team *buscarEquipo(const std::string &);
//     void mostrarEquipos() const;
//     void iniciarBatalla(const std::string &, const std::string &);
//     void rankingPersonajes();
// };

// #endif