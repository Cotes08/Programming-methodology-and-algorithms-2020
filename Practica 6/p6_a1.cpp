/*
Práctica 6 A1 Algoritmos voraces

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Función para ordenar de manera decreciente los objetos de la mochila en relación a VALOR/PESO de cada objeto
void OrdenarDecreciente_VP(float *O, float *P, float *V, int n)
{

    // O = (1, 2) -> (2, 1)
    // V = (10, 24) -> (24, 10)
    // P = (5, 4) -> (4, 5)
    // V/P criterio

    // Variable auxiliar para intercambiar los valores
    float aux;

    // Bucle anidado para comprobar todos los elementos del vector
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            // Mientras no se sobrepase el tamaño del vector hacemos las comprobaciones
            if (i != n && j != n && V[j] / P[j] < V[j + 1] / P[j + 1])
            {

                aux = O[j];
                O[j] = O[j + 1];
                O[j + 1] = aux;

                aux = V[j];
                V[j] = V[j + 1];
                V[j + 1] = aux;

                aux = P[j];
                P[j] = P[j + 1];
                P[j + 1] = aux;
            }
        }
    }
}

// Función mochila
float *Mochila(float M, int n, float *O, float *P, float *V)
{

    float *X;
    int i;
    float peso;

    // Reservamos memoria para el vector
    X = new float[n + 1];

    // Comprobamos la reserva de memoria
    if (X == NULL)
    {

        cout << "Error al reservar memoria" << endl;
    }

    // init X
    for (i = 0; i <= n; i++)
    {
        X[i] = 0;
    }

    OrdenarDecreciente_VP(O, P, V, n);

    i = 1;
    peso = 0;

    while (peso < M && i <= n)
    {
        if (peso + P[i] <= M)
        {
            X[i] = 1;
            peso += P[i];
        }
        else
        {
            X[i] = (M - peso) / P[i];
            peso = M;
        }
        i++;
    }

    return X;
}

int main()
{

    int M; // Elementos mochila
    int n; // Items
    float *result;
    float *P, pesoFinal = 0;
    float *V, valorFinal = 0;
    float *O;

    cout << "Peso maximo de la mochila:" << endl;
    cin >> M;
    cout << "Total de objetos:" << endl;
    cin >> n;

    P = new float[n + 1];
    for (int i = 1; i <= n; i++)
    {

        cout << "Peso del objeto " << i << ":" << endl;
        cin >> P[i];
    }

    V = new float[n + 1];
    for (int i = 1; i <= n; i++)
    {

        cout << "Valor del objeto " << i << ":" << endl;
        cin >> V[i];
    }

    O = new float[n + 1];
    for (int i = 1; i <= n; i++)
    {

        O[i] = i;
    }

    result = Mochila(M, n, O, P, V);

    for (int i = 1; i <= n; i++)
    {

        pesoFinal = pesoFinal + (result[i] * P[i]);

        valorFinal = valorFinal + (result[i] * V[i]);

        cout << "Objeto introducido en la posicion " << i << " es el objeto: " << O[i] << " y se ha introducido: " << result[i] << endl;
    }

    cout << "Peso total de la mochila: " << pesoFinal << endl;
    cout << "Valor total de la mochila: " << valorFinal << endl;

    return 0;
}