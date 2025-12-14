#include <stdio.h>

int visited[20];

void dfs(int graph[20][20], int n, int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n = 4;
    int graph[20][20] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };

    dfs(graph, n, 0);
    return 0;
}
