#include <stdio.h>
#include <stdbool.h>

#define MAX_V 50
#define INF 999999

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX_V][MAX_V], int V, int src) {
    int dist[MAX_V];
    bool sptSet[MAX_V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        if (u == -1) break;
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
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
    int V, src;
    int graph[MAX_V][MAX_V];

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1) return 0;

    printf("Enter weighted adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
