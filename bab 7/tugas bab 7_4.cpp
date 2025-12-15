#include <iostream>
using namespace std;

#define MAX 15  // kapasitas maksimum queue

struct Record {
    int id;
    string nama;
};

Record QUEUE[MAX];
int FRONT = -1;
int REAR = -1;
int COUNT = 0;

// Cek apakah queue kosong
bool isEmpty() {
    return (FRONT == -1);
}

// Fungsi untuk menampilkan isi queue
void tampilkanQueue() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "\n=== Isi Antrian ===\n";
    for (int i = FRONT; i <= REAR; i++) {
        cout << "Record " << i - FRONT + 1
             << ": ID=" << QUEUE[i].id
             << ", Nama=" << QUEUE[i].nama << endl;
    }
    cout << "---------------------------\n";
}

// Fungsi untuk menghapus 10 record
void hapusQueue() {
    int i = 1;
    while (i <= 10) {
        if (isEmpty()) {
            cout << "?? Antrian kosong, proses delete dihentikan.\n";
            break;
        }

        Record temp = QUEUE[FRONT];
        cout << "??? Record yang dihapus: ID=" << temp.id
             << ", Nama=" << temp.nama << endl;

        FRONT++;
        COUNT--;

        // Reset queue jika kosong setelah delete
        if (FRONT > REAR) {
            FRONT = -1;
            REAR = -1;
        }

        i++;
    }
    cout << "Proses penghapusan antrian selesai.\n";
}

int main() {
    // Contoh pengisian awal queue
    REAR = 4; FRONT = 0; COUNT = 5;
    for (int i = 0; i <= 4; i++) {
        QUEUE[i].id = i + 1;
        QUEUE[i].nama = "Mahasiswa_" + to_string(i + 1);
    }

    cout << "===== Program Delete Antrian 10 Record =====\n";
    tampilkanQueue();

    hapusQueue();

    tampilkanQueue();

    return 0;
}

