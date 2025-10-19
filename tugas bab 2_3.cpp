#include <iostream>
#include <iomanip> // untuk manipulasi format
using namespace std;

int main() {
    float x[5][8]; // array 2D 5x8

    cout << "Alamat elemen array x[i][j] (hexadecimal):\n";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "x[" << i << "][" << j << "] = 0x"
                 << hex << uppercase 
                 << reinterpret_cast<uintptr_t>(&x[i][j]) << "  ";
        }
        cout << endl;
    }

    cout << "\nAlamat elemen x[0][0]: 0x" 
         << hex << uppercase << reinterpret_cast<uintptr_t>(&x[0][0]) << endl;

    cout << "Alamat elemen x[2][4]: 0x" 
         << hex << uppercase << reinterpret_cast<uintptr_t>(&x[2][4]) << endl;

    return 0;
}

