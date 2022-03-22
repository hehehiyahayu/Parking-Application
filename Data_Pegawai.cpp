#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Data_Pegawai.h";

using namespace std;

typedef struct{
	char id[40];
	char nama[20];
	char password[15];
	int jenis_pegawai;
} Akun;

string current_date_time_as_id() {
	time_t now = time(NULL);
	struct tm tstruct;
	char id[40];
	tstruct = *localtime(&now);
	//format: DDMMYYYYHHmmss
	strftime(id, sizeof(id), "%d%m%Y%H%M%S", &tstruct);
	return id;
}

void create_data_pegawai() {
	Akun Dt_pegawai;
	char confirm;
	do {
		cout << "\nSilahkan isi nama pegawai :\n";
		scanf("%s", &Dt_pegawai.nama);
		system("cls");

		cout << "Silahkan isi password pegawai :\n";
		scanf("%s", &Dt_pegawai.password);
		system("cls");

		menu_jenis_pegawai();
		cout << "Pilih Jenis Pegawai berdasarkan nomor di dalam menu :\n";
		scanf("%d", &Dt_pegawai.jenis_pegawai);
		system("cls");

		//Data Pegawai

		fstream file;

		file.open("Data.txt", ios_base::app);
		if (!file.is_open()) {
			cout << "error while opening the file" << endl;
		}
		else {
			file << "\n";
			file << current_date_time_as_id();
			file << " ";
			file << Dt_pegawai.nama;
			file << " ";
			file << Dt_pegawai.password;
			file << " ";
			if (Dt_pegawai.jenis_pegawai == 1) {
				file << "super_admin";
			}
			else {
				file << "admin";
			}
		}

		cout << "Apakah ingin menambah data(Y/N)\n";
		cin >> confirm;
		system("cls");
	} while ((confirm == 'y') || (confirm == 'Y'));

	if ((confirm == 'n') || (confirm == 'N')) {
		sistem_data_pegawai();
	}
}

void read_data_pegawai() {
	system("cls");
	typedef struct {
		char id[40];
		char Nama[20];
		char Password[15];
		char Level[12];
	} Pegawai;

	Pegawai data_pegawai;
	FILE* f_pegawai;

	if ((f_pegawai = fopen("Data.txt", "rt")) == NULL) {
		printf("File tida dapat dibuka\n");
		exit(1);
	}
	printf("\n\t\t Data Pegawai \n\n");
	printf("\tID \t\tNama \tLevel \n");

	while (!feof(f_pegawai)) {
		fscanf(f_pegawai, "%s %s %s %s", &data_pegawai.id, &data_pegawai.Nama, &data_pegawai.Password, &data_pegawai.Level);
		printf("\t%s \t%s \t%s \n", &data_pegawai.id, &data_pegawai.Nama, &data_pegawai.Level);
	}
	fclose(f_pegawai);

	cout << "\nApakah anda ingin kembali ? (Y/N) ";
	string keluar;
	cin>>keluar;

	if ((keluar == "y") || (keluar == "Y")) {
		sistem_data_pegawai();
	}
	else {
		read_data_pegawai();
	}
}