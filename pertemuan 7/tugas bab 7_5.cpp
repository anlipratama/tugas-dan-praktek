#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int F, R;
    int pilihan;

    cout << "Pilih jenis Queue:\n";
    cout << "1. Linear Queue\n";
    cout << "2. Circular Queue\n";
    cout << "Pilihan (1/2): ";
    cin >> pilihan;

    cout << "Masukkan FRONT (F): ";
    cin >> F;
    cout << "Masukkan REAR (R): ";
    cin >> R;

    if (F == -1) {
        cout << "Queue kosong. Jumlah elemen = 0\n";
    } else {
        int jumlahElemen;

        if (pilihan == 1) { // Linear Queue
            jumlahElemen = R - F + 1;
            cout << "Jenis Queue: Linear Queue\n";
        } else if (pilihan == 2) { // Circular Queue
            if (R >= F) {
                jumlahElemen = R - F + 1;
            } else { // R < F
                jumlahElemen = MAX - F + R + 1;
            }
            cout << "Jenis Queue: Circular Queue\n";
        } else {
            cout << "Pilihan tidak valid!\n";
            return 0;
        }

        cout << "Jumlah elemen yang ada isinya = " << jumlahElemen << endl;
    }

    return 0;
}

