#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Rekap.h";

using namespace std;

extern string global_level;

void read_data_rekap() {
	system("cls");
	typedef struct {
		char ID[40];
		char Kendaraan[10];
		char Member[11];
		char JM[2];
		char JK[2];
		char total[12];
	} Rekap;

	Rekap data;
	FILE* f_rekap;

	if ((f_rekap = fopen("Rekap.txt", "rt")) == NULL) {
		printf("File tida dapat dibuka\n");
		exit(1);
	}
	printf("\n\t\t\t\t\t\t Rekap Pembayaran \n\n");
	printf("\tID \t\tKendaraan \tMember \t\t\tJam_Masuk \tJam_Keluar \tTotal\n");

	while (!feof(f_rekap)) {
		fscanf(f_rekap, "%s %s %s %s %s %s", &data.ID, &data.Kendaraan, &data.Member, &data.JM, &data.JK, &data.total);
		printf("\t%s \t%s \t\t%s____ \t\t%s_ \t\t%s_ \t\t%s_\n", &data.ID, &data.Kendaraan, &data.Member, &data.JM, &data.JK, &data.total);
	}
	fclose(f_rekap);

	cout << "\nApakah anda ingin keluar ? (Y/N)\n";
	string keluar;
	cin >> keluar;

	if ((keluar == "y") || (keluar == "Y")) {
		if (global_level == "super_admin") {
			int halaman = sistem_menu_super_admin();
			//Level_Admin = level;
			cout << halaman;
		}
		else if (global_level == "admin") {
			int halaman = sistem_menu_admin();
			//Level_Admin = level;
			cout << halaman;
		}
		else {
			cout << "username atau password anda salah tidak ditemukan";
		}
	}
	else {
		read_data_rekap();
	}
}