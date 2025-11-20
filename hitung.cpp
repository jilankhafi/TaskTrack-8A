#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int hitungTotalTugas() {
    ifstream file("tugas.txt");
    string baris;
    int total = 0;

    if (!file.is_open()) return 0;

    while (getline(file, baris)) {
        if (baris != "") {
            total++;
        }
    }

    file.close();
    return total;
