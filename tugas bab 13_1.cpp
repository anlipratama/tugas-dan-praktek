#include <iostream>
#include <iomanip>
#include <string>
#include <thread>    
#include <chrono>      
#include <limits>      
using namespace std;


struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* prev;
    Mahasiswa* next;
};


Mahasiswa* head = nullptr;
Mahasiswa* tail = nullptr;


void waitForKey() {
    cout << "\nTekan Enter untuk melanjutkan...";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

Mahasiswa* buatNode(const string& nama, const string& nim, const string& gender, float nilai) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->gender = gender;
    baru->nilai = nilai;
    baru->prev = nullptr;
    baru->next = nullptr;
    return baru;
}

void insertData() {
    string nama, nim, gender;
    float nilai;

    cout << "\n=== INPUT DATA MAHASISWA ===\n";
    cout << "NIM     : "; 
    cin >> nim;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nama    : "; getline(cin, nama);
    cout << "Gender  : "; getline(cin, gender);
    cout << "Nilai   : "; cin >> nilai;

    Mahasiswa* baru = buatNode(nama, nim, gender, nilai);

    if (head == nullptr) {
        head = tail = baru;
    }
    else if (nim < head->nim) {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    else if (nim > tail->nim) {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    else {
        Mahasiswa* bantu = head;
        while (bantu != nullptr && bantu->nim < nim)
            bantu = bantu->next;

        if (bantu != nullptr) {
            baru->prev = bantu->prev;
            baru->next = bantu;
            if (bantu->prev) bantu->prev->next = baru;
            bantu->prev = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    cout << "\n>>> Data berhasil ditambahkan!\n";
    waitForKey();
}

void hapusData() {
    if (head == nullptr) {
        cout << "\n>>> Linked List masih kosong!\n";
        waitForKey();
        return;
    }

    string nim;
    cout << "\nMasukkan NIM yang akan dihapus: ";
    cin >> nim;

    Mahasiswa* bantu = head;
    while (bantu != nullptr && bantu->nim != nim)
        bantu = bantu->next;

    if (bantu == nullptr) {
        cout << "\n>>> Data dengan NIM " << nim << " tidak ditemukan!\n";
        waitForKey();
        return;
    }


    if (bantu == head && bantu == tail) {
        head = tail = nullptr;
    }

    else if (bantu == head) {
        head = head->next;
        if (head) head->prev = nullptr;
    }

    else if (bantu == tail) {
        tail = tail->prev;
        if (tail) tail->next = nullptr;
    }

    else {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
    }

    delete bantu;
    cout << "\n>>> Data berhasil dihapus!\n";
    waitForKey();
}

void cetakData() {
    if (head == nullptr) {
        cout << "\n>>> Data masih kosong!\n";
        waitForKey();
        return;
    }

    Mahasiswa* bantu = head;
    cout << "\n=== DAFTAR DATA MAHASISWA ===\n";
    cout << left << setw(15) << "NIM"
         << setw(30) << "Nama"
         << setw(10) << "Gender"
         << setw(10) << "Nilai" << endl;
    cout << "--------------------------------------------------------------\n";

    while (bantu != nullptr) {
        cout << left << setw(15) << bantu->nim
             << setw(30) << bantu->nama
             << setw(10) << bantu->gender
             << setw(10) << bantu->nilai << endl;
        bantu = bantu->next;
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // jeda 300 ms
    }
    waitForKey();
}

int main() {
    int pilihan;

    do {


        cout << " DOUBLY LINKED LIST\n";
        cout << "==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1 – 4): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            insertData();
            break;
        case 2:
            hapusData();
            break;
        case 3:
            cetakData();
            break;
        case 4:
            cout << "\nTerima kasih! Program selesai.\n";
            break;
        default:
            cout << "\nPilihan tidak valid!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            waitForKey();
        }

    } while (pilihan != 4);

    while (head) {
        Mahasiswa* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;

    return 0;
}

