#include <iostream>
using namespace std;

#define MAX 12  // kapasitas deque

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

// Cek penuh kanan
bool fullRight() {
    return (REAR == MAX - 1);
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

// Insert dari kanan sampai 10 record atau penuh kanan
void insertRight10() {
    int i = 1;
    while (i <= 10 && !fullRight()) {
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

    if (fullRight()) {
        cout << "\n?? Penuh kanan, proses pengisian dihentikan sebelum 10 record.\n";
    }

    cout << "\n? Proses pengisian selesai.\n";
    tampilkanDeque();
}

int main() {
    cout << "===== Program Insert 10 Record dari Kanan (Rear) =====\n";
    insertRight10();
    return 0;
}

