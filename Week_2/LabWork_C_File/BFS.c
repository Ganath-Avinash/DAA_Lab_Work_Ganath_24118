#include <stdio.h>

int queue[20], front = -1, rear = -1;
int visited[20];

void bfs(int graph[20][20], int n, int start) {
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        int v = queue[++front];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
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

    bfs(graph, n, 0);
    return 0;
}
