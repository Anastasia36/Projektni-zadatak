#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
static int brojRobe = 0;
void kreiranje_datoteke(const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "wb");
	if (pF == NULL) {
		perror("Kreiranje datoteke roba.bin");
		exit(EXIT_FAILURE);
	}
	fwrite(&brojRobe, sizeof(int), 1, pF);
	fclose(pF);
}

void dodaj_robu(const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "rb+");
	if (pF == NULL) {
		perror("Dodavanje robe u datoteke roba.bin");
		exit(EXIT_FAILURE);
	}
	fread(&brojRobe, sizeof(int), 1, pF);
	printf("broj robe: %d\n", brojRobe);
	ROBA temp = { 0 };
	temp.id = brojRobe;
	getchar();
	printf("Upisi marku robe\n");
	scanf("%29[^\n]", temp.marka);
	printf("Upisi vrstu robe\n");
	scanf("%29[^\n]", temp.vrsta);
	printf("Upisi velicinu robe\n");
	scanf("%29[^\n]", temp.velicina);
	printf("Upisi cijenu robe\n");
	scanf("%29[^\n]", temp.cijena);
	printf("Upisi boju robe\n");
	scanf("%19[^\n]", temp.boja);

	fseek(pF, sizeof(ROBA) * brojRobe, SEEK_CUR);
	fwrite(&temp, sizeof(ROBA), 1, pF);
	rewind(pF);
	brojRobe++;
	fwrite(&brojRobe, sizeof(int), 1, pF);
	fclose(pF);
}
void uredi_robu() {
	FILE* fp = NULL;
	int ispravak;
	fp = fopen("roba.bin", "rb+");
	if (fp == NULL)
		printf("Nema unesenih artikala\n\n");
	else {
		printf("Unesi broj artikla koji zelite ispraviti.\n");
		scanf("%d", &ispravak);
		fseek(fp, sizeof(int) + (sizeof(ROBA) * (ispravak - 1)), SEEK_SET);
		ROBA ispravljen_artikl;
		ispravljen_artikl.id = ispravak;
		getchar();
		printf("\nUnesi ispravljenu marku robe: ");
		scanf("%29[^\n]", ispravljen_artikl.marka);
		printf("\nUnesi vrstu robe: ");
		scanf("%29[^\n]", ispravljen_artikl.vrsta);
		printf("\nUnesi velicinu robe: ");
		scanf("%d", &ispravljen_artikl.velicina);
		printf("\nUnesi cijenu robe: ");
		scanf("%d", &ispravljen_artikl.cijena);
		printf("\nUnesi boju robe: ");
		scanf("%9[^\n]", &ispravljen_artikl.boja);
		fwrite(&ispravljen_artikl, sizeof(ROBA), 1, fp);
		rewind(fp);
		fwrite(&brojRobe, sizeof(int), 1, fp);
		fclose(fp);
	}
}

void ispisi_robu(const ROBA* const polje_robe) {
	if (polje_robe == NULL) {
		printf("Polje robe je prazno!\n");
		return;
	}
	int i;
	for (i = 0; i < brojRobe; i++)
	{
		printf("Roba broj %d\tID: %d\tmarka: %s\tvrsta: %s\tvelicina: %f\t cijena: %f\t boja: %s\n",
			i + 1,
			(polje_robe + i)->id,
			(polje_robe + i)->marka,
			(polje_robe + i)->vrsta,
			(polje_robe + i)->velicina,
			(polje_robe + i)->cijena,
			(polje_robe + i)->boja);
	}
}

void* pretrazi_robu(ROBA* const poljeRobe) {
	if (poljeRobe == NULL) {
		printf("Polje robe je prazno!\n");
		return NULL;
	}
	int i;
	char trazena_marka[30] = { '\0' };
	printf("Unesi trazenu marku za pronalazak robe.\n");
	getchar();
	scanf("%29[^\n]", trazena_marka);
	for (i = 0; i < brojRobe; i++)
	{
		if (!strcmp(trazena_marka, (poljeRobe + i)->marka)) {
			printf("Marka je pronadjena\n");
			return (poljeRobe + i);
		}
	}
	return NULL;
}

