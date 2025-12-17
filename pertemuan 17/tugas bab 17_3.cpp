#include <iostream>
using namespace std;

int main() {
    int data[] = {8, 22, 7, 9, 31, 5, 13};
    int n = 7;
    int swapCount = 0;

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Tukar data
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swapCount++;
            }
        }
    }

    cout << "Jumlah swapping: " << swapCount << endl;
    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}
