#include <stdio.h>

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    int heights[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (heights[i] > heights[j]) {
                int temp = heights[i];
                heights[i] = heights[j];
                heights[j] = temp;
            }
        }
    }

    int max_length = L;
    for (int i = 0; i < N; i++) {
        if (heights[i] <= max_length) {
            max_length++;
        } else {
            break;
        }
    }

    printf("%d\n", max_length);

    return 0;
}
