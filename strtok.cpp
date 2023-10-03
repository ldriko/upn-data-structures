#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main()
{
    char *token;
    char kalimat[80] = "Saya adalah pilot";

    system("cls");

    token = strtok(kalimat, " ");

    int sum = 0;

    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
        sum++;
    }

    cout << "Jumlah kata: " << sum;
}