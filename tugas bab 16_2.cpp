#include <iostream>
using namespace std;

int main() {
    int data[] = {5, 7, 12, 15, 17, 19, 22, 25, 27, 32};
    int n = 10;
    int N;

    cout << "Masukkan nilai yang dicari: ";
    cin >> N;

    int low = 0, high = n - 1;
    bool ditemukan = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (data[mid] == N) {
            cout << "Data ditemukan pada index ke-" << mid << endl;
            ditemukan = true;
            break;
        } else if (N < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
