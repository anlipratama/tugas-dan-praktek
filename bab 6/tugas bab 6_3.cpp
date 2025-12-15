#include <iostream>
using namespace std;

#define MAX 10

// Struktur Record
struct Record {
    int id;
    string nama;
};

// Variabel antrian
Record QUEUE[MAX];
int FRONT = -1;
int REAR = -1;
int COUNT = 0;

// Fungsi Inisialisasi
void inisialisasi() {
    FRONT = -1;
    REAR = -1;
    COUNT = 0;
    cout << "? Antrian berhasil diinisialisasi.\n";
}

// Fungsi Insert (Enqueue)
void insertRecord() {
    if (REAR == MAX - 1) {
        cout << "?? Antrian Penuh! Tidak bisa menambahkan record.\n";
        return;
    }

    Record temp;
    cout << "Masukkan ID: ";
    cin >> temp.id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, temp.nama);

    if (FRONT == -1) FRONT = 0; // jika antrian kosong
    REAR++;
    QUEUE[REAR] = temp;
    COUNT++;

    cout << "? Record berhasil ditambahkan ke antrian.\n";
}

// Fungsi Delete (Dequeue)
void deleteRecord() {
    if (FRONT == -1 || FRONT > REAR) {
        cout << "?? Antrian Kosong! Tidak ada record untuk dihapus.\n";
        return;
    }

    Record temp = QUEUE[FRONT];
    cout << "??? Record yang dihapus: ID=" << temp.id 
         << ", Nama=" << temp.nama << endl;

    FRONT++;
    COUNT--;

    if (FRONT > REAR) { // reset antrian jika kosong
        FRONT = -1;
        REAR = -1;
    }
}

// Fungsi Reset
void resetQueue() {
    FRONT = -1;
    REAR = -1;
    COUNT = 0;
    cout << "?? Antrian berhasil di-reset.\n";
}

// Fungsi Tampilkan Antrian
void tampilkanQueue() {
    if (FRONT == -1) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "\n=== Isi Antrian ===\n";
    for (int i = FRONT; i <= REAR; i++) {
        cout << "Record " << i - FRONT + 1 << ": ID=" << QUEUE[i].id
             << ", Nama=" << QUEUE[i].nama << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n===== MENU ANTRIAN RECORD =====\n";
        cout << "1. Inisialisasi Antrian\n";
        cout << "2. Insert Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Reset Antrian\n";
        cout << "5. Tampilkan Antrian\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: inisialisasi(); break;
            case 2: insertRecord(); break;
            case 3: deleteRecord(); break;
            case 4: resetQueue(); break;
            case 5: tampilkanQueue(); break;
            case 6: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}

