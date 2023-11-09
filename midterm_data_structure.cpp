#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    string name;
    char gender;
    Node *next = NULL;
    Node *prev = NULL;
};

char showMenu()
{
    char choice;

    cout << "Menu:" << endl;
    cout << "1. Masukkan mahasiswa" << endl;
    cout << "2. Keluarkan mahasiswa" << endl;
    cout << "3. Lanjutkan giliran bernyanyi" << endl;
    cout << "4. Pisah lingkaran mahasiswa dan mahasiswi"
         << endl
         << endl;

    cout << "Pilih (q untuk keluar): ";
    cin >> choice;

    return choice;
}

void waitEnter()
{
    cout << endl
         << "Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void showCircle(Node *head, bool pause = true, bool clear = true, string title = "mahasiswa")
{
    if (clear)
        system("cls");

    if (head == NULL)
    {
        cout << "Belum ada mahasiswa" << endl;

        if (pause)
            return waitEnter();
        else
            return;
    }

    cout << "Lingkaran " << title << ":" << endl;

    Node *currentNode = head;

    do
    {
        cout << currentNode->name << " -> ";
        currentNode = currentNode->next;
    } while (currentNode != head);

    cout << "..." << endl;

    if (pause)
        waitEnter();
}

bool isCindy(Node *node)
{
    return node->name == "Cindy" || node->name == "cindy";
}

bool isMale(Node *node)
{
    return node->gender == 'L' || node->gender == 'l';
}

void addHead(Node **head, Node **singing)
{
    system("cls");

    showCircle(*head, false);

    cout << endl;

    Node *newNode = new Node;

    if (newNode == NULL)
    {
        cout << "Memori tidak cukup" << endl;
        return;
    }

    cout << "Masukkan nama mahasiswa baru: ";
    cin >> newNode->name;
    cout << "Masukkan gender mahasiswa baru (P/L): ";
    cin >> newNode->gender;

    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;

        *singing = *head;
    }
    else
    {
        if ((isCindy(newNode) && (isMale(*head) || isMale((*head)->prev))) || ((isCindy((*head)) || isCindy((*head)->prev)) && isMale(newNode)))
        {
            cout << endl
                 << "Cindy tidak mau bersebelahan dengan mahasiswa laki-laki" << endl;
            return waitEnter();
        }

        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void addMid(Node **head, Node **singing)
{
    system("cls");

    showCircle(*head, false);

    cout << endl;

    Node *newNode = new Node;

    if (newNode == NULL)
    {
        cout << "Memori tidak cukup" << endl;
        return;
    }

    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;

        *singing = *head;
    }
    else
    {
        showCircle(*head, false);

        cout << endl;

        cout << "Masukkan nama mahasiswa baru: ";
        cin >> newNode->name;
        cout << "Masukkan gender mahasiswa baru (P/L): ";
        cin >> newNode->gender;
        cout << endl;

        Node *currentNode = *head;

        cout << "Masukkan " << newNode->name << " setelah: ";
        string prevName;
        cin >> prevName;

        while (currentNode->name != prevName)
        {
            currentNode = currentNode->next;

            if (currentNode == *head)
            {
                cout << "Nama mahasiswa tidak ditemukan" << endl;
                return waitEnter();
            }
        }

        if ((isCindy(newNode) && (isMale(currentNode) || isMale(currentNode->next))) || ((isCindy(currentNode) || isCindy(currentNode->next)) && isMale(newNode)))
        {
            cout << endl
                 << "Cindy tidak mau bersebelahan dengan mahasiswa laki-laki" << endl;
            return waitEnter();
        }

        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    }
}

void addTail(Node **head, Node **singing)
{
    system("cls");

    showCircle(*head, false);

    cout << endl;

    Node *newNode = new Node;

    if (newNode == NULL)
    {
        cout << "Memori tidak cukup" << endl;
        return;
    }

    cout << "Masukkan nama mahasiswa baru: ";
    cin >> newNode->name;
    cout << "Masukkan gender mahasiswa baru (P/L): ";
    cin >> newNode->gender;

    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;

        *singing = *head;
    }
    else
    {
        if ((isCindy(newNode) && (isMale(*head) || isMale((*head)->prev))) || ((isCindy((*head)) || isCindy((*head)->prev)) && isMale(newNode)))
        {
            cout << endl
                 << "Cindy tidak mau bersebelahan dengan mahasiswa laki-laki" << endl;
            return waitEnter();
        }

        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void addMahasiswa(Node **head, Node **singing)
{
    system("cls");

    showCircle(*head, false);

    cout << endl;

    char choice;

    cout << "1. Masukkan mahasiswa baru diawal" << endl;
    cout << "2. Masukkan mahasiswa baru ditengah" << endl;
    cout << "3. Masukkan mahasiswa baru diakhir"
         << endl
         << endl;
    cout << "Pilih: ";
    cin >> choice;

    if (choice == '1')
        addHead(head, singing);
    else if (choice == '2')
        addMid(head, singing);
    else if (choice == '3')
        addTail(head, singing);
}

void removeMahasiswa(Node **head)
{
    system("cls");

    if (*head == NULL)
    {
        cout << "Belum ada mahasiswa" << endl;
        return waitEnter();
    }

    showCircle(*head, false);

    cout << endl;

    cout << "Masukkan nama mahasiswa yang ingin dikeluarkan: ";
    string name;
    cin >> name;

    Node *currentNode = *head;

    while (currentNode->name != name)
    {
        currentNode = currentNode->next;

        if (currentNode == *head)
        {
            cout << "Nama mahasiswa tidak ditemukan" << endl;
            return waitEnter();
        }
    }

    if (isCindy(currentNode) && (isMale(currentNode->prev) || isMale(currentNode->next)))
    {
        cout << endl
             << "Cindy tidak mau bersebelahan dengan mahasiswa laki-laki" << endl;
        return waitEnter();
    }

    if ((isCindy(currentNode->prev) && isMale(currentNode->next)) || (isCindy(currentNode->next) && isMale(currentNode->prev)))
    {
        cout << endl
             << "Cindy tidak mau bersebelahan dengan mahasiswa laki-laki" << endl;
        return waitEnter();
    }

    if (currentNode == *head)
    {
        if (currentNode->next == *head)
        {
            *head = NULL;
        }
        else
        {
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
            *head = currentNode->next;
        }
    }
    else
    {
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
    }

    delete currentNode;
}

void showSinging(Node *singing)
{
    if (singing == NULL)
        return;

    cout << "~ " << singing->name << " sedang bernyanyi ~" << endl;
}

void nextSinging(Node **singing)
{
    system("cls");

    if (singing == NULL)
        return;

    Node *nextSinging = (*singing)->next;
    *singing = nextSinging;
}

void separateCircle(Node *head)
{
    Node *headMahasiswa = NULL, *headMahasiswi = NULL;

    if (head == NULL)
    {
        cout << "Belum ada mahasiswa" << endl;
        return waitEnter();
    }

    Node *currentNode = head;

    do
    {
        Node *newNode = new Node;

        if (newNode == NULL)
        {
            cout << "Memori tidak cukup" << endl;
            return;
        }

        newNode->name = currentNode->name;
        newNode->gender = currentNode->gender;

        if (newNode->gender == 'L' || newNode->gender == 'l')
        {
            if (headMahasiswa == NULL)
            {
                headMahasiswa = newNode;
                headMahasiswa->next = headMahasiswa;
                headMahasiswa->prev = headMahasiswa;
            }
            else
            {
                newNode->next = headMahasiswa;
                newNode->prev = headMahasiswa->prev;
                headMahasiswa->prev->next = newNode;
                headMahasiswa->prev = newNode;
            }
        }
        else if (newNode->gender == 'P' || newNode->gender == 'p')
        {
            if (headMahasiswi == NULL)
            {
                headMahasiswi = newNode;
                headMahasiswi->next = headMahasiswi;
                headMahasiswi->prev = headMahasiswi;
            }
            else
            {
                newNode->next = headMahasiswi;
                newNode->prev = headMahasiswi->prev;
                headMahasiswi->prev->next = newNode;
                headMahasiswi->prev = newNode;
            }
        }

        currentNode = currentNode->next;
    } while (currentNode != head);

    showCircle(headMahasiswa, false);

    cout << endl;

    showCircle(headMahasiswi, true, false, "mahasiswi");
}

int main()
{
    Node *head = NULL, *singing = NULL;
    char choice;

    while (choice != 'q')
    {
        system("cls");

        showCircle(head, false);

        cout << endl;

        if (singing != NULL)
        {
            showSinging(singing);

            cout << endl;
        }

        choice = showMenu();

        if (choice == '1')
            addMahasiswa(&head, &singing);
        else if (choice == '2')
            removeMahasiswa(&head);
        else if (choice == '3')
            nextSinging(&singing);
        else if (choice == '4')
            separateCircle(head);
    }

    return 0;
}
