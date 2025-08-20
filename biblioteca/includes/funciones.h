
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include "libro.h"

void agregarLibro(Libro *&, int &, Libro);
void mostrar(const Libro *, int);
void eliminarLibro(Libro *&, const std::string &, int &);
Libro *buscarLibro(Libro *, const std::string &, int);

void ordenarPorTitulo(Libro *, int);

void duplicarLibro(Libro *&, int &, int);
void duplicarLibroPorLibro(Libro *&, int &, Libro);
void liberarBiblioteca(Libro *&, int &);

#endif
