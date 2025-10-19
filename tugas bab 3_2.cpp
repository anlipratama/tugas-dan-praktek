#include <iostream>
using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    int no_urut;
    string nama;
    int umur;
};

int main() {
    Mahasiswa mhs[5]; // Array untuk 5 mahasiswa

    // Input data mahasiswa
    for (int i = 0; i < 5; i++) {
        mhs[i].no_urut = i + 1; // No urut mulai dari 1
        cout << "Masukkan nama mahasiswa ke-" << mhs[i].no_urut << ": ";
        cin.ignore(); // Bersihkan input buffer
        getline(cin, mhs[i].nama);
        cout << "Masukkan umur mahasiswa ke-" << mhs[i].no_urut << ": ";
        cin >> mhs[i].umur;
    }

    // Mencetak detail mahasiswa dengan No urut 2
    cout << "\nDetail Mahasiswa dengan No Urut 2:\n";
    cout << "No Urut: " << mhs[1].no_urut << endl; // index 1 = no urut 2
    cout << "Nama: " << mhs[1].nama << endl;
    cout << "Umur: " << mhs[1].umur << " tahun" << endl;

    return 0;
}

