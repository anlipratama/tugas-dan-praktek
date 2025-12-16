#include <iostream>
using namespace std;

// Deklarasi node linked list
struct Node {
    int data;
    Node* link;
};

Node* top = nullptr; // Pointer ke elemen teratas stack

// Fungsi untuk menambahkan elemen ke stack
void push(int data) {
    Node* temp = new Node();

    // Periksa apakah heap penuh
    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = top;
    top = temp;
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty() {
    return top == nullptr;
}

// Fungsi untuk melihat elemen teratas stack
int peek() {
    if (!isEmpty())
        return top->data;
    else {
        cout << "\nStack Kosong";
        exit(1);
    }
}

// Fungsi untuk menghapus elemen teratas stack
void pop() {
    if (isEmpty()) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }

    Node* temp = top;
    top = top->link;
    temp->link = nullptr;
    delete temp; // Lepaskan memori
}

// Fungsi untuk menampilkan semua elemen stack
void display() {
    if (isEmpty()) {
        cout << "\nStack Underflow";
        return;
    }

    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // Push elemen ke dalam stack
    push(11);
    push(22);
    push(33);
    push(44);

    cout << "Stack saat ini: ";
    display();

    // Tampilkan elemen teratas
    cout << "Elemen Top adalah: " << peek() << endl;

    // Hapus beberapa elemen
    pop();
    pop();

    cout << "Stack setelah pop: ";
    display();

    cout << "Elemen Top adalah: " << peek() << endl;

    return 0;
}

