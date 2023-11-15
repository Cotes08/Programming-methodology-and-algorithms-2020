
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct Nodo
{
    string nprog;
    int nivel;          // nivel en el arbol
    float valor, corte; // valor(en realidad haría falta valor y peso, pero para este caso no es necesario) con esto compara qué elemento prefiere
};                      // corte es el límite donde deja de probar combinaciones al ser un caso peor

int seleccionar_pivote(float *Vec, int izq, int der)
{
    int centro = (izq * der) / 2;
    if ((Vec[izq] > Vec[der] && Vec[izq] < Vec[centro]) || (Vec[izq] < Vec[der] && Vec[izq] > Vec[centro]))
        return izq;
    else if ((Vec[der] > Vec[izq] && Vec[der] < Vec[centro]) || (Vec[der] < Vec[izq] && Vec[der] > Vec[centro]))
        return der;
    else
        return centro;
}

void quicksort(float *V, int izq, int der, string *nomprog)
{ // 5 10 7 13 14 16 1 12
    int i, d, p;
    float pivote;
    p = seleccionar_pivote(V, izq, der); // 5 13 12     se queda con 12
    if (p >= 0)
    {
        pivote = V[p];
        i = izq;
        d = der;

        while (i <= d)
        {
            while (V[i] < pivote)
            {
                i++;
            }
            while (V[d] > pivote)
            {
                d--;
            }
            if (i <= d)
            {
                double aux;
                string aux2;
                aux2 = nomprog[i];
                nomprog[i] = nomprog[d];
                nomprog[d] = aux2;
                aux = V[i];
                V[i] = V[d];
                V[d] = aux;
                i++;
                d--;
            }
        }
        if (izq < d)
            quicksort(V, izq, d, nomprog);
        if (i < der)
            quicksort(V, i, der, nomprog);
    }
}

float calcularsuma(int *X, float *PV, int k)
{
    float suma = 0;
    for (int i = 1; i <= k; i++)
    {
        suma = suma + PV[i] * X[i];
        // cout<<"Suma: "<< suma << endl;
    }
    return suma;
}

void vueltaatras(int n, float M, float *P, float *V, int *X, int k, int *Xoptimo, float &voptimo)
{

    int i;
    float peso = 0, valor;

    if (k <= n)
    {

        for (i = 0; i <= 1; i++)
        {

            X[k] = i;
            peso = calcularsuma(X, P, k);

            if (peso <= M)
            {

                if (k == n)
                {

                    valor = calcularsuma(X, V, k);

                    if (valor > voptimo)
                    {

                        for (int j = 1; j <= n; j++)
                        {

                            Xoptimo[j] = X[j];
                        }
                        voptimo = valor;
                    }
                }
                else
                    vueltaatras(n, M, P, V, X, k + 1, Xoptimo, voptimo);
            }
        }
    }
}

int main()
{

    int opcion, numprog = 0, i, n, k = 1, *Xoptimo, *X, cont;
    char *archivo, linea[30];
    string *programa;
    float *peso, *peso2, moch, ram = 0, suma = 0, voptimo = -1000, pesoaux = 0;

    do
    {

        cout << endl
             << "1.- Obtener lista de programas." << endl;
        cout << "2.- Capacidad disponible en la memoria." << endl;
        cout << "3.- Grabar maximo numero de programas." << endl;
        cout << "4.- Grabar maximo de capacidad." << endl;
        cout << "5.- Salir." << endl;

        cout << "Introduce la opcion que deseas realizar: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            archivo = new char;
            cout << "Nombre del archivo: ";
            cin >> archivo;

            FILE *datos;
            datos = fopen(archivo, "r");

            if (!datos)
            {
                cout << "No se ha encontrado el fichero indicado.\n";
                break;
            }

            fgets(linea, 30, datos);
            numprog = atoi(linea);

            programa = new string[numprog + 1];
            peso = new float[numprog + 1];
            peso2 = new float[numprog + 1];
            for (int i = 0; i < numprog; i++)
            {
                // Lectura de la segunda linea
                fgets(linea, 30, datos);
                programa[i + 1] = linea;

                // Lectura de la segunda linea
                fgets(linea, 30, datos);
                peso[i + 1] = atof(linea); // Convertir el token a entero
                peso2[i + 1] = peso[i + 1];
            }
            cout << endl
                 << "Numero de programas: " << numprog << endl
                 << endl;
            for (int i = 1; i <= numprog; i++)
            {
                cout << "Nombre del programa: " << programa[i];
                cout << "Peso del programa: " << peso[i] << endl
                     << endl;
            }
            break;
        case 2:
            cout << "Indica el espacio de memoria libre(GBs): ";
            cin >> ram;
            cout << endl;

            break;

        case 3:

            quicksort(peso, 1, numprog, programa);

            i = 1;
            cout << endl;
            cout << "----- Programas maximos que se pueden introducir -----" << endl
                 << endl;
            while ((ram >= peso[i] + suma) && (i <= numprog))
            {
                suma += peso[i];
                cout << "Programa " << i << ": " << programa[i];
                // cout << "Suma: " << suma << endl;
                i++;
            }
            cout << endl
                 << "Memoria usada: " << suma << endl;
            cout << "Maximo numero de programas: " << i - 1 << endl
                 << endl;

            break;

        case 4:
            pesoaux = 0;
            voptimo = 0;
            n = sizeof(peso);

            cout << endl;

            X = new int[n + 1];
            Xoptimo = new int[n + 1];

            cout << endl;

            cout << "----- Programas para maximizar el uso de ram -----" << endl
                 << endl;

            vueltaatras(n, ram, peso, peso2, X, k, Xoptimo, voptimo);
            cont = 0;
            for (int j = 1; j <= n; j++)
            {

                if (Xoptimo[j] == 1)
                {

                    cout << j << ": " << peso[j] << "GB " << programa[j];

                    pesoaux = pesoaux + peso[j];
                    cont++;
                }
            }

            cout << endl;
            cout << "Numero de programas utilizados: " << cont << endl;
            cout << "Ram utilizada: " << pesoaux << "GB. " << endl;

            cout << endl;

            cout << "Programa/s que queda/n fuera:";

            for (int j = 1; j <= n; j++)
            {

                if (Xoptimo[j] == 0)
                {

                    if (j <= n)
                        cout << " ";

                    cout << j;
                }
            }
            cout << endl;

            delete[] X;
            delete[] Xoptimo;

            break;

        default:
            break;
        }
    } while (opcion != 5);
    return 0;
}