#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;


void delay() {
this_thread::sleep_for(chrono::milliseconds(300));
}


int main() {
int a[10];
srand(time(0));


cout << "Data awal : ";
for (int i = 0; i < 10; i++) {
a[i] = rand() % 100;
cout << a[i] << " ";
}
cout << "\n\nProses Bubble Sort:\n";


for (int i = 0; i < 9; i++) {
for (int j = 0; j < 9 - i; j++) {
cout << "Bandingkan " << a[j] << " dan " << a[j + 1];
if (a[j] > a[j + 1]) {
swap(a[j], a[j + 1]);
cout << " -> Tukar";
}
cout << endl;
delay();
}
}


cout << "\nHasil akhir : ";
for (int x : a) cout << x << " ";
return 0;
}
