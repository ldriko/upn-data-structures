#include <iostream>

using namespace std;

struct Stack
{
    int data;
    Stack *next;
};

void wait()
{
    cout << endl;
    cout << "Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

char showMenu(int max, int count)
{
    char menu;

    system("cls");

    cout << "Batas stack: " << max << endl;
    cout << "Jumlah data: " << count << endl
         << endl;
    cout << "Operasi Stack:" << endl;
    cout << "1. Push Stack" << endl;
    cout << "2. Pop Stack" << endl;
    cout << "3. Tampilkan Stack" << endl;
    cout << "4. Tampilkan Top Stack" << endl;
    cout << "5. Berikan Batas Stack" << endl;
    cout << "6. Kosongi Stack" << endl;
    cout << "q. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> menu;

    return menu;
}

bool isFull(int max, int count)
{
    return count == max;
}

bool isEmpty(Stack *top, int count)
{
    return top == NULL || count == 0;
}

void push(Stack **top, int max, int *count)
{
    system("cls");

    if (isFull(max, *count))
    {
        cout << "Stack penuh!" << endl;
        wait();
        return;
    }

    Stack *newStack = new Stack;

    if (newStack == NULL)
    {
        cout << "Alokasi memori stack gagal!" << endl;
        return wait();
    }

    cout << "Masukkan data: ";
    cin >> newStack->data;

    newStack->next = NULL;

    if (!isEmpty(*top, *count))
        newStack->next = *top;

    *top = newStack;
    *count += 1;
}

void pop(Stack **top, int *count)
{
    system("cls");

    if (isEmpty(*top, *count))
    {
        cout << "Stack kosong!" << endl;
        return wait();
    }

    Stack *temp = *top;
    int data = temp->data;

    *top = (*top)->next;
    delete temp;
    *count -= 1;

    cout << "Data yang dikeluarkan: " << data << endl;
    wait();
}

void empty(Stack **top, int *count)
{
    system("cls");

    if (isEmpty(*top, *count))
    {
        cout << "Stack kosong!" << endl;
        return wait();
    }

    Stack *temp = *top;

    while (temp != NULL)
    {
        *top = (*top)->next;
        delete temp;
        temp = *top;
    }

    *count = 0;
}

void show(Stack *top, int count)
{
    system("cls");

    if (isEmpty(top, count))
    {
        cout << "Stack kosong!" << endl;
        return wait();
    }

    cout << "Stack: " << endl;

    while (top != NULL)
    {
        cout << top->data << endl;
        cout << "-----" << endl;
        top = top->next;
    }

    wait();
}

void showTop(Stack *top, int count)
{
    system("cls");

    if (isEmpty(top, count))
    {
        cout << "Stack kosong!" << endl;
        return wait();
    }

    cout << "Top stack: " << top->data << endl;
    wait();
}

void setMax(int *max, int count)
{
    system("cls");

    int newMax = 0;

    cout << "Jumlah data: " << count << endl
         << endl;

    cout << "Masukkan batas stack baru: ";
    cin >> newMax;

    if (newMax < count)
    {
        cout << "Batas stack tidak boleh lebih kecil dari jumlah data!" << endl;
        return wait();
    }

    *max = newMax;

    return;
}

int main()
{
    Stack *top = NULL;
    int max = 0, count = 0;
    char menu;

    while (menu != 'q')
    {
        menu = showMenu(max, count);

        if (menu == '1')
            push(&top, max, &count);
        else if (menu == '2')
            pop(&top, &count);
        else if (menu == '3')
            show(top, count);
        else if (menu == '4')
            showTop(top, count);
        else if (menu == '5')
            setMax(&max, count);
        else if (menu == '6')
            empty(&top, &count);
        else if (menu == 'q')
            system("cls");
        else
        {
            cout << "Menu tidak tersedia!" << endl;
            wait();
        }
    }
}