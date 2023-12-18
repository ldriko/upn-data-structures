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

void wait()
{
    cout << "Tekan enter untuk melanjutkan...";
    cin.ignore().get();
}

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

    cout << "Antrian Pengiriman: " << endl;

    while (temp != NULL)
    {
        cout << i << ". " << temp->data << endl;
        temp = temp->next;
        i++;
    }
}

int main()
{
    Queue q;
    q.count = 0;
    q.head = NULL;
    q.tail = NULL;

    int choice;

    do
    {
        system("cls");

        cout << "Antrian Pasien Rumah Sakit" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Hapus Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        if (choice == 1)
        {
            string data;
            cout << "Masukkan nama pasien: ";
            cin >> data;
            enqueue(q, data);
        }
        else if (choice == 2)
        {
            dequeue(q);
        }
        else if (choice == 3)
        {
            print(q);
            wait();
        }
    } while (choice != 4);

    return 0;
}