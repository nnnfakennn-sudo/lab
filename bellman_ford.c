#include <stdio.h>
#include <stdlib.h>

#define INF 999999

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, struct Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int V, E, src;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &V, &E) != 2) return 0;

    struct Edge edges[E];
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(V, E, edges, src);
    return 0;
}
