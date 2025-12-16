#include <bits/stdc++.h>
using namespace std;

// Fungsi Binary Search Iteratif
int binarySearch(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    int langkah = 0;

    while (l <= r) {
        langkah++;
        int m = (l + r) / 2;

        if (a[m] == x) {
            cout << "Jumlah langkah: " << langkah << endl;
            return m;
        }

        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    cout << "Jumlah langkah: " << langkah << endl;
    return -1;
}

int main() {
    int a[15];

    // Mengisi array dengan bilangan genap
    for (int i = 0; i < 15; i++) {
        a[i] = (i + 1) * 2;
    }

    int x = 16;

    int idx = binarySearch(a, 15, x);

    if (idx != -1)
        cout << "Data ditemukan di index " << idx << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    return 0;
}

