#include <iostream>

int sumarArreglo(int *arr, int n);
int *mayorElemento(int *arr, int n);

int main()
{
    int numero = 10;
    int *p = &numero;

    std::cout << numero << std::endl;
    std::cout << &numero << std::endl;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    std::cout << &p << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

    *p = 11;

    int arr[5] = {1, 2, 3, 4, 5};
    int *auxArr = arr; // arr decae a puntero al primer elemento

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(auxArr + i) << std::endl;
    }

    int suma = 0;
    int minimo = arr[0];
    int maximo = arr[0];

    for (int i = 0; i < 5; i++)
    {
        suma += *(arr + i);

        if (*(arr + i) > maximo)
        {
            maximo = *(arr + i);
        }

        if (*(arr + i) < minimo)
        {
            minimo = *(arr + i);
        }
    }
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << suma << std::endl;
    std::cout << minimo << std::endl;
    std::cout << maximo << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

    int suma2 = 0;
    int *maximo2{arr};
    int *minimo2{arr};

    /**Sobre escribe el valor* */
    // int suma2 = 0;
    // int *maximo2{arr};
    // int *minimo2{arr};
    // for (int i = 0; i < 5; i++)
    // {

    //     suma2 += *(arr + i);
    //     if (*(arr + i) > *maximo2)
    //     {
    //         *maximo2 = *(arr + i);
    //     }

    //     if (*(arr + i) < *minimo2)
    //     {
    //         *minimo2 = *(arr + i);
    //     }
    // }

    for (int i = 0; i < 5; i++)
    {

        suma2 += *(arr + i);
        if (*(arr + i) > *maximo2)
        {
            maximo2 = (arr + i);
        }

        if (*(arr + i) < *minimo2)
        {
            minimo2 = (arr + i);
        }
    }

    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << suma2 << std::endl;

    std::cout << *maximo2 << std::endl;
    std::cout << maximo2 << std::endl;

    std::cout << *minimo2 << std::endl;
    std::cout << minimo2 << std::endl;
    std::cout << std::endl;

    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "-------------------------------------Invertir arreglo---------------------------------------------------------" << std::endl;
    int arr2[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5 / 2; i++)
    {
        int temp = *(arr2 + i);
        *(arr2 + i) = *(arr2 + (5 - 1 - i));
        *(arr2 + (5 - 1 - i)) = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(arr2 + i) << std::endl;
    }

    std::cout << "-------------------------------------Buscar Valor---------------------------------------------------------" << std::endl;
    int arrBuscar[5] = {1, 2, 3, 4, 5};
    int *Buscador = arrBuscar;
    int numerBuscar = 4;
    for (int i = 0; i < 5; i++)
    {

        if (*(arrBuscar + i) == numerBuscar)
        {
            Buscador = (arrBuscar + i);
            break;
        }
    }
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << *Buscador << std::endl;
    std::cout << Buscador << std::endl;
    std::cout << &arrBuscar[3] << std::endl;

    std::cout << "-------------------------------------------Ordenamiento---------------------------------------------------" << std::endl;

    int arrOrdenar[5] = {2, 5, 1, 3, 4};
    int contadorOrdenador = 5;

    for (int i = 0; i < contadorOrdenador - 1; i++)
    {
        for (int j = 0; j < contadorOrdenador - i - 1; j++)
        {

            if (*(arrOrdenar + j) > *(arrOrdenar + j + 1))
            {
                int temp = *(arrOrdenar + j);
                *(arrOrdenar + j) = *(arrOrdenar + j + 1);
                *(arrOrdenar + j + 1) = temp;
            }
        }
    }

    for (int i = 0; i < contadorOrdenador; i++)
    {
        std::cout << *(arrOrdenar + i) << std::endl;
    }
    std::cout << "-------------------------------------------funcion suma---------------------------------------------------" << std::endl;
    int arrTotal[5] = {2, 5, 1, 3, 4};

    int retornoSuma = sumarArreglo(arrTotal, 5);
    std::cout << retornoSuma << std::endl;

    std::cout << "-------------------------------------------Mayor Elemento---------------------------------------------------" << std::endl;
    int arrTotalMayor[5] = {2, 5, 1, 8, 4};
    int *retorMayorPuntero = mayorElemento(arrTotalMayor, 5);
    std::cout << *retorMayorPuntero << std::endl;
    std::cout << retorMayorPuntero << std::endl;

    std::cout << arrTotalMayor[3] << std::endl;
    std::cout << &arrTotalMayor[3] << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    *retorMayorPuntero = 10;

    for (int i = 0; i < 5; i++)
    {
        std::cout << arrTotalMayor[i] << std::endl;
    }

    std::cout << "-------------------------------------Puntero dinamico recorrer---------------------------------------------------------" << std::endl;
    int numeroDePunterosArr = 5;
    int *punteroDinamicoArr = new int[numeroDePunterosArr];
    int *recorrerPunteroDinamico = punteroDinamicoArr;

    for (int i = 0; i < numeroDePunterosArr; i++)
    {
        *recorrerPunteroDinamico = i + 1;
        recorrerPunteroDinamico++;
    }
    // Queda al final del arreglo asi que debo volver a asignarlo
    // se debe resetear el puntero
    recorrerPunteroDinamico = punteroDinamicoArr;

    for (int i = 0; i < numeroDePunterosArr; i++)
    {
        std::cout << *recorrerPunteroDinamico << std::endl;
        recorrerPunteroDinamico++;
    }

    delete[] punteroDinamicoArr;

    std::cout << "-------------------------------------Puntero dinamico recorrer de forma normal---------------------------------------------------------" << std::endl;
    int numeroDePunterosArr2 = 5;
    int *punteroDinamicoArr2 = new int[numeroDePunterosArr2];
    int *recorrerPunteroDinamico2 = punteroDinamicoArr2;

    for (int i = 0; i < numeroDePunterosArr2; i++)
    {
        punteroDinamicoArr2[i] = i + 1;
    }
    // Queda al final del arreglo asi que debo volver a asignarlo
    // recorrerPunteroDinamico = punteroDinamicoArr;

    for (int i = 0; i < numeroDePunterosArr2; i++)
    {
        std::cout << punteroDinamicoArr2[i] << std::endl;
    }

    delete[] punteroDinamicoArr2;

    std::cout << "-------------------------------------Puntero dinamico recorrer de forma normal---------------------------------------------------------" << std::endl;

    int numeroDePunterosArr3 = 5;
    int *punteroDinamicoArr3 = new int[numeroDePunterosArr3];
    int *recorrerPunteroDinamico3 = punteroDinamicoArr3;
    int sumador = 0;

    for (int i = 0; i < numeroDePunterosArr3; i++)
    {
        *recorrerPunteroDinamico3 = i + 2;
        recorrerPunteroDinamico3++;
    }
    // Queda al final del arreglo asi que debo volver a asignarlo
    recorrerPunteroDinamico3 = punteroDinamicoArr3;

    for (int i = 0; i < numeroDePunterosArr3; i++)
    {

        sumador += *recorrerPunteroDinamico3;
        recorrerPunteroDinamico3++;
    }
    recorrerPunteroDinamico3 = punteroDinamicoArr3;

    for (int i = 0; i < numeroDePunterosArr3; i++)
    {
        std::cout << *recorrerPunteroDinamico3 << std::endl;
        recorrerPunteroDinamico3++;
    }

    std::cout << sumador << std::endl;

    delete[] punteroDinamicoArr3;

    std::cout << "-------------------------------------Invertir un arreglo dinamico---------------------------------------------------------" << std::endl;

    int numeroDePunterosArr4 = 5;
    int *punteroDinamicoArr4 = new int[numeroDePunterosArr4];
    int *recorrerPunteroDinamico4 = punteroDinamicoArr4;

    for (int i = 0; i < numeroDePunterosArr4; i++)
    {
        *recorrerPunteroDinamico4 = i + 1;
        recorrerPunteroDinamico4++;
    }
    // Queda al final del arreglo asi que debo volver a asignarlo
    recorrerPunteroDinamico4 = punteroDinamicoArr4;

    for (int i = 0; i < numeroDePunterosArr4 / 2; i++)
    {
        int temp = *(recorrerPunteroDinamico4 + i);
        *(recorrerPunteroDinamico4 + i) = *(recorrerPunteroDinamico4 + (numeroDePunterosArr4 - i - 1));
        *(recorrerPunteroDinamico4 + (numeroDePunterosArr4 - i - 1)) = temp;
    }

    for (int i = 0; i < numeroDePunterosArr4; i++)
    {
        std::cout << *recorrerPunteroDinamico4 << std::endl;
        recorrerPunteroDinamico4++;
    }

    delete[] punteroDinamicoArr4;

    return 0;
}

int sumarArreglo(int *arr, int n)
{

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += *(arr + i);
    }

    return total;
}

int *mayorElemento(int *arr, int n)
{
    int *mayor = arr;
    for (int i = 0; i < n; i++)
    {

        if (*(arr + i) > *mayor)
        {
            mayor = (arr + i);
        }
    }

    return mayor;
}