#include <stdio.h>
#include <limits.h>

// Helper function to print optimal parenthesization recursively
void printParenthesis(int i, int j, int n, int s[n + 1][n + 1], char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printParenthesis(i, s[i][j], n, s, name);
    printParenthesis(s[i][j] + 1, j, n, s, name);
    printf(")");
}

void matrixChainOrder(int p[], int n) {
    int m[n + 1][n + 1];
    int s[n + 1][n + 1];

    // Base case: cost is 0 when multiplying a single matrix
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length (from 2 to n)
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Optimal split point
                }
            }
        }
    }

    printf("Matrix Chain Multiplication Analysis\n");
    printf("Minimum Scalar Multiplications : %d\n", m[1][n]);
    printf("Optimal Parenthesization        : ");
    char name = 'A';
    printParenthesis(1, n, n, s, &name);
}

int main() {
    int n;

    printf("Enter the number of matrices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Number of matrices must be positive.\n");
        return 1;
    }

    int p[n + 1];
    printf("Enter %d dimension values (p0 p1 ... p%d): ", n + 1, n);
    for (int i = 0; i <= n; i++) {
        if (scanf("%d", &p[i]) != 1 || p[i] <= 0) {
            printf("Invalid dimension input.\n");
            return 1;
        }
    }

    matrixChainOrder(p, n);

    return 0;
}