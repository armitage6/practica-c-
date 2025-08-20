
#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "libro.h"

class Usuario
{

private:
    std::string nombre;
    int edad;
    Libro *librosPrestados;
    int cantidadLibros;

public:
    Usuario();
    Usuario(const std::string &, int, Libro *, int);
    Usuario(const Usuario &);
    Usuario &operator=(const Usuario &otro);
    ~Usuario();

    // setters

    void setNombre(const std::string &);
    void setEdad(int);
    void setLiBrosPrestados(Libro *, int);
    void setCantidadLibros(int);

    // geters

    std::string getNombre() const;
    int getEdad() const;
    const Libro *getLiBrosPrestados() const;
    int getCantidadLibros() const;

    void mostrar() const;
    void agregarLibroPrestado(const Libro &);
    void devolverLibro(const std::string &titulo);
    Libro *buscarLibro(const std::string &titulo);
    void ordenarLibrosPorFecha();
    void filtrarLibroPorGenero(GeneroLibro &genero);
    void ContarLibrosSegunGeneroUsuario();
};

#endif
