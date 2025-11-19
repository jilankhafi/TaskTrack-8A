#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Fungsi Tambah Tugas
void tambahTugas() {
    string namaTugas, deadline, prioritas;
    int nilaiPrioritas;

    getline(cin, namaTugas);

    cout << "Masukkan nama tugas: ";
    getline(cin, namaTugas);

    cout << "Masukkan deadline (contoh: 2025-11-15): ";
    getline(cin, deadline);

    while (true) {
        cout << "Masukkan prioritas:\n"; 
        cout << "1. Tinggi\n";
        cout << "2. Sedang\n";
        cout << "3. Rendah\n";
        cin >> nilaiPrioritas;

        if (nilaiPrioritas >= 1 && nilaiPrioritas <= 3) {
            break;
        }

        cout << "Prioritas tidak valid! Coba lagi.\n";
    }

    if (nilaiPrioritas == 1) prioritas = "Tinggi";
    else if (nilaiPrioritas == 2) prioritas = "Sedang";
    else prioritas = "Rendah";

    ofstream file("tugas.txt", ios::app);
    file << namaTugas << " | " << deadline << " | " << prioritas << endl;
    file.close();

    cout << "Tugas berhasil disimpan!\n";
}

// Fungsi Lihat Tugas
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

// Fungsi Hapus Tugas
void hapusSemuaTugas() {
    ofstream file("tugas.txt", ios::trunc);
    file.close();
    cout << "Semua tugas berhasil dihapus!\n";
}

// Fungsi Utama
int main() {
    int pilihan;

    while (true) {
        cout << "\n===== MENU TUGAS =====\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Semua Tugas\n";
        cout << "3. Hapus Semua Tugas\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) tambahTugas();
        else if (pilihan == 2) lihatTugas();
        else if (pilihan == 3) hapusSemuaTugas();
        else if (pilihan == 4) break;
        else cout << "Menu tidak valid!\n";
    }

    return 0;
}
