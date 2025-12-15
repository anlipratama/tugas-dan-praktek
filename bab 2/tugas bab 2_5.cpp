#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x[2][3][5]; // array 3D: 2x3x5

    cout << "Alamat elemen array x[i][j][k] (hexadecimal):\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 5; k++) {
                cout << "x[" << i << "][" << j << "][" << k << "] = 0x"
                     << hex << uppercase 
                     << reinterpret_cast<uintptr_t>(&x[i][j][k]) << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "\nAlamat elemen x[1][1][4]: 0x" 
         << hex << uppercase << reinterpret_cast<uintptr_t>(&x[1][1][4]) << endl;

    cout << "Alamat elemen x[0][0][3]: 0x" 
         << hex << uppercase << reinterpret_cast<uintptr_t>(&x[0][0][3]) << endl;

    return 0;
}

