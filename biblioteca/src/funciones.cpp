#include <iostream>
#include "../includes/funciones.h"

void mostrar(const Libro *arrLibro, int cantidad)
{

    for (int i = 0; i < cantidad; i++)
    {
        arrLibro[i].mostrar();
    }
}

void agregarLibro(Libro *&arrLibro, int &cantidad, Libro libroAgregar)
{

    Libro *newLibro = new Libro[cantidad + 1];
    for (short i = 0; i < cantidad; i++)
    {
        newLibro[i] = arrLibro[i];
    }

    newLibro[cantidad] = libroAgregar;

    delete[] arrLibro;
    arrLibro = newLibro;
    cantidad++;
}

void eliminarLibro(Libro *&arrLibro, const std::string &tituloLibro, int &cantidad)
{
    int poss = -1;
    for (int i = 0; i < cantidad; i++)
    {
        if (arrLibro[i].getTitulo() == tituloLibro)
        {

            poss = i;
            break;
        }
    }

    if (poss == -1)
    {
        std::cout << "Libro no encontrado" << std::endl;
        return;
    }

    Libro *newArrLibro = new Libro[cantidad - 1];

    int newContidad{};
    for (int i = 0; i < cantidad; i++)
    {

        if (poss != i)
        {
            newArrLibro[newContidad++] = arrLibro[i];
        }
    }

    delete[] arrLibro;
    arrLibro = newArrLibro;
    cantidad--;
}

Libro *buscarLibro(Libro *arrLibro, const std::string &tituloLibro, int cantidad)
{

    for (int i = 0; i < cantidad; i++)
    {
        if (arrLibro[i].getTitulo() == tituloLibro)
        {
            return &arrLibro[i];
        }
    }

    return nullptr;
}

void ordenarPorTitulo(Libro *arrLibro, int cantidad)
{

    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if (arrLibro[j].getTitulo() > arrLibro[j + 1].getTitulo())
            {

                Libro temp = arrLibro[j];
                arrLibro[j] = arrLibro[j + 1];
                arrLibro[j + 1] = temp;
            }
        }
    }
}

void duplicarLibro(Libro *&arrLibro, int &cantidad, int indice)
{

    Libro *newLibro = new Libro[cantidad + 1];
    for (short i = 0; i < cantidad; i++)
    {
        newLibro[i] = arrLibro[i];
    }

    newLibro[cantidad] = arrLibro[indice];

    delete[] arrLibro;
    arrLibro = newLibro;
    cantidad++;
}
void duplicarLibroPorLibro(Libro *&arrLibro, int &cantidad, Libro diplicarLibro)
{

    Libro *newLibro = new Libro[cantidad + 1];
    for (short i = 0; i < cantidad; i++)
    {
        newLibro[i] = arrLibro[i];
    }

    newLibro[cantidad] = diplicarLibro;

    delete[] arrLibro;
    arrLibro = newLibro;
    cantidad++;
}

void liberarBiblioteca(Libro *&arrLibro, int &cantidad)
{

    if (arrLibro != nullptr)
    {
        delete[] arrLibro;
        arrLibro = nullptr;
        cantidad = 0;
    }
}