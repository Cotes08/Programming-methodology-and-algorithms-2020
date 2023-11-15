#include <iostream>

using namespace std;

int contar(int *V, int x, int n)
{
    int i, nveces = 0;

    for (i = 1; i <= n; i++)
    {
        if (V[i] == x)
        {
            nveces++;
        }
    }

    return nveces;
}

int main()
{
    int x, n, i;

    // Pedimos por pantalla las variables
    cout << "Introduce el valor a buscar: ";
    cin >> x;

    cout << "Introduce el tamano del vector: ";
    cin >> n;

    // Creamos los vectores
    int vpeor[n + 1], vmejor[n + 1], vcualquiera[n + 1];

    // Le damos valores a los vectores

    cout << endl;
    cout << "Vector caso peor: ";
    for (i = 1; i <= n; i++)
    {
        vpeor[i] = x;
        cout << " " << vpeor[i];
    }
    cout << endl;

    cout << "Vector caso mejor: ";
    for (i = 1; i <= n; i++)
    {
        vmejor[i] = i;
        cout << " " << vmejor[i];
    }
    cout << endl;

    cout << "Vector caso cualquiera: ";
    for (i = 1; i <= n; i++)
    {
        if (i < (n / 2))
        {
            vcualquiera[i] = x;
            cout << " " << vcualquiera[i];
        }
        else
        {
            vcualquiera[i] = i;
            cout << " " << vcualquiera[i];
        }
    }
    cout << endl;
    cout << endl;

    cout << "Caso Peor: " << contar(vpeor, x, n) << endl;
    cout << "Caso Mejor: " << contar(vmejor, x, n) << endl;
    cout << "Caso Cualquiera: " << contar(vcualquiera, x, n) << endl;
}
