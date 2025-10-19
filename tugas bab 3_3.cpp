#include <iostream>
using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    int no_urut;
    string nama;
    int umur;
    string alamat;
    float nilai;
};

int main() {
    const int JUMLAH = 15;
    Mahasiswa mhs[JUMLAH];

    // Input data mahasiswa
    for (int i = 0; i < JUMLAH; i++) {
        mhs[i].no_urut = i + 1; // No urut otomatis mulai dari 1
        cout << "\nMasukkan data mahasiswa ke-" << mhs[i].no_urut << ":\n";

        cout << "Nama: ";
        cin.ignore(); // Bersihkan buffer input
        getline(cin, mhs[i].nama);

        cout << "Umur: ";
        cin >> mhs[i].umur;

        cin.ignore(); // Bersihkan buffer sebelum membaca alamat
        cout << "Alamat: ";
        getline(cin, mhs[i].alamat);

        cout << "Nilai: ";
        cin >> mhs[i].nilai;
    }

    // Mencetak data mahasiswa
    cout << "\nData Mahasiswa:\n";
    cout << "No\tNama\t\tUmur\tAlamat\t\t\tNilai\n";
    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < JUMLAH; i++) {
        cout << mhs[i].no_urut << "\t"
             << mhs[i].nama << "\t\t"
             << mhs[i].umur << "\t"
             << mhs[i].alamat << "\t\t"
             << mhs[i].nilai << endl;
    }

    return 0;
}

