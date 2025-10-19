#include <iostream>
using namespace std;

#define MAX1 5   // ukuran maksimum Stack1
#define MAX2 5   // ukuran maksimum Stack2

// Deklarasi array Stack dan penunjuk top
int STACK1[MAX1], STACK2[MAX2];
int TOP1 = -1, TOP2 = -1;

// Fungsi PUSH untuk Stack1
void PUSH1() {
    int data;
    if (TOP1 == MAX1 - 1) {
        cout << "??  Stack1 PENUH!\n";
    } else {
        cout << "Masukkan data ke Stack1: ";
        cin >> data;
        TOP1++;
        STACK1[TOP1] = data;
        cout << "? Data " << data << " berhasil di-PUSH ke Stack1.\n";
    }
}

// Fungsi POP untuk Stack1
void POP1() {
    if (TOP1 == -1) {
        cout << "??  Stack1 KOSONG!\n";
    } else {
        cout << "? Data yang di-POP dari Stack1: " << STACK1[TOP1] << endl;
        TOP1--;
    }
}

// Fungsi PUSH untuk Stack2
void PUSH2() {
    int data;
    if (TOP2 == MAX2 - 1) {
        cout << "??  Stack2 PENUH!\n";
    } else {
        cout << "Masukkan data ke Stack2: ";
        cin >> data;
        TOP2++;
        STACK2[TOP2] = data;
        cout << "? Data " << data << " berhasil di-PUSH ke Stack2.\n";
    }
}

// Fungsi POP untuk Stack2
void POP2() {
    if (TOP2 == -1) {
        cout << "??  Stack2 KOSONG!\n";
    } else {
        cout << "? Data yang di-POP dari Stack2: " << STACK2[TOP2] << endl;
        TOP2--;
    }
}

// Fungsi menampilkan isi kedua Stack
void tampilkanStack() {
    cout << "\n=== ISI STACK1 ===\n";
    if (TOP1 == -1)
        cout << "(kosong)\n";
    else
        for (int i = TOP1; i >= 0; i--)
            cout << STACK1[i] << endl;

    cout << "\n=== ISI STACK2 ===\n";
    if (TOP2 == -1)
        cout << "(kosong)\n";
    else
        for (int i = TOP2; i >= 0; i--)
            cout << STACK2[i] << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n===== MENU DUA STACK =====";
        cout << "\n1. PUSH ke Stack1";
        cout << "\n2. POP dari Stack1";
        cout << "\n3. PUSH ke Stack2";
        cout << "\n4. POP dari Stack2";
        cout << "\n5. TAMPILKAN isi kedua Stack";
        cout << "\n6. KELUAR";
        cout << "\nPilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: PUSH1(); break;
            case 2: POP1(); break;
            case 3: PUSH2(); break;
            case 4: POP2(); break;
            case 5: tampilkanStack(); break;
            case 6: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}

