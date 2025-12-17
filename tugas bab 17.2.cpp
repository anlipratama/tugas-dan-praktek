// Program C++ untuk implementasi Selection Sort
#include <bits/stdc++.h>
using namespace std;

/* Fungsi untuk menukar dua elemen */
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Fungsi Selection Sort */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;

        // Mencari elemen minimum di bagian array yang belum diurutkan
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Menukar elemen minimum dengan elemen pertama
        swap(&arr[min_idx], &arr[i]);
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Array yang diurutkan:\n";
    printArray(arr, n);

    return 0;
}

