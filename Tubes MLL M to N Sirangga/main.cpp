#include "Tubes.h"

int main() {
    List_mat MT;
    listMah LM;
    int pilihan, jumlahMat;
    infotype_mat a;
    infotype b;
    adrMah p;
    adr_mat q;
    string n_matkul ,NIM ,nama , code_matkul, matkul, code;
    jumlahMat = 0;

    createNewListMah(LM);
    createNewListMat(MT);
    while (true){
        system("cls");
        cout << "========================================= Selamat Datang Pada Sistem Sirangga ========================================="<<endl<<endl;
        cout << "\t\t\t\t======================== INPUT DATA ========================"<< endl;
        ViewMah(LM);
        cout<<endl;
        ViewMat(MT);
        cout<<endl;
        showMahMat(MT, LM);
        cout<<endl;
        cout<< "Jumlah Matakuliah Yang Tersedia : "<<jumlahMat<<endl;
        cout<<endl<<endl;
        cout<<"Menu"<<endl;
        cout<<"1. Masukan Data Mahasiswa" << endl;
        cout<<"2. Masukan Data Matakuliah" << endl;
        cout<<"3. Assign Matakuliah" << endl;
        cout<<"4. Unassigns Matakuliah" << endl<<endl;
        cout<<"Masukan Pilihan Anda : ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout<< "Masukan Nama : ";
            cin >> b.nama;
            cout<< "Masukan NIM : ";
            cin >> b.NIM;
            cout<< "Masukan IPK : ";
            cin>> b.IPK;
            if (b.IPK < 3.00){
                b.SKSMah = 19;
            }else{
                b.SKSMah = 24;
            }
            p = createNewElmMah(b);
            insertLastMah(LM, p);
        }else if (pilihan == 2){
            cout<< "Masukan Matakuliah :";
            cin >> a.n_matkul;
            cout << "Code Matkul : ";
            cin >> a.code_matkul;
            cout << "Bobot SKS Matkul : ";
            cin >> a.SKS;
            q = createNewElmMat(a);
            insertFirstMat(MT, q);
            jumlahMat++;
        }else if (pilihan == 3){
            cout << "Masukan NIM : ";
            cin >> NIM;
            cout<< "Kuota SKS Yang Masih Dapat Anda Ambil : "<<infoMah(p).SKSMah<<endl;
            cout << "Matkul Yang Ingin Di Assign : ";
            cin >> n_matkul;
            cout << "Code Matkul Yang Ingin Di Assign : ";
            cin >> code_matkul;
            if ((infoMah(p).SKSMah-info_mat(q).SKS) < 0){
                cout<<"Maaf Bobot SKS Yang Anda Ambil Sudah Melebihi Kuota SKS"<<endl;
                system("PAUSE");
            }else{
                assignMahasiswa(LM, MT, NIM, n_matkul, code_matkul);
            }
        }else if (pilihan == 4){
            cout << "Masukan NIM anda : ";
            cin >> NIM;
            cout << "Kode Matakuliah Yang Ingin Di Unassigns : ";
            cin >> code_matkul;
            cout << "Nama Matakuliah Yang Ingin Di Unassigns : ";
            cin >> n_matkul;
            batalPilihMatkul(LM, NIM, code_matkul, n_matkul);
            showMahMat(MT, LM);
        }else {
            system("PAUSE");
        }
    }
}
