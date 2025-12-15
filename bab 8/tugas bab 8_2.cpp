#include <iostream>
using namespace std;

#define MAX 15  // kapasitas maksimum deque

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

// Cek apakah deque penuh total
bool isFull() {
    return ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1));
}

// Cek penuh kanan
bool fullRight() {
    return (REAR == MAX - 1);
}

// Cek penuh kiri
bool fullLeft() {
    return (FRONT == 0);
}

// Menampilkan kondisi deque
void tampilStatus() {
    cout << "\n===== STATUS DEQUE =====\n";
    if (isEmpty()) cout << "Deque kosong (tidak ada isinya)\n";
    else {
        cout << "Deque ada isinya\n";
        cout << "FRONT = " << FRONT << ", REAR = " << REAR << endl;
        if (fullRight()) cout << "Penuh kanan (tidak bisa diisi dari kanan)\n";
        if (fullLeft()) cout << "Penuh kiri (tidak bisa diisi dari kiri)\n";
        if (isFull()) cout << "Deque penuh total (tidak bisa diisi dari kiri maupun kanan)\n";
        int jumlahElemen;
        if (REAR >= FRONT) jumlahElemen = REAR - FRONT + 1;
        else jumlahElemen = MAX - FRONT + REAR + 1;
        cout << "Jumlah elemen saat ini: " << jumlahElemen << endl;
    }
    cout << "========================\n";
}

// Insert dari kanan
void insertRight(Record temp) {
    if (isFull()) {
        cout << "?? Tidak bisa menambahkan record, deque penuh total!\n";
        return;
    }
    if (isEmpty()) FRONT = REAR = 0;
    else if (REAR == MAX - 1 && FRONT != 0) REAR = 0;
    else REAR++;
    DEQUE[REAR] = temp;
}

// Insert dari kiri
void insertLeft(Record temp) {
    if (isFull()) {
        cout << "?? Tidak bisa menambahkan record, deque penuh total!\n";
        return;
    }
    if (isEmpty()) FRONT = REAR = 0;
    else if (FRONT == 0 && REAR != MAX - 1) FRONT = MAX - 1;
    else FRONT--;
    DEQUE[FRONT] = temp;
}

// Delete dari kanan
void deleteRight() {
    if (isEmpty()) {
        cout << "?? Deque kosong, tidak ada record untuk dihapus.\n";
        return;
    }
    Record temp = DEQUE[REAR];
    cout << "??? Record dihapus dari kanan: ID=" << temp.id << ", Nama=" << temp.nama << endl;
    if (FRONT == REAR) FRONT = REAR = -1;
    else if (REAR == 0) REAR = MAX - 1;
    else REAR--;
}

// Delete dari kiri
void deleteLeft() {
    if (isEmpty()) {
        cout << "?? Deque kosong, tidak ada record untuk dihapus.\n";
        return;
    }
    Record temp = DEQUE[FRONT];
    cout << "??? Record dihapus dari kiri: ID=" << temp.id << ", Nama=" << temp.nama << endl;
    if (FRONT == REAR) FRONT = REAR = -1;
    else if (FRONT == MAX - 1) FRONT = 0;
    else FRONT++;
}

// Tampilkan seluruh deque
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
    cout << "================\n";
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
        cout << "6. Tampilkan Status Deque\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu (1-7): ";
        cin >> pilihan;
        cin.ignore();

        Record temp;
        switch (pilihan) {
            case 1:
                cout << "Masukkan ID: "; cin >> temp.id; cin.ignore();
                cout << "Masukkan Nama: "; getline(cin, temp.nama);
                insertRight(temp);
                break;
            case 2:
                cout << "Masukkan ID: "; cin >> temp.id; cin.ignore();
                cout << "Masukkan Nama: "; getline(cin, temp.nama);
                insertLeft(temp);
                break;
            case 3: deleteRight(); break;
            case 4: deleteLeft(); break;
            case 5: tampilkanDeque(); break;
            case 6: tampilStatus(); break;
            case 7: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);

    return 0;
}

