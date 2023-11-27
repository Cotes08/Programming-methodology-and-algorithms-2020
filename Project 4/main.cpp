#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

int p42(int x, int y)
{
    stack<int> pila;
    int x1, y1, s;
    x1 = x;
    y1 = y;
    s = 0;

    while (x1 >= 5)
    {

        x1 = x1 - 4;
        y1 = y1 / 3;
        pila.push(x1);
        pila.push(y1);
    }
    s = x1 + y1;

    while (x1 < x && !pila.empty())
    {

        y1 = pila.top();
        pila.pop();
        x1 = pila.top();
        pila.pop();
        s = s + x1 * y1;
    }

    return s;
}

int p42r(int x, int y)
{
    if (x <= 4)
        return x + y;
    else
    {
        x = x - 4;
        y = y / 3;
        return p42r(x, y) + x * y;
    }
}

int main()
{
    int x, y;
    cout << "Introduce valores de x:" << endl;
    cin >> x;
    cout << "Introduce valores de y:" << endl;
    cin >> y;

    cout << "Resultado Recursivo: " << p42r(x, y) << endl;

    cout << "Resultado iterativo: " << p42(x, y) << endl;

    return 0;
}
