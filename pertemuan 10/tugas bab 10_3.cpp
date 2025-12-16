#include <iostream>
using namespace std;

#define MAX 5 // kapasitas stack

int stack[MAX];
int top = -1; // indeks elemen teratas

// Cek apakah stack kosong
bool isEmpty() {
    return top == -1;
}

// Cek apakah stack penuh
bool isFull() {
    return top == MAX - 1;
}

// Push: menambahkan elemen ke stack
void push(int value) {
    if (isFull()) {
        cout << "?? Stack penuh, tidak bisa menambahkan " << value << endl;
        return;
    }
    top++;
    stack[top] = value;
    cout << "? Push: " << value << " berhasil ditambahkan ke stack.\n";
}

// Pop: menghapus elemen dari stack
void pop() {
    if (isEmpty()) {
        cout << "?? Stack kosong, tidak ada elemen untuk dihapus.\n";
        return;
    }
    int value = stack[top];
    cout << "??? Pop: " << value << " dihapus dari stack.\n";
    top--;
}

// Peek: melihat elemen teratas tanpa menghapus
void peek() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "?? Elemen teratas: " << stack[top] << endl;
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
    int pilihan, value;
    do {
        cout << "\n=== MENU STACK ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Lihat Elemen Teratas)\n";
        cout << "4. Tampilkan Stack\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai untuk Push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                tampilStack();
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}

