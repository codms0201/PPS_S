#include <stdio.h>
#include <stdbool.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool isHarshad(int num) {
    int digitSum = sumOfDigits(num);
    return (num % digitSum == 0);
}

int main() {
    int num1 = 10;
    int num2 = 12;
    int num3 = 11;
    int num4 = 13;

    printf("%d: %s\n", num1, isHarshad(num1) ? "true" : "false");
    printf("%d: %s\n", num2, isHarshad(num2) ? "true" : "false");
    printf("%d: %s\n", num3, isHarshad(num3) ? "true" : "false");
    printf("%d: %s\n", num4, isHarshad(num4) ? "true" : "false");

    return 0;
}
