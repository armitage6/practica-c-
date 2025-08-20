
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <string>
#include "libro.h"
#include "enums.h"
#include "usuario.h"

class Biblioteca
{

private:
    std::string nombre;
    std::string direccion;
    Libro *catalogo;
    int cantidadLibros;
    Usuario *usuarios;
    int cantidadUsuarios;

public:
    Biblioteca();
    Biblioteca(const std::string &, const std::string &, Libro *, int, Usuario *, int);
    Biblioteca(const Biblioteca &);
    Biblioteca &operator=(const Biblioteca &otra);
    ~Biblioteca();

    // setters

    void setNombre(const std::string &);
    void setDireccion(const std::string &);
    void setCatalogo(Libro *, int);
    void setCantidadLibros(int);
    void setUsuarios(Usuario *, int);
    void setCantidadUsuarios(int);
    // geters

    const std::string &getNombre() const;
    const std::string &gettDireccion() const;
    const Libro *getCatalogo() const;
    int getCantidadLibros() const;
    const Usuario *getUsuarios() const;
    int getCantidadUsuarios() const;

    void mostrar() const;
    void agregarLibro(const Libro &);
    void eliminarLibro(const std::string &titulo);
    Libro *buscarLibro(const std::string &titulo);
    void agregarUsuario(const Usuario &);
    void eliminarUsuario(const std::string &nombre);
    Usuario *buscarUsuario(const std::string &nombre);
    void mostrarLibrosPorGenero(const GeneroLibro &genero) const;
    void mostrarUsuariosConLibrosPrestados() const;
    void ordenarLibrosPorFecha();
    void ordenarUsuariosPorCantidadLibros();
};

#endif
