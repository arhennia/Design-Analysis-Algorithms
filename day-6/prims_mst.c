#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Structure to represent a node in the Min-Priority Queue
typedef struct {
    int v;
    int key;
} MinHeapNode;

// Structure to represent a Min-Priority Queue (Min-Heap)
typedef struct {
    int size;
    int capacity;
    int *pos; // To track positions of vertices in heap for decreaseKey
    MinHeapNode **array;
} MinPriorityQueue;

// Create a new Min-Heap node
MinHeapNode *newMinHeapNode(int v, int key) {
    MinHeapNode *node = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    node->v = v;
    node->key = key;
    return node;
}

// Create a Min-Priority Queue
MinPriorityQueue *createMinPriorityQueue(int capacity) {
    MinPriorityQueue *minHeap = (MinPriorityQueue *)malloc(sizeof(MinPriorityQueue));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode **)malloc(capacity * sizeof(MinHeapNode *));
    return minHeap;
}

// Swap two nodes in the Min-Heap
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify at a given index
void minHeapify(MinPriorityQueue *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];

        // Update positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// Check if Min-Heap is empty
int isEmpty(MinPriorityQueue *minHeap) {
    return minHeap->size == 0;
}

// Extract the node with minimum key
MinHeapNode *extractMin(MinPriorityQueue *minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    MinHeapNode *root = minHeap->array[0];
    MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

// Decrease key value of a given vertex v
void decreaseKey(MinPriorityQueue *minHeap, int v, int key) {
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;

    while (i > 0 && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if a vertex is in the Min-Heap
int isInMinHeap(MinPriorityQueue *minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

// Free Min-Heap memory
void freeMinHeap(MinPriorityQueue *minHeap) {
    if (minHeap) {
        for (int i = 0; i < minHeap->capacity; i++) {
            if (minHeap->array[i])
                free(minHeap->array[i]);
        }
        free(minHeap->array);
        free(minHeap->pos);
        free(minHeap);
    }
}

// Helper function to open input file from various paths
FILE *openInputFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) return fp;

    char path[256];
    snprintf(path, sizeof(path), "input/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    snprintf(path, sizeof(path), "day-6/input/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    snprintf(path, sizeof(path), "day-6/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    snprintf(path, sizeof(path), "../day-6/input/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    return NULL;
}

// Prim's algorithm using Min-Priority Queue
void primMST(int **graph, int n, int startVertex) {
    int *parent = (int *)malloc(n * sizeof(int));
    int *key = (int *)malloc(n * sizeof(int));

    MinPriorityQueue *minHeap = createMinPriorityQueue(n);

    // Initialize Min-Heap with all vertices
    for (int v = 0; v < n; v++) {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    minHeap->size = n;

    // Start from the user-specified vertex (1-indexed to 0-indexed)
    int s = startVertex - 1;
    key[s] = 0;
    decreaseKey(minHeap, s, key[s]);

    while (!isEmpty(minHeap)) {
        MinHeapNode *minNode = extractMin(minHeap);
        int u = minNode->v;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && isInMinHeap(minHeap, v) && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
        }
    }

    // Build Cost Adjacency Matrix of the Minimum Spanning Tree
    int **mstMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mstMatrix[i] = (int *)calloc(n, sizeof(int));
    }

    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            int u = parent[i];
            int v = i;
            mstMatrix[u][v] = graph[u][v];
            mstMatrix[v][u] = graph[u][v];
            totalWeight += graph[u][v];
        }
    }

    // Display the Cost Adjacency Matrix of MST
    printf("\nOutput:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%-3d", mstMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalWeight);

    // Clean up
    for (int i = 0; i < n; i++) {
        free(mstMatrix[i]);
    }
    free(mstMatrix);
    free(parent);
    free(key);
    freeMinHeap(minHeap);
}

int main(void) {
    int n, startVertex;

    printf("Enter the Number of Vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the Starting Vertex: ");
    if (scanf("%d", &startVertex) != 1 || startVertex < 1 || startVertex > n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    // Open inUnAdjMat.dat
    FILE *fp = openInputFile("inUnAdjMat.dat");
    if (!fp) {
        printf("Error: Could not open inUnAdjMat.dat\n");
        return 1;
    }

    // Allocate and read adjacency matrix
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (fscanf(fp, "%d", &graph[i][j]) != 1) {
                printf("Error: Failed to read matrix element at [%d][%d]\n", i, j);
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);

    // Apply Prim's Algorithm
    primMST(graph, n, startVertex);

    // Free graph memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
