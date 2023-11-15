/*
Práctica 8 Vuelta atras

*/
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

float calcularsuma(int *X, float *PV, int k)
{
    float suma = 0;
    for (int i = 1; i <= k; i++)
    {
        if (X[i] == 1)
        {
            suma = suma + PV[i];
        }
    }
    return suma;
}

string vueltaatras(int n, float M, float *P, float *V, int *X, int k, int *Xoptimo, float &voptimo, string traza)
{
    stringstream ss;
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

                    cout << "valor=calcularsuma(X,V,k): " << valor << endl;
                    cout << "peso=calcularsuma(X,V,k): " << peso << endl;

                    if (valor > voptimo)
                    {

                        cout << "valor----->voptimo" << endl;
                        cout << "valor: " << valor << endl;
                        cout << "voptimo: " << voptimo << endl
                             << endl;

                        for (int j = 1; j <= n; j++)
                        {

                            Xoptimo[j] = X[j];

                            cout << "Xoptimo= " << Xoptimo[j] << " ";
                            cout << "X= " << X[j] << " ";
                        }

                        voptimo = valor;

                        cout << "Vop= " << voptimo << " ";
                    }
                }

                else
                    vueltaatras(n, M, P, V, X, k + 1, Xoptimo, voptimo, traza);
            }
        }
    }
    return traza;
}

int main()
{
    int n, k = 1, *Xoptimo, *X;
    float *V, *P, M, voptimo = -1000;
    int i;
    string traza = "";

    cout << "Introduce el peso maximo de la mochila (M):";
    cin >> M;
    cout << "Introduce el total de objetos (n):";
    cin >> n;

    cout << endl;

    X = new int[n + 1];
    Xoptimo = new int[n + 1];

    P = new float[n + 1];
    V = new float[n + 1];

    cout << "PESOS:" << endl;

    for (i = 1; i <= n; i++)
    {

        cout << "Objeto " << i << ":";
        cin >> P[i];
        cout << endl;
    }

    cout << "VALORES:" << endl;

    for (i = 1; i <= n; i++)
    {
        cout << "Objeto " << i << ":";
        cin >> V[i];
        cout << endl;
    }

    cout << endl;

    cout << "OBJETOS A INTRODUCIR EN LA MALETA" << endl;

    traza = vueltaatras(n, M, P, V, X, k, Xoptimo, voptimo, traza);

    float peso = 0;

    // cout<< "valor= "<<valor<<"  ";
    cout << "Xoptimo=(";
    for (int j = 1; j <= n; j++)
    {

        cout << Xoptimo[j];
        if (j != n)
            traza += ",";
        if (Xoptimo[j] == 1)
        {

            // cout<<j<<": "<<P[j]<<"kg - Valor: "<<V[j]<<endl;

            peso = peso + P[j];
        }
    }

    cout << ")  ";
    cout << "voptimo=" << voptimo << endl;

    cout << endl;

    cout << "Peso: " << peso << endl;
    cout << "Valor: " << voptimo << endl;

    cout << endl;

    cout << "OBJETOS QUE QUEDAN FUERA:";

    for (int j = 1; j <= n; j++)
    {

        if (Xoptimo[j] == 0)
        {

            if (j <= n)
                cout << " ";

            cout << j;
        }
    }
    cout << traza;
    cout << endl;

    delete[] X;
    delete[] Xoptimo;
    delete[] P;
    delete[] V;

    return 0;
}