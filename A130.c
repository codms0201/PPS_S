#include <stdio.h>
#include <stdlib.h>

int main() {
    int K;
    scanf("%d", &K);

    int* stack = (int*)malloc(sizeof(int) * K);
    int top = -1;

    int sum = 0;

    for (int i = 0; i < K; i++) {
        int num;
        scanf("%d", &num);

        if (num == 0) {
            sum -= stack[top];
            top--;
        } else {
            stack[++top] = num;
            sum += num;
        }
    }

    printf("%d\n", sum);

    free(stack);

    return 0;
}