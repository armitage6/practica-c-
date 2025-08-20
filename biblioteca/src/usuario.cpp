#include <iostream>
#include <stdexcept>
#include "usuario.h"
#include "enums.h"

Usuario::Usuario()
    : nombre{}, edad{}, librosPrestados{nullptr}, cantidadLibros{} {}

// como voy a pasar un puntero ne librosPrestado lo mejor es crear mi propio for para ser dueño de los libros y asi no crear free/ crash que si elimino el main queda como colgarnte
Usuario::Usuario(const std::string &nombre_, int edad_, Libro *librosPrestados_, int cantidadLibros_)
    : nombre{nombre_}, edad{edad_}, cantidadLibros{cantidadLibros_}
{

    if (edad_ < 0)
    {
        throw std::invalid_argument("Error: edad no valida menor a 0");
    }

    if (cantidadLibros_ > 0 && librosPrestados_ != nullptr)
    {
        this->librosPrestados = new Libro[cantidadLibros_];
        for (int i = 0; i < cantidadLibros_; i++)
        {
            this->librosPrestados[i] = librosPrestados_[i];
        }
        this->cantidadLibros = cantidadLibros_;
    }
    else
    {
        this->librosPrestados = nullptr;
        cantidadLibros = 0;
    }
}

Usuario::Usuario(const Usuario &otroUsuario)
    : nombre{otroUsuario.nombre}, edad{otroUsuario.edad}, cantidadLibros{otroUsuario.cantidadLibros}
{

    if (otroUsuario.cantidadLibros > 0 && otroUsuario.librosPrestados != nullptr)
    {
        this->librosPrestados = new Libro[otroUsuario.cantidadLibros];
        for (int i = 0; i < otroUsuario.cantidadLibros; i++)
        {
            this->librosPrestados[i] = otroUsuario.librosPrestados[i];
        }
    }
    else
    {
        this->librosPrestados = nullptr;
        cantidadLibros = 0;
    }
}
Usuario &Usuario::operator=(const Usuario &otro)
{
    if (this == &otro)
        return *this; // Evitar auto-asignación

    // 1. Liberar recursos actuales
    delete[] librosPrestados;

    // 2. Copiar miembros primitivos
    nombre = otro.nombre;
    edad = otro.edad;
    cantidadLibros = otro.cantidadLibros;

    // 3. Copiar libros (si los hay)
    if (otro.cantidadLibros > 0 && otro.librosPrestados != nullptr)
    {
        librosPrestados = new Libro[otro.cantidadLibros];
        std::copy(otro.librosPrestados, otro.librosPrestados + otro.cantidadLibros, librosPrestados);
    }
    else
    {
        librosPrestados = nullptr;
        cantidadLibros = 0;
    }

    return *this;
}
Usuario::~Usuario()
{

    delete[] this->librosPrestados;
    this->librosPrestados = nullptr;

    std::cout << "El constructos de usuarios se llamo" << std::endl;
}

// setters

void Usuario::setNombre(const std::string &nombre_)
{
    nombre = nombre_;
}
void Usuario::setEdad(int edad_)
{
    if (edad_ < 0)
    {
        throw std::invalid_argument("Error: edad no valida menor a 0");
    }

    edad = edad_;
}
void Usuario::setLiBrosPrestados(Libro *librosPrestados_, int newCandiad)
{

    if (newCandiad < 0)
    {
        throw std::invalid_argument("Error: Cantidad Del parametro menor a 0");
    }

    if (librosPrestados_ == nullptr)
    {
        throw std::runtime_error("Error: librosPrestados hacereferencia a una memoria nula");
    }

    // hacer esto antes para que no exista fuga de memoria si es que el puntero estaba apuntando a otra direccion de memoria previamente
    delete[] librosPrestados;
    librosPrestados = nullptr;
    cantidadLibros = 0;

    if (newCandiad > 0)
    {

        Libro *newLibrosPrestados = new Libro[newCandiad];

        for (int i = 0; i < newCandiad; i++)
        {

            newLibrosPrestados[i] = librosPrestados_[i];
        }

        librosPrestados = newLibrosPrestados;
        cantidadLibros = newCandiad;
    }
}
void Usuario::setCantidadLibros(int cantidadLibros_)
{
    cantidadLibros = cantidadLibros_;
}

// geters

std::string Usuario::getNombre() const
{

    return nombre;
}
int Usuario::getEdad() const
{

    return edad;
}
const Libro *Usuario::getLiBrosPrestados() const
{

    return librosPrestados;
}
int Usuario::getCantidadLibros() const
{

    return cantidadLibros;
}

