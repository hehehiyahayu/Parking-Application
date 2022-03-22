#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Invoice.h";

using namespace std;

extern string global_level;

void read_data_invoice() {
	system("cls");
	typedef struct {
		char ID[40];
		char Kendaraan[10];
		char Member[11];
		char JM[2];
		char JK[2];
		char total[12];
	} Invoice;

	Invoice data;
	FILE* f_invoice;

	if ((f_invoice = fopen("Invoice.txt", "rt")) == NULL) {
		printf("File tida dapat dibuka\n");
		exit(1);
	}
	printf("\n\t\t\t\t\t\t Struk Pembayaran \n\n");
	printf("\tID \t\tKendaraan \tMember \t\t\tJam_Masuk \tJam_Keluar \tTotal\n");

	while (!feof(f_invoice)) {
		fscanf(f_invoice, "%s %s %s %s %s %s", &data.ID ,&data.Kendaraan, &data.Member, &data.JM, &data.JK, &data.total);
		printf("\t%s \t%s \t\t%s____ \t\t%s \t\t%s \t\t%s\n\n", &data.ID, &data.Kendaraan, &data.Member, &data.JM, &data.JK, &data.total);
	}
	fclose(f_invoice);
}