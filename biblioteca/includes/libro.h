#ifndef LIBRO_H
#define LIBRO_H
#include <string>
#include "fecha.h"
#include "enums.h"

class Libro
{

private:
    std::string titulo;
    std::string autor;
    Fecha fechaPublicacion;
    GeneroLibro genero;
    EstadoLibro estado;

public:
    Libro();
    Libro(const std::string &, const std::string &, Fecha, GeneroLibro, EstadoLibro);
    Libro(const Libro &);
    Libro &operator=(const Libro &otro);
    ~Libro();

    // setters

    void setTitulo(const std::string &);
    void setAutor(const std::string &);
    void setFechaPublicacion(Fecha);
    void setGeneroLibro(GeneroLibro);
    void setEstadoLibro(EstadoLibro);

    // geters

    std::string getTitulo() const;
    std::string getAutor() const;
    Fecha getFechaPublicacion() const;
    GeneroLibro getGeneroLibro() const;
    EstadoLibro getEstadoLibro() const;

    void mostrar() const;
    void prestar();
    void devolver();
    bool estaDisponible() const;
};

#endif
