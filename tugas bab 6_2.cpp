#include <iostream>
using namespace std;

#define MAX 10

struct Record {
    int id;
    string nama;
};

int main() {
    Record QUEUE[MAX];
    int FRONT = 0, REAR = 4; // Misal antrian awal sudah ada 5 record
    // Contoh data awal
    for (int i = FRONT; i <= REAR; i++) {
        QUEUE[i].id = i+1;
        QUEUE[i].nama = "Nama" + to_string(i+1);
    }

    int DELETE_COUNT = 0;

    cout << "=== Menghapus Antrian Record ===\n";

    while (DELETE_COUNT < 10 && FRONT <= REAR) {
        // Ambil record di FRONT
        Record temp = QUEUE[FRONT];
        cout << "Record yang dihapus: ID=" << temp.id 
             << ", Nama=" << temp.nama << endl;

        FRONT++; // Geser FRONT
        DELETE_COUNT++;
    }

    // Jika antrian sudah kosong
    if (FRONT > REAR) {
        FRONT = -1;
        REAR = -1;
        cout << "Antrian sudah kosong.\n";
    }

    cout << "Jumlah record yang dihapus: " << DELETE_COUNT << endl;

    return 0;
}