void Usuario::mostrar() const
{

    std::cout << nombre << std::endl;
    std::cout << edad << std::endl;
    std::cout << cantidadLibros << std::endl;
}
void Usuario::agregarLibroPrestado(const Libro &agregarLibro)
{

    Libro *newContenedorLibro = new Libro[cantidadLibros + 1];

    for (int i = 0; i < cantidadLibros; i++)
    {

        newContenedorLibro[i] = librosPrestados[i];
    }
    newContenedorLibro[cantidadLibros] = agregarLibro;
    delete[] librosPrestados;
    librosPrestados = newContenedorLibro;
    newContenedorLibro[cantidadLibros].prestar();
    setCantidadLibros(cantidadLibros + 1);
}
void Usuario::devolverLibro(const std::string &titulo)
{

    if (cantidadLibros <= 0)
    {
        throw std::out_of_range("Error: la cantidad de libros que dispone es menor o igual a 0 no se puede eliminar");
    }

    int indice = -1;

    for (int i = 0; i < cantidadLibros; i++)
    {

        if (librosPrestados[i].getTitulo() == titulo)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        throw std::out_of_range("Error: El libro no fue encontrado");
    }

    Libro *newContenedorLibros = nullptr;
    try
    {
        newContenedorLibros = new Libro[cantidadLibros - 1];
    }
    catch (const std::bad_alloc &e)
    {
        throw std::runtime_error("Error: memoria insuficiente para devolver el libro");
    }

    librosPrestados[indice].devolver();
    int newCantidad{};
    for (int i = 0; i < cantidadLibros; i++)
    {

        if (indice != i)
        {
            newContenedorLibros[newCantidad++] = librosPrestados[i];
        }
    }
    delete[] librosPrestados;

    librosPrestados = newContenedorLibros;

    setCantidadLibros(cantidadLibros - 1);
}
Libro *Usuario::buscarLibro(const std::string &titulo)
{

    for (int i = 0; i < cantidadLibros; i++)
    {
        if (librosPrestados[i].getTitulo() == titulo)
        {
            return &librosPrestados[i];
        }
    }

    return nullptr;
}
void Usuario::ordenarLibrosPorFecha()
{

    for (int i = 0; i < cantidadLibros - 1; i++)
    {

        for (int j = 0; j < cantidadLibros - i - 1; j++)
        {
            int dia = librosPrestados[j].getFechaPublicacion().dia;
            int mes = librosPrestados[j].getFechaPublicacion().mes;
            int anio = librosPrestados[j].getFechaPublicacion().anio;

            int diaS = librosPrestados[j + 1].getFechaPublicacion().dia;
            int mesS = librosPrestados[j + 1].getFechaPublicacion().mes;
            int anioS = librosPrestados[j + 1].getFechaPublicacion().anio;

            bool fechaMayor = false;

            if (anio > anioS)
            {
                fechaMayor = true;
            }
            else if (anio == anioS)
            {
                if (mes > mesS)
                {
                    fechaMayor = true;
                }
                else if (mes == mesS)
                {
                    if (dia > diaS)
                    {
                        fechaMayor = true;
                    }
                }
            }

            if (fechaMayor)
            {
                Libro auxLibro = librosPrestados[j];
                librosPrestados[j] = librosPrestados[j + 1];
                librosPrestados[j + 1] = auxLibro;
            }
        }
    }
}
void Usuario::filtrarLibroPorGenero(GeneroLibro &genero)
{
    for (int i = 0; i < cantidadLibros; i++)
    {
        if (librosPrestados[i].getGeneroLibro() == genero)
        {

            librosPrestados[i].mostrar();
        }
    }
}
void Usuario::ContarLibrosSegunGeneroUsuario()
{

    int FICCION = 0,
        NO_FICCION = 0,
        CIENCIA = 0,
        ARTE = 0,
        HISTORIA = 0,
        TECNOLOGIA = 0;

    for (int i = 0; i < cantidadLibros; i++)
    {

        if (librosPrestados[i].getGeneroLibro() == 0)
        {
            FICCION++;
        }
        if (librosPrestados[i].getGeneroLibro() == 1)
        {
            NO_FICCION++;
        }
        if (librosPrestados[i].getGeneroLibro() == 2)
        {
            CIENCIA++;
        }
        if (librosPrestados[i].getGeneroLibro() == 3)
        {
            ARTE++;
        }
        if (librosPrestados[i].getGeneroLibro() == 4)
        {
            HISTORIA++;
        }
        if (librosPrestados[i].getGeneroLibro() == 5)
        {
            TECNOLOGIA++;
        }
    }

    std::cout << "Tienes esta cantidad de libros de FICCION: " << FICCION << std::endl;
    std::cout << "Tienes esta cantidad de libros de NO_FICCION: " << NO_FICCION << std::endl;
    std::cout << "Tienes esta cantidad de libros de CIENCIA: " << CIENCIA << std::endl;
    std::cout << "Tienes esta cantidad de libros de ARTE: " << ARTE << std::endl;
    std::cout << "Tienes esta cantidad de libros de HISTORIA: " << HISTORIA << std::endl;
    std::cout << "Tienes esta cantidad de libros de TECNOLOGIA: " << TECNOLOGIA << std::endl;
}