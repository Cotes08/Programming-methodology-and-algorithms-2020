/*
Práctica 7 Programación dinámica

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

float maximo(float antes, float suma)
{

    // Quédate entre lo que conseguías antes o lo que tenías antes más lo que vas a meter

    if (antes >= suma)
        return antes;

    return suma; // if(suma >= antes)
}

float mochila(int M, int n, int *P, float *V)
{

    float **T;
    int i, j;

    // Reservamos memoria para la matriz
    T = new float *[n + 1];

    if (T == NULL)
    {

        cout << "Error al reservar memoria" << endl;
        return -1;
    }

    for (i = 0; i <= n; i++)
    {

        T[i] = new float[M + 1];

        if (T[i] == NULL)
        {

            cout << "Error al reservar memoria" << endl;
            return -1;
        }
    }

    // Inicializamos la primera fila de la matriz a 0
    for (i = 0; i <= M; i++)
    {

        T[0][i] = 0;
    }

    // Inicializamos la primera columna de la matriz a 0
    for (i = 0; i <= n; i++)
    {

        T[i][0] = 0;
    }

    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= M; j++)
        {

            if (P[i] > j)
            {

                T[i][j] = T[i - 1][j];
            }
            else
            {

                T[i][j] = maximo(T[i - 1][j], V[i] + T[i - 1][j - P[i]]);
            }
        }
    }

    // Mostramos la matriz con sus valores
    cout << "Contenido de la matriz: " << endl;
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= M; j++)
        {

            cout << T[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;

    return T[n][M];
}

int main()
{

    int M, *P, n;
    float *V;

    cout << "Peso maximo de la mochila: ";
    cin >> M;

    cout << endl;

    cout << "Total de objetos: ";
    cin >> n;

    cout << endl;

    P = new int[n + 1];

    if (P == NULL)
    {

        cout << "Error al reservar memoria para pesos_objetos" << endl;

        return -1;
    }

    for (int i = 1; i <= n; i++)
    {

        cout << "Peso del objeto " << i << ": ";
        cin >> P[i];

        cout << endl;
    }

    V = new float[n + 1];

    if (V == NULL)
    {

        cout << "Error al reservar memoria para valores_objetos" << endl;

        return -1;
    }

    for (int i = 1; i <= n; i++)
    {

        cout << "Valor del objeto " << i << ": ";
        cin >> V[i];

        cout << endl;
    }

    cout << "Valor maximo que puede llevar: " << mochila(M, n, P, V);

    cout << endl;

    delete[] P;

    delete[] V;

    return 0;
}
