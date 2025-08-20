#include <iostream>
#include "../includes/libro.h"
#include "../includes/funciones.h"
#include "../includes/usuario.h"
#include "../includes/biblioteca.h"

int main()
{

    int totalLibros = 16;

    Libro *catalogo = new Libro[totalLibros];

    catalogo[0] = Libro("Cumbres", "Chichuelo", Fecha{2, 6, 20}, FICCION, PRESTADO);
    catalogo[1] = Libro("Neuromente", "Gibson", Fecha{7, 3, 24}, FICCION, PRESTADO);
    catalogo[2] = Libro("Roma", "Marco Aurelio", Fecha{2, 5, 21}, HISTORIA, PRESTADO);
    catalogo[3] = Libro("Matematica", "Roberto", Fecha{10, 12, 24}, CIENCIA, PRESTADO);
    catalogo[4] = Libro("El Principito", "Saint-Exupéry", Fecha{10, 4, 43}, FICCION, PRESTADO);
    catalogo[5] = Libro("Breves respuestas a las grandes preguntas", "Stephen Hawking", Fecha{1, 10, 18}, CIENCIA, PRESTADO);
    catalogo[6] = Libro("Historia de Roma", "Tácito", Fecha{5, 7, 15}, HISTORIA, PRESTADO);
    catalogo[7] = Libro("Cálculo", "James Stewart", Fecha{3, 9, 21}, CIENCIA, PRESTADO);
    catalogo[8] = Libro("1984", "George Orwell", Fecha{8, 6, 21}, FICCION, PRESTADO);
    catalogo[9] = Libro("Neurociencia para principiantes", "Gibson", Fecha{12, 11, 22}, CIENCIA, PRESTADO);
    catalogo[10] = Libro("Guerra y Paz", "Tolstói", Fecha{1, 1, 66}, HISTORIA, PRESTADO);
    catalogo[11] = Libro("Álgebra Lineal", "Gilbert Strang", Fecha{2, 2, 19}, CIENCIA, PRESTADO);
    catalogo[12] = Libro("La Odisea", "Homero", Fecha{12, 5, 23}, HISTORIA, DISPONIBLE);
    catalogo[13] = Libro("Fundación", "Isaac Asimov", Fecha{1, 6, 51}, FICCION, PRESTADO);
    catalogo[14] = Libro("El Universo en una cáscara de nuez", "Stephen Hawking", Fecha{15, 9, 22}, CIENCIA, DISPONIBLE);
    catalogo[15] = Libro("Hamlet", "William Shakespeare", Fecha{1, 1, 26}, FICCION, RESERVADO);

    int cantidadUsuarios = 3;
    Usuario *usuarios = new Usuario[cantidadUsuarios]{
        Usuario("Juan Perez", 23, &catalogo[0], 5),
        Usuario("María López", 27, &catalogo[5], 6),
        Usuario("Carlos Gómez", 25, &catalogo[11], 5)};

    Biblioteca biblioteca = Biblioteca("Biblioteca De Chile", "Chuleta", catalogo, totalLibros, usuarios, cantidadUsuarios);

    // biblioteca.mostrarLibrosPorGenero(HISTORIA);
    biblioteca.mostrarUsuariosConLibrosPrestados();

    delete[] catalogo;
    delete[] usuarios;

    return 0;
}
