#include <iostream>
#include <string>
using namespace std;

// Struktur Buku
struct Buku {
    int no_akses;
    string penulis;
    string judul;
    bool diterbitkan; // true jika diterbitkan
};

// Fungsi menampilkan satu buku
void tampilBuku(Buku b) {
    cout << "No Akses: " << b.no_akses << "\n";
    cout << "Penulis: " << b.penulis << "\n";
    cout << "Judul: " << b.judul << "\n";
    cout << "Status: " << (b.diterbitkan ? "Diterbitkan" : "Belum Diterbitkan") << "\n\n";
}

// Fungsi menampilkan semua buku
void tampilSemuaBuku(Buku perpustakaan[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada buku di perpustakaan.\n";
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        tampilBuku(perpustakaan[i]);
    }
}

// Fungsi menambah buku
void tambahBuku(Buku perpustakaan[], int &jumlah) {
    cin.ignore();
    perpustakaan[jumlah].no_akses = jumlah + 1;
    cout << "Nama Penulis: ";
    getline(cin, perpustakaan[jumlah].penulis);
    cout << "Judul Buku: ";
    getline(cin, perpustakaan[jumlah].judul);
    perpustakaan[jumlah].diterbitkan = false;
    jumlah++;
    cout << "Buku berhasil ditambahkan.\n";
}

// Fungsi menampilkan semua buku dari penulis tertentu
void bukuPenulisTertentu(Buku perpustakaan[], int jumlah, string penulisCari) {
    bool ada = false;
    for (int i = 0; i < jumlah; i++) {
        if (perpustakaan[i].penulis == penulisCari) {
            tampilBuku(perpustakaan[i]);
            ada = true;
        }
    }
    if (!ada) cout << "Tidak ada buku dari penulis tersebut.\n";
}

// Fungsi menghitung jumlah buku dengan judul tertentu
void jumlahBukuJudul(Buku perpustakaan[], int jumlah, string judulCari) {
    int hitung = 0;
    for (int i = 0; i < jumlah; i++) {
        if (perpustakaan[i].judul == judulCari)
            hitung++;
    }
    cout << "Jumlah buku dengan judul \"" << judulCari << "\": " << hitung << "\n";
}

// Fungsi menampilkan jumlah total buku yang belum diterbitkan
void jumlahTotalBuku(Buku perpustakaan[], int jumlah) {
    int hitung = 0;
    for (int i = 0; i < jumlah; i++) {
        if (!perpustakaan[i].diterbitkan)
            hitung++;
    }
    cout << "Jumlah total buku yang tersedia: " << hitung << "\n";
}

// Fungsi menerbitkan buku
void terbitkanBuku(Buku perpustakaan[], int &jumlah, int noAkses) {
    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (perpustakaan[i].no_akses == noAkses && !perpustakaan[i].diterbitkan) {
            perpustakaan[i].diterbitkan = true;
            // Mengurangi jumlah buku yang tersedia
            cout << "Buku \"" << perpustakaan[i].judul << "\" berhasil diterbitkan.\n";
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Buku dengan nomor akses " << noAkses << " tidak ditemukan atau sudah diterbitkan.\n";
    }
}

int main() {
    const int MAX_BUKU = 100;
    Buku perpustakaan[MAX_BUKU];
    int jumlahBuku = 0;
    int pilihan;

    do {
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "1. Tampilkan informasi buku (by No Akses)\n";
        cout << "2. Tambahkan buku baru\n";
        cout << "3. Tampilkan semua buku dari penulis tertentu\n";
        cout << "4. Tampilkan jumlah buku dengan judul tertentu\n";
        cout << "5. Tampilkan jumlah total buku di perpustakaan\n";
        cout << "6. Terbitkan buku\n";
        cout << "7. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: {
                int no;
                cout << "Masukkan No Akses buku: ";
                cin >> no;
                bool ada = false;
                for (int i = 0; i < jumlahBuku; i++) {
                    if (perpustakaan[i].no_akses == no) {
                        tampilBuku(perpustakaan[i]);
                        ada = true;
                        break;
                    }
                }
                if (!ada) cout << "Buku tidak ditemukan.\n";
                break;
            }
            case 2:
                if (jumlahBuku < MAX_BUKU)
                    tambahBuku(perpustakaan, jumlahBuku);
                else
                    cout << "Perpustakaan sudah penuh!\n";
                break;
            case 3: {
                cin.ignore();
                string penulisCari;
                cout << "Masukkan nama penulis: ";
                getline(cin, penulisCari);
                bukuPenulisTertentu(perpustakaan, jumlahBuku, penulisCari);
                break;
            }
            case 4: {
                cin.ignore();
                string judulCari;
                cout << "Masukkan judul buku: ";
                getline(cin, judulCari);
                jumlahBukuJudul(perpustakaan, jumlahBuku, judulCari);
                break;
            }
            case 5:
                jumlahTotalBuku(perpustakaan, jumlahBuku);
                break;
            case 6: {
                int no;
                cout << "Masukkan No Akses buku yang akan diterbitkan: ";
                cin >> no;
                terbitkanBuku(perpustakaan, jumlahBuku, no);
                break;
            }
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while(pilihan != 7);

    return 0;
}

