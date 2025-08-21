#include <iostream>

// Con
void punteroFuncion(int *&, int *&);
void sumaPunterosArr(int *, int &);
void funcionPunteroDoble(int **);

int main()
{
    int numero1 = 5;
    int *puntero1 = &numero1;

    *puntero1 = 8;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << numero1 << std::endl;
    std::cout << &numero1 << std::endl;
    std::cout << puntero1 << std::endl;
    std::cout << *puntero1 << std::endl;
    std::cout << &puntero1 << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    int *puntero2 = nullptr;
    if (puntero2 != nullptr)
    {
        std::cout << "apunta a algo" << std::endl;
    }

    int x = 5;
    int y = 10;

    int *numeroPuntero1 = &x;
    int *numeroPuntero2 = &y;

    std::cout << &x << std::endl;
    std::cout << &y << std::endl;
    std::cout << numeroPuntero1 << std::endl;
    std::cout << numeroPuntero2 << std::endl;
    std::cout << &numeroPuntero1 << std::endl;
    std::cout << &numeroPuntero2 << std::endl;

    punteroFuncion(numeroPuntero1, numeroPuntero2);

    std::cout << "---------------------------------------punteroFuncion-------------------------------------------------" << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << numeroPuntero1 << std::endl;
    std::cout << numeroPuntero2 << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    int *arrPunter[10];
    int arreglo[6] = {1, 2, 3, 4, 5, 6};
    arrPunter[0] = &arreglo[0];

    for (int i = 0; i < 10; i++)
    {
        std::cout << *arrPunter[0]++ << std::endl;
    }

    for (int i = 0; i < 6; i++)
    {
        std::cout << *(arreglo + i) << std::endl;
    }

    int auxPunteroXX = 5;
    int *punteroAuxPunteroDoble = &auxPunteroXX;
    int **arrPunterXXX = &punteroAuxPunteroDoble;

    std::cout << "----------------------------------auxPunteroXX------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << auxPunteroXX << std::endl;
    std::cout << &auxPunteroXX << std::endl;
    std::cout << punteroAuxPunteroDoble << std::endl;
    std::cout << *punteroAuxPunteroDoble << std::endl;
    std::cout << &punteroAuxPunteroDoble << std::endl;

    std::cout << **arrPunterXXX << std::endl;
    std::cout << *arrPunterXXX << std::endl;
    std::cout << arrPunterXXX << std::endl;
    std::cout << &arrPunterXXX << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    int arreglo3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sumador{};
    sumaPunterosArr(arreglo3, sumador);

    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << sumador << std::endl;

    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    int auxPunteroSolo = 8;
    int *auxPunteroDoble = &auxPunteroSolo;
    int **punteroDoble = &auxPunteroDoble;

    funcionPunteroDoble(punteroDoble);

    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << auxPunteroSolo << std::endl;
    std::cout << &auxPunteroSolo << std::endl;
    std::cout << std::endl;
    std::cout << *auxPunteroDoble << std::endl;
    std::cout << auxPunteroDoble << std::endl;
    std::cout << &auxPunteroDoble << std::endl;
    std::cout << std::endl;
    std::cout << **punteroDoble << std::endl;
    std::cout << *punteroDoble << std::endl;
    std::cout << punteroDoble << std::endl;
    std::cout << &punteroDoble << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    **punteroDoble = 3;

    std::cout << std::endl;
    std::cout << *auxPunteroDoble << std::endl;
    std::cout << auxPunteroDoble << std::endl;
    std::cout << &auxPunteroDoble << std::endl;
    std::cout << std::endl;
    std::cout << **punteroDoble << std::endl;
    std::cout << *punteroDoble << std::endl;
    std::cout << punteroDoble << std::endl;
    std::cout << &punteroDoble << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    delete punteroDoble;
    punteroDoble = nullptr;

    std::cout << std::endl;
    std::cout << *auxPunteroDoble << std::endl;
    std::cout << auxPunteroDoble << std::endl;
    std::cout << &auxPunteroDoble << std::endl;
    std::cout << std::endl;
    std::cout << **punteroDoble << std::endl;
    std::cout << *punteroDoble << std::endl;
    std::cout << punteroDoble << std::endl;
    std::cout << &punteroDoble << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    return 0;
}

//*& permite cambiar la referencia a la que apuntaen el misma funcion y si afuera tengo un puntero asignado con memoria dinamica dentro lo puedo desreferencia y asignar a nueva memoria dinamica la cual sobrevira al terminar la funcion
void punteroFuncion(int *&num1, int *&num2)
{

    std::cout << "----------------------------------------------------------------------------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << "----------------------------------------------------------------------------------------" << std::endl;

    // Aca se modifica  *temp qyue apounta a la misma direccion de memoria por lo tanto cuando intento asignar se pierde el valor de num1 y por eso repite el valor en los  2
    //  int *temp = num1;
    //  *num1 = *num2;
    //  *num2 = *temp;

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void sumaPunterosArr(int *arr, int &sumador)
{

    for (int i = 0; i < 10; i++)
    {
        sumador += *(arr + i);
    }
}

void funcionPunteroDoble(int **punteroDoble)
{

    **punteroDoble = 42;
    *punteroDoble = new int(8);
}