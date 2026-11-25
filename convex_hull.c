#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

struct Point p0;

void swap(struct Point *p1, struct Point *p2) {
    struct Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int distSq(struct Point p1, struct Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2) {
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

void convexHull(struct Point points[], int n) {
    if (n < 3) {
        printf("Convex hull requires at least 3 points.\n");
        return;
    }

    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    swap(&points[0], &points[min]);
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(struct Point), compare);

    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }

    if (m < 3) return;

    struct Point stack[m];
    int top = -1;
    stack[++top] = points[0];
    stack[++top] = points[1];
    stack[++top] = points[2];

    for (int i = 3; i < m; i++) {
        while (top >= 1 && orientation(stack[top - 1], stack[top], points[i]) != 2)
            top--;
        stack[++top] = points[i];
    }

    printf("Convex Hull points:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }
}

int main() {
    int n;
    printf("Enter number of points: ");
    if (scanf("%d", &n) != 1 || n < 3) return 0;

    struct Point points[n];
    printf("Enter points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convexHull(points, n);
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
