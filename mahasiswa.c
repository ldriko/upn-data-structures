#include <stdio.h>

struct Mahasiswa
{
	unsigned int npm;
	char name[50];
	float ipk;
};

typedef struct Mahasiswa Mahasiswa;

int showMenu()
{
	int menu;

	printf("Menu:\n");
	printf("1. Tampilkan data mahasiswa\n");
	printf("2. Ubah data mahasiswa\n");
	printf("3. Hapus data mahasiswa\n");
	printf("4. Keluar\n");

	printf("Pilih menu: ");
	scanf("%d", &menu);
	printf("\n");

	return menu;
}

void setMahasiswa(Mahasiswa *mhs, int i)
{
	printf("%d. Masukkan NPM: ", i + 1);
	scanf("%u", &mhs->npm);

	printf("   Masukkan nama: ");
	scanf("%s", mhs->name);

	printf("   Masukkan IPK: ");
	scanf("%f", &mhs->ipk);
	printf("\n");
}

void showMahasiswa(Mahasiswa mhs[], int count)
{
	int i;

	printf("Data mahasiswa:\n");

	for (i = 0; i < count; i++)
	{
		if (mhs[i].npm == 0)
		{
			printf("%d. Kosong\n\n", i + 1);
			continue;
		}

		printf("%d. NPM: %u\n", i + 1, mhs[i].npm);
		printf("   Nama: %s\n", mhs[i].name);
		printf("   IPK: %.2f\n", mhs[i].ipk);
		printf("\n");
	}
}

void updateMahasiswa(Mahasiswa mhs[])
{
	int i;

	printf("Masukkan urutan mahasiswa yang ingin diubah: ");
	scanf("%d", &i);

	printf("\n");
	printf("Ubah data mahasiswa ke-%d\n", i);

	i--;

	printf("Masukkan NPM (%u): ", mhs[i].npm);
	scanf("%u", &mhs[i].npm);

	printf("Masukkan nama (%s): ", mhs[i].name);
	scanf("%s", mhs[i].name);

	printf("Masukkan IPK (%.2f): ", mhs[i].ipk);
	scanf("%f", &mhs[i].ipk);

	printf("Data mahasiswa berhasil diubah!\n\n");
}

void deleteMahasiswa(Mahasiswa mhs[])
{
	int i;

	printf("Masukkan urutan mahasiswa yang ingin dihapus: ");
	scanf("%d", &i);

	i--;

	mhs[i].npm = 0;
	mhs[i].name[0] = '\0';
	mhs[i].ipk = 0;

	printf("Data mahasiswa ke-%d berhasil dihapus!\n\n", i + 1);
}

int main()
{
	int count;

	printf("Masukkan jumlah mahasiswa: ");
	scanf("%d", &count);
	printf("\n");

	Mahasiswa mhs[count];
	int i;

	for (i = 0; i < count; i++)
	{
		setMahasiswa(&mhs[i], i);
	}

	int menu = showMenu();

	while (menu != 4)
	{
		switch (menu)
		{
		case 1:
			showMahasiswa(mhs, count);
			break;
		case 2:
			updateMahasiswa(mhs);
			break;
		case 3:
			deleteMahasiswa(mhs);
			break;
		default:
			printf("Menu tidak tersedia!\n");
			break;
		}

		menu = showMenu();
	}

	return 0;
}
