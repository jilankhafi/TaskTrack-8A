#include <iostream>
#include <string>
using namespace std;

// Import semua file modular
#include "tambah.cpp"
#include "lihat.cpp"
#include "hapus.cpp"
#include "cari.cpp"
#include "hitung.cpp"

int main() {
    string pilihan;
    string menu[6] = {"1", "2", "3", "4", "5", "6"};
    while (true) {
        cout << "\n===== MENU TUGAS =====\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Semua Tugas\n";
        cout << "3. Hapus Semua Tugas\n";
        cout << "4. Cari Tugas\n";
        cout << "5. Hitung Total Tugas\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";

        cin >> pilihan;

        if (pilihan == menu[0]) {
            if (tambahTugas() == 1)
                cout << "Tugas berhasil disimpan!\n";
        }
        else if (pilihan == menu[1]) {
            lihatTugas();
        }
        else if (pilihan == menu[2]) {
            hapusSemuaTugas();
        }
        else if (pilihan == menu[3]) {
            cariTugas();
        }
        else if (pilihan == menu[4]) {
            cout << "Total tugas: " << hitungTotalTugas() << endl;
        }
        else if (pilihan == menu[5]) {
            cout << "Selamat Tinggal!\n";
            break;
        }
        else {
            cout << "Menu tidak valid! Masukkan angka 1 - 6.\n";
        }
    }

    return 0;
}