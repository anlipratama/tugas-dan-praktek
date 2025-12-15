#include <iostream>
using namespace std;

int main() {
    const int n = 100; // kapasitas queue
    int F, R;

    // Input posisi FRONT dan REAR
    cout << "Masukkan FRONT (F): ";
    cin >> F;
    cout << "Masukkan REAR (R): ";
    cin >> R;

    // Validasi input
    if (F < 0 || R < 0 || F >= n || R >= n || F > R) {
        cout << "Input tidak valid! Pastikan 0 <= F <= R < " << n << endl;
        return 0;
    }

    // a. Jumlah pengantri yang belum dilayani
    int belumDilayani = R - F + 1;

    // b. Jumlah kolom yang masih bisa diisi
    int sisaKolom = n - (R + 1);

    // Output hasil
    cout << "\nJumlah pengantri yang belum dilayani: " << belumDilayani << endl;
    cout << "Jumlah kolom yang masih bisa diisi: " << sisaKolom << endl;

    return 0;
}

