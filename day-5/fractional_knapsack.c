#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
} ITEM;

void swapItem(ITEM *a, ITEM *b) {
    ITEM temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify based on profit_weight_ratio
void minHeapify(ITEM arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio < arr[smallest].profit_weight_ratio) {
        smallest = left;
    }
    if (right < n && arr[right].profit_weight_ratio < arr[smallest].profit_weight_ratio) {
        smallest = right;
    }

    if (smallest != i) {
        swapItem(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Heap sort in non-increasing order using Min-Heap
void heapSortNonIncreasing(ITEM arr[], int n) {
    // 1. Build min-heap
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    // 2. Extract elements: swap min root with end, then min-heapify reduced heap
    for (int i = n - 1; i > 0; i--) {
        swapItem(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }

    ITEM *items = (ITEM *)malloc(n * sizeof(ITEM));
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        if (scanf("%f %f", &items[i].item_profit, &items[i].item_weight) != 2) {
            printf("Invalid input.\n");
            free(items);
            return 1;
        }
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    float capacity;
    printf("Enter the capacity of knapsack: ");
    if (scanf("%f", &capacity) != 1) {
        printf("Invalid capacity.\n");
        free(items);
        return 1;
    }

    // Sort items in non-increasing order of profit_weight_ratio using heap sort
    heapSortNonIncreasing(items, n);

    float *amount_taken = (float *)calloc(n, sizeof(float));
    float remaining_capacity = capacity;
    float max_profit = 0.0f;

    for (int i = 0; i < n; i++) {
        if (remaining_capacity >= items[i].item_weight) {
            amount_taken[i] = 1.0f;
            remaining_capacity -= items[i].item_weight;
            max_profit += items[i].item_profit;
        } else if (remaining_capacity > 0.0f) {
            amount_taken[i] = remaining_capacity / items[i].item_weight;
            max_profit += amount_taken[i] * items[i].item_profit;
            remaining_capacity = 0.0f;
        } else {
            amount_taken[i] = 0.0f;
        }
    }

    printf("\nItem No   profit      Weight      Amount to be taken\n");
    for (int i = 0; i < n; i++) {
        printf("%-9d %-11f %-11f %f\n",
               items[i].item_id,
               items[i].item_profit,
               items[i].item_weight,
               amount_taken[i]);
    }

    printf("Maximum profit: %f\n", max_profit);

    free(amount_taken);
    free(items);
    return 0;
}
