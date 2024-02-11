#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return abs(*(int*)b) - abs(*(int*)a);
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize && k > 0; ++i) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    if (k % 2 == 1) {
        nums[numsSize - 1] = -nums[numsSize - 1];
    }

    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    int nums[] = {4, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 1;

    int result = largestSumAfterKNegations(nums, numsSize, k);

    printf("Largest possible sum after modifications: %d\n", result);

    return 0;
}
