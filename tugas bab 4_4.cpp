#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   // ukuran maksimum stack
    int S[MAX];           // array stack
    int top = 4;          // contoh: stack sudah terisi 5 elemen (0..4)
    
    // data contoh di dalam stack
    S[0] = 10;
    S[1] = 20;
    S[2] = 30;
    S[3] = 40;
    S[4] = 50;

    cout << "=== POP ISI STACK ===\n";

    // selama stack masih ada isinya
    while (top >= 0) {
        cout << "Mengeluarkan data: " << S[top] << endl;
        top--; // turunkan posisi top (hapus elemen terakhir)
    }

    cout << "Stack sekarang sudah KOSONG." << endl;

    return 0;
}

