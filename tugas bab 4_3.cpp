#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   // ukuran maksimal stack
    int S[MAX];           // array stack
    int top = -1;         // posisi awal stack (kosong)
    int data;

    cout << "=== PUSH DATA KE STACK SAMPAI PENUH ===\n";

    while (true) {
        // Cek apakah stack sudah penuh
        if (top == MAX - 1) {
            cout << "Stack sudah PENUH! Tidak bisa menambah data lagi.\n";
            break;
        }

        cout << "Masukkan data: ";
        cin >> data;

        // PUSH data ke stack
        top++;
        S[top] = data;

        cout << "Data " << data << " berhasil di-PUSH ke stack.\n";
    }

    return 0;
}

