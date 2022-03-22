#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include <time.h>
#include "Pembayaran.h";

using namespace std;

extern string global_level;

void menu_jenis_kendaraan() {
	cout << "1. Mobil\n";
	cout << "2. Motor\n";
	cout << "3. Muatan\n";
	cout << "\n";
}

void menu_jenis_bayar() {
	cout << "1. Member\n";
	cout << "2. Non-Member\n";
	cout << "\n";
}

struct Pembayaran {
	int jenis_kendaraan;
	int jenis_bayar;
	int jam_masuk;
	int jam_keluar;
	int total_bayar;
};

int pembayaran() {
	//int n = 0;
	struct Pembayaran Dt_Parkir;
	char confirm;
	do {
		menu_jenis_kendaraan();
		cout << "Pilih Jenis Kendaraan berdasarkan nomor di dalam menu :\n";
		scanf("%d", &Dt_Parkir.jenis_kendaraan);
		//cin>>Dt_Parkir[n].jenis_kendaraan;
		system("cls");

		menu_jenis_bayar();
		cout << "Pilih Jenis Pelanggan berdasarkan nomor di dalam menu :\n";
		scanf("%d", &Dt_Parkir.jenis_bayar);
		//cin>>Dt_Parkir[n].jenis_bayar;
		system("cls");

		cout << "Silahkan isi Jam Masuk Kendaraan :\n";
		scanf("%d", &Dt_Parkir.jam_masuk);
		//cin>>Dt_Parkir[n].jam_masuk;
		system("cls");

		cout << "Silahkan isi Jam Keluar Kendaraan :\n";
		scanf("%d", &Dt_Parkir.jam_keluar);
		//cin>>Dt_Parkir[n].jam_keluar;
		system("cls");

		Dt_Parkir.total_bayar = perhitungan_total(Dt_Parkir.jenis_kendaraan, Dt_Parkir.jenis_bayar, Dt_Parkir.jam_masuk, Dt_Parkir.jam_keluar);

		//Rekap

		fstream file;

		file.open("Rekap.txt", ios_base::app);
		if (!file.is_open()) {
			cout << "error while opening the file" << endl;
		}
		else {
			file << "\n";
			file << current_date_time();
			file << " ";
			if (Dt_Parkir.jenis_kendaraan == 1) {
				file << "Mobil";
				file << "\t\t\t";
			}
			else if (Dt_Parkir.jenis_kendaraan == 2) {
				file << "Motor";
				file << "\t\t\t";
			}
			else {
				file << "Muatan";
				file << "\t\t\t";
			}
			if (Dt_Parkir.jenis_bayar == 1) {
				file << "Member";
				file << "\t\t\t";
			}
			else {
				file << "Non-Member";
				file << "\t\t";
			}
			file << Dt_Parkir.jam_masuk;
			file << "\t\t";
			file << Dt_Parkir.jam_keluar;
			file << "\t\t";
			file << "Rp.";
			file << Dt_Parkir.total_bayar;
			file << ",00";
			//file << "\n";
		}

		//Invoice
		ofstream invoice("Invoice.txt", ofstream::trunc);
		invoice << current_date_time();
		invoice << " ";

		if (Dt_Parkir.jenis_kendaraan == 1) {
			invoice << "Mobil";
			invoice << "\t\t\t";
		}
		else if (Dt_Parkir.jenis_kendaraan == 2) {
			invoice << "Motor";
			invoice << "\t\t\t";
		}
		else {
			invoice << "Muatan";
			invoice << "\t\t\t";
		}
		if (Dt_Parkir.jenis_bayar == 1) {
			invoice << "Member";
			invoice << "\t\t\t";
		}
		else {
			invoice << "Non-Member";
			invoice << "\t\t";
		}
		invoice << Dt_Parkir.jam_masuk;
		invoice << "\t\t";
		invoice << Dt_Parkir.jam_keluar;
		invoice << "\t\t";
		invoice << "Rp.";
		invoice << Dt_Parkir.total_bayar;
		invoice << ",00";

		invoice.close();

		read_data_invoice();

		cout << "Apakah ingin menambah data(Y/N)\n";
		cin >> confirm;
		system("cls");
	} while ((confirm == 'y') || (confirm == 'Y'));

	if ((confirm == 'n') || (confirm == 'N')) {
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

	return 0;
}

//Waktu sebagai ID

string current_date_time() {
	time_t now = time(NULL);
	struct tm tstruct;
	char buf[40];
	tstruct = *localtime(&now);
	//format: DD-MM-YYYY-HH-mm-ss
	strftime(buf, sizeof(buf), "%d%m%Y%H%M%S", &tstruct);
	return buf;
}

//Perhitungan Total

int perhitungan_total(int jk, int jb, int jam_m, int jam_k) {
	//printf("%d\n", jk);
	//printf("%d\n", jb);
	//printf("%d\n", jam_m);
	//printf("%d\n", jam_k);
	int total;
	int selisih = (jam_k - jam_m);
	if (jk == 1) {
		if (jb == 1) {
			total = (selisih * 10000) - (3000 * selisih);
			return total;
		}
		else {
			total = (selisih * 10000);
			return total;
		}
	}
	else if (jk == 2) {
		if (jb == 1) {
			total = (selisih * 5000) - (1000 * selisih);
			return total;
		}
		else {
			total = (selisih * 5000);
			return total;
		}
	}
	else {
		if (jb == 1) {
			total = (selisih * 15000) - (5000 * selisih);
			return total;
		}
		else {
			total = (selisih * 15000);
			return total;
		}
	}
	//return total;
}