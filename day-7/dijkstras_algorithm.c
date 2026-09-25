#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Helper to open input file across various paths
FILE *openInputFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) return fp;

    char path[256];
    snprintf(path, sizeof(path), "input/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    snprintf(path, sizeof(path), "day-7/input/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    snprintf(path, sizeof(path), "day-7/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    snprintf(path, sizeof(path), "../day-7/input/%s", filename);
    fp = fopen(path, "r");
    if (fp) return fp;

    return NULL;
}

// Find unvisited vertex with minimum distance value
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Build string representation of path from source to target
void formatPath(int parent[], int src, int target, char *buffer, size_t bufsize) {
    if (src == target) {
        snprintf(buffer, bufsize, "-");
        return;
    }

    int path[256];
    int count = 0;
    int curr = target;

    while (curr != -1) {
        path[count++] = curr + 1; // 1-indexed
        if (curr == src) break;
        curr = parent[curr];
    }

    if (path[count - 1] != src + 1) {
        snprintf(buffer, bufsize, "No Path");
        return;
    }

    buffer[0] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        char temp[16];
        if (i == count - 1) {
            snprintf(temp, sizeof(temp), "%d", path[i]);
        } else {
            snprintf(temp, sizeof(temp), "->%d", path[i]);
        }
        strncat(buffer, temp, bufsize - strlen(buffer) - 1);
    }
}

// Dijkstra's Algorithm for Single Source Shortest Path
void dijkstra(int **graph, int n, int src) {
    int *dist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));
    int *parent = (int *)malloc(n * sizeof(int));

    int s = src - 1; // 0-indexed source

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[s] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Display output in tabular format
    printf("\nOutput:\n");
    printf("%-9s %-14s %-7s %s\n", "Source", "Destination", "Cost", "Path");

    for (int i = 0; i < n; i++) {
        char pathStr[256];
        formatPath(parent, s, i, pathStr, sizeof(pathStr));

        if (dist[i] == INT_MAX) {
            printf("%-9d %-14d %-7s %s\n", src, i + 1, "INF", "No Path");
        } else {
            printf("%-9d %-14d %-7d %s\n", src, i + 1, dist[i], pathStr);
        }
    }

    free(dist);
    free(visited);
    free(parent);
}

int main(void) {
    int n, src;

    printf("Enter the Number of Vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the Source Vertex: ");
    if (scanf("%d", &src) != 1 || src < 1 || src > n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    FILE *fp = openInputFile("inDiAdjMat1.dat");
    if (!fp) {
        printf("Error: Could not open inDiAdjMat1.dat\n");
        return 1;
    }

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (fscanf(fp, "%d", &graph[i][j]) != 1) {
                printf("Error reading matrix element at [%d][%d]\n", i, j);
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);

    dijkstra(graph, n, src);

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
