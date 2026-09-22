#include <stdio.h>
#include <stdlib.h>

// Structure to store a character and its frequency
typedef struct {
    char alphabet;
    int frequency;
} SYMBOL;

// Node of the Huffman Tree
typedef struct HuffmanNode {
    char alphabet;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// Min-Priority Queue for Huffman Nodes
typedef struct {
    int size;
    int capacity;
    HuffmanNode **array;
} MinPriorityQueue;

// Helper to create a new Huffman node
HuffmanNode *createNode(char alphabet, int frequency) {
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->alphabet = alphabet;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper to create a Min-Priority Queue
MinPriorityQueue *createQueue(int capacity) {
    MinPriorityQueue *queue = (MinPriorityQueue *)malloc(sizeof(MinPriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (HuffmanNode **)malloc(capacity * sizeof(HuffmanNode *));
    return queue;
}

void swapNodes(HuffmanNode **a, HuffmanNode **b) {
    HuffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify keyed on frequency
void minHeapify(MinPriorityQueue *queue, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < queue->size &&
        queue->array[left]->frequency < queue->array[smallest]->frequency) {
        smallest = left;
    }

    if (right < queue->size &&
        queue->array[right]->frequency < queue->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapNodes(&queue->array[idx], &queue->array[smallest]);
        minHeapify(queue, smallest);
    }
}

// Extract minimum frequency node from Min-Priority Queue
HuffmanNode *extractMin(MinPriorityQueue *queue) {
    if (queue->size <= 0) return NULL;

    HuffmanNode *minNode = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    queue->size--;
    minHeapify(queue, 0);

    return minNode;
}

// Insert a node into Min-Priority Queue
void insertQueue(MinPriorityQueue *queue, HuffmanNode *node) {
    queue->size++;
    int i = queue->size - 1;

    while (i > 0 && node->frequency < queue->array[(i - 1) / 2]->frequency) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}

// Construct Huffman Tree
HuffmanNode *buildHuffmanTree(SYMBOL symbols[], int n) {
    MinPriorityQueue *queue = createQueue(n);

    // Populate queue with initial symbol nodes
    for (int i = 0; i < n; i++) {
        HuffmanNode *node = createNode(symbols[i].alphabet, symbols[i].frequency);
        insertQueue(queue, node);
    }

    // Combine two lowest frequency nodes until 1 node remains
    while (queue->size > 1) {
        HuffmanNode *left = extractMin(queue);
        HuffmanNode *right = extractMin(queue);

        // Internal nodes marked with '$'
        HuffmanNode *parent = createNode('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        insertQueue(queue, parent);
    }

    HuffmanNode *root = extractMin(queue);

    free(queue->array);
    free(queue);

    return root;
}

// In-order traversal of Huffman tree (displaying symbols of leaf nodes)
void inorderTraversal(HuffmanNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        if (root->alphabet != '$') {
            printf("%c ", root->alphabet);
        }
        inorderTraversal(root->right);
    }
}

// Free memory allocated for Huffman tree
void freeTree(HuffmanNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Create an array of structures where size = number of alphabets
    SYMBOL *symbols = (SYMBOL *)malloc(n * sizeof(SYMBOL));
    if (symbols == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        if (scanf(" %c", &symbols[i].alphabet) != 1) {
            printf("Error reading alphabet.\n");
            free(symbols);
            return 1;
        }
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &symbols[i].frequency) != 1) {
            printf("Error reading frequency.\n");
            free(symbols);
            return 1;
        }
    }

    // Build the tree using Min-Priority Queue
    HuffmanNode *root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);
    free(symbols);

    return 0;
}
