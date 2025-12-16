#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void animasi(string teks) {
    cout << teks;
    for (int i = 0; i < 3; i++) {
        cout << "."; 
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cout << endl;
}

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    int nilai;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

Node* topNode = NULL;

void push() {
    Node* baru = new Node;
    cout << "\n=== INPUT DATA MAHASISWA ===\n";
    cout << "Nama   : ";
    cin.ignore();
    getline(cin, baru->data.nama);
    cout << "NIM    : ";
    getline(cin, baru->data.nim);
    cout << "Gender : ";
    getline(cin, baru->data.gender);
    cout << "Nilai Struktur Data : ";
    cin >> baru->data.nilai;

    baru->next = topNode;
    topNode = baru;

    animasi("Menambahkan data ke Stack");
    cout << "? Data berhasil ditambahkan!\n";
}

void pop() {
    if (topNode == NULL) {
        cout << "\n? Stack kosong, tidak ada data yang bisa dihapus!\n";
        return;
    }

    animasi("Menghapus data teratas");

    Node* hapus = topNode;
    topNode = topNode->next;

    cout << "\nData yang dihapus:\n";
    cout << "Nama   : " << hapus->data.nama << endl;
    cout << "NIM    : " << hapus->data.nim << endl;
    cout << "Gender : " << hapus->data.gender << endl;
    cout << "Nilai  : " << hapus->data.nilai << endl;

    delete hapus;
}

void display() {
    if (topNode == NULL) {
        cout << "\n? Stack kosong, tidak ada data untuk ditampilkan!\n";
        return;
    }

    animasi("Mencetak data Stack");

    cout << "\n=== DATA MAHASISWA (TOP ? BOTTOM) ===\n";

    Node* bantu = topNode;
    int no = 1;
    while (bantu != NULL) {
        cout << "\nData ke-" << no++ << endl;
        cout << "Nama   : " << bantu->data.nama << endl;
        cout << "NIM    : " << bantu->data.nim << endl;
        cout << "Gender : " << bantu->data.gender << endl;
        cout << "Nilai  : " << bantu->data.nilai << endl;
        bantu = bantu->next;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n=============================\n";
        cout << "   PROGRAM STACK MAHASISWA   \n";
        cout << "=============================\n";
        cout << "1. INSERT DATA (PUSH)\n";
        cout << "2. HAPUS DATA (POP)\n";
        cout << "3. CETAK DATA (DISPLAY)\n";
        cout << "4. EXIT\n";
        cout << "Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: 
                animasi("Keluar program");
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "? Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}

