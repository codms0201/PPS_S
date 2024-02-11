#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char buttons[N + 2];
    scanf("%s", buttons + 1);

    int result = 0;

    for (int i = 1; i <= N; i++) {
        if (buttons[i] == '1') {
            result++;
            buttons[i] = '0';
            buttons[i + 1] = '1';
            buttons[i + 2] = '1';
        }
    }

    printf("%d\n", result);

    return 0;
}
