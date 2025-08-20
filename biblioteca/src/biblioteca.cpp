#include <iostream>
#include <stdexcept>
#include "../includes/biblioteca.h"

Biblioteca::Biblioteca()
    : nombre{}, direccion{}, catalogo{nullptr}, cantidadLibros{}, usuarios{nullptr}, cantidadUsuarios{}
{
}

Biblioteca::Biblioteca(const std::string &nombre_, const std::string &direccion_, Libro *catalogo_, int cantidadLibros_, Usuario *usuarios_, int cantidadUsuarios_)
    : nombre{nombre_}, direccion{direccion_}, catalogo{nullptr}, cantidadLibros{cantidadLibros_}, usuarios{nullptr}, cantidadUsuarios{cantidadUsuarios_}
{
    // Asignar a cantalogos
    if (cantidadLibros_ > 0 && catalogo_ != nullptr)
    {

        this->catalogo = new Libro[cantidadLibros_];

        for (int i = 0; i < cantidadLibros_; i++)
        {

            this->catalogo[i] = catalogo_[i];
        }
    }
    else
    {
        this->catalogo = nullptr;
        cantidadLibros = 0;
    }

    // asignar a usuarios

    if (cantidadUsuarios_ > 0 && usuarios_ != nullptr)
    {

        this->usuarios = new Usuario[cantidadUsuarios_];

        for (int i = 0; i < cantidadUsuarios_; i++)
        {

            this->usuarios[i] = usuarios_[i];
        }
    }
    else
    {
        this->usuarios = nullptr;
        cantidadUsuarios = 0;
    }
}
Biblioteca::Biblioteca(const Biblioteca &otraBiblioteca)
    : nombre{otraBiblioteca.nombre}, direccion{otraBiblioteca.direccion}, catalogo{nullptr}, cantidadLibros{otraBiblioteca.cantidadLibros}, usuarios{nullptr}, cantidadUsuarios{otraBiblioteca.cantidadUsuarios}
{

    if (otraBiblioteca.cantidadLibros > 0 && otraBiblioteca.catalogo != nullptr)
    {

        this->catalogo = new Libro[otraBiblioteca.cantidadLibros];

        for (int i = 0; i < otraBiblioteca.cantidadLibros; i++)
        {

            this->catalogo[i] = otraBiblioteca.catalogo[i];
        }
    }
    else
    {
        this->catalogo = nullptr;
        cantidadLibros = 0;
    }

    // asignar a usuarios

    if (otraBiblioteca.cantidadUsuarios > 0 && otraBiblioteca.usuarios != nullptr)
    {

        this->usuarios = new Usuario[otraBiblioteca.cantidadUsuarios];

        for (int i = 0; i < otraBiblioteca.cantidadUsuarios; i++)
        {

            this->usuarios[i] = otraBiblioteca.usuarios[i];
        }
    }
    else
    {
        this->usuarios = nullptr;
        cantidadUsuarios = 0;
    }
}

Biblioteca &Biblioteca::operator=(const Biblioteca &otraBiblioteca)
{

    if (this == &otraBiblioteca)
        return *this; // Evitar auto-asignación

    // 1. Liberar recursos actuales
    delete[] catalogo;
    delete[] usuarios;

    // 2. Copiar miembros primitivos
    nombre = otraBiblioteca.nombre;
    direccion = otraBiblioteca.direccion;
    cantidadLibros = otraBiblioteca.cantidadLibros;
    cantidadUsuarios = otraBiblioteca.cantidadUsuarios;

    if (otraBiblioteca.cantidadLibros > 0 && otraBiblioteca.catalogo != nullptr)
    {

        this->catalogo = new Libro[otraBiblioteca.cantidadLibros];

        for (int i = 0; i < otraBiblioteca.cantidadLibros; i++)
        {

            this->catalogo[i] = otraBiblioteca.catalogo[i];
        }
    }
    else
    {
        this->catalogo = nullptr;
        cantidadLibros = 0;
    }

    // asignar a usuarios

    if (otraBiblioteca.cantidadUsuarios > 0 && otraBiblioteca.usuarios != nullptr)
    {

        this->usuarios = new Usuario[otraBiblioteca.cantidadUsuarios];

        for (int i = 0; i < otraBiblioteca.cantidadUsuarios; i++)
        {

            this->usuarios[i] = otraBiblioteca.usuarios[i];
        }
    }
    else
    {
        this->usuarios = nullptr;
        cantidadUsuarios = 0;
    }

    return *this;
}
Biblioteca::~Biblioteca()
{

    delete[] catalogo;
    catalogo = nullptr;

    delete[] usuarios;
    usuarios = nullptr;

    std::cout << "El constructos de biblioteca se llamo" << std::endl;
}

