
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX]; // Ukuran maksimum Stack

    Stack() { top = -1; }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

// Menambahkan elemen ke dalam Stack
bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    } else {
        a[++top] = x;
        cout << x << " didorong ke dalam tumpukan\n";
        return true;
    }
}

// Menghapus elemen dari Stack
int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

// Melihat elemen teratas Stack
int Stack::peek() {
    if (top < 0) {
        cout << "Tumpukan Kosong\n";
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

// Mengecek apakah Stack kosong
bool Stack::isEmpty() {
    return (top < 0);
}

// Program utama untuk menguji fungsi Stack
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " dikeluarkan dari tumpukan\n";

    return 0;
}

