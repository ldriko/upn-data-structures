#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *next;
};

struct Queue
{
    int count;
    Node *head;
    Node *tail;
};

void enqueue(Queue &q, string data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (q.count == 0)
    {
        q.head = newNode;
        q.tail = newNode;
    }
    else
    {
        q.tail->next = newNode;
        q.tail = newNode;
    }

    q.count++;
}

void dequeue(Queue &q)
{
    if (q.count == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node *temp = q.head;
        q.head = q.head->next;
        delete temp;
        q.count--;
    }
}

void print(Queue q)
{
    Node *temp = q.head;
    int i = 1;

    cout << "Antrian Saat Ini: " << endl;

    while (temp != NULL)
    {
        cout << i << ". " << temp->data << endl;
        temp = temp->next;
        i++;
    }

    cout << endl;
    cout << "Tekan enter untuk melanjutkan" << endl;
    cin.ignore();
    cin.get();
}

int main()
{
    Queue q;

    q.count = 0;
    q.head = NULL;
    q.tail = NULL;

    char pilih;

    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Cetak" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == '1')
        {
            string data;
            cout << "Data: ";
            cin >> data;
            enqueue(q, data);
        }
        else if (pilih == '2')
        {
            dequeue(q);
        }
        else if (pilih == '3')
        {
            print(q);
        }
        else if (pilih == '4')
        {
            cout << "Terima kasih" << endl;
        }
        else
        {
            cout << "Pilihan tidak tersedia" << endl;
        }
    } while (pilih != '4');
}