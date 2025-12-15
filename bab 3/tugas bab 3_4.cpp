#include <iostream>
using namespace std;

// Struktur Buku
struct Buku {
    int no_akses;
    string penulis;
    string judul;
    bool diterbitkan;
};

// Fungsi untuk menambahkan buku
void tambahBuku(Buku perpustakaan[], int &jumlah) {
    cout << "\nMasukkan data buku ke-" << jumlah + 1 << ":\n";
    perpustakaan[jumlah].no_akses = jumlah + 1;

    cin.ignore();
    cout << "Nama Penulis: ";
    getline(cin, perpustakaan[jumlah].penulis);

    cout << "Judul Buku: ";
    getline(cin, perpustakaan[jumlah].judul);

    char status;
    cout << "Apakah buku diterbitkan? (y/n): ";
    cin >> status;
    perpustakaan[jumlah].diterbitkan = (status == 'y' || status == 'Y');

    jumlah++;
}

// Fungsi untuk menampilkan semua buku
void tampilBuku(Buku perpustakaan[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada buku di perpustakaan.\n";
        return;
    }

    cout << "\nDaftar Buku di Perpustakaan:\n";
    cout << "No\tPenulis\t\tJudul\t\tStatus\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < jumlah; i++) {
        cout << perpustakaan[i].no_akses << "\t"
             << perpustakaan[i].penulis << "\t\t"
             << perpustakaan[i].judul << "\t\t"
             << (perpustakaan[i].diterbitkan ? "Diterbitkan" : "Belum Diterbitkan") << endl;
    }
}

int main() {
    const int MAX_BUKU = 100;
    Buku perpustakaan[MAX_BUKU];
    int jumlahBuku = 0;

    int pilihan;

    do {
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Semua Buku\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                if (jumlahBuku < MAX_BUKU)
                    tambahBuku(perpustakaan, jumlahBuku);
                else
                    cout << "Perpustakaan sudah penuh!\n";
                break;
            case 2:
                tampilBuku(perpustakaan, jumlahBuku);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 3);

    return 0;
}

