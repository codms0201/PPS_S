#include <stdio.h>

int isHanNumber(int n) {
    if (n < 100) {
        return 1;
    }

    int digit[3];
    int idx = 0;

    while (n > 0) {
        digit[idx++] = n % 10;
        n /= 10;
    }

    return (digit[0] - digit[1] == digit[1] - digit[2]);
}

int main() {
    int N;
    printf("자연수 N을 입력하세요: ");
    scanf("%d", &N);

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (isHanNumber(i)) {
            count++;
        }
    }

    printf("%d보다 작거나 같은 한수의 개수: %d\n", N, count);

    return 0;
}
