#include <stdio.h>

#define MAX_W 50
#define MAX_H 50

int w, h;
int map[MAX_H][MAX_W];

void dfs(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w || map[x][y] == 0) {
        return;
    }

    map[x][y] = 0;

    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}

int count_islands() {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 1) {
                count++;
                dfs(i, j);
            }
        }
    }
    return count;
}

int main() {
    while (1) {
        scanf("%d %d", &w, &h);

        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int result = count_islands();
        printf("%d\n", result);
    }

    return 0;
}
