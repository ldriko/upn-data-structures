#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Customer
{
   string name;
   float total;
};

template <typename T>

struct Node
{
   T value;
   Node<T> *next = NULL;
   Node<T> *prev = NULL;
};

void insertHead(Node<Customer> **head, Node<Customer> **tail);
void insertAfter(Node<Customer> **head, Node<Customer> **tail);
void insertTail(Node<Customer> **head, Node<Customer> **tail);
void removeHead(Node<Customer> **head, Node<Customer> **tail);
void remove(Node<Customer> **head, Node<Customer> **tail);
void removeTail(Node<Customer> **head, Node<Customer> **tail);
void count(Node<Customer> *head);
void countTotal(Node<Customer> *head);
void traverse(Node<Customer> *head, bool pause = false);
void waitEnter();

int main()
{
   Node<Customer> *head = NULL, *tail = NULL;
   string pilih;

   do
   {
      system("cls");

      cout << "Menu Antrian:" << endl;
      cout << "1. Tambah pelanggan di awal" << endl;
      cout << "2. Tambah pelanggan di tengah" << endl;
      cout << "3. Tambah pelanggan di akhir" << endl;
      cout << "4. Hapus pelanggan di awal" << endl;
      cout << "5. Hapus pelanggan di tengah" << endl;
      cout << "6. Hapus pelanggan di akhir" << endl;
      cout << "7. Jumlah pelanggan" << endl;
      cout << "8. Jumlah total pembelian pelanggan" << endl;
      cout << "9. Cetak list" << endl;
      cout << "q. Keluar" << endl;
      cout << "Masukkan pilihan: ";
      cin >> pilih;

      if (pilih == "1")
         insertHead(&head, &tail);
      else if (pilih == "2")
         insertAfter(&head, &tail);
      else if (pilih == "3")
         insertTail(&head, &tail);
      else if (pilih == "4")
         removeHead(&head, &tail);
      else if (pilih == "5")
         remove(&head, &tail);
      else if (pilih == "6")
         removeTail(&head, &tail);
      else if (pilih == "7")
         count(head);
      else if (pilih == "8")
         countTotal(head);
      else if (pilih == "9")
         traverse(head, true);
   } while (pilih != "q");

   return 0;
}

void insertHead(Node<Customer> **head, Node<Customer> **tail)
{
   Customer customer;
   Node<Customer> *newNode;

   system("cls");

   cout << "Masukkan nama pelanggan: ";
   cin >> customer.name;
   cout << "Masukkan total pembelian pelanggan: ";
   cin >> customer.total;

   newNode = new Node<Customer>;
   newNode->value = customer;

   if (*head == NULL)
   {
      *head = newNode;
      *tail = newNode;
   }
   else
   {
      newNode->next = *head;
      (*head)->prev = newNode;
      *head = newNode;
   }
}

void insertAfter(Node<Customer> **head, Node<Customer> **tail)
{
   Customer customer;
   Node<Customer> *newNode, *currentNode;
   string after;

   system("cls");
   traverse(*head);

   if (*head == NULL)
   {
      cout << "Antrian kosong";
      waitEnter();
      return;
   }

   cout << endl;
   cout << "Setelah pelanggan: ";
   cin >> after;
   cout << "Masukkan nama pelanggan: ";
   cin >> customer.name;
   cout << "Masukkan total pembelian pelanggan: ";
   cin >> customer.total;
   cout << endl;

   currentNode = *head;

   while (currentNode != NULL && currentNode->value.name != after)
   {
      currentNode = currentNode->next;
   }

   if (currentNode == NULL)
   {
      cout << "Pelanggan tidak ditemukan";
      waitEnter();
      return;
   }

   newNode = new Node<Customer>;
   newNode->value = customer;
   newNode->next = currentNode->next;
   currentNode->next->prev = newNode;
   newNode->prev = currentNode;
   currentNode->next = newNode;

   if (currentNode == *tail)
      *tail = newNode;
}

