#include <stdio.h>
#include <stdbool.h>

struct Point {
    int x, y;
};

bool onSegment(struct Point p, struct Point q, struct Point r) {
    if (q.x <= (p.x > r.x ? p.x : r.x) && q.x >= (p.x < r.x ? p.x : r.x) &&
        q.y <= (p.y > r.y ? p.y : r.y) && q.y >= (p.y < r.y ? p.y : r.y))
        return true;
    return false;
}

int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(struct Point p1, struct Point q1, struct Point p2, struct Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main() {
    struct Point p1, q1, p2, q2;
    printf("Enter segment 1 start (x1 y1): ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Enter segment 1 end (x2 y2): ");
    scanf("%d %d", &q1.x, &q1.y);
    printf("Enter segment 2 start (x3 y3): ");
    scanf("%d %d", &p2.x, &p2.y);
    printf("Enter segment 2 end (x4 y4): ");
    scanf("%d %d", &q2.x, &q2.y);

    if (doIntersect(p1, q1, p2, q2)) {
        printf("The line segments intersect.\n");
    } else {
        printf("The line segments do NOT intersect.\n");
    }

    return 0;
}
