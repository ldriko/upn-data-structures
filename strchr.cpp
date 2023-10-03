#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main()
{
    char *password = "12345!oke";
    char *result;

    system("cls");

    result = strchr(password, '!');

    if (result)
    {
        cout << *result;
    }
}