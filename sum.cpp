
#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

void sumP(int *a, int b)
{
    *a = *a + b;
}

int main()
{
    int a = 10;
    int b = 20;

    cout << "Direct sum: " << sum(a, b) << endl;
    sumP(&a, b);
    cout << "Pointer sum: " << a;
}