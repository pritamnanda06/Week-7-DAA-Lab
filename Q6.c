#include <stdio.h>
#include <stdlib.h>

typedef struct { int year, type; } Event;

int compare(const void *a, const void *b) {
    Event *e1 = (Event *)a, *e2 = (Event *)b;
    return (e1->year != e2->year) ? e1->year - e2->year : e1->type - e2->type;
}

int main() {
    int n;
    printf("Enter number of scientists: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    Event events[2 * n];
    for (int i = 0; i < n; i++) {
        printf("Scientist %d (Birth Death): ", i + 1);
        scanf("%d %d", &events[2 * i].year, &events[2 * i + 1].year);
        events[2 * i].type = 1;       // Birth (+1)
        events[2 * i + 1].type = -1;  // Death (-1)
    }

    qsort(events, 2 * n, sizeof(Event), compare);

    int current = 0, max_alive = 0, best_year = 0;
    for (int i = 0; i < 2 * n; i++) {
        current += events[i].type;
        if (current > max_alive) {
            max_alive = current;
            best_year = events[i].year;
        }
    }

    printf("\nMaximum scientists alive concurrently: %d\n", max_alive);
    printf("Year of peak concurrent scientists: %d\n", best_year);

    return 0;
}