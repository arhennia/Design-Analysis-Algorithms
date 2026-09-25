#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void findLCS(const char *X, const char *Y) {
    int m = (int)strlen(X);
    int n = (int)strlen(Y);

    int **L = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        L[i] = (int *)calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] >= L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    int lcsLength = L[m][n];

    char *lcsStr = (char *)malloc((lcsLength + 1) * sizeof(char));
    lcsStr[lcsLength] = '\0';

    int i = m, j = n;
    int index = lcsLength - 1;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr[index--] = X[i - 1];
            i--;
            j--;
        } else if (L[i - 1][j] >= L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("\nOutput:\n");
    printf("LCS: %s\n", lcsStr);
    printf("LCS Length: %d\n", lcsLength);

    free(lcsStr);
    for (int k = 0; k <= m; k++) {
        free(L[k]);
    }
    free(L);
}

int main(void) {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter the first string into an array: ");
    if (scanf("%1023s", str1) != 1) {
        printf("Invalid first string.\n");
        return 1;
    }

    printf("Enter the second string into an array: ");
    if (scanf("%1023s", str2) != 1) {
        printf("Invalid second string.\n");
        return 1;
    }

    findLCS(str1, str2);
    return 0;
}
