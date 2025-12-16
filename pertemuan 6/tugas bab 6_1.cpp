#include <iostream>
using namespace std;

#define MAX 10

struct Record {
    int id;
    string nama;
};

int main() {
    Record QUEUE[MAX];
    int FRONT = -1, REAR = -1;
    int COUNT = 0;
    Record temp;

    cout << "=== Pengisian Antrian Record ===\n";

    while (COUNT < MAX) {
        if (REAR == MAX - 1) {
            cout << "?? Antrian penuh, proses pengisian dihentikan.\n";
            break;
        }

        // Input data record
        cout << "\nMasukkan ID record: ";
        cin >> temp.id;
        cout << "Masukkan Nama: ";
        cin.ignore(); // untuk mengabaikan newline
        getline(cin, temp.nama);

        // Update antrian
        if (FRONT == -1) FRONT = 0;
        REAR++;
        QUEUE[REAR] = temp;
        COUNT++;

        cout << "? Record berhasil ditambahkan ke antrian.\n";
    }

    cout << "\n=== Pengisian Antrian Selesai ===\n";
    cout << "Jumlah record di antrian: " << COUNT << endl;

    // Tampilkan semua record
    for (int i = FRONT; i <= REAR; i++) {
        cout << "Record " << i+1 << ": ID=" << QUEUE[i].id 
             << ", Nama=" << QUEUE[i].nama << endl;
    }

    return 0;
}

