#include <iostream>

using namespace std;

char showMenu(string *text);
void countCharacters(string *text);
void countWords(string *text);
void searchWord(string *text);
void countWord(string *text);

int main()
{
    string text = "Dennis MacAlistair Ritchie (9 September 1941 - 12 Oktober 2011) adalah seorang ilmuwan komputer yang dikenal atas sumbangsihnya membuat bahasa pemrograman C dan berbagai sistem operasi seperti Multics dan Unix. Ritchie menerima penghargaan Turing Award pada tahun 1983 dan National Medal of Technology 1998 pada 21 April 1999. Ia menjabat sebagai kepala Departemen Riset Perangkat lunak Sistem di Lucent Technologies saat pensiun pada tahun 2007. Ritchie dikenal sebagai pembuat bahasa pemrograman C, pengembang utama sistem operasi, dan sebagai salah satu dari penulis (bersama Brian Kernighan) buku Kamus Bahasa C, The C Programming Language. Penemuan bahasa C dan pengembangan Unix menjadikan Ricthie dan Ken Thompson sebagai pionir utama dunia komputasi modern. Bahasa C hingga kini masih digunakan secara luas dalam program aplikasi, sistem operasi, pengembangan sistem benam, dan pengaruhnya dalam bahasa pemrograman modern lain. Sedangkan Unix juga telah memberikan pengaruh besar, membangun konsep dan prinsip dalam dunia komputasi masa kini";
    char menu;

    while (menu != 'q')
    {
        system("cls");

        menu = showMenu(&text);

        switch (menu)
        {
        case '1':
            countCharacters(&text);
            break;
        case '2':
            countWords(&text);
            break;
        case '3':
            searchWord(&text);
            break;
        case '4':
            countWord(&text);
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

char showMenu(string *text)
{
    char menu;

    cout << "Teks: " << endl;
    cout << *text << endl
         << endl;

    cout << "Menu:" << endl;
    cout << "1. Hitung jumlah seluruh karakter" << endl;
    cout << "2. Hitung jumlah seluruh kata" << endl;
    cout << "3. Cari kata pada teks" << endl;
    cout << "4. Hitung jumlah suatu kata" << endl;
    cout << "q. Keluar" << endl
         << endl;
    cout << "Pilih: ";

    cin >> menu;

    return menu;
}

void waitEnter()
{
    cout << endl
         << endl
         << "Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void countCharacters(string *text)
{
    int count = 0;
    int countWithSpaces = 0;

    for (unsigned int i = 0; i < text->length(); i++)
    {
        if (!isspace(text->at(i)))
            count++;
        countWithSpaces++;
    }

    cout << "Jumlah karakter: " << count << endl;
    cout << "Jumlah karakter (dengan spasi): " << countWithSpaces;

    waitEnter();
}

void countWords(string *text)
{
    int count = 0;

    for (unsigned int i = 0; i < text->length(); i++)
    {
        if (isspace(text->at(i)))
            count++;
    }

    cout << "Jumlah kata: " << count + 1;

    waitEnter();
}

void searchWord(string *text)
{
    string keyword;

    cout << "Masukkan kata yang ingin dicari: ";
    cin >> keyword;
    cout << endl;

    string sentence = "", word = "";
    int sentenceCount = 0;
    bool firstOfSentence = true, found = false;

    cout << "Hasil pencarian:" << endl;

    for (unsigned int i = 0; i < text->length(); i++)
    {
        if (firstOfSentence)
            sentence = "";

        sentence += text->at(i);

        if (text->at(i) == '.')
        {
            firstOfSentence = true;

            if (found)
            {
                sentenceCount++;
                cout << sentenceCount << ". " << sentence << endl;
                found = false;
            }
        }
        else
            firstOfSentence = false;

        if (isspace(text->at(i)))
            word = "";
        else
            word += text->at(i);

        if (word == keyword)
            found = true;
    }

    cout << endl
         << "Jumlah kalimat yang mengandung kata '" << keyword << "': " << sentenceCount;

    waitEnter();
}

void countWord(string *text)
{
    string keyword;

    cout << "Masukkan kata yang ingin dihitung: ";
    cin >> keyword;
    cout << endl;

    string word = "";
    int count = 0;

    for (unsigned int i = 0; i < text->length(); i++)
    {
        if (isspace(text->at(i)))
            word = "";
        else
            word += text->at(i);

        if (word == keyword)
            count++;
    }

    cout << "Jumlah kata '" << keyword << "' pada teks: " << count;

    waitEnter();
}