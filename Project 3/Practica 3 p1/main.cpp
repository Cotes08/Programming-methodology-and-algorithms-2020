#include <iostream>

using namespace std;

int binario(int x)
{
    int b;
    if (x == 0)
        b = 0;
    else
        b = x % 2 + 10 * (binario(x / 2));
    return b;
}

int main()
{
    int x;
    cout << "Introduce el valor: ";
    cin >> x;
    cout << "Binario: " << binario(x);
}
