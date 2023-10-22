#include <iostream>

using namespace std;

struct Journal
{
    string title;
    string author;
    string affiliation;
    string email;
    string abstract;
    string keywords;
};

char showMenu()
{
    char choice;

    system("cls");

    cout << "Penulisan Jurnal" << endl;
    cout << "1. Input judul jurnal" << endl;
    cout << "2. Input nama penulis" << endl;
    cout << "3. Input afiliasi penulis" << endl;
    cout << "4. Input email penulis" << endl;
    cout << "5. Input abstrak jurnal" << endl;
    cout << "6. Input kata kunci jurnal" << endl;
    cout << "7. Tampilkan jurnal" << endl;
    cout << "q. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> choice;
    cin.ignore();

    return choice;
}

void waitEnter()
{
    cout << endl
         << "Tekan enter untuk melanjutkan...";
    cin.get();
}

bool validateTitle(string *title)
{
    int words = 0;
    int length = title->length();

    for (int i = 0; i < length; i++)
    {
        if (title->at(i) == ' ')
            words++;
        else if (i == length - 1)
            words++;
    }

    return words >= 5 && words <= 14;
}

void inputTitle(Journal *journal)
{
    system("cls");

    string title = "";

    cout << "Judul jurnal saat ini:" << endl
         << journal->title << endl
         << endl;

    cout << "Masukkan judul jurnal (Kosongi untuk batal): " << endl;
    getline(cin, title);

    if (title.length() == 0)
        return;

    if (!validateTitle(&title))
    {
        cout << "Judul jurnal harus terdiri dari 5-14 kata" << endl;
        waitEnter();
        return inputTitle(journal);
    }

    journal->title = title;
}

bool validateAuthor(string *author)
{
    int commas = 0;
    int length = author->length();

    for (int i = 0; i < length; i++)
    {
        if (author->at(i) == ',')
            commas++;
    }

    return commas <= 2;
}

void inputAuthor(Journal *journal)
{
    system("cls");

    string author = "";

    cout << "Nama penulis saat ini:" << endl
         << journal->author << endl
         << endl;

    cout << "Masukkan nama penulis (Kosongi untuk batal): " << endl;
    getline(cin, author);

    if (author.length() == 0)
        return;

    if (!validateAuthor(&author))
    {
        cout << "Nama penulis maksimal terdiri dari 3 orang" << endl;
        waitEnter();
        return inputAuthor(journal);
    }

    journal->author = author;
}

void inputAffiliation(Journal *journal)
{
    system("cls");

    string affiliation = "";

    cout << "Afiliasi penulis saat ini:" << endl
         << journal->affiliation << endl
         << endl;

    cout << "Masukkan afiliasi penulis (Kosongi untuk batal): " << endl;
    getline(cin, affiliation);

    if (affiliation.length() == 0)
        return;

    journal->affiliation = affiliation;
}

bool validateEmail(string *email)
{
    int at = email->find('@');
    int dot = email->find('.ac.id');

    return at > 0 && dot > at;
}

void inputEmail(Journal *journal)
{
    system("cls");

    string email = "";

    cout << "Email penulis saat ini:" << endl
         << journal->email << endl
         << endl;

    cout << "Masukkan email penulis (Kosongi untuk batal): " << endl;
    getline(cin, email);

    if (email.length() == 0)
        return;

    if (!validateEmail(&email))
    {
        cout << "Email tidak valid" << endl;
        waitEnter();
        return inputEmail(journal);
    }

    journal->email = email;
}

bool validateAbstract(string *abstract)
{
    int words = 0;
    int length = abstract->length();

    for (int i = 0; i < length; i++)
    {
        if (abstract->at(i) == ' ')
            words++;
        else if (i == length - 1)
            words++;
    }

    return words <= 200;
}

void inputAbstract(Journal *journal)
{
    system("cls");

    string abstract = "";

    cout << "Abstrak jurnal saat ini:" << endl
         << journal->abstract << endl
         << endl;

    cout << "Masukkan abstrak jurnal (Kosongi untuk batal): " << endl;
    getline(cin, abstract);

    if (abstract.length() == 0)
        return;

    if (!validateAbstract(&abstract))
    {
        cout << "Abstrak jurnal maksimal 200 kata" << endl;
        waitEnter();
        return inputAbstract(journal);
    }

    journal->abstract = abstract;
}

bool validateKeywords(string *keywords)
{
    int commas = 0;
    int length = keywords->length();

    for (int i = 0; i < length; i++)
    {
        if (keywords->at(i) == ',')
            commas++;
    }

    return commas >= 2 && commas <= 4;
}

void inputKeywords(Journal *journal)
{
    system("cls");

    string keywords = "";

    cout << "Kata kunci jurnal saat ini:" << endl
         << journal->keywords << endl
         << endl;

    cout << "Kata kunci jurnal (Kosongi untuk batal): " << endl;
    getline(cin, keywords);

    if (keywords.length() == 0)
        return;

    if (!validateKeywords(&keywords))
    {
        cout << "Kata kunci jurnal harus terdiri dari 3-5 kata" << endl;
        waitEnter();
        return inputKeywords(journal);
    }

    journal->keywords = keywords;
}

string exportJournal(Journal *journal)
{
    string result = "";

    result += journal->title + "\n\n";
    result += journal->author + "\n";
    result += journal->affiliation + "\n";
    result += journal->email + "\n\n";
    result += journal->abstract + "\n\n";
    result += "Kata kunci: " + journal->keywords + "\n";

    return result;
}

int main()
{
    Journal journal;
    char choice;

    while (choice != 'q')
    {
        choice = showMenu();

        if (choice == '1')
            inputTitle(&journal);
        else if (choice == '2')
            inputAuthor(&journal);
        else if (choice == '3')
            inputAffiliation(&journal);
        else if (choice == '4')
            inputEmail(&journal);
        else if (choice == '5')
            inputAbstract(&journal);
        else if (choice == '6')
            inputKeywords(&journal);
        else if (choice == '7')
        {
            string result = exportJournal(&journal);

            cout << endl
                 << endl
                 << result << endl;
            waitEnter();
        }
        else if (choice == 'q')
            system("cls");
        else
        {
            cout << "Menu tidak tersedia" << endl;
            waitEnter();
        }
    }

    return 0;
}
