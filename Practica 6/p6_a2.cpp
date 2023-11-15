/*
Práctica 6 A2 Algoritmos voraces

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

void OrdenarDecreciente_VP(float *O, float *P, float *V, int n)
{

    // O = (1, 2) -> (2, 1)
    // V = (10, 24)
    // P = (5, 4)

    float aux;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

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

    int M;
    int n;
    float *result;
    float *P, pesoFinal = 0;
    float *V, valorFinal = 0;
    float *O;

    FILE *fDatos;
    char linea[200], *tok, fichero[15];

    P = new float[n + 1];

    V = new float[n + 1];

    O = new float[n + 1];

    for (int i = 1; i <= n; i++)
    {

        O[i] = i;
    }

    cout << "Introduce nombre fichero: ";
    cin >> fichero;

    if (fichero == NULL)
        cout << "Fichero no existe" << endl;

    // Abrir fichero de nombre
    fDatos = fopen(fichero, "r");

    // Lectura de la primera linea
    fgets(linea, 200, fDatos);
    tok = strtok(linea, " \t\r\n");
    M = atoi(tok); // Convertir el token a entero

    // Lectura de la segunda linea
    fgets(linea, 200, fDatos);
    tok = strtok(linea, " \t\r\n");
    n = atoi(tok); // Convertir el token a entero

    // Lectura de la tercera linea
    fgets(linea, 200, fDatos);
    tok = strtok(linea, " \t\r\n");

    for (int i = 1; i <= n; i++)
    {

        P[i] = atoi(tok); // convertir el token a entero
        tok = strtok(NULL, " \t\r\n");
    }

    // Lectura de la cuarta linea
    fgets(linea, 200, fDatos);
    tok = strtok(linea, " \t\r\n");

    for (int i = 1; i <= n; i++)
    {

        V[i] = atoi(tok); // convertir el token a entero
        tok = strtok(NULL, " \t\r\n");
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

    fclose(fDatos);

    return 0;
}
