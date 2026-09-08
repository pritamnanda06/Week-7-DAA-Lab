#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Dynamic Programming function to find the minimum number of drops
int eggDrop(int eggs, int floors) {
    // dp[i][j] represents minimum drops needed with i eggs and j floors
    int dp[eggs + 1][floors + 1];

    // Base cases: 0 floors -> 0 drops, 1 floor -> 1 drop
    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    // Base case: 1 egg -> j drops for j floors
    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j;
    }

    // Fill the rest of the DP table using optimal substructure
    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= j; k++) {
                // max(breaks at floor k, survives at floor k)
                int res = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
                if (res < dp[i][j]) {
                    dp[i][j] = res;
                }
            }
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs, floors;

    printf("Enter the number of eggs (E): ");
    if (scanf("%d", &eggs) != 1 || eggs <= 0) {
        printf("Invalid input for eggs.\n");
        return 1;
    }

    printf("Enter the number of floors (F): ");
    if (scanf("%d", &floors) != 1 || floors < 0) {
        printf("Invalid input for floors.\n");
        return 1;
    }

    int result = eggDrop(eggs, floors);

    printf("Number of Eggs (E)   : %d\n", eggs);
    printf("Number of Floors (F) : %d\n", floors);
    printf("Minimum Droppings    : %d\n", result);

    return 0;
}