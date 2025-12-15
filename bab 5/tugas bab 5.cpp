
#include <iostream>
using namespace std;

#define MAX 5

// Deklarasi Kelas Double Stack
class DStack {
private:
    int top1;
    int top2;
    int ele[MAX];

public:
    DStack();

    void pushA(int item);
    void pushB(int item);
    int popA(int *item);
    int popB(int *item);
};

// Inisialisasi Double Stack
DStack::DStack() {
    top1 = -1;
    top2 = MAX;
}

// Operasi PUSH di Stack 1
void DStack::pushA(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack1";
        return;
    }
    top1++;
    ele[top1] = item;
    cout << "\nItem disisipkan di Stack1 : " << item;
}

// Operasi PUSH di Stack 2
void DStack::pushB(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack2";
        return;
    }
    top2--;
    ele[top2] = item;
    cout << "\nItem disisipkan di Stack2 : " << item;
}

// Operasi POP di Stack 1
int DStack::popA(int *item) {
    if (top1 == -1) {
        cout << "\nStack Underflow Stack1";
        return -1;
    }
    *item = ele[top1--];
    return 0;
}

// Operasi POP di Stack 2
int DStack::popB(int *item) {
    if (top2 == MAX) {
        cout << "\nStack Underflow Stack2";
        return -1;
    }
    *item = ele[top2++];
    return 0;
}

// Program Utama
int main() {
    int item = 0;
    DStack s = DStack();

    // Push data ke Stack 1
    s.pushA(10);
    s.pushA(20);
    s.pushA(30);

    // Push data ke Stack 2
    s.pushB(40);
    s.pushB(50);
    s.pushB(60);

    // Pop data dari Stack 1
    if (s.popA(&item) == 0)
        cout << "\nMenghapus Item dari Stack1 : " << item;
    if (s.popA(&item) == 0)
        cout << "\nMenghapus Item dari Stack1 : " << item;
    if (s.popA(&item) == 0)
        cout << "\nMenghapus Item dari Stack1 : " << item;

    // Pop data dari Stack 2
    if (s.popB(&item) == 0)
        cout << "\nMenghapus Item dari Stack2 : " << item;
    if (s.popB(&item) == 0)
        cout << "\nMenghapus Item dari Stack2 : " << item;
    if (s.popB(&item) == 0)
        cout << "\nMenghapus Item dari Stack2 : " << item;

    cout << endl;
    return 0;
}

