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

        if (pilihan == "1") {
            int status = tambahTugas();
            if (status == 1)
                cout << "Tugas berhasil disimpan!\n";
        }
        else if (pilihan == "2") {
            lihatTugas();
        }
        else if (pilihan == "3") {
            hapusSemuaTugas();
        }
        else if (pilihan == "4") {
            cariTugas();
        }
        else if (pilihan == "5") {
            cout << "Total tugas: " << hitungTotalTugas() << endl;
        }
        else if (pilihan == "6") {
            cout << "Selamat Tinggal!\n";
            break;
        }
        else {
            cout << "Menu tidak valid! Harap masukkan 1 - 6.\n";
        }
    }

    return 0;
}