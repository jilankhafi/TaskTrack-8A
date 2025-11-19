#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void lihatTugas() {
    ifstream file("tugas.txt");
    string baris;

    cout << "\n===== DAFTAR TUGAS =====\n";

    if (!file.is_open()) {
        cout << "Belum ada tugas.\n";
        return;
    }

    bool kosong = true;

    while (getline(file, baris)) {
        kosong = false;
        cout << baris << endl;
    }

    if (kosong) cout << "Belum ada tugas.\n";

    file.close();
}
