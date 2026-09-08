#include <stdio.h>

long long move_count = 0;

void turnOn(int n);

// Turn OFF n switches (given all n switches are currently ON)
void turnOff(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Move %lld: Toggle switch 1\n", ++move_count);
        return;
    }
    if (n == 2) {
        printf("Move %lld: Toggle switch 2\n", ++move_count);
        printf("Move %lld: Toggle switch 1\n", ++move_count);
        return;
    }
    turnOff(n - 2);
    printf("Move %lld: Toggle switch %d\n", ++move_count, n);
    turnOn(n - 2);
    turnOff(n - 1);
}

// Turn ON n switches (given all n switches are currently OFF)
void turnOn(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Move %lld: Toggle switch 1\n", ++move_count);
        return;
    }
    if (n == 2) {
        printf("Move %lld: Toggle switch 1\n", ++move_count);
        printf("Move %lld: Toggle switch 2\n", ++move_count);
        return;
    }
    turnOn(n - 1);
    turnOff(n - 2);
    printf("Move %lld: Toggle switch %d\n", ++move_count, n);
    turnOn(n - 2);
}

int main() {
    int n;
    printf("Enter number of switches (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Direct formula for total moves: (2^(n+1) - 2)/3 for even n, (2^(n+1) - 1)/3 for odd n
    long long total_moves = (n % 2 == 0) ? ((1LL << (n + 1)) - 2) / 3 : ((1LL << (n + 1)) - 1) / 3;

    printf("Security Switches Solution\n");
    printf("Number of Switches (n) : %d\n", n);
    printf("Minimum Moves          : %lld\n", total_moves);

    if (n <= 6) {
        printf("Sequence of moves:\n");
        turnOff(n);
    } else {
        printf("Move sequence suppressed (n > 6 to prevent excessive log size).\n");
    }

    return 0;
}