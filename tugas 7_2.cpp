#include <iostream>
using namespace std;

#define MAX 10  // kapasitas queue

struct Record {
    int id;
    string nama;
};

Record QUEUE[MAX];
int FRONT = -1;
int REAR = -1;

// Cek apakah queue kosong
bool isEmpty() {
    return (FRONT == -1);
}

// Cek apakah queue penuh
bool isFull() {
    return (REAR == MAX - 1);
}

// Insert (Enqueue)
void insertRecord() {
    if (isFull()) {
        cout << "?? Queue Penuh! Tidak bisa menambahkan record.\n";
        return;
    }

    Record temp;
    cout << "Masukkan ID: ";
    cin >> temp.id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, temp.nama);

    if (isEmpty()) FRONT = 0; // jika queue kosong, atur FRONT

    REAR++;
    QUEUE[REAR] = temp;

    cout << "? Record berhasil ditambahkan.\n";
}

// Delete (Dequeue)
void deleteRecord() {
    if (isEmpty()) {
        cout << "?? Queue Kosong! Tidak ada record untuk dihapus.\n";
        return;
    }

    Record temp = QUEUE[FRONT];
    cout << "??? Record yang dihapus: ID=" << temp.id
         << ", Nama=" << temp.nama << endl;

    FRONT++;

    // Reset jika queue kosong setelah delete
    if (FRONT > REAR) {
        FRONT = -1;
        REAR = -1;
    }
}

// Tampilkan isi queue
void tampilkanQueue() {
    if (isEmpty()) {
        cout << "Queue Kosong.\n";
        return;
    }

    cout << "\n=== Isi Queue ===\n";
    for (int i = FRONT; i <= REAR; i++) {
        cout << "Record " << i - FRONT + 1 << ": ID=" << QUEUE[i].id
             << ", Nama=" << QUEUE[i].nama << endl;
    }
    cout << "---------------------\n";
}

// Reset queue
void resetQueue() {
    FRONT = -1;
    REAR = -1;
    cout << "?? Queue berhasil di-reset.\n";
}

int main() {
    int pilihan;

    do {
        cout << "\n===== MENU LINEAR QUEUE =====\n";
        cout << "1. Insert Record (Enqueue)\n";
        cout << "2. Delete Record (Dequeue)\n";
        cout << "3. Tampilkan Queue\n";
        cout << "4. Reset Queue\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: insertRecord(); break;
            case 2: deleteRecord(); break;
            case 3: tampilkanQueue(); break;
            case 4: resetQueue(); break;
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}

