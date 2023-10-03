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
   Node<T> *next;
};

void insertHead(Node<Customer> **head, Node<Customer> **tail);
void insertAfter(Node<Customer> **head, Node<Customer> **tail);
void insertTail(Node<Customer> **head, Node<Customer> **tail);
void remove(Node<Customer> **head, Node<Customer> **tail);
void traverse(Node<Customer> *head, bool pause = false);
void waitEnter();

int main()
{
   Node<Customer> *head = NULL, *tail = NULL;
   char pilih;

   do
   {
      system("clear");

      cout << "Menu Antrian:" << endl;
      cout << "1. Tambah pelanggan di awal" << endl;
      cout << "2. Tambah pelanggan di tengah" << endl;
      cout << "3. Tambah pelanggan di akhir" << endl;
      cout << "4. Hapus pelanggan" << endl;
      cout << "5. Cetak list" << endl;
      cout << "q. Keluar" << endl;
      cout << "Masukkan pilihan: ";
      cin >> pilih;

      if (pilih == '1')
         insertHead(&head, &tail);
      else if (pilih == '2')
         insertAfter(&head, &tail);
      else if (pilih == '3')
         insertTail(&head, &tail);
      else if (pilih == '4')
         remove(&head, &tail);
      else if (pilih == '5')
         traverse(head, true);
   } while (pilih != 'q');

   return 0;
}

void insertHead(Node<Customer> **head, Node<Customer> **tail)
{
   Customer customer;
   Node<Customer> *newNode;

   system("clear");

   cout << "Masukkan nama pelanggan: ";
   cin >> customer.name;
   cout << "Masukkan total pembelian pelanggan: ";
   cin >> customer.total;

   newNode = new Node<Customer>;
   newNode->value = customer;
   newNode->next = NULL;

   if (*head == NULL)
   {
      *head = newNode;
      *tail = newNode;
   }
   else
   {
      newNode->next = *head;
      *head = newNode;
   }
}

void insertAfter(Node<Customer> **head, Node<Customer> **tail)
{
   Customer customer;
   Node<Customer> *newNode, *currentNode;
   string after;

   system("clear");
   traverse(*head);

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
   currentNode->next = newNode;

   if (currentNode == *tail)
      *tail = newNode;
}

void insertTail(Node<Customer> **head, Node<Customer> **tail)
{
   Customer customer;
   Node<Customer> *newNode;

   system("clear");

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
      *tail = newNode;
   }
}

void remove(Node<Customer> **head, Node<Customer> **tail)
{
   string name;

   system("clear");
   traverse(*head);

   cout << endl
        << "Masukkan nama pelanggan yang ingin dihapus: ";
   cin >> name;

   Node<Customer> *currentNode = *head;
   Node<Customer> *previousNode = NULL;

   while (currentNode != NULL && currentNode->value.name != name)
   {
      previousNode = currentNode;
      currentNode = currentNode->next;
   }

   if (currentNode == NULL)
   {
      cout << "Pelanggan tidak ditemukan";
      waitEnter();
      return;
   }

   if (previousNode == NULL)
   {
      *head = currentNode->next;
   }
   else
   {
      previousNode->next = currentNode->next;
   }

   if (currentNode == *tail)
   {
      *tail = previousNode;
   }

   delete currentNode;
}

void traverse(Node<Customer> *head, bool pause)
{
   Node<Customer> *currentNode = head;

   system("clear");

   while (currentNode != NULL)
   {
      cout << currentNode->value.name << " (" << currentNode->value.total << ")";
      cout << " -> ";

      currentNode = currentNode->next;
   }

   cout << "NULL";

   if (pause)
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