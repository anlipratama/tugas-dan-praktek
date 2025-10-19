#include <iostream>
using namespace std;

#define MAX 5  // kapasitas queue

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

// Inisialisasi / Reset queue
void resetQueue() {
    FRONT = -1;
    REAR = -1;
    cout << "?? Queue berhasil di-reset.\n";
}

// Insert record ke queue
void enqueue() {
    if (isFull()) {
        cout << "?? Queue Penuh, tidak bisa menambahkan data.\n";
        return;
    }

    Record temp;
    cout << "Masukkan ID: ";
    cin >> temp.id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, temp.nama);

    if (isEmpty()) FRONT = 0;

    REAR++;
    QUEUE[REAR] = temp;
    cout << "? Record berhasil ditambahkan ke queue.\n";
}

// Delete record dari queue
void dequeue() {
    if (isEmpty()) {
        cout << "?? Queue Kosong, tidak ada data untuk dihapus.\n";
        return;
    }

    Record temp = QUEUE[FRONT];
    cout << "??? Record yang dihapus: ID=" << temp.id
         << ", Nama=" << temp.nama << endl;

    FRONT++;

    // Jika semua elemen telah dihapus, reset queue
    if (FRONT > REAR) {
        FRONT = -1;
        REAR = -1;
    }
}

// Tampilkan kondisi queue
void tampilkanQueue() {
    cout << "\n=== Kondisi Queue ===\n";
    if (isEmpty()) {
        cout << "Queue Kosong (tidak ada isinya)\n";
    } else if (isFull() && FRONT == 0) {
        cout << "Queue Penuh tapi belum ada elemen yang dihapus\n";
    } else if (isFull()) {
        cout << "Queue Penuh (tidak bisa diisi)\n";
    } else {
        cout << "Queue Bisa diisi dan ada isinya\n";
    }

    if (!isEmpty()) {
        cout << "Isi Queue:\n";
        for (int i = FRONT; i <= REAR; i++) {
            cout << "ID=" << QUEUE[i].id << ", Nama=" << QUEUE[i].nama << endl;
        }
    }
    cout << "-----------------------------\n";
}

int main() {
    int pilihan;

    do {
        cout << "\n===== MENU LINEAR QUEUE =====\n";
        cout << "1. Enqueue (Insert Record)\n";
        cout << "2. Dequeue (Delete Record)\n";
        cout << "3. Tampilkan Queue dan Kondisi\n";
        cout << "4. Reset Queue\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: tampilkanQueue(); break;
            case 4: resetQueue(); break;
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}

