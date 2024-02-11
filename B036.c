#include <stdio.h>

int main() {
    char expression[51];
    scanf("%s", expression);

    int result = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '+') {
            result += sign * num;
            num = 0;
        } else if (expression[i] == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else {
            num = num * 10 + (expression[i] - '0');
        }
    }

    result += sign * num;

    printf("%d\n", result);

    return 0;
}
