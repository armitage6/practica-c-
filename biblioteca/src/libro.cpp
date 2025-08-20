#include <iostream>
#include "../includes/libro.h"

Libro::Libro()
    : titulo{},
      autor{},
      fechaPublicacion{},
      genero{},
      estado{} {}

Libro::Libro(const std::string &titulo_, const std::string &autor_, Fecha fecha_, GeneroLibro fechaPublicacion_, EstadoLibro estado_)
    : titulo{titulo_},
      autor{autor_},
      fechaPublicacion{fecha_},
      genero{fechaPublicacion_},
      estado{estado_} {}

Libro::Libro(const Libro &libroCopia)
    : titulo{libroCopia.titulo},
      autor{libroCopia.autor},
      fechaPublicacion{libroCopia.fechaPublicacion},
      genero{libroCopia.genero},
      estado{libroCopia.estado} {}
Libro &Libro::operator=(const Libro &otro)
{
    if (this != &otro)
    { // protegerse contra auto-asignación
        titulo = otro.titulo;
        autor = otro.autor;
        fechaPublicacion = otro.fechaPublicacion;
        genero = otro.genero;
        estado = otro.estado;
    }
    return *this;
}
Libro::~Libro()
{
}

// setters

void Libro::setTitulo(const std::string &titulo_)
{
    this->titulo = titulo_;
}
void Libro::setAutor(const std::string &autor_)
{
    this->autor = autor_;
}
void Libro::setFechaPublicacion(Fecha fechaPublicacion_)
{
    this->fechaPublicacion = fechaPublicacion_;
}
void Libro::setGeneroLibro(GeneroLibro genero_)
{
    this->genero = genero_;
}
void Libro::setEstadoLibro(EstadoLibro estado_)
{
    this->estado = estado_;
}

// geters

std::string Libro::getTitulo() const
{

    return this->titulo;
}
std::string Libro::getAutor() const
{
    return this->autor;
}
Fecha Libro::getFechaPublicacion() const
{

    return this->fechaPublicacion;
}
GeneroLibro Libro::getGeneroLibro() const
{
    return this->genero;
}
EstadoLibro Libro::getEstadoLibro() const
{
    return this->estado;
}

void Libro::mostrar() const
{

    std::cout << this->titulo << std::endl;
    std::cout << this->autor << std::endl;
    std::cout << this->fechaPublicacion.dia << "/" << fechaPublicacion.mes << "/" << fechaPublicacion.anio << std::endl;
    std::cout << this->genero << std::endl;
    std::cout << this->estado << std::endl;
}
void Libro::prestar()
{

    this->estado = PRESTADO;
}
void Libro::devolver()
{
    this->estado = DISPONIBLE;
}
bool Libro::estaDisponible() const
{

    if (estado == DISPONIBLE)
        return true;
    else if (estado == PRESTADO)
        return false;
    else if (estado == RESERVADO)
        return false;
    else
        return false;
}