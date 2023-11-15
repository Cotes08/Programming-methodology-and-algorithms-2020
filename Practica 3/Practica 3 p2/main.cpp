#include <iostream>

using namespace std;

int combinaciones(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else
        return combinaciones(n - 1, k - 1) + combinaciones(n - 1, k);
}

int combinaciones_traza(int n, int k, int &i, int j)
{
    i++;

    for (int x = 0; x < j; x++)
        cout << "\t";

    cout << i << ".- combinaciones_traza(" << n << "," << k << ")\n";

    if (k == 0 || k == n)
    {
        j--;
        return 1;
    }
    else
    {
        j++;
        return combinaciones_traza(n - 1, k - 1, i, j) + combinaciones_traza(n - 1, k, i, j);
    }
}

int main()
{
    int n, k, i = 0, c;
    cout << "Introduce n: ";
    cin >> n;
    cout << "Introduce k: ";
    cin >> k;
    cout << "Combinaciones posibles: " << combinaciones(n, k) << endl;
    c = combinaciones_traza(n, k, i, 0);
    cout << "Combinaciones posibles(traza): " << c;
}
