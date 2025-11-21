// input library yang akan digunakan
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int tambahTugas() {
    // deklarasi variabel
    string namaTugas, deadline, prioritas , inputPrioritas;
    string pilihan[3] = {"1", "2", "3"};  

    getline(cin, namaTugas); // membersihkan buffer

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
        cin >> inputPrioritas;

        if (inputPrioritas == pilihan[0]) {
            prioritas = "Tinggi";
            valid = true;
        }
        else if (inputPrioritas == pilihan[1]) {
            prioritas = "Sedang";
            valid = true;
        }
        else if (inputPrioritas == pilihan[2]) {
            prioritas = "Rendah";
            valid = true;
        }
        else {
            cout << "Input tidak valid!\n\n";
        }
    }
    ofstream file("tugas.txt", ios::app);
    file << namaTugas << " | " << deadline << " | " << prioritas << endl;
    file.close();

    return 1;
}
//anjay dah selesai wakkk
//gacor gacor
