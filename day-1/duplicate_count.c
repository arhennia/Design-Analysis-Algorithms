#include <stdio.h>
int main() {
    FILE *fp;
    int n, arr[100];
    int i, j;
    int duplicateCount = 0;
    int maxFreq = 0;
    int mostRepeat;
    fp = fopen("input/input1.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    printf("content of the array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (i = 0; i < n; i++) {
        int count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        int first = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                first = 0;
                break;
            }
        }
        if (first && count > 1)
            duplicateCount++;

        if (first && count > maxFreq) {
            maxFreq = count;
            mostRepeat = arr[i];
        }
    }
    printf("total # duplicate values = %d\n", duplicateCount);
    printf("most repeating element in the arr = %d\n", mostRepeat);
    return 0;
}