#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        double num;
        char op1, op2, op3;
        scanf("%lf %c %c %c", &num, &op1, &op2, &op3);

        double result;
        if (op1 == '@') {
            result = num * 3;
        } else if (op1 == '%') {
            result = num + 5;
        } else {
            result = num - 7;
        }

        if (op2 == '@') {
            result *= 3;
        } else if (op2 == '%') {
            result += 5;
        } else if (op2 == '#') {
            result -= 7;
        }

        if (op3 == '@') {
            result *= 3;
        } else if (op3 == '%') {
            result += 5;
        } else if (op3 == '#') {
            result -= 7;
        }

        printf("%.2lf\n", result);
    }

    return 0;
}
