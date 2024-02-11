#include <stdio.h>

int sumOfFirstK(int k) {
    return (k * (k + 1)) / 2;
}

int arrangeCoins(int n) {
    int left = 0, right = n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long totalCoins = sumOfFirstK(mid);

        if (totalCoins == n) {
            return mid;
        } else if (totalCoins < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int main() {
    int n = 5;
    int result = arrangeCoins(n);

    printf("Number of complete rows: %d\n", result);

    return 0;
}
