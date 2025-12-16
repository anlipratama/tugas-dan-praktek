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

// Cek apakah deque penuh
bool isFull() {
    return ((FRONT == 0 && REAR == MAX-1) || (FRONT == REAR + 1));
}

// Insert dari kanan (Rear)
void insertRight() {
    if (isFull()) {
        cout << "?? Deque penuh! Tidak bisa menambahkan record.\n";
        return;
    }

    Record temp;
    cout << "Masukkan ID: ";
    cin >> temp.id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, temp.nama);

    if (isEmpty()) {
        FRONT = REAR = 0;
    } else if (REAR == MAX-1 && FRONT != 0) {
        REAR = 0;
    } else {
        REAR++;
    }

    DEQUE[REAR] = temp;
    cout << "? Record berhasil ditambahkan di kanan.\n";
}

// Insert dari kiri (Front)
void insertLeft() {
    if (isFull()) {
        cout << "?? Deque penuh! Tidak bisa menambahkan record.\n";
        return;
    }

    Record temp;
    cout << "Masukkan ID: ";
    cin >> temp.id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, temp.nama);

    if (isEmpty()) {
        FRONT = REAR = 0;
    } else if (FRONT == 0 && REAR != MAX-1) {
        FRONT = MAX - 1;
    } else {
        FRONT--;
    }

    DEQUE[FRONT] = temp;
    cout << "? Record berhasil ditambahkan di kiri.\n";
}

// Delete dari kanan (Rear)
void deleteRight() {
    if (isEmpty()) {
        cout << "?? Deque kosong! Tidak ada record untuk dihapus.\n";
        return;
    }

    Record temp = DEQUE[REAR];
    cout << "??? Record dihapus dari kanan: ID=" << temp.id
         << ", Nama=" << temp.nama << endl;

    if (FRONT == REAR) {
        FRONT = REAR = -1;
    } else if (REAR == 0) {
        REAR = MAX - 1;
    } else {
        REAR--;
    }
}

// Delete dari kiri (Front)
void deleteLeft() {
    if (isEmpty()) {
        cout << "?? Deque kosong! Tidak ada record untuk dihapus.\n";
        return;
    }

    Record temp = DEQUE[FRONT];
    cout << "??? Record dihapus dari kiri: ID=" << temp.id
         << ", Nama=" << temp.nama << endl;

    if (FRONT == REAR) {
        FRONT = REAR = -1;
    } else if (FRONT == MAX - 1) {
        FRONT = 0;
    } else {
        FRONT++;
    }
}

// Tampilkan isi deque
void tampilkanDeque() {
    if (isEmpty()) {
        cout << "Deque kosong.\n";
        return;
    }

    cout << "\n=== Isi Deque ===\n";
    int i = FRONT;
    int idx = 1;
    while (true) {
        cout << idx << ". ID=" << DEQUE[i].id << ", Nama=" << DEQUE[i].nama << endl;
        if (i == REAR) break;
        i = (i + 1) % MAX;
        idx++;
    }
    cout << "----------------------\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n===== MENU DEQUE =====\n";
        cout << "1. Insert dari Kanan (Rear)\n";
        cout << "2. Insert dari Kiri (Front)\n";
        cout << "3. Delete dari Kanan (Rear)\n";
        cout << "4. Delete dari Kiri (Front)\n";
        cout << "5. Tampilkan Deque\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: insertRight(); break;
            case 2: insertLeft(); break;
            case 3: deleteRight(); break;
            case 4: deleteLeft(); break;
            case 5: tampilkanDeque(); break;
            case 6: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}

