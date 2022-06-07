#ifndef HEADER_H
#define HEADER_H
typedef struct roba {
	int id;
	char marka[30];
	char vrsta[30];
	float velicina;
	float cijena;
	char boja[10];
}ROBA;

int izbornik(const char* const);
void kreiranje_datoteke(const char* const);
void dodaj_robu(const char* const);
void uredi_robu(const ROBA* const);
void* ucitaj_robu(const char* const);
void ispisi_robu(const ROBA* const);
void* pretrazi_robu(ROBA* const);
void izbrisi_robu(ROBA** const, const ROBA* const, const char* const);
void promjena_ime_datoteci(const char*);
void brisanje_datoteke(const char*);
int izlaz(ROBA*);
#endif 