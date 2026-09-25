#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph edge
typedef struct {
    int u;
    int v;
    int w;
} Edge;

// Structure to represent a subset for Union-Find
typedef struct {
    int parent;
    int rank;
} Subset;

// Comparator function to sort edges by weight in ascending order
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->w - edgeB->w;
}

// Find set of an element i (with path compression)
int findSet(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findSet(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets x and y (by rank)
void unionSets(Subset subsets[], int x, int y) {
    int rootX = findSet(subsets, x);
    int rootY = findSet(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Kruskal's algorithm to find Minimum Cost Spanning Tree
void kruskalMST(Edge edges[], int n, int m) {
    // Sort all edges in non-decreasing order of their weight
    qsort(edges, m, sizeof(Edge), compareEdges);

    // Allocate memory for creating n subsets (1-indexed nodes 1 to n)
    Subset *subsets = (Subset *)malloc((n + 1) * sizeof(Subset));
    for (int v = 1; v <= n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    Edge *mstEdges = (Edge *)malloc((n - 1) * sizeof(Edge));
    int edgeCount = 0;
    int totalWeight = 0;

    for (int i = 0; i < m && edgeCount < n - 1; i++) {
        Edge nextEdge = edges[i];

        int setU = findSet(subsets, nextEdge.u);
        int setV = findSet(subsets, nextEdge.v);

        // If including this edge does not cause a cycle
        if (setU != setV) {
            mstEdges[edgeCount++] = nextEdge;
            totalWeight += nextEdge.w;
            unionSets(subsets, setU, setV);
        }
    }

    // Display selected edges and cost
    printf("\nOutput:\n");
    printf("Edge\tCost\n");
    for (int i = 0; i < edgeCount; i++) {
        // Display edge in representation
        printf("%d--%d\t%d\n", mstEdges[i].u, mstEdges[i].v, mstEdges[i].w);
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalWeight);

    free(subsets);
    free(mstEdges);
}

int main(void) {
    int n, m;

    printf("Enter the number of nodes and edges (n m): ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Invalid input for nodes or edges.\n");
        return 1;
    }

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));
    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        if (scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w) != 3) {
            printf("Invalid edge format at line %d.\n", i + 1);
            free(edges);
            return 1;
        }
    }

    kruskalMST(edges, n, m);

    free(edges);
    return 0;
}
