#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

char showMenu()
{
    char menu;

    cout << "Menu:" << endl;
    cout << "1. Masukkan data awal" << endl;
    cout << "2. Masukkan data akhir" << endl;
    cout << "3. Masukkan data setelah" << endl;
    cout << "4. Hapus data awal" << endl;
    cout << "5. Hapus data akhir" << endl;
    cout << "6. Hapus data tengah" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "q. Exit" << endl
         << endl;
    cout << "Pilih: ";

    cin >> menu;

    return menu;
}

void insertHead(Node **head)
{
    int data;

    cout << "Masukkan data: ";
    cin >> data;

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL)
    {
        Node *last = *head;

        while (last->next != *head)
            last = last->next;

        last->next = newNode;
    }
    else
        newNode->next = newNode;

    *head = newNode;
}

void insertTail(Node **head)
{
    int data;

    cout << "Masukkan data: ";
    cin >> data;

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL)
    {
        Node *last = *head;

        while (last->next != *head)
            last = last->next;

        last->next = newNode;
    }
    else
        newNode->next = newNode;

    *head = newNode;
}

void insertAfter(Node **head)
{
    int data, after;

    cout << "Masukkan data: ";
    cin >> data;
    cout << "Masukkan data setelah: ";
    cin >> after;

    Node *newNode = new Node;
    newNode->data = data;

    Node *temp = *head;

    while (temp->data != after)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void showData(Node *head)
{
    Node *temp = head;

    if (head != NULL)
    {
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
    }
    else
        cout << "Data kosong" << endl;
}

void waitEnter()
{
    cout << endl
         << "Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

int main()
{
    Node *head = NULL;

    char menu;

    while (menu != 'q')
    {
        system("cls");

        menu = showMenu();

        switch (menu)
        {
        case '1':
            insertHead(&head);
            break;
        case '2':
            insertTail(&head);
            break;
        case '3':
            insertAfter(&head);
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            showData(head);
            waitEnter();
            break;
        case 'q':
            system("cls");
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    }

    return 0;
}
