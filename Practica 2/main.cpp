#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void intercambiar(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void seleccion(int *&V, int n)
{
    int posmin, i, j;

    for (i = 1; i <= n - 1; i++)
    {
        posmin = i;
        for (j = i + 1; j <= n; j++)
        {
            if (V[j] < V[posmin])
            {
                posmin = j;
            }
        }
        intercambiar(V[i], V[posmin]);
    }
}

void seleccionInversa(int *&v, int n)
{
    int i, j, posmin;

    for (i = 1; i < n - 1; i++)
    {
        posmin = i;

        for (j = i + 1; j < n; j++)
        {
            if (v[j] > v[posmin])
                posmin = j;
        }
        intercambiar(v[i], v[posmin]);
    }
}

int main()
{
    clock_t tinicio, tfin;
    double tiempo;
    int i, semilla, inicial, fin, tamanov;

    cout << "Semilla para generar aleatorios: ";
    cin >> semilla;
    cout << "Introduce el tamano del vector: ";
    cin >> tamanov;
    cout << "Posiciones INICIAL y Final del vector para mostrar" << endl;
    cout << "INICIAL: ";
    cin >> inicial;
    cout << "FINAL: ";
    cin >> fin;
    srand(semilla);
    int *V = new int[tamanov + 1];

    for (i = 1; i <= tamanov; i++)
    {
        V[i] = rand();
    }

    cout << "\n\nALGORITMO DE SELECCION \n\n";

    cout << "CASO CUALQUIERA" << endl;
    cout << "-----------------" << endl;
    cout << "Vector a ordenar: ";
    for (i = inicial; i <= fin; i++)
    {
        cout << " " << V[i] << " ";
    }
    tinicio = clock();
    seleccion(V, tamanov);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    cout << "\nVector ordenado: ";
    for (i = inicial; i <= fin; i++)
    {
        cout << " " << V[i] << " ";
    }
    cout << "\nEl tiempo de ejecucion en ms es " << tiempo << endl;

    cout << "\nCASO MEJOR" << endl;
    cout << "-----------------" << endl;
    cout << "Vector a ordenar: ";
    for (i = inicial; i <= fin; i++)
    {
        cout << " " << V[i] << " ";
    }
    tinicio = clock();
    seleccion(V, tamanov);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    cout << "\nVector ordenado: ";
    for (i = inicial; i <= fin; i++)
    {
        cout << " " << V[i] << " ";
    }
    cout << "\nEl tiempo de ejecucion en ms es " << tiempo << endl;

    cout << "\nCASO PEOR" << endl;
    cout << "-----------------" << endl;

    seleccionInversa(V, tamanov);

    cout << "Vector a ordenar: ";
    for (i = inicial; i <= fin; i++)
    {
        cout << " " << V[i] << " ";
    }
    tinicio = clock();
    seleccion(V, tamanov);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    cout << "\nVector ordenado: ";
    for (i = inicial; i <= fin; i++)
    {
        cout << " " << V[i] << " ";
    }
    cout << "\nEl tiempo de ejecucion en ms es " << tiempo << endl;
}
