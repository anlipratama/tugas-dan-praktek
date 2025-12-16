#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   // ukuran stack
    int S[MAX];           // array stack
    int top = -1;         // posisi teratas stack (-1 artinya kosong)
    int data;

    cout << "=== PROGRAM STACK DENGAN ARRAY 1 DIMENSI ===\n";
    cout << "Masukkan data (999 untuk berhenti)\n";

    while (true) {
        cout << "\nMasukkan data: ";
        cin >> data;

        // 1) Jika data = 999 ? berhenti
        if (data == 999) {
            cout << "Proses selesai.\n";
            break;
        }

        // 2) Jika data >= 60 ? PUSH
        else if (data >= 60) {
            if (top < MAX - 1) {
                top++;          // naikkan posisi top
                S[top] = data;  // simpan data ke stack
                cout << "Data " << data << " disimpan ke stack (PUSH).\n";
            } else {
                cout << "Stack Penuh!\n";
                break; // selesai jika stack penuh
            }
        }

        // 3) Jika data < 60 ? POP
        else {
            if (top >= 0) {
                cout << "Data " << S[top] << " diambil dari stack (POP).\n";
                top--;  // kurangi posisi top
            } else {
                cout << "Stack Kosong!\n";
                break; // selesai jika kosong
            }
        }
    }

    // Menampilkan isi akhir stack
    if (top >= 0) {
        cout << "\nIsi stack terakhir:\n";
        for (int i = top; i >= 0; i--) {
            cout << S[i] << " ";
        }
        cout << endl;
    } else {
        cout << "\nStack kosong.\n";
    }

    return 0;
}

