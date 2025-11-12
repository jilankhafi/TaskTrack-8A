#include <iostream>
#include <string>
using namespace std;

//anjay

struct Tugas {
    string nama;
    string deadline;
    string prioritas; // "Tinggi", "Sedang", "Rendah"
    bool selesai;
};

const int MAX_TUGAS = 100;
Tugas daftarTugas[MAX_TUGAS];
int jumlahTugas = 0;

void tambahTugas() {
    if (jumlahTugas >= MAX_TUGAS) {
        cout << "Daftar tugas penuh!\n";
        return;
    }

    Tugas t;
    cout << "\nMasukkan nama tugas       : ";
    getline(cin, t.nama);
    cout << "Masukkan deadline tugas   : ";
    getline(cin, t.deadline);
    cout << "Masukkan prioritas (Tinggi/Sedang/Rendah): ";
    getline(cin, t.prioritas);
    t.selesai = false;

    daftarTugas[jumlahTugas++] = t;
    cout << "Tugas berhasil ditambahkan!\n";
}

void tampilkanSemua() {
    if (jumlahTugas == 0) {
        cout << "\nBelum ada tugas yang dicatat.\n";
        return;
    }

    cout << "\n=== Daftar Tugas ===\n";
    for (int i = 0; i < jumlahTugas; i++) {
        cout << i + 1 << ". " << daftarTugas[i].nama
             << " | Deadline: " << daftarTugas[i].deadline
             << " | Prioritas: " << daftarTugas[i].prioritas
             << " | Status: " << (daftarTugas[i].selesai ? "Selesai" : "Belum Selesai") << endl;
    }
}

void tandaiSelesai() {
    tampilkanSemua();
    if (jumlahTugas == 0) return;

    string input;
    cout << "\nMasukkan nomor tugas yang sudah selesai: ";
    getline(cin, input);
    int index = stoi(input); // konversi string ke int

    if (index < 1 || index > jumlahTugas) {
        cout << "Nomor tugas tidak valid!\n";
        return;
    }

    daftarTugas[index - 1].selesai = true;
    cout << "Tugas \"" << daftarTugas[index - 1].nama << "\" telah ditandai selesai!\n";
}

void tampilkanByPrioritas() {
    if (jumlahTugas == 0) {
        cout << "\nBelum ada tugas yang dicatat.\n";
        return;
    }

    string prior;
    cout << "\nMasukkan prioritas yang ingin ditampilkan (Tinggi/Sedang/Rendah): ";
    getline(cin, prior);

    cout << "\n=== Tugas dengan Prioritas " << prior << " ===\n";
    bool ditemukan = false;
    for (int i = 0; i < jumlahTugas; i++) {
        if (daftarTugas[i].prioritas == prior) {
            cout << "- " << daftarTugas[i].nama
                 << " (Deadline: " << daftarTugas[i].deadline
                 << ", Status: " << (daftarTugas[i].selesai ? "Selesai" : "Belum") << ")\n";
            ditemukan = true;
        }
    }

    if (!ditemukan) cout << "Tidak ada tugas dengan prioritas " << prior << ".\n";
}

int main() {
    string input;
    int pilihan = 0;

    do {
        cout << "\n===== TaskTrack: Pengelola Tugas Harian =====\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Tampilkan Semua Tugas\n";
        cout << "3. Tandai Tugas Selesai\n";
        cout << "4. Tampilkan Tugas Berdasarkan Prioritas\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        getline(cin, input);
        if (input.empty()) continue;
        pilihan = stoi(input);

        switch (pilihan) {
            case 1: tambahTugas(); break;
            case 2: tampilkanSemua(); break;
            case 3: tandaiSelesai(); break;
            case 4: tampilkanByPrioritas(); break;
            case 5: cout << "\nTerima kasih telah menggunakan TaskTrack!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
