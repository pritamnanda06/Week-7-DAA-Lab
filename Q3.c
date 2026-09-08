#include <stdio.h>

long long dp[100];
int opt_k[100];

// Standard 3-peg Hanoi for remaining (n - k) disks
void hanoi3(int n, int offset, char src, char tgt, char aux) {
    if (n == 0) return;
    hanoi3(n - 1, offset, src, aux, tgt);
    printf("Move disk %d: %c -> %c\n", offset + n, src, tgt);
    hanoi3(n - 1, offset, aux, tgt, src);
}

// 4-peg Reve's puzzle (Frame-Stewart algorithm)
void reve(int n, int offset, char src, char tgt, char aux1, char aux2) {
    if (n == 0) return;
    if (n == 1) {
        printf("Move disk %d: %c -> %c\n", offset + 1, src, tgt);
        return;
    }
    int k = opt_k[n];
    reve(k, offset, src, aux1, aux2, tgt);
    hanoi3(n - k, offset + k, src, tgt, aux2);
    reve(k, offset, aux1, tgt, src, aux2);
}

int main() {
    int n;
    printf("Enter number of disks (n): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n >= 100) return 1;

    // Dynamic programming to compute optimal split point k
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = -1;
        for (int k = 1; k < i; k++) {
            long long moves = 2 * dp[k] + ((1LL << (i - k)) - 1);
            if (dp[i] == -1 || moves < dp[i]) {
                dp[i] = moves;
                opt_k[i] = k;
            }
        }
    }

    printf("Minimum moves for %d disks: %lld\n\n", n, dp[n]);
    if (n <= 8) {
        reve(n, 0, 'A', 'D', 'B', 'C');
    }

    return 0;
}