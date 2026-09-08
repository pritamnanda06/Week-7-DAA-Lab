#include <stdio.h>

void solveHittingTarget(int n) {
    if (n <= 1) {
        printf("Number of hiding spots (n) must be greater than 1.\n");
        return;
    }

    printf("Hitting a Moving Target Analysis\n");
    printf("Number of Hiding Spots (n) : %d\n", n);

    if (n == 2) {
        printf("Minimum Shots Guaranteed   : 2\n");
        printf("Shooting Sequence:\n");
        printf("Shot 1: Target spot 2\n");
        printf("Shot 2: Target spot 2\n");
        return;
    }

    int total_shots = 2 * (n - 2);
    printf("Minimum Shots Guaranteed   : %d\n", total_shots);

    printf("Shooting Sequence:\n");
    int shot_number = 1;

    // Pass 1: Forward sweep from spot 2 to n-1
    printf("--- Pass 1 (Forward Sweep) ---\n");
    for (int spot = 2; spot <= n - 1; spot++) {
        printf("Shot %d: Target spot %d\n", shot_number++, spot);
    }

    // Pass 2: Reverse sweep from spot n-1 down to 2
    printf("--- Pass 2 (Reverse Sweep) ---\n");
    for (int spot = n - 1; spot >= 2; spot--) {
        printf("Shot %d: Target spot %d\n", shot_number++, spot);
    }
}

int main() {
    int n;

    printf("Enter the number of hiding spots (n > 1): ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("Invalid input. n must be an integer greater than 1.\n");
        return 1;
    }

    solveHittingTarget(n);

    return 0;
}