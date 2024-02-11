#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char DNA[N + 1];
    scanf("%s", DNA);

    int mutations_A = 0, mutations_B = 0;
    int min_mutations = 0;

    for (int i = 0; i < N; i++) {
        if (DNA[i] == 'A') {
            mutations_B++;
        } else {
            mutations_A++;
        }

        min_mutations = (mutations_A < mutations_B) ? mutations_A : mutations_B;
    }

    printf("%d\n", min_mutations);

    return 0;
}
