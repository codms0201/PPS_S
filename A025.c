#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    if (n <= 0) {
        return false;
    }

    while (n > 1) {
        if (n % 4 != 0) {
            return false;
        }
        n /= 4;
    }

    return true;
}

int main() {
    int num1 = 16;
    int num2 = 5;
    int num3 = 1;

    printf("Input: %d, Output: %s\n", num1, isPowerOfFour(num1) ? "true" : "false");
    printf("Input: %d, Output: %s\n", num2, isPowerOfFour(num2) ? "true" : "false");
    printf("Input: %d, Output: %s\n", num3, isPowerOfFour(num3) ? "true" : "false");

    return 0;
}
