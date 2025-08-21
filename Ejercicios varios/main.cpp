#include <iostream>
struct nodo
{
    int dato;
    nodo *siguiente;
};

int main()
{

    // int num = 2;
    // int *puntero = new int;
    // puntero = &num;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << &num << std::endl;
    // std::cout << num << std::endl;
    // std::cout << &puntero << std::endl;
    // std::cout << *puntero << std::endl;
    // std::cout << puntero << std::endl;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;

    // int num2 = 2;
    // int *puntero2 = new int[2];
    // puntero2[0] = num2;
    // puntero2[1] = 3;

    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << &puntero2 << std::endl;
    // std::cout << *puntero2 << std::endl;
    // std::cout << puntero2 << std::endl;
    // std::cout << puntero2[0] << std::endl;
    // std::cout << puntero2[1] << std::endl;
    // std::cout << &puntero2[0] << std::endl;
    // std::cout << &puntero2[1] << std::endl;

    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;

    // int **puntero3 = new int *[2];
    // puntero3[0] = new int(2);
    // puntero3[1] = new int(3);

    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << &puntero3 << std::endl;
    // std::cout << **puntero3 << std::endl;
    // std::cout << *puntero3 << std::endl;
    // std::cout << puntero3 << std::endl;
    // std::cout << *puntero3[0] << std::endl;
    // std::cout << puntero3[0] << std::endl;
    // std::cout << &puntero3[0] << std::endl;
    // std::cout << *puntero3[1] << std::endl;
    // std::cout << puntero3[1] << std::endl;
    // std::cout << &puntero3[1] << std::endl;

    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;

    // int a = 5, b = 10;
    // int *p1 = &a;
    // int *p2 = &b;
    // int **pp = new int *[2]{p1, p2};
    // int **temp2 = pp;
    // for (int i = 0; i < 2; i++)
    // {
    //     std::cout << **temp2 << std::endl;
    //     std::cout << *temp2 << std::endl;
    //     std::cout << temp2 << std::endl;

    //     temp2++;
    // }
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // int num1x = 7, num2x = 14, num3x = 21;
    // int *puntero1x = &num1x;
    // int *puntero2x = &num2x;
    // int *puntero3x = &num3x;

    // int **punteroDoble = new int *[3]{puntero1x, puntero2x, puntero3x};
    // int **tempx = punteroDoble;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << puntero1x << std::endl;
    // std::cout << &puntero1x << std::endl;
    // std::cout << puntero2x << std::endl;
    // std::cout << &puntero2x << std::endl;
    // std::cout << puntero3x << std::endl;
    // std::cout << &puntero3x << std::endl;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
    // for (int i = 0; i < 2; i++)
    // {
    //     std::cout << **tempx << std::endl;
    //     std::cout << *tempx << std::endl;
    //     std::cout << tempx << std::endl;
    //     std::cout << &punteroDoble[i] << std::endl;
    //     tempx++;
    // }

    nodo *cabeza = nullptr;

    // cabeza->siguiente == nodo1->siguiente
    nodo *nodo1 = new nodo;
    nodo1->dato = 5;
    nodo1->siguiente = nullptr;
    cabeza = nodo1;

    nodo *nodo2 = new nodo;
    nodo2->dato = 6;
    nodo2->siguiente = nullptr;
    nodo1->siguiente = nodo2;

    nodo *nodo3 = new nodo;
    nodo3->dato = 7;
    nodo3->siguiente = nullptr;
    nodo2->siguiente = nodo3;

    nodo *nodo4 = new nodo;
    nodo4->dato = 8;
    nodo4->siguiente = nullptr;
    nodo3->siguiente = nodo4;

    //     nodo* actual = cabeza;
    // actual copia el valor del puntero cabeza, es decir, la dirección del primer nodo.
    // Pero actual y cabeza son punteros distintos.
    // Mover actual no cambia cabeza.

    int numeroLista = 9;
    nodo *nodo5 = new nodo;
    nodo5->dato = numeroLista;
    nodo5->siguiente = nullptr;

    if (cabeza == nullptr)
    {
        cabeza = nodo5;
    }
    else
    {

        nodo *actual = cabeza;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nodo5;
    }

    int numeroLista2 = 10;
    nodo *nodo6 = new nodo;
    nodo6->dato = numeroLista2;
    nodo6->siguiente = nullptr;

    if (nodo6 == nullptr)
    {
        cabeza = nodo6;
    }
    else
    {

        nodo *actual = cabeza;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nodo6;
    }

    int numeroLista3 = 4;
    nodo *nodo7 = new nodo;
    nodo7->dato = numeroLista3;
    nodo7->siguiente = cabeza;
    cabeza = nodo7;

    if (cabeza->dato == 4)
    {
        nodo *temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    nodo *actualizado = cabeza;
    while (actualizado->siguiente != nullptr && actualizado->siguiente->dato != 9)
    {
        actualizado = actualizado->siguiente;
    }

    if (actualizado->siguiente != nullptr)
    {
        nodo *temp = actualizado->siguiente;
        actualizado->siguiente = actualizado->siguiente->siguiente;
        delete temp;
    }

    nodo *tempxxx = cabeza;

    while (tempxxx != nullptr)
    {
        std::cout << tempxxx->dato << std::endl;
        tempxxx = tempxxx->siguiente;
    }

    return 0;
}