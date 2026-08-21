#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int p = low + 1;
    int q = high;

    while (1) {
        while (p <= high && A[p] <= pivot) {
            p++;
        }
        while (q >= low && A[q] > pivot) {
            q--;
        }

        if (p < q) {
            swap(&A[p], &A[q]);
        } else {
            swap(&A[low], &A[q]);
            return q;
        }
    }
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int loc = partition(A, low, high);
        quickSort(A, low, loc - 1);
        quickSort(A, loc + 1, high);
    }
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}