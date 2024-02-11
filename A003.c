#include <stdio.h>
#include <stdlib.h>

int* increment_large_integer(int* digits, int size, int* returnSize) {
    int carry = 1;

    for (int i = size - 1; i >= 0; i--) {
        int current_sum = digits[i] + carry;
        digits[i] = current_sum % 10;
        carry = current_sum / 10;
    }

    if (carry) {
        (*returnSize)++;
        digits = (int*)realloc(digits, (*returnSize) * sizeof(int));
        digits[0] = carry;
    }

    return digits;
}

int main() {
    int digits[] = {1, 2, 3};
    int size = sizeof(digits) / sizeof(digits[0]);
    int returnSize = size;

    int* result = increment_large_integer(digits, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);

    return 0;
}
