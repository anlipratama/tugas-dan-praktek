#include <iostream>
using namespace std;

#define MAX 10  // kapasitas deque

struct Record {
    int id;
    string nama;
};

Record DEQUE[MAX];
int FRONT = -1;
int REAR = -1;

// Cek apakah deque kosong
bool isEmpty() {
    return (FRONT == -1);
}

// Insert contoh record untuk simulasi
void insertContoh() {
    FRONT = 0;
    REAR = 4; // misal awal ada 5 record
    for (int i = FRONT; i <= REAR; i++) {
        DEQUE[i].id = i + 1;
        DEQUE[i].nama = "Mahasiswa_" + to_string(i + 1);
    }
}

// Tampilkan isi deque
void tampilkanDeque() {
    if (isEmpty()) {
        cout << "Deque kosong.\n";
        return;
    }
    cout << "\n=== Isi Deque ===\n";
    for (int i = FRONT; i <= REAR; i++) {
        cout << "Record " << i - FRONT + 1
             << ": ID=" << DEQUE[i].id
             << ", Nama=" << DEQUE[i].nama << endl;
    }
    cout << "================\n";
}

// Hapus semua record dari kanan
void deleteFromRight() {
    if (isEmpty()) {
        cout << "?? Deque kosong, tidak ada record untuk dihapus.\n";
        return;
    }

    cout << "\n??? Menghapus record dari kanan satu per satu...\n";
    while (!isEmpty()) {
        Record temp = DEQUE[REAR];
        cout << "Record dihapus: ID=" << temp.id
             << ", Nama=" << temp.nama << endl;

        if (FRONT == REAR) { // hanya satu elemen tersisa
            FRONT = REAR = -1; // deque kosong
        } else {
            REAR--; // geser REAR ke kiri
        }
    }
    cout << "? Semua record berhasil dihapus, deque kosong.\n";
}

int main() {
    cout << "===== Simulasi Delete Semua dari Kanan (Rear) =====\n";

    // Masukkan data awal untuk simulasi
    insertContoh();
    tampilkanDeque();

    // Hapus semua record dari kanan
    deleteFromRight();

    tampilkanDeque();

    return 0;
}

