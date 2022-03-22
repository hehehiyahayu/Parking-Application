#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Main.h";
#include "Login.h";
#include "Menu.h";

using namespace std;

string global_level;

int menu_utama() {
	system("cls");
	int pil = 0;
	char confirm;
	menu();

	cin >> pil;
	switch (pil) {
		case 1: {
			system("cls");
			login();
			break;
		}
		case 2: {
			exit(0);
			break;
		}
		default: {
			return 0;
			break;
		}
	}
	return 0;
}

void menu() {
	printf("\t Menu : \n");
	printf("1. Login \n");
	printf("2. Exit \n");
	printf("\n");
	printf("Pilih : ");
}

int login() {
	//read database
	string testline;
	string word[6][4];

	ifstream Test("Data.txt");

	if (!Test)
	{
		cout << "There was an error opening the file.\n";
		return 0;
	}
	//store words in array
	int x = 0, y = 0;
	while (Test >> testline)
	{
		word[y][x] = testline;
		x++;
		if (testline == "")
			y++;
	}
	//deklarasi data
	string id, username, password, level;
	char ch;
	int i;
	int pil;

	//login:
	//tampilan login
	cout << "LOGIN" << endl;

	//input data	
	cout << "\nUsername : "; cin >> username;
	cout << "\nPassword : "; ch = _getch();

	while (ch != 13) {
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}

	//perulangan untuk mengecek apakah data yang dinputkan sudah sesuai dengan data
	for (i = 0; i <= 10; i++) {
		//cek inputan data
		if (word[i][1] == username && word[i][2] == password) {
			level = word[i][3];
			break;
		}
	}
	cout << "\n\n";

	//Percabangan untuk output berdasarkan level
	if (level == "super_admin") {
		global_level = "super_admin";
		int halaman = sistem_menu_super_admin();
		cout << halaman;
	}
	else if (level == "admin") {
		global_level = "admin";
		int halaman = sistem_menu_admin();
		cout << halaman;
	}
	else {
		cout << "username atau password anda salah atau tidak ditemukan";
	}

	return 0;
}
