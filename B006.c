#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 10000

typedef struct {
    int vertices[MAX_N + 1][MAX_N + 1];
    int visited[MAX_N + 1];
} Graph;

typedef struct {
    int data[MAX_N];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

void enqueue(Queue* q, int x) {
    if (q->rear == MAX_N - 1) {
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->data[++(q->rear)] = x;
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return -1;
    }

    return q->data[(q->front)++];
}

void dfs(Graph* graph, int v, int n) {
    printf("%d ", v);
    graph->visited[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph->vertices[v][i] && !graph->visited[i]) {
            dfs(graph, i, n);
        }
    }
}

void bfs(Graph* graph, int v, int n) {
    Queue q;
    initQueue(&q);

    printf("%d ", v);
    graph->visited[v] = 1;
    enqueue(&q, v);

    while (q.front != -1) {
        int current = dequeue(&q);

        for (int i = 1; i <= n; i++) {
            if (graph->vertices[current][i] && !graph->visited[i]) {
                printf("%d ", i);
                graph->visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int n, m, v;
    Graph graph;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i <= n; i++) {
        graph.visited[i] = 0;
        for (int j = 0; j <= n; j++) {
            graph.vertices[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph.vertices[a][b] = graph.vertices[b][a] = 1;
    }

    dfs(&graph, v, n);
    printf("\n");

    for (int i = 0; i <= n; i++) {
        graph.visited[i] = 0;
    }

    bfs(&graph, v, n);
    printf("\n");

    return 0;
}