void insertTail(Node<Customer> **head, Node<Customer> **tail)
{
   Customer customer;
   Node<Customer> *newNode;

   system("cls");

   cout << "Masukkan nama pelanggan: ";
   cin >> customer.name;
   cout << "Masukkan total pembelian pelanggan: ";
   cin >> customer.total;

   newNode = new Node<Customer>;
   newNode->value = customer;
   newNode->next = NULL;

   if (*tail == NULL)
   {
      *head = newNode;
      *tail = newNode;
   }
   else
   {
      (*tail)->next = newNode;
      newNode->prev = *tail;
      *tail = newNode;
   }
}

void removeHead(Node<Customer> **head, Node<Customer> **tail)
{
   Node<Customer> *currentNode = *head;

   system("cls");

   if (currentNode == NULL)
   {
      cout << "Antrian kosong";
      waitEnter();
      return;
   }

   *head = currentNode->next;
   currentNode->next->prev = NULL;

   if (currentNode == *tail)
   {
      *tail = NULL;
   }

   delete currentNode;

   cout << "Pelanggan di awal telah dihapus";

   waitEnter();
}

void remove(Node<Customer> **head, Node<Customer> **tail)
{
   string target;

   system("cls");
   traverse(*head);

   cout << endl;
   cout << "Setelah pelanggan: ";
   cin >> target;

   Node<Customer> *currentNode = *head;

   while (currentNode != NULL && currentNode->value.name != target)
   {
      currentNode = currentNode->next;
   }

   if (currentNode == NULL)
   {
      cout << "Pelanggan tidak ditemukan";
      waitEnter();
      return;
   }

   if (currentNode->prev == NULL)
   {
      *head = currentNode->next;
      currentNode->next->prev = NULL;
   }
   else
   {
      currentNode->prev->next = currentNode->next;
      currentNode->next->prev = currentNode->prev;
   }

   if (currentNode == *tail)
   {
      *tail = currentNode->prev;
      currentNode->prev->next = NULL;
   }

   delete currentNode;

   cout << "Pelanggan telah dihapus";

   waitEnter();
}

void removeTail(Node<Customer> **head, Node<Customer> **tail)
{
   Node<Customer> *currentNode = *head;

   system("cls");

   if (currentNode == NULL)
   {
      cout << "Antrian kosong";
      waitEnter();
      return;
   }

   while (currentNode != *tail)
   {
      currentNode = currentNode->next;
   }

   if (currentNode->prev == NULL)
   {
      *head = NULL;
   }
   else
   {
      currentNode->prev->next = NULL;
      currentNode->prev = NULL;
   }

   *tail = currentNode->prev;

   delete currentNode;

   cout << "Pelanggan di akhir telah dihapus";

   waitEnter();
}

void traverse(Node<Customer> *head, bool pause)
{
   Node<Customer> *currentNode = head;

   system("cls");

   cout << "NULL <- ";

   while (currentNode != NULL)
   {
      cout << currentNode->value.name << " (" << currentNode->value.total << ")";
      if (currentNode->next != NULL)
         cout << " <-> ";

      currentNode = currentNode->next;
   }

   cout << "-> NULL";

   if (pause)
      waitEnter();
}

void count(Node<Customer> *head)
{
   Node<Customer> *currentNode = head;
   int count = 0;

   system("cls");

   while (currentNode != NULL)
   {
      count++;

      currentNode = currentNode->next;
   }

   cout << "Jumlah pelanggan: " << count;

   waitEnter();
}

void countTotal(Node<Customer> *head)
{
   Node<Customer> *currentNode = head;
   float total = 0;

   system("cls");

   while (currentNode != NULL)
   {
      total += currentNode->value.total;

      currentNode = currentNode->next;
   }

   cout << "Jumlah total pembelian pelanggan: " << total;

   waitEnter();
}

void waitEnter()
{
   cout << endl
        << endl
        << "Tekan enter untuk melanjutkan...";
   cin.ignore();
   cin.get();
}