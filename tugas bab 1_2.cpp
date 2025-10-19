#include <iostream>
using namespace std;

int main() {
    float lebar, tinggi;

    cout << "Masukkan lebar: ";
    cin >> lebar;
    cout << "Masukkan tinggi: ";
    cin >> tinggi;

    float luas = lebar * tinggi;
    float keliling = 2 * (lebar + tinggi);

    cout << "Luas persegi panjang = " << luas << endl;
    cout << "Keliling persegi panjang = " << keliling << endl;

    return 0;
}

