#include <iostream>

using namespace std;

int main()
{
    string name = "Heaven";
    string *name2 = &name;

    *name2 = "Diva";

    cout << name;

    // i = 3
    // i = 7
    // j = 9
    // j = -2
}
