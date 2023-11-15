#include <iostream>
using namespace std;

int seleccionar_pivote(int *V, int izq, int der)
{
    int pos_izq, pos_der, pos_cen;
    pos_izq = izq;
    pos_der = der;
    pos_cen = (pos_izq + pos_der) / 2;
    if ((V[pos_izq] < V[pos_cen]) && (V[pos_cen] < V[pos_der]))
    {
        return pos_cen;
    }
    if ((V[pos_izq] < V[pos_cen]) && (V[pos_cen] > V[pos_der]) && (V[pos_izq] < V[pos_der]))
    {
        return pos_der;
    }
    if ((V[pos_izq] > V[pos_cen]) && (V[pos_cen] < V[pos_der]))
    {
        return pos_izq;
    }
    if ((V[pos_izq] > V[pos_cen]) && (V[pos_cen] > V[pos_der]))
    {
        return pos_cen;
    }
    if ((V[pos_izq] < V[pos_cen]) && (V[pos_cen] > V[pos_der]) && (V[pos_izq] > V[pos_der]))
    {
        return pos_izq;
    }
    if (V[pos_izq] > V[pos_der])
    {
        return pos_izq;
    }
    else
    {
        return pos_izq;
    }

    return 0;
}

void quicksort(int *V, int izq, int der)
{
    int i, d, p, pivote;

    p = seleccionar_pivote(V, izq, der);

    if (p > 0)
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
                int aux;
                aux = V[i];
                V[i] = V[d];
                V[d] = aux;

                i++;
                d--;
            }
        }
        // for ( int j=1; j<=der ; j++)
        //{
        //     cout<< " " << V[j];
        // }
        // cout<< "\n";
        if (izq < d)
            quicksort(V, izq, d);
        if (i < der)
            quicksort(V, i, der);
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
    quicksort(V, 1, n);
    cout << "Vector ordenado:";
    for (i = 1; i <= n; i++)
    {
        cout << " " << V[i];
    }
    cout << endl;
}
