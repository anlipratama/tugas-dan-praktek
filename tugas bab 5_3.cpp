#include <iostream>
using namespace std;

#define MAX 10  // ukuran array maksimal

class DoubleStack {
private:
    int data[MAX];
    int top1;  // untuk Stack1 (dari kiri)
    int top2;  // untuk Stack2 (dari kanan)

public:
    // Konstruktor
    DoubleStack() {
        top1 = -1;
        top2 = MAX;
    }

    // PUSH untuk Stack1
    void push1(int value) {
        if (top1 + 1 == top2) {
            cout << "?? Stack Penuh! Tidak bisa push ke Stack1.\n";
        } else {
            data[++top1] = value;
            cout << "? Data " << value << " berhasil ditambahkan ke Stack1.\n";
        }
    }

    // PUSH untuk Stack2
    void push2(int value) {
        if (top2 - 1 == top1) {
            cout << "?? Stack Penuh! Tidak bisa push ke Stack2.\n";
        } else {
            data[--top2] = value;
            cout << "? Data " << value << " berhasil ditambahkan ke Stack2.\n";
        }
    }

    // POP dari Stack1
    void pop1() {
        if (top1 == -1) {
            cout << "?? Stack1 Kosong! Tidak bisa pop.\n";
        } else {
            cout << "??? Data " << data[top1--] << " dihapus dari Stack1.\n";
        }
    }

    // POP dari Stack2
    void pop2() {
        if (top2 == MAX) {
            cout << "?? Stack2 Kosong! Tidak bisa pop.\n";
        } else {
            cout << "??? Data " << data[top2++] << " dihapus dari Stack2.\n";
        }
    }

    // Cek kondisi stack
    void kondisi() {
        cout << "\n=== Kondisi Stack ===\n";
        if (top1 + 1 == top2)
            cout << "?? Stack Penuh (Stack1 dan Stack2 sudah bertemu)\n";
        else if (top1 == -1 && top2 == MAX)
            cout << "?? Kedua Stack Kosong\n";
        else
            cout << "?? Stack masih bisa diisi\n";
        cout << "--------------------------\n";
    }
};

int main() {
    DoubleStack ds;
    int pilih, nilai;

    do {
        cout << "\n=== MENU DOUBLE STACK ===\n";
        cout << "1. PUSH ke Stack1\n";
        cout << "2. PUSH ke Stack2\n";
        cout << "3. POP dari Stack1\n";
        cout << "4. POP dari Stack2\n";
        cout << "5. Tampilkan kondisi Stack\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nilai untuk Stack1: ";
                cin >> nilai;
                ds.push1(nilai);
                break;
            case 2:
                cout << "Masukkan nilai untuk Stack2: ";
                cin >> nilai;
                ds.push2(nilai);
                break;
            case 3:
                ds.pop1();
                break;
            case 4:
                ds.pop2();
                break;
            case 5:
                ds.kondisi();
                break;
            case 6:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 6);

    return 0;
}

