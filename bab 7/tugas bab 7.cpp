#include <iostream>
using namespace std;

#define MAX 5

// Deklarasi Circular Queue
class CirQueue {
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    CirQueue();
    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// Inisialisasi Circular Queue
CirQueue::CirQueue() {
    front = 0;
    rear = -1;
    count = 0;
}

// Mengecek apakah queue penuh
int CirQueue::isFull() {
    return (count == MAX) ? 1 : 0;
}

// Mengecek apakah queue kosong
int CirQueue::isEmpty() {
    return (count == 0) ? 1 : 0;
}

// Menambahkan item ke circular queue
void CirQueue::insertQueue(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow";
        return;
    }
    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;
    cout << "\nDimasukkan item: " << item;
}

// Menghapus item dari circular queue
int CirQueue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow";
        return -1;
    }
    *item = ele[front];
    front = (front + 1) % MAX;
    count--;
    return 0;
}

int main() {
    int item;
    CirQueue q;

    // Menambahkan item ke queue
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);
    q.insertQueue(60); // Overflow

    // Menghapus beberapa item dari queue
    for (int i = 0; i < 5; i++) {
        if (q.deleteQueue(&item) == 0) {
            cout << "\nItem dihapus: " << item << endl;
        }
    }

    // Menambahkan item lagi setelah delete
    q.insertQueue(60);

    // Menghapus sisa item
    while (q.deleteQueue(&item) == 0) {
        cout << "\nItem dihapus: " << item << endl;
    }

    cout << "\n";
    return 0;
}

