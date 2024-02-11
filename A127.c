#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int T;
    printf("테스트 케이스의 개수 T를 입력하세요: ");
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int A, B;
        printf("자연수 A와 B를 입력하세요: ");
        scanf("%d %d", &A, &B);

        printf("%d\n", lcm(A, B));
    }

    return 0;
}
