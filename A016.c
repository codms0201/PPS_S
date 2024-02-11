#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int solution(int people[], int peopleSize, int limit) {r
    qsort(people, peopleSize, sizeof(int), compare);

    int left = 0, right = peopleSize - 1;
    int boats = 0;

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++;
            right--;
        } else {
            left++;
        }

        boats++;
    }

    return boats;
}

int main() {
    int people1[] = {70, 50, 80, 50};
    int limit1 = 100;
    printf("Result 1: %d\n", solution(people1, sizeof(people1) / sizeof(people1[0]), limit1));

    int people2[] = {70, 80, 50};
    int limit2 = 100;
    printf("Result 2: %d\n", solution(people2, sizeof(people2) / sizeof(people2[0]), limit2));

    return 0;
}
