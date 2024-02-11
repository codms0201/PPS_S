#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);

    int A[50], B[50];

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    qsort(A, N, sizeof(int), compare);

    qsort(B, N, sizeof(int), compare);

    long long S = 0;
    for (int i = 0; i < N; i++) {
        S += (long long)A[i] * B[i];
    }

    printf("%lld\n", S);

    return 0;
}
