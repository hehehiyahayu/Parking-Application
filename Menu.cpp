#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>

#include "Menu.h";
#include "Data_Pegawai.h";
#include "Pembayaran.h";
#include "Rekap.h";
#include "Main.h";
#include "Login.h";

using namespace std;

//extern string global_level;

void menu_super_admin() {
	printf("\t Menu : \n");
	printf("1. Pembayaran \n");
	printf("2. Data Pegawai \n");
	printf("3. Rekap \n");
	printf("4. Logout \n");
	printf("5. Exit \n");
	printf("\n");
	printf("Pilih : ");
}

int sistem_menu_super_admin() {
	int pil;
	system("cls");
	menu_super_admin();
	cin >> pil;
	switch (pil) {
		case 1: {
			system("cls");
			printf("\t Pembayaran\n");
			pembayaran();
			break;
		}
		case 2: {
			printf("data pegawai");
			sistem_data_pegawai();
			break;
		}
		case 3: {
			printf("rekap");
			read_data_rekap();
			break;
		}
		case 4: {
			printf("logout");
			menu_utama();
			break;
		}
		case 5: {
			printf("exit");
			exit(0);
			break;
		}
		default: {
			return 0;
			break;
		}
	}
}

void menu_admin() {
	printf("\t Menu : \n");
	printf("1. Pembayaran \n");
	printf("2. Rekap \n");
	printf("3. Logout \n");
	printf("4. Exit \n");
	printf("\n");
	printf("Pilih : ");
}

int sistem_menu_admin() {
	int pil;
	system("cls");
	menu_admin();
	cin >> pil;
	switch (pil) {
		case 1: {
			system("cls");
			printf("\t Pembayaran\n");
			pembayaran();
			break;
		}
		case 2: {
			printf("rekap");
			read_data_rekap();
			break;
		}
		case 3: {
			printf("logout");
			menu_utama();
			break;
		}
		case 4: {
			printf("exit");
			exit(0);
			break;
		}
		default: {
			return 0;
			break;
		}
	}
}

void menu_data_pegawai() {
	printf("\t Menu Data Pegawai : \n");
	printf("1. Data Pegawai \n");
	printf("2. Buat Akun Pegawai \n");
	printf("3. Keluar \n");
	printf("\n");
	printf("Pilih : ");
}

void menu_jenis_pegawai() {
	printf("\t Menu Jenis Pegawai : \n");
	printf("1. Super Admin \n");
	printf("2. Admin \n");
	printf("\n");
	printf("Pilih : ");
}

int sistem_data_pegawai() {
	int pil;
	system("cls");
	menu_data_pegawai();
	cin >> pil;
	switch (pil) {
		case 1: {
			system("cls");
			printf("\t Data Pegawai\n");
			read_data_pegawai();
			break;
		}
		case 2: {
			system("cls");
			printf("\t Buat Akun Pegawai\n");
			create_data_pegawai();
			break;
		}
		case 3: {
			system("cls");
			sistem_menu_super_admin();
			break;
		}
		default: {
			return 0;
			break;
		}
	}
}