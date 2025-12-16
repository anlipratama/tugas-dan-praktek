#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NIM;
    string NAMA;
    float NILAI;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;

Mahasiswa* buatNode(string nim, string nama, float nilai) {
    Mahasiswa* baru = new Mahasiswa;
    baru->NIM = nim;
    baru->NAMA = nama;
    baru->NILAI = nilai;
    baru->next = nullptr;
    return baru;
}

void tambahData(string nim, string nama, float nilai) {
    Mahasiswa* baru = buatNode(nim, nama, nilai);

    if (head == nullptr || nilai < head->NILAI) {
        baru->next = head;
        head = baru;
    } else {
        Mahasiswa* bantu = head;
        while (bantu->next != nullptr && bantu->next->NILAI < nilai) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
    cout << "Data berhasil ditambahkan!\n";
}

void tampilNilai90() {
    Mahasiswa* bantu = head;
    bool ketemu = false;

    cout << "\nData Mahasiswa dengan NILAI = 90:\n";
    while (bantu != nullptr) {
        if (bantu->NILAI >= 90) {
            cout << "NIM   : " << bantu->NIM << endl;
            cout << "NAMA  : " << bantu->NAMA << endl;
            cout << "NILAI : " << bantu->NILAI << endl;
            cout << "-------------------------\n";
            ketemu = true;
        }
        bantu = bantu->next;
    }

    if (!ketemu)
        cout << "Tidak ada mahasiswa dengan nilai = 90.\n";
}


void tampilSemua() {
    if (head == nullptr) {
        cout << "Data kosong.\n";
        return;
    }

    cout << "\n=== Daftar Seluruh Data Mahasiswa ===\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        cout << "NIM   : " << bantu->NIM << endl;
        cout << "NAMA  : " << bantu->NAMA << endl;
        cout << "NILAI : " << bantu->NILAI << endl;
        cout << "-------------------------\n";
        bantu = bantu->next;
    }
}

void hapusData(string nim) {
    if (head == nullptr) {
        cout << "Data kosong.\n";
        return;
    }

    Mahasiswa* hapus;
    if (head->NIM == nim) {
        hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data dengan NIM " << nim << " telah dihapus.\n";
        return;
    }

    Mahasiswa* bantu = head;
    while (bantu->next != nullptr && bantu->next->NIM != nim) {
        bantu = bantu->next;
    }

    if (bantu->next == nullptr) {
        cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
    } else {
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
        cout << "Data dengan NIM " << nim << " telah dihapus.\n";
    }
}

void hitungRataRata() {
    if (head == nullptr) {
        cout << "Data kosong.\n";
        return;
    }

    int jumlah = 0;
    float total = 0;
    Mahasiswa* bantu = head;

    while (bantu != nullptr) {
        total += bantu->NILAI;
        jumlah++;
        bantu = bantu->next;
    }

    cout << "\nRata-rata nilai kelas: " << total / jumlah << endl;
}

int main() {
    int pilihan;
    string nim, nama;
    float nilai;

    do {
        cout << "\n===== MENU LINKED LIST MAHASISWA =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data dengan Nilai = 90\n";
        cout << "3. Tampilkan Semua Data\n";
        cout << "4. Hapus Data (NIM = 2007140022)\n";
        cout << "5. Hitung Rata-rata Nilai Kelas\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM   : "; cin >> nim;
                cout << "Masukkan NAMA  : "; cin.ignore(); getline(cin, nama);
                cout << "Masukkan NILAI : "; cin >> nilai;
                tambahData(nim, nama, nilai);
                break;
            case 2:
                tampilNilai90();
                break;
            case 3:
                tampilSemua();
                break;
            case 4:
                hapusData("2007140022");
                break;
            case 5:
                hitungRataRata();
                break;
            case 6:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}

