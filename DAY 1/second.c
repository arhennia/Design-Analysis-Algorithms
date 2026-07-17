#include <stdio.h>

int main() {
    FILE *fp;
    int n, arr[100], prefix[100], i;

    fp = fopen("text files/input2.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    prefix[0] = arr[0];

    for (i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    printf("input array : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\noutput array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", prefix[i]);
    }

    return 0;
}