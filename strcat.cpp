#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char firstName[] = "Heaven";
    char lastName[] = "Aldrico";

    strcat(firstName, " ");
    strcat(firstName, lastName);

    cout << firstName;
}