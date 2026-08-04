#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

// Function to calculate square of the area using Heron's formula
// Using square of area (16 * Area^2) avoids floating-point precision issues
double get_area_square(triangle tr) {
    double p = (tr.a + tr.b + tr.c) / 2.0;
    return p * (p - tr.a) * (p - tr.b) * (p - tr.c);
}

void sort_by_area(triangle* tr, int n) {
    // Bubble sort to order triangles by area in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (get_area_square(tr[j]) > get_area_square(tr[j + 1])) {
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}