// setters

void Biblioteca::setNombre(const std::string &nombre_)
{
    nombre = nombre_;
}
void Biblioteca::setDireccion(const std::string &direccion_)
{
    direccion = direccion_;
}
void Biblioteca::setCatalogo(Libro *catalogo_, int cantidadLibros_)
{
    if (cantidadLibros_ < 0)
    {
        throw std::invalid_argument("Error: Cantidad Del parametro menor a 0");
    }

    if (catalogo_ == nullptr)
    {
        throw std::runtime_error("Error: catalogo hacereferencia a una memoria nula");
    }

    delete[] catalogo;
    catalogo = nullptr;
    cantidadLibros = 0;

    if (cantidadLibros_ > 0)
    {

        Libro *newCatalogo = new Libro[cantidadLibros_];

        for (int i = 0; i < cantidadLibros_; i++)
        {

            newCatalogo[i] = catalogo_[i];
        }
        catalogo = newCatalogo;
        cantidadLibros = cantidadLibros_;
    }
}
void Biblioteca::setCantidadLibros(int cantidadLibros_)
{

    cantidadLibros = cantidadLibros_;
}
void Biblioteca::setUsuarios(Usuario *usuarios_, int cantidadUsuarios_)
{

    if (cantidadUsuarios_ < 0)
    {
        throw std::invalid_argument("Error: Cantidad Del parametro menor a 0");
    }

    if (usuarios_ == nullptr)
    {
        throw std::runtime_error("Error: usuarios hacereferencia a una memoria nula");
    }

    delete[] this->usuarios;
    this->usuarios = nullptr;
    this->cantidadUsuarios = 0;

    if (cantidadUsuarios_ > 0)
    {

        Usuario *newUsuarios = new Usuario[cantidadUsuarios_];

        for (int i = 0; i < cantidadUsuarios_; i++)
        {

            newUsuarios[i] = usuarios_[i];
        }
        usuarios = newUsuarios;
        cantidadUsuarios = cantidadUsuarios_;
    }
}
void Biblioteca::setCantidadUsuarios(int cantidadUsuarios_)
{
    cantidadLibros = cantidadUsuarios_;
}
// geters

const std::string &Biblioteca::getNombre() const
{
    return nombre;
}
const std::string &Biblioteca::gettDireccion() const
{
    return direccion;
}
const Libro *Biblioteca::getCatalogo() const
{
    return catalogo;
}
int Biblioteca::getCantidadLibros() const
{
    return cantidadLibros;
}
const Usuario *Biblioteca::getUsuarios() const
{
    return usuarios;
}
int Biblioteca::getCantidadUsuarios() const
{
    return cantidadUsuarios;
}

