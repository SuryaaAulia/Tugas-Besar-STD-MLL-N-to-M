#include "Tubes.h"

void createNewListMah(listMah &LM) {
    FirstMah(LM) = NULL;
}

adrMah createNewElmMah(infotype xM) {
  adrMah p = new elmListMah;
  infoMah(p) = xM;
  nextMah(p) = NULL;
  return p;
}

void insertLastMah(listMah &LM, adrMah P) {
  if (FirstMah(LM) == NULL) {
    FirstMah(LM) = P;
  } else {
    adrMah Q = FirstMah(LM);
    while (nextMah(Q) != NULL) {
      Q = nextMah(Q);
    }
    nextMah(Q) = P;
  }
}

adrMah findMaha(listMah LM, string NIM) {
  adrMah p = FirstMah(LM);
  while (p != NULL) {
    if (infoMah(p).NIM == NIM) {
      return p;
    }
    p = nextMah(p);
  }
  return NULL;
}

void ViewMah (listMah LM) {
    cout << "Nama, NIM, IPK : ";
    if (FirstMah(LM) == NULL){
        cout << "List Kosong" << endl;
    }else {
        adrMah q = FirstMah(LM);
        while (q!= NULL){
            cout << infoMah(q).nama<<", "<< infoMah(q).NIM <<"("<<infoMah(q).SKSMah<<") "<<"|";
            q = nextMah(q);
        }
    }
    cout<<endl;
}

void batalPilihMatkul(listMah &LM, string NIM, string code_matkul, string n_matkul){
    adrMah P = findMaha(LM, NIM);
    adr_mat Q;
    Q = nextMatkul(P);
    if(info_mat(Q).code_matkul == code_matkul && info_mat(Q).n_matkul == n_matkul){
        deleteFirstMatkul(nextMatkul(P));
        infoMah(P).SKSMah += info_mat(Q).SKS;
    }else{
        while(next_mat(Q) != NULL){
            if (info_mat(next_mat(Q)).code_matkul == code_matkul && info_mat(next_mat(Q)).n_matkul == n_matkul){
                deleteAfterMatkul(Q);
                infoMah(P).SKSMah += info_mat(next_mat(Q)).SKS;
            }
            Q = next_mat(Q);
        }
    }
}
