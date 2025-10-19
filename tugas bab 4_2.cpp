#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   // ukuran stack
    int S[MAX];           // array stack
    int top = -1;         // posisi top stack (-1 artinya kosong)
    int data;

    cout << "=== PROGRAM STACK (PUSH sampai penuh, POP sampai kosong) ===\n";

    // ==========================
    // PROSES INPUT & PUSH
    // ==========================
    cout << "\nMasukkan data (999 untuk berhenti):\n";
    while (true) {
        cout << "Data: ";
        cin >> data;

        // Jika input = 999 ? selesai input
        if (data == 999) {
            cout << "Input data selesai (999 terdeteksi).\n";
            break;
        }

        // Cek apakah stack penuh
        if (top == MAX - 1) {
            cout << "Stack Penuh! Tidak bisa menambah data lagi.\n";
            break;
        }

        // PUSH data ke stack
        top++;
        S[top] = data;
        cout << "Data " << data << " dimasukkan ke stack (PUSH).\n";
    }

    // ==========================
    // PROSES POP SAMPAI KOSONG
    // ==========================
    cout << "\nMengeluarkan isi stack (POP):\n";
    if (top == -1) {
        cout << "Stack kosong! Tidak ada data untuk di-POP.\n";
    } else {
        while (top >= 0) {
            cout << "Data " << S[top] << " diambil dari stack (POP).\n";
            top--; // mengurangi posisi top
        }
        cout << "\nStack sekarang kosong.\n";
    }

    return 0;
}

