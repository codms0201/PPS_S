#include <stdio.h>

int main() {
    char numA[10001], numB[10001], result[10002];
    int carry = 0;

    scanf("%s %s", numA, numB);

    int i = 10000;
    int resultIndex = 0;

    while (i >= 0) {
        int digitA = (i >= strlen(numA)) ? 0 : numA[i] - '0';
        int digitB = (i >= strlen(numB)) ? 0 : numB[i] - '0';

        int sum = digitA + digitB + carry;
        result[resultIndex++] = (sum % 10) + '0';
        carry = sum / 10;

        i--;
    }

    if (carry > 0) {
        result[resultIndex++] = carry + '0';
    }

    for (int j = resultIndex - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }

    return 0;
}
