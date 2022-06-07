#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main(void) {
	int uvijet = 1;
	char imeDatoteke[20] = { '\0' };
	printf("Unesite ime datoteke s kojom se treba raditi!\n");
	scanf("%19[^\n]", imeDatoteke);
	while (uvijet) {
		uvijet = izbornik(imeDatoteke);
	}
	printf("Kraj programa!\n");
	return 0;
}
int izbornik(const char* const imeDatoteke) {
	printf("**********SKLADIŠTE ROBE**********");
	printf("Odaberite broj radnje koju želite izvršiti:");
	printf("*********************************************\n");
	printf("\t\t\t1: Kreiraj datoteku\n");
	printf("\t\t\t2: Dodaj robu\n");
	printf("\t\t\t3: Uredi robu\n");
	printf("\t\t\t4: Ispis cijelog skladišta robe\n");
	printf("\t\t\t5: Pretraži robu\n");
	printf("\t\t\t6: Izbriši robu\n");
	printf("\t\t\t7: Izbriši datoteku\n");
	printf("\t\t\t8: Izlaz\n");
	printf("*******************************************************\n");

	int uvijet = 0;
	static ROBA* polje_robe = NULL;
	static ROBA* pronadi_robu = NULL;
	scanf("%d", &uvijet);
	switch (uvijet) {
	case 1:
		kreiranje_datoteke(imeDatoteke);
		break;
	case 2:
		dodaj_robu(imeDatoteke);
		break;
	case 3:

	case 4:
		ispisi_robu(polje_robe);
		break;
	case 5:
		pronadi_robu = (ROBA*) pretrazi_robu(polje_robe);
		break;
	case 6:
		izbrisi_robu(&pronadi_robu, polje_robe, imeDatoteke);
		break;
	case 7:
		promjena_ime_datoteci(imeDatoteke);
		break;
	case 8:
		uvijet = exit(polje_robe);
		break;
	default:
		uvijet = 0;
	}
	return uvijet;
}
