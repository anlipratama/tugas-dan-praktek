#include <iostream>
using namespace std;

int main() {
    char x[12]; // deklarasi array 12 elemen

    cout << "Alamat elemen array x[0] sampai x[11]:\n";
    for (int i = 0; i < 12; i++) {
        cout << "x[" << i << "] = " << static_cast<void*>(&x[i]) << endl;
    }

    cout << "\nAlamat elemen ke-8: &x[8] = " << static_cast<void*>(&x[8]) << endl;

    return 0;
}

