#include <stdio.h>

int main() {
    int nums[100];
    int count = 0;
    int d_num;

    printf("배열에 넣을 원소들을 겹치지 않게 입력해주세요. (입력을 끝내려면 -1을 입력하세요)\n");

    while (1) {
        scanf("%d", &nums[count]);
        if (nums[count] == -1) break; // -1을 입력하면 입력 종료
        count++;
    }

    printf("divisor을 입력 해주세요. ");
    scanf("%d", &d_num);

    int result[100];
    int resultCount = 0;

    printf("[");
    for (int i = 0; i < count; i++) {
        if (nums[i] % d_num == 0) {
            result[resultCount] = nums[i];
            resultCount++;
            int j = resultCount - 1;
            while (j > 0 && result[j] < result[j - 1]) {
                int temp = result[j];
                result[j] = result[j - 1];
                result[j - 1] = temp;
                j--;
            }
        }
    }

    if (resultCount == 0) {
        printf("-1");
    } else {
        for (int i = 0; i < resultCount; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", result[i]);
        }
    }
    printf("]");

    return 0;
}