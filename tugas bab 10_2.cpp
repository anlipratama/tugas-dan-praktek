#include <iostream>
using namespace std;

#define MAX 5 // kapasitas queue

int queue[MAX];
int front = -1; // indeks elemen depan
int rear = -1;  // indeks elemen belakang

// Cek apakah queue kosong
bool isEmpty() {
    return front == -1;
}

// Cek apakah queue penuh
bool isFull() {
    return rear == MAX - 1;
}

// Enqueue: menambahkan elemen ke akhir queue
void enqueue(int value) {
    if (isFull()) {
        cout << "?? Queue penuh, tidak bisa menambahkan " << value << endl;
        return;
    }
    if (isEmpty()) front = 0;
    rear++;
    queue[rear] = value;
    cout << "Enqueue: " << value << " (Rear=" << rear << ")\n";
}

// Dequeue: menghapus elemen dari depan queue
void dequeue() {
    if (isEmpty()) {
        cout << "?? Queue kosong, tidak ada elemen untuk dihapus.\n";
        return;
    }
    int value = queue[front];
    cout << "Dequeue: " << value << " (Front=" << front << ")\n";
    if (front == rear) {
        // Hanya satu elemen tersisa, queue menjadi kosong
        front = rear = -1;
    } else {
        front++;
    }
}

// Tampilkan isi queue
void tampilQueue() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "Isi queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== Contoh FIFO (Queue) ===\n";

    // Enqueue beberapa elemen
    enqueue(10);
    enqueue(20);
    enqueue(30);

    tampilQueue();

    // Dequeue elemen sesuai FIFO
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // mencoba dequeue saat queue kosong

    return 0;
}

