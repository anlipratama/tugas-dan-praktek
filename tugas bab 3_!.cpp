#include <iostream>
using namespace std;

// Mendefinisikan struktur Mahasiswa
struct Mahasiswa {
    int no_urut;
    string nama;
    int usia;
    float nilai;
};

int main() {
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    Mahasiswa mhs[n]; // Array of struct

    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i + 1 << ":\n";
        mhs[i].no_urut = i + 1;
        cout << "Nama: ";
        cin.ignore(); // Membersihkan input buffer
        getline(cin, mhs[i].nama);
        cout << "Usia: ";
        cin >> mhs[i].usia;
        cout << "Nilai: ";
        cin >> mhs[i].nilai;
    }

    // Menampilkan data mahasiswa
    cout << "\nData Mahasiswa:\n";
    cout << "No\tNama\t\tUsia\tNilai\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << mhs[i].no_urut << "\t" 
             << mhs[i].nama << "\t\t" 
             << mhs[i].usia << "\t" 
             << mhs[i].nilai << endl;
    }

    return 0;
}

