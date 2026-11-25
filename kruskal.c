#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int cmp(const void *a, const void *b) {
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

int main() {
    int n, m, mincost = 0, count = 0;
    struct Edge edges[100];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, m, sizeof(edges[0]), cmp);

    printf("Edges in MST:\n");
    for (int i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, edges[i].w);
            mincost += edges[i].w;
            union1(u, v);
            count++;
        }
    }
    printf("Total Cost = %d\n", mincost);
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
