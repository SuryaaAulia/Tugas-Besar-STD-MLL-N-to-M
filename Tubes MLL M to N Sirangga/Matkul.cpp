#include "Tubes.h"

void createNewListMat(List_mat &MT){
  first_mat(MT) = NULL;
}

adr_mat createNewElmMat(infotype_mat xMT){
  adr_mat p = new elmMatkul;
  info_mat(p) = xMT;
  next_mat(p) = NULL;
  return p;
}

void insertFirstMat(List_mat &MT, adr_mat P){
  if (first_mat(MT) == NULL ){
    first_mat(MT) = P;
  }else {
    next_mat(P) = first_mat(MT);
    first_mat(MT) = P;
  }
}

void deleteAfterMatkul(adr_mat P){
    adr_mat Q = next_mat(P);
    if (next_mat(P) != NULL){
        next_mat(P) = next_mat(Q);
        next_mat(Q) = NULL;
    }else{
        next_mat(P) = NULL;
    }
}

void deleteFirstMatkul(adr_mat &P){
    adr_mat Q = P;
    P = next_mat(Q);
    Q = NULL;
}


adr_mat findMatkul(List_mat MT, string n_matkul, string code_matkul){
  adr_mat p = first_mat(MT);
  while (p != NULL){
    if (info_mat(p).n_matkul == n_matkul && info_mat(p).code_matkul == code_matkul){
      return p;
    }
    p = next_mat(p);
  }
  return NULL;
}

void assignMahasiswa(listMah &LM, List_mat &MT, string NIM, string n_matkul, string code_matkul){
    adrMah P = findMaha(LM, NIM);
    int x = 0;
    if (infoMah(P).SKSMah == 19){
        x = 19;
    }else{
        x = 24;
    }
    adr_mat Q = findMatkul(MT, n_matkul, code_matkul);
    if (Q != NULL){
        Q = createNewElmMat(info_mat(Q));
        if (P != NULL && infoMah(P).SKSMah <= x && (infoMah(P).SKSMah - info_mat(Q).SKS) >= 0){
            if (nextMatkul(P) == NULL){
                nextMatkul(P) = Q;
            }else{
                next_mat(Q) = nextMatkul(P);
                nextMatkul(P) = Q;
            }
            infoMah(P).SKSMah -= info_mat(Q).SKS;
        }
    }
}

void ViewMat(List_mat MT){
    cout << "Daftar Matakuliah, Code Matakuliah, SKS : ";
    if (first_mat(MT) == NULL) {
        cout<<"List Kosong"<<endl;
    }else {
        adr_mat q = first_mat(MT);
        while (q != NULL) {
            cout << info_mat(q).n_matkul<<", "<< info_mat(q).code_matkul<<", "<<info_mat(q).SKS<< "| ";
            q = next_mat(q);
        }
    }
    cout<<endl;
}

void showMahMat(List_mat MT, listMah LM){
    cout << "NIM, (Total Bobot SKS Diambil), Matakuliah Yang Diambil : ";
    adrMah P = FirstMah(LM);
    adr_mat Q;
    if (FirstMah(LM) == NULL){
        cout<<"List Kosong"<<endl;
    }
    while(P != NULL){
        cout<<infoMah(P).NIM<<": ";
        Q = nextMatkul(P);
        while(Q != NULL){
            cout <<"("<<info_mat(Q).SKS<<")"<<"|"<< info_mat(Q).n_matkul << "-" << info_mat(Q).code_matkul << "|, ";
            Q = next_mat(Q);
        }
        P = nextMah(P);
    }
    cout<<endl;
}
