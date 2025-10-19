#include <iostream>
using namespace std;

#define MAX 20  // kapasitas queue

struct Record {
    int id;
    string nama;
};

Record CQUEUE[MAX];
int FRONT = -1;
int REAR = -1;

// Cek apakah circular queue kosong
bool isEmpty() {
    return (FRONT == -1);
}

// Cek apakah circular queue penuh
bool isFull() {
    return ((REAR + 1) % MAX == FRONT);
}

// Hitung jumlah elemen
int countElements() {
    if (isEmpty()) return 0;
    if (REAR >= FRONT) return REAR - FRONT + 1;
    return MAX - FRONT + REAR + 1;
}

// Sisa kapasitas
int remainingSpace() {
    return MAX - countElements();
}

// Enqueue
void enqueue() {
    if (isFull()) {
        cout << "?? Circular Queue Penuh! Tidak bisa menambahkan record.\n";
        return;
    }

    Record temp;
    cout << "Masukkan ID: ";
    cin >> temp.id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, temp.nama);

    if (isEmpty()) FRONT = 0;

    REAR = (REAR + 1) % MAX;
    CQUEUE[REAR] = temp;

    cout << "? Record berhasil ditambahkan.\n";
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "?? Circular Queue Kosong! Tidak ada data untuk dihapus.\n";
        return;
    }

    Record temp = CQUEUE[FRONT];
    cout << "??? Record yang dihapus: ID=" << temp.id
         << ", Nama=" << temp.nama << endl;

    if (FRONT == REAR) { // satu elemen terakhir
        FRONT = -1;
        REAR = -1;
    } else {
        FRONT = (FRONT + 1) % MAX;
    }
}

// Tampilkan kondisi queue
void tampilkanQueue() {
    cout << "\n=== Kondisi Circular Queue ===\n";
    if (isEmpty()) cout << "Queue Kosong (tidak ada isinya)\n";
    else if (isFull()) cout << "Queue Penuh (tidak bisa diisi)\n";
    else cout << "Queue Bisa diisi dan ada isinya\n";

    int n = countElements();
    cout << "Jumlah record: " << n << endl;
    cout << "Sisa kapasitas: " << remainingSpace() << endl;

    if (!isEmpty()) {
        cout << "Isi Queue:\n";
        int i = FRONT;
        int idx = 1;
        while (true) {
            cout << idx << ". ID=" << CQUEUE[i].id << ", Nama=" << CQUEUE[i].nama << endl;
            if (i == REAR) break;
            i = (i + 1) % MAX;
            idx++;
        }
    }
    cout << "---------------------------\n";
}

// Reset queue
void resetQueue() {
    FRONT = -1;
    REAR = -1;
    cout << "?? Circular Queue berhasil di-reset.\n";
}

int main() {
    int pilihan;

    do {
        cout << "\n===== MENU CIRCULAR QUEUE =====\n";
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

