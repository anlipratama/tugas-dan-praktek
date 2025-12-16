#include <bits/stdc++.h>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear  = NULL;

// Fungsi enqueue (tambah data ke queue)
void enqueue(int x) {
    Node* baru = new Node;
    baru->data = x;
    baru->next = NULL;

    if (!rear) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
}

// Fungsi dequeue (hapus data dari depan queue)
void dequeue() {
    if (!front) return;

    Node* temp = front;
    front = front->next;
    delete temp;

    if (!front)
        rear = NULL;
}

// Fungsi tampil data queue
void tampil() {
    Node* temp = front;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    tampil();   // 1 2 3

    dequeue();

    tampil();   // 2 3

    return 0;
}

