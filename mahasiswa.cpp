#include <iostream>

using namespace std;

struct Mahasiswa
{
    long long npm;
    string name;
    float ipk;
};

int showMenu()
{
    int menu;

    cout << "Menu: " << endl;
    cout << "1. Tampilkan data mahasiswa" << endl;
    cout << "2. Ubah data mahasiswa" << endl;
    cout << "3. Hapus data mahasiswa" << endl;
    cout << "4. Keluar" << endl;

    cout << "Pilih menu: ";
    cin >> menu;

    return menu;
}

void setMahasiswa(Mahasiswa *mhs, int i)
{
    cout << i + 1 << ". Masukkan NPM: ";
    cin >> mhs->npm;

    cout << "   Masukkan nama: ";
    cin.ignore();
    getline(cin >> ws, mhs->name);

    cout << "   Masukkan IPK: ";
    cin >> mhs->ipk;
}

void updateMahasiswa(Mahasiswa mhs[])
{
    int i;

    cout << "Masukkan urutan mahasiswa yang ingin diubah: ";
    cin >> i;

    cout << endl;

    cout << "Ubah data mahasiswa ke-" << i << ": " << endl;

    i--;

    cout << "Masukkan NPM (" << mhs[i].npm << "): ";
    cin >> mhs[i].npm;

    cout << "Masukkan nama (" << mhs[i].name << "): ";
    cin.ignore();
    getline(cin >> ws, mhs[i].name);

    cout << "Masukkan IPK (" << mhs[i].ipk << "): ";
    cin >> mhs[i].ipk;

    cout << "Data mahasiswa berhasil diubah!" << endl;
    cout << endl;
}

void showMahasiswa(Mahasiswa mhs[], int count)
{
    cout << "Data mahasiswa: " << endl;

    for (int i = 0; i < count; i++)
    {
        if (mhs[i].npm == 0)
        {
            cout << i + 1 << ". Kosong" << endl
                 << endl;
            continue;
        }

        cout << i + 1 << ". NPM: " << mhs[i].npm << endl;
        cout << "   Nama: " << mhs[i].name << endl;
        cout << "   IPK: " << mhs[i].ipk << endl;
        cout << endl;
    }
}

void deleteMahasiswa(Mahasiswa mhs[])
{
    int i;

    cout << "Masukkan urutan mahasiswa yang ingin dihapus: ";
    cin >> i;

    i--;

    mhs[i].npm = 0;
    mhs[i].name = "";
    mhs[i].ipk = 0;

    cout << "Data mahasiswa ke-" << i + 1 << " berhasil dihapus!" << endl;
    cout << endl;
}

int main()
{
    int count;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> count;
    cout << endl;

    Mahasiswa mhs[count];

    for (int i = 0; i < count; i++)
    {
        setMahasiswa(&mhs[i], i);
        cout << endl;
    }

    bool isRunning = true;

    while (isRunning)
    {
        int menu = showMenu();

        cout << endl;

        if (menu == 1)
            showMahasiswa(mhs, count);
        else if (menu == 2)
            updateMahasiswa(mhs);
        else if (menu == 3)
            deleteMahasiswa(mhs);
        else if (menu == 4)
            isRunning = false;
        else
            cout << "Menu tidak tersedia!" << endl;
    }

    return 0;
}