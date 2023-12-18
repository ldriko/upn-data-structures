#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Node
{
    char data;
    Node *next;
};

void push(Node *&top, char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop(Node *&top)
{
    Node *temp = top;
    top = top->next;
    delete temp;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void printStep(int &step, char infix, string postfix)
{
    cout << "Langkah " << step << ": " << infix << " -> " << postfix << endl;
    step++;
}

string toPostfix(Node *top, string infix)
{
    int step = 1;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            push(top, infix[i]);
            printStep(step, infix[i], postfix);
        }
        else if (infix[i] == ')')
        {
            while (top->data != '(')
            {
                postfix += top->data;
                printStep(step, infix[i], postfix);
                pop(top);
            }
            pop(top);
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (top == NULL)
            {
                push(top, infix[i]);
            }
            else
            {
                while (top != NULL && precedence(top->data) >= precedence(infix[i]))
                {
                    postfix += top->data;
                    printStep(step, infix[i], postfix);
                    pop(top);
                }
                push(top, infix[i]);
            }
        }
        else
        {
            postfix += infix[i];
            printStep(step, infix[i], postfix);
        }
    }

    while (top != NULL)
    {
        postfix += top->data;
        printStep(step, top->data, postfix);
        pop(top);
    }

    return postfix;
}

double calculatePostfix(Node *top, string postfix)
{
    for (size_t i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            double operand1 = top->data;
            pop(top);
            double operand2 = top->data;
            pop(top);

            if (postfix[i] == '+')
            {
                push(top, operand2 + operand1);
            }
            else if (postfix[i] == '-')
            {
                push(top, operand2 - operand1);
            }
            else if (postfix[i] == '*')
            {
                push(top, operand2 * operand1);
            }
            else if (postfix[i] == '/')
            {
                push(top, operand2 / operand1);
            }
        }
        else
        {
            push(top, postfix[i] - '0');
        }
    }

    return top->data;
}

int main()
{
    system("cls");

    char repeat = 'y';

    while (repeat == 'y' || repeat == 'Y')
    {
        system("cls");

        Node *top = NULL;
        string infix, postfix;

        cout << "Masukkan operasi infix: ";
        cin >> infix;

        system("cls");

        cout << "Infix: " << infix << endl
             << endl;

        postfix = toPostfix(top, infix);
        top = NULL;

        cout << endl;
        cout << "Postfix: " << postfix << endl;
        cout << "Hasil: " << calculatePostfix(top, postfix) << endl
             << endl;

        cout << "Ulangi? (y/n): ";
        cin >> repeat;
    }

    return 0;
}