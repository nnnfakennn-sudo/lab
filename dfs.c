#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    int edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("DFS traversal: ");
    dfs(start);
    printf("\n");
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
