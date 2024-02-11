#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int result = A * B * C;
    int count[10] = {0};

    while (result > 0) {
        int digit = result % 10;
        count[digit]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", count[i]);
    }

    return 0;
}
