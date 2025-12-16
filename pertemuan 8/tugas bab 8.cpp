#include <iostream>
using namespace std;

#define MAX 5

// Deklarasi Double Ended Queue (Deque)
class DQueue {
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    DQueue();
    int isFull();
    int isEmpty();
    void insertDQueueAtRear(int item);
    int deleteDQueueAtFront(int *item);
    void insertDQueueAtFront(int item);
    int deleteDQueueAtRear(int *item);
};

// Inisialisasi Deque
DQueue::DQueue() {
    front = 0;
    rear = -1;
    count = 0;
}

// Mengecek apakah Deque penuh
int DQueue::isFull() {
    return (count == MAX) ? 1 : 0;
}

// Mengecek apakah Deque kosong
int DQueue::isEmpty() {
    return (count == 0) ? 1 : 0;
}

// Menambahkan item di Rear
void DQueue::insertDQueueAtRear(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow";
        return;
    }
    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;
    cout << "\nDimasukkan di Belakang FRONT: " << front << ", REAR: " << rear;
    cout << "\nItem dimasukkan: " << item << endl;
}

// Menghapus item di Front
int DQueue::deleteDQueueAtFront(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow";
        return -1;
    }
    *item = ele[front];
    front = (front + 1) % MAX;
    count--;
    cout << "\nSetelah Hapus Di Depan FRONT: " << front << ", REAR: " << rear;
    return 0;
}

// Menambahkan item di Front
void DQueue::insertDQueueAtFront(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow";
        return;
    }
    front = (front == 0) ? MAX - 1 : front - 1;
    ele[front] = item;
    count++;
    cout << "\nSetelah Sisipkan Di Depan FRONT: " << front << ", REAR: " << rear;
    cout << "\nItem yang disisipkan: " << item << endl;
}

// Menghapus item di Rear
int DQueue::deleteDQueueAtRear(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow";
        return -1;
    }
    *item = ele[rear];
    rear = (rear == 0) ? MAX - 1 : rear - 1;
    count--;
    cout << "\nSetelah Hapus Di Belakang FRONT: " << front << ", REAR: " << rear;
    return 0;
}

int main() {
    int item;
    DQueue q;

    // Menambahkan item di Rear
    q.insertDQueueAtRear(10);
    q.insertDQueueAtRear(20);
    q.insertDQueueAtRear(30);

    // Menambahkan item di Front
    q.insertDQueueAtFront(40);
    q.insertDQueueAtFront(50);
    q.insertDQueueAtFront(60); // Overflow

    // Menghapus item di Front
    for (int i = 0; i < 3; i++) {
        if (q.deleteDQueueAtFront(&item) == 0) {
            cout << "\nItem dihapus: " << item << endl;
        }
    }

    // Menghapus item di Rear
    while (q.deleteDQueueAtRear(&item) == 0) {
        cout << "\nItem dihapus: " << item << endl;
    }

    cout << "\n";
    return 0;
}

