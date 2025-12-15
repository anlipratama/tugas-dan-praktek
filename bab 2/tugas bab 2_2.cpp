#include <iostream>
#include <iomanip> // untuk manipulasi format
using namespace std;

int main() {
    int x[15]; // deklarasi array 15 elemen

    cout << "Alamat elemen array x[0] sampai x[14] (hexadecimal):\n";
    for (int i = 0; i < 15; i++) {
        cout << "x[" << i << "] = " 
             << "0x" << hex << uppercase 
             << reinterpret_cast<uintptr_t>(&x[i]) << endl;
    }

    cout << "\nAlamat elemen x[3]: 0x" << hex << uppercase 
         << reinterpret_cast<uintptr_t>(&x[3]) << endl;

    cout << "Alamat elemen x[9]: 0x" << hex << uppercase 
         << reinterpret_cast<uintptr_t>(&x[9]) << endl;

    return 0;
}

