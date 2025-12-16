#include <iostream>
using namespace std;

#define MAX 10
int S2[MAX];
int TOP2 = -1;

// Fungsi POP semua isi Stack2
void popAllStack2() {
    if (TOP2 == -1) {
        cout << "Stack2 Kosong.\n";
    } else {
        cout << "Mengambil semua isi Stack2:\n";
        while (TOP2 >= 0) {
            cout << "Data yang diambil: " << S2[TOP2] << endl;
            TOP2--;  // mengurangi top
        }
        cout << "Semua data Stack2 sudah diambil.\n";
    }
}

int main() {
    // Contoh: isi Stack2 terlebih dahulu
    S2[++TOP2] = 100;
    S2[++TOP2] = 200;
    S2[++TOP2] = 300;

    // Panggil fungsi untuk mengeluarkan semua isi Stack2
    popAllStack2();

    return 0;
}

