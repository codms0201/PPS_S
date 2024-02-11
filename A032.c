#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int k, n;
        scanf("%d %d", &k, &n);

        int apt[15][15] = {0};

        for (int i = 1; i <= 14; i++) {
            apt[0][i] = i;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                apt[i][j] = apt[i - 1][j] + apt[i][j - 1];
            }
        }

        printf("%d\n", apt[k][n]);
    }

    return 0;
}
