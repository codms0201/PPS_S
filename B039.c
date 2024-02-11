#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int weight, src, dest;
} Edge;

typedef struct Subset {
    int parent, rank;
} Subset;

int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Edge edges[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &edges[i].weight);
        edges[i].src = i;
        edges[i].dest = i + 1;
    }

    Subset subsets[n + 1];
    for (int i = 0; i <= n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, n, sizeof(Edge), compare);

    long long totalEnergy = 0;

    for (int i = 0; i < n; i++) {
        int srcRoot = find(subsets, edges[i].src);
        int destRoot = find(subsets, edges[i].dest);

        if (srcRoot != destRoot) {
            totalEnergy += (long long)edges[i].weight;
            Union(subsets, srcRoot, destRoot);
        }
    }

    printf("%lld\n", totalEnergy);

    return 0;
}
