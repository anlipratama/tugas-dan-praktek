#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;

void animasi(string teks) {
    for (char c : teks) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << endl;
}

void insertData() {
    Mahasiswa* baru = new Mahasiswa;
    cout << "Nama   : "; getline(cin, baru->nama);
    cout << "NIM    : "; getline(cin, baru->nim);
    cout << "Gender : "; getline(cin, baru->gender);
    cout << "Nilai  : "; cin >> baru->nilai; cin.ignore();

    if (head == nullptr) {
        head = baru;
        baru->next = head;
    } else if (baru->nim < head->nim) {
        Mahasiswa* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = baru;
        baru->next = head;
        head = baru;
    } else {
        Mahasiswa* curr = head;
        while (curr->next != head && curr->next->nim < baru->nim)
            curr = curr->next;
        baru->next = curr->next;
        curr->next = baru;
    }
    animasi("Data berhasil ditambahkan...");
}

void hapusData() {
    if (head == nullptr) {
        animasi("Linked list kosong");
        return;
    }
    string cari;
    cout << "Masukkan NIM yang dihapus: "; getline(cin, cari);

    Mahasiswa* curr = head;
    Mahasiswa* prev = nullptr;
    do {
        if (curr->nim == cari) break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr->nim != cari) {
        animasi("Data tidak ditemukan");
        return;
    }

    if (curr == head && curr->next == head) {
        delete head;
        head = nullptr;
    } else if (curr == head) {
        Mahasiswa* temp = head;
        while (temp->next != head) temp = temp->next;
        head = head->next;
        temp->next = head;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
    animasi("Data berhasil dihapus...");
}

void cetakData() {
    if (head == nullptr) {
        animasi("Linked list kosong");
        return;
    }
    Mahasiswa* temp = head;
    cout << "\nData Mahasiswa (Circular):\n";
    do {
        cout << "----------------------------------\n";
        cout << "Nama   : " << temp->nama << endl;
        cout << "NIM    : " << temp->nim << endl;
        cout << "Gender : " << temp->gender << endl;
        cout << "Nilai  : " << temp->nilai << endl;
        temp = temp->next;
        this_thread::sleep_for(chrono::milliseconds(300));
    } while (temp != head);
    cout << "----------------------------------\n";
}

int main() {
    int pilih;
    do {
        cout << "\nCIRCULAR LINKED LIST\n";
        cout << "==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1-4): ";
        cin >> pilih; cin.ignore();

        switch (pilih) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: animasi("Program selesai..."); break;
            default: animasi("Pilihan tidak valid");
        }
    } while (pilih != 4);
    return 0;
}


