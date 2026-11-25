#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS traversal: ");
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
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
    bfs(start);
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
