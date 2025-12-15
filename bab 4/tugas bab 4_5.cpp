#include <iostream>
using namespace std;

#define MAX 10  // ukuran maksimum stack

int main() {
    int S[MAX];   // array stack
    int top = -1; // posisi awal stack kosong
    int data;
    int pilihan;

    do {
        cout << "\n===== MENU STACK =====";
        cout << "\n1. PUSH (Tambah Data)";
        cout << "\n2. POP (Keluarkan Data)";
        cout << "\n3. CEK KONDISI STACK";
        cout << "\n4. TAMPILKAN ISI STACK";
        cout << "\n5. KELUAR";
        cout << "\nPilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: // PUSH
                if (top == MAX - 1) {
                    cout << "??  Stack PENUH! Tidak bisa menambah data.\n";
                } else {
                    cout << "Masukkan data: ";
                    cin >> data;
                    top++;
                    S[top] = data;
                    cout << "? Data " << data << " berhasil di-PUSH ke stack.\n";
                }
                break;

            case 2: // POP
                if (top == -1) {
                    cout << "??  Stack KOSONG! Tidak ada data untuk di-POP.\n";
                } else {
                    cout << "? Data yang di-POP: " << S[top] << endl;
                    top--;
                }
                break;

            case 3: // CEK KONDISI STACK
                if (top == -1) {
                    cout << "?? Kondisi: Stack KOSONG.\n";
                } else if (top == MAX - 1) {
                    cout << "?? Kondisi: Stack PENUH.\n";
                } else if (top < MAX - 1 && top >= 0) {
                    cout << "?? Kondisi: Stack ADA ISINYA dan MASIH BISA DIISI.\n";
                }
                break;

            case 4: // TAMPILKAN ISI STACK
                if (top == -1) {
                    cout << "Stack KOSONG. Tidak ada data untuk ditampilkan.\n";
                } else {
                    cout << "\nIsi Stack (dari atas ke bawah):\n";
                    for (int i = top; i >= 0; i--) {
                        cout << "S[" << i << "] = " << S[i] << endl;
                    }
                }
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}

