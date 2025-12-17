/* Program C untuk implementasi Merge Sort */
#include <stdio.h>
#include <stdlib.h>

/* Menggabungkan dua sub-array dari arr[]
   Sub-array pertama: arr[l..m]
   Sub-array kedua  : arr[m+1..r] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* Array sementara */
    int L[n1], R[n2];

    /* Salin data ke array sementara */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Gabungkan kembali ke arr[l..r] */
    i = 0;      // indeks awal sub-array pertama
    j = 0;      // indeks awal sub-array kedua
    k = l;      // indeks awal array gabungan

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    /* Salin sisa elemen L[], jika ada */
    while (i < n1)
        arr[k++] = L[i++];

    /* Salin sisa elemen R[], jika ada */
    while (j < n2)
        arr[k++] = R[j++];
}

/* Fungsi rekursif Merge Sort */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Menghindari overflow
        int m = l + (r - l) / 2;

        // Urutkan bagian kiri dan kanan
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Gabungkan hasilnya
        merge(arr, l, m, r);
    }
}

/* Fungsi untuk mencetak array */
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Program utama */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array yang diberikan:\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray yang diurutkan:\n");
    printArray(arr, arr_size);

    return 0;
}