// metodos
void Biblioteca::mostrar() const
{

    std::cout << nombre << std::endl;
    std::cout << direccion << std::endl;
    std::cout << cantidadLibros << std::endl;
    std::cout << usuarios << std::endl;
}
void Biblioteca::agregarLibro(const Libro &libro)
{

    Libro *newLibro = new Libro[cantidadLibros + 1];
    for (int i = 0; i < cantidadLibros; i++)
    {
        newLibro[i] = catalogo[i];
    }

    newLibro[cantidadLibros] = libro;
    delete[] catalogo;
    catalogo = newLibro;
    setCantidadLibros(cantidadLibros + 1);
}
void Biblioteca::eliminarLibro(const std::string &titulo)
{

    int indice = -1;
    for (int i = 0; i < cantidadLibros; i++)
    {
        if (catalogo[i].getTitulo() == titulo)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        throw std::out_of_range("Error: la cantidad de libros que dispone es menor o igual a 0 no se puede eliminar");
    }

    Libro *newLibro = new Libro[cantidadLibros - 1];
    for (int i = 0; i < cantidadLibros; i++)
    {
        if (indice != i)
        {
            newLibro[i] = catalogo[i];
        }
    }

    delete[] catalogo;
    catalogo = newLibro;
    setCantidadLibros(cantidadLibros - 1);
}
Libro *Biblioteca::buscarLibro(const std::string &titulo)
{

    for (int i = 0; i < cantidadLibros; i++)
    {
        if (catalogo[i].getTitulo() == titulo)
        {
            return &catalogo[i];
        }
    }

    return nullptr;
}
void Biblioteca::agregarUsuario(const Usuario &usuario_)
{
    Usuario *newUsuario = new Usuario[cantidadUsuarios + 1];
    for (int i = 0; i < cantidadUsuarios; i++)
    {
        newUsuario[i] = usuarios[i];
    }

    newUsuario[cantidadUsuarios] = usuario_;
    delete[] usuarios;
    usuarios = newUsuario;
    setCantidadUsuarios(cantidadUsuarios + 1);
}
void Biblioteca::eliminarUsuario(const std::string &nombre)
{
    int indice = -1;
    for (int i = 0; i < cantidadUsuarios; i++)
    {
        if (usuarios[i].getNombre() == nombre)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        throw std::out_of_range("Error: la cantidad de usuarios que dispone es menor o igual a 0 no se puede eliminar");
    }

    Usuario *newUsuario = new Usuario[cantidadUsuarios - 1];
    for (int i = 0; i < cantidadUsuarios; i++)
    {
        if (indice != i)
        {
            newUsuario[i] = usuarios[i];
        }
    }

    delete[] usuarios;
    usuarios = newUsuario;
    setCantidadUsuarios(cantidadUsuarios - 1);
}
Usuario *Biblioteca::buscarUsuario(const std::string &nombre)
{

    for (int i = 0; i < cantidadUsuarios; i++)
    {
        if (usuarios[i].getNombre() == nombre)
        {
            return &usuarios[i];
        }
    }

    return nullptr;
}
void Biblioteca::mostrarLibrosPorGenero(const GeneroLibro &genero) const
{

    bool HayLibros = false;

    for (int i = 0; i < cantidadLibros; i++)
    {
        if (catalogo[i].getGeneroLibro() == genero)
        {
            catalogo[i].mostrar();
            HayLibros = true;
        }
    }

    if (!HayLibros)
    {
        std::cout << "La biblioteca no cuenta con libros de ese genero" << std::endl;
    }
}
void Biblioteca::mostrarUsuariosConLibrosPrestados() const
{

    bool libroPrestado = false;

    for (int i = 0; i < cantidadUsuarios; i++)
    {

        for (int j = 0; j < usuarios[i].getCantidadLibros(); j++)
        {

            if (usuarios[i].getLiBrosPrestados()[j].getEstadoLibro() == 1)
            {

                usuarios[i].mostrar();

                std::cout << "El libro prestado es: " << usuarios[i].getLiBrosPrestados()[j].getTitulo() << std::endl;
                libroPrestado = true;
            }
        }
    }

    if (!libroPrestado)
    {
        std::cout << "No hay usuarios con libros prestados" << std::endl;
    }
}
void Biblioteca::ordenarLibrosPorFecha()
{

    for (int i = 0; i < cantidadLibros - 1; i++)
    {

        for (int j = 0; j < cantidadLibros - i - 1; j++)
        {
            int anio = catalogo[j].getFechaPublicacion().anio;
            int mes = catalogo[j].getFechaPublicacion().mes;
            int dia = catalogo[j].getFechaPublicacion().dia;

            int anio2 = catalogo[j + 1].getFechaPublicacion().anio;
            int mes2 = catalogo[j + 1].getFechaPublicacion().mes;
            int dia2 = catalogo[j + 1].getFechaPublicacion().dia;
            bool fechaMayor = false;

            if (anio > anio2)
            {
                fechaMayor = true;
            }
            else if (anio == anio2)
            {
                if (mes > mes2)
                {
                    fechaMayor = true;
                }
                else if (mes == mes2)
                {
                    if (dia > dia2)
                    {
                        fechaMayor = true;
                    }
                }
            }

            if (fechaMayor)
            {

                Libro temp = catalogo[j];
                catalogo[j] = catalogo[j + 1];
                catalogo[j + 1] = temp;
            }
        }
    }
}
void Biblioteca::ordenarUsuariosPorCantidadLibros()
{

    for (int i = 0; i < cantidadUsuarios - 1; i++)
    {

        for (int j = 0; j < cantidadUsuarios - i - 1; j++)
        {

            if (usuarios[j].getCantidadLibros() > usuarios[j + 1].getCantidadLibros())
            {
                Usuario temp = usuarios[j];
                usuarios[j] = usuarios[j + 1];
                usuarios[j + 1] = temp;
            }
        }
    }
}