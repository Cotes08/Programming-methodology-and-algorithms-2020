#include <iostream>
using namespace std;

int seleccionar_pivote(int *V, int izq, int der)
{
    // devolvemos el primer elemento de la izquierda del vector
    return izq;
}

void quicksort(int *V, int izq, int der, int cont)
{

    int i, d, p, pivote;

    p = seleccionar_pivote(V, izq, der);

    if (p > 0)
    {

        pivote = V[p];

        i = izq;

        d = der;

        cout << cont << ".- "
             << "quicksort(V," << V[izq] << "," << V[der] << ")" << endl;

        cout << "p = " << p << endl;

        cout << "pivote = " << pivote << endl;

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
                int aux;
                aux = V[i];
                V[i] = V[d];
                V[d] = aux;

                i++;
                d--;
            }
        }

        for (int j = 1; j <= der; j++)
        {

            cout << " " << V[j];
        }

        cout << "\n";

        cont++;

        if (izq < d)
            quicksort(V, izq, d, cont);
        if (i < der)
            quicksort(V, i, der, cont);
    }
}

int main()
{
    int n;
    cout << "Introduce el numero de elementos del vector:";
    cin >> n;
    cout << endl;

    int *V;
    V = new int(n + 1);

    int i;
    for (i = 1; i <= n; i++)
    {
        cout << "Introduce elemento " << i << ":";
        cin >> V[i];
        cout << endl;
    }
    cout << "Vector original:";
    for (i = 1; i <= n; i++)
    {
        cout << " " << V[i];
    }
    cout << endl;
    quicksort(V, 1, n, 1);
    cout << "Vector ordenado:";
    for (i = 1; i <= n; i++)
    {
        cout << " " << V[i];
    }
    cout << endl;
}
