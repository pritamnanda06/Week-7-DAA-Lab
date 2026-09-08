#include <stdio.h>

// Function to compute minimum moves to invert the coin triangle
void solveCoinTriangle(int n) {
    if (n <= 0) {
        printf("Number of rows must be greater than zero.\n");
        return;
    }

    int total_coins = n * (n + 1) / 2;
    int min_moves = (n * (n + 1)) / 6;

    printf("Number of rows (n)    : %d\n", n);
    printf("Total number of coins : %d\n", total_coins);
    printf("Minimum moves required: %d\n", min_moves);
    printf("Stationary coins      : %d\n", total_coins - min_moves);
}

int main() {
    int rows;
    
    printf("Enter the number of rows (n) for the coin triangle: ");
    if (scanf("%d", &rows) != 1) {
        printf("Invalid input format.\n");
        return 1;
    }

    solveCoinTriangle(rows);

    return 0;
}