/* Program C++ untuk implementasi Quick Sort */
#include <bits/stdc++.h>
using namespace std;

/* Fungsi utilitas untuk menukar dua elemen */
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Fungsi partition
   - Mengambil elemen terakhir sebagai pivot
   - Menempatkan pivot pada posisi yang benar
   - Elemen lebih kecil dari pivot di kiri
   - Elemen lebih besar dari pivot di kanan */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        // Jika elemen lebih kecil dari pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Menempatkan pivot pada posisi yang benar
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* Fungsi utama Quick Sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi adalah indeks partisi
        int pi = partition(arr, low, high);

        // Rekursi untuk bagian kiri dan kanan
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Fungsi untuk mencetak array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Program utama */
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Array yang diurutkan:\n";
    printArray(arr, n);

    return 0;
}

