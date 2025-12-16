#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* baru = new Node;
    baru->data = x;

    if (!head) {
        head = baru;
        baru->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = baru;
        baru->next = head;
    }
}

void hapus(int x) {
    if (!head) return;

    Node *curr = head, *prev = NULL;

    do {
        if (curr->data == x) break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr->data != x) return;

    if (curr == head && curr->next == head) {
        delete head;
        head = NULL;
    } else if (curr == head) {
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        head = head->next;
        temp->next = head;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}

void tampil() {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    tampil();     // 10 20 30
    hapus(20);
    tampil();     // 10 30

    return 0;
}

