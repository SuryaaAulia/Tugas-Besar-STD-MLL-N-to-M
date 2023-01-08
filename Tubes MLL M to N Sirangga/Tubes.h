#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

#define nextMah(x) x->nextMah
#define nextMah1(x) x->nextMah
#define nextMah2(x) x->nextMah
#define nextMatkul(x) x->nextMatkul
#define FirstMah(L) L.FirstMah
#define infoMah(x) x->infoMah
#define next_mat(x) x->next_mat
#define first_mat(L) L.first_mat
#define info_mat(x) x->info_mat

using namespace std;

struct mahasiswa {
  string nama, NIM;
  int SKSMah;
  float IPK;
};
struct Matkul {
  string n_matkul, code_matkul;
  int SKS;
};

typedef mahasiswa infotype;
typedef Matkul infotype_mat;

typedef struct elmListMah *adrMah;
typedef struct elmMatkul *adr_mat;

struct elmListMah {
    infotype infoMah;
    adrMah nextMah;
    adr_mat nextMatkul;
};
struct elmMatkul {
  infotype_mat info_mat;
  adr_mat next_mat;
};

struct listMah {
  adrMah FirstMah;
};
struct List_mat {
  adr_mat first_mat;
};

void createNewListMah(listMah &LM);
adrMah createNewElmMah(infotype xM);
void insertLastMah(listMah &LM, adrMah P);
void assignMahasiswa(listMah &LM, List_mat &MT, string NIM, string n_matkul, string code_matkul);
void ViewMah (listMah LM);
adrMah findMaha(listMah LM, string NIM);
void batalPilihMatkul(listMah &LM, string NIM, string code_matkul, string n_matkul);

void createNewListMat(List_mat &MT);
adr_mat createNewElmMat(infotype_mat xMT);
void insertFirstMat(List_mat &MT, adr_mat P);
adr_mat findMatkul(List_mat MT, string n_matkul, string code_matkul);
void ViewMat(List_mat MT);
void showMahMat(List_mat MT, listMah LM);
void deleteAfterMatkul(adr_mat P);
void deleteFirstMatkul(adr_mat &P);
#endif // TUBES_H_INCLUDED
