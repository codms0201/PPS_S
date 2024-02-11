#include <stdio.h>

#define MAX_COMPUTERS 100

int graph[MAX_COMPUTERS + 1][MAX_COMPUTERS + 1];
int visited[MAX_COMPUTERS + 1];

void dfs(int current, int n) {
    visited[current] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[current][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }

    dfs(1, n);

    int infectedCount = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            infectedCount++;
        }
    }

    printf("%d\n", infectedCount - 1);

    return 0;
}
