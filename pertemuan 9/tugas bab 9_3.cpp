#include <iostream>
using namespace std;

// Struktur simpul (node)
struct Node {
    int info;
    Node* link;
};

Node* FIRST = NULL;

// Fungsi untuk menambah node di akhir list
void tambahNode(int nilai) {
    Node* baru = new Node;
    baru->info = nilai;
    baru->link = NULL;

    if (FIRST == NULL) {
        FIRST = baru;
    } else {
        Node* bantu = FIRST;
        while (bantu->link != NULL)
            bantu = bantu->link;
        bantu->link = baru;
    }
}

// a. Menghitung jumlah simpul
int hitungSimpul() {
    int jumlah = 0;
    Node* q = FIRST;
    while (q != NULL) {
        jumlah++;
        q = q->link;
    }
    return jumlah;
}

// b. Menghitung total nilai INFO
int totalInfo() {
    int total = 0;
    Node* q = FIRST;
    while (q != NULL) {
        total += q->info;
        q = q->link;
    }
    return total;
}

// c. Menampilkan semua nilai INFO
void cetakInfo() {
    Node* q = FIRST;
    cout << "Nilai INFO dalam Linked List: ";
    while (q != NULL) {
        cout << q->info << " ";
        q = q->link;
    }
    cout << endl;
}

// d. Menghitung jumlah simpul dengan nilai INFO = 50
int hitungInfo50() {
    int count = 0;
    Node* q = FIRST;
    while (q != NULL) {
        if (q->info == 50)
            count++;
        q = q->link;
    }
    return count;
}

int main() {
    // Membuat linked list contoh
    tambahNode(25);
    tambahNode(12);
    tambahNode(33);
    tambahNode(50);
    tambahNode(27);
    tambahNode(14);
    tambahNode(50);

    // Menampilkan hasil
    cout << "Jumlah simpul: " << hitungSimpul() << endl;
    cout << "Total nilai INFO: " << totalInfo() << endl;
    cetakInfo();
    cout << "Jumlah simpul dengan INFO = 50: " << hitungInfo50() << endl;

    return 0;
}
