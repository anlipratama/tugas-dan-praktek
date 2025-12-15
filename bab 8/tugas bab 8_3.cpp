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

// Cek apakah penuh kanan
bool fullRight() {
    return (REAR == MAX - 1);
}

// Insert record dari kanan
void insertRight() {
    int i = 1;
    while (!fullRight()) {
        Record temp;
        cout << "\nMasukkan ID record ke-" << i << ": ";
        cin >> temp.id;
        cin.ignore();
        cout << "Masukkan Nama record ke-" << i << ": ";
        getline(cin, temp.nama);

        if (isEmpty()) {
            FRONT = REAR = 0;
        } else {
            REAR++;
        }

        DEQUE[REAR] = temp;
        cout << "? Record ke-" << i << " berhasil ditambahkan dari kanan.\n";
        i++;
    }
    cout << "\n?? Penuh kanan, tidak bisa menambahkan record lagi dari kanan.\n";
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

int main() {
    cout << "===== Program Insert Deque dari Kanan (Rear) =====\n";
    insertRight();
    tampilkanDeque();
    return 0;
}

