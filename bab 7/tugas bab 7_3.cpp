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

// Cek apakah queue penuh
bool isFull() {
    return (REAR == MAX - 1);
}

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

// Fungsi untuk mengisi 10 record
void isiQueue() {
    int i = 1;
    while (i <= 10) {
        if (isFull()) {
            cout << "?? Antrian penuh, proses pengisian dihentikan.\n";
            break;
        }

        Record temp;
        cout << "Masukkan ID record ke-" << i << ": ";
        cin >> temp.id;
        cin.ignore();
        cout << "Masukkan Nama record ke-" << i << ": ";
        getline(cin, temp.nama);

        if (isEmpty()) FRONT = 0;

        REAR++;
        QUEUE[REAR] = temp;
        COUNT++;

        cout << "? Record ke-" << i << " berhasil ditambahkan.\n";
        i++;
    }
    cout << "Proses pengisian antrian selesai.\n";
}

int main() {
    cout << "===== Program Pengisian Antrian (Linear Queue) =====\n";
    isiQueue();
    tampilkanQueue();

    return 0;
}

