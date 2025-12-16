#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int front, rear;
    int ele[MAX];

public:
    // Inisialisasi queue
    Queue() {
        front = 0;
        rear = -1;
    }

    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// Mengecek apakah queue penuh
int Queue::isFull() {
    return (rear == MAX - 1) ? 1 : 0;
}

// Mengecek apakah queue kosong
int Queue::isEmpty() {
    return (front == rear + 1) ? 1 : 0;
}

// Masukkan item ke queue
void Queue::insertQueue(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow" << endl;
        return;
    }
    ele[++rear] = item;
    cout << "\nNilai yang disisipkan: " << item;
}

// Hapus item dari queue
int Queue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow" << endl;
        return -1;
    }
    *item = ele[front++];
    return 0;
}

int main() {
    int item = 0;
    Queue q;

    // Menambahkan item ke queue
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);
    q.insertQueue(60); // Overflow

    // Menghapus item dari queue
    for (int i = 0; i < 6; i++) {
        if (q.deleteQueue(&item) == 0) {
            cout << "\nItem dihapus: " << item;
        }
    }

    cout << endl;
    return 0;
}

