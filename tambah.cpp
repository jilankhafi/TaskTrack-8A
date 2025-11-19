/*
input library yang akan digunakan
kedalam Function nya
*/
#include <iostream>   
#include <fstream>
#include <string>
using namespace std;

int tambahTugas() {
    // deklarasi varabel 
    string namaTugas, deadline, prioritas;
    int nilaiPrioritas;

    getline(cin, namaTugas); //memberihkan buffer dari cin

    cout << "Masukkan nama tugas: ";
    getline(cin, namaTugas);

    cout << "Masukkan deadline (contoh: 2025-11-15): ";
    getline(cin, deadline);

    bool valid = false;

    while (!valid) {
        cout << "Masukkan prioritas:\n";
        cout << "1. Tinggi\n";
        cout << "2. Sedang\n";
        cout << "3. Rendah\n";
        cout << "Pilih menu [1/2/3]: ";
        cin >> nilaiPrioritas;

        if (nilaiPrioritas >= 1 && nilaiPrioritas <= 3) {
            switch (nilaiPrioritas) {
                case 1: prioritas = "Tinggi"; valid = true; break;
                case 2: prioritas = "Sedang"; valid = true; break;
                case 3: prioritas = "Rendah"; valid = true; break;
            }
        } else {
            cout << "Input tidak valid!\n\n";
        }
    }

    ofstream file("tugas.txt", ios::app);
    file << namaTugas << " | " << deadline << " | " << prioritas << endl;
    file.close();

    return 1;
}
//bagian mcihael

