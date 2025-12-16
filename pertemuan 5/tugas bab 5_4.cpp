#include <iostream>
using namespace std;

#define MAX 10
int S1[MAX];
int TOP1 = -1;

// Fungsi POP semua isi Stack1
void popAllStack1() {
    if (TOP1 == -1) {
        cout << "Stack1 Kosong.\n";
    } else {
        cout << "Mengambil semua isi Stack1:\n";
        while (TOP1 >= 0) {
            cout << "Data yang diambil: " << S1[TOP1] << endl;
            TOP1--;  // mengurangi top
        }
        cout << "Semua data Stack1 sudah diambil.\n";
    }
}

int main() {
    // Contoh: isi Stack1 terlebih dahulu
    S1[++TOP1] = 10;
    S1[++TOP1] = 20;
    S1[++TOP1] = 30;

    // Panggil fungsi untuk mengeluarkan semua isi Stack1
    popAllStack1();

    return 0;
}

