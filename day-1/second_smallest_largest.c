#include <stdio.h>
#include <limits.h>

int main() {
    FILE *fp;
    int n, i, arr[50];
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;
    fp = fopen("input/input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    for (i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    if (secondSmallest == INT_MAX)
        printf("Second smallest element does not exist.\n");
    else
        printf("Second smallest element = %d\n", secondSmallest);

    if (secondLargest == INT_MIN)
        printf("Second largest element does not exist.\n");
    else
        printf("Second largest element = %d\n", secondLargest);

    return 0;
}