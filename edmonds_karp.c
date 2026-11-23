#include <stdio.h>
#include <stdbool.h>

#define MAX_V 50
#define INF 999999

bool bfs(int rGraph[MAX_V][MAX_V], int s, int t, int parent[], int V) {
    bool visited[MAX_V] = {false};
    int queue[MAX_V];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
                if (v == t) return true;
            }
        }
    }
    return false;
}

int edmondsKarp(int graph[MAX_V][MAX_V], int s, int t, int V) {
    int u, v;
    int rGraph[MAX_V][MAX_V];

    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[MAX_V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent, V)) {
        int path_flow = INF;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V, source, sink;
    int graph[MAX_V][MAX_V];

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1) return 0;

    printf("Enter capacity adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source and sink vertex: ");
    scanf("%d %d", &source, &sink);

    printf("Maximum Flow: %d\n", edmondsKarp(graph, source, sink, V));
    return 0;
}
