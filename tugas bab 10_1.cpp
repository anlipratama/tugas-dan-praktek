#include <iostream>
using namespace std;

#define MAX 5 // kapasitas stack

int stack[MAX];
int top = -1; // indeks elemen teratas

// Fungsi untuk cek stack penuh
bool isFull() {
    return top == MAX - 1;
}

// Fungsi untuk cek stack kosong
bool isEmpty() {
    return top == -1;
}

// Push: menambahkan elemen ke stack
void push(int value) {
    if (isFull()) {
        cout << "?? Stack penuh, tidak bisa menambahkan " << value << endl;
        return;
    }
    top++;
    stack[top] = value;
    cout << "Push: " << value << " (Top=" << top << ")\n";
}

// Pop: menghapus elemen dari stack
void pop() {
    if (isEmpty()) {
        cout << "?? Stack kosong, tidak ada elemen untuk dihapus.\n";
        return;
    }
    int value = stack[top];
    cout << "Pop: " << value << " (Top=" << top << ")\n";
    top--;
}

// Tampilkan isi stack
void tampilStack() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "Isi stack: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== Contoh LIFO (Stack) ===\n";

    // Push beberapa elemen
    push(10);
    push(20);
    push(30);

    tampilStack();

    // Pop elemen sesuai LIFO
    pop();
    pop();
    pop();
    pop(); // mencoba pop saat stack kosong

    return 0;
}

