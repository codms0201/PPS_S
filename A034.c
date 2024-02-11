#include <stdio.h>

int main() {
    int remainders[42] = {0};
    int input, count = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &input);
        int remainder = input % 42;
        remainders[remainder] = 1;
    }

    for (int i = 0; i < 42; i++) {
        if (remainders[i] == 1) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
