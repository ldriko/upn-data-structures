#include <iostream>
#include <fstream>

using namespace std;

// Using stack to check if the code is valid or not
struct Node
{
    string data;
    Node *next;
};

void push(Node **head, string data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

bool isEmpty(Node *head)
{
    return !head;
}

bool validateClosingBrackets(Node **head, string data)
{
    if (isEmpty(*head))
        return false;

    if (data == "}" && (*head)->data == "{")
        return true;
    else if (data == "]" && (*head)->data == "[")
        return true;
    else if (data == ")" && (*head)->data == "(")
        return true;
    else
        return false;
}

int main()
{
    string filename, code;

    cout << "Masukkan nama file garuda: ";
    cin >> filename;

    ifstream file(filename.c_str(), ios::in);

    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return 0;
    }

    string line;

    while (getline(file, line))
    {
        code += line;
    }

    Node *head = NULL;

    for (size_t i = 0; i < code.length(); i++)
    {
        if (code[i] == '{' || code[i] == '[' || code[i] == '(')
        {
            string data(1, code[i]);
            push(&head, data);
        }
        else if (code[i] == '}' || code[i] == ']' || code[i] == ')')
        {
            string data(1, code[i]);
            if (validateClosingBrackets(&head, data))
                head = head->next;
            else
            {
                cout << "Code tidak valid" << endl;
                return 0;
            }
        }
    }

    if (isEmpty(head))
        cout << "Code valid" << endl;
    else
        cout << "Code tidak valid" << endl;

    return 0;
}