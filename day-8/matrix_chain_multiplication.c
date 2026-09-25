#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Print the optimal parenthesization of matrices
void printOptimalParens(int **s, int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printf(" ");
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Matrix Chain Multiplication using Dynamic Programming
void matrixChainOrder(int p[], int n) {
    // Allocate M and S tables (1-indexed: 1..n x 1..n)
    int **m = (int **)malloc((n + 1) * sizeof(int *));
    int **s = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        m[i] = (int *)calloc(n + 1, sizeof(int));
        s[i] = (int *)calloc(n + 1, sizeof(int));
    }

    // m[i][i] is already 0 from calloc

    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Display M Table
    printf("\nOutput:\nM Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%-8d", m[i][j]);
        }
        printf("\n");
    }

    // Display S Table
    printf("\nS Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%-8d", s[i][j]);
        }
        printf("\n");
    }

    // Display Optimal Parenthesization
    printf("\nOptimal parenthesization: ");
    printOptimalParens(s, 1, n);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(m[i]);
        free(s[i]);
    }
    free(m);
    free(s);
}

int main(void) {
    int n;

    printf("Enter number of matrices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    int *p = (int *)malloc((n + 1) * sizeof(int));
    int prev_col = 0;

    for (int i = 1; i <= n; i++) {
        int r, c;
        printf("Enter row and col size of A%d: ", i);
        if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
            printf("Invalid matrix dimensions.\n");
            free(p);
            return 1;
        }

        if (i == 1) {
            p[0] = r;
            p[1] = c;
            prev_col = c;
        } else {
            if (r != prev_col) {
                printf("Dimension mismatch! A%d rows (%d) != A%d columns (%d).\n",
                       i, r, i - 1, prev_col);
                free(p);
                return 1;
            }
            p[i] = c;
            prev_col = c;
        }
    }

    matrixChainOrder(p, n);

    free(p);
    return 0;
}
